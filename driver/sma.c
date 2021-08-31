#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Moving Average (SMA) Device Driver");
MODULE_AUTHOR("Rennel Ongcoy");

#define SMA_WINDOW_SIZE (5)

#define SMA_BUFFER_SIZE (128)
unsigned char sma_buffer[SMA_BUFFER_SIZE];

/* Device Number */
dev_t device_number;

/* Cdev */
struct cdev sma_cdev;

/* File operations */
ssize_t sma_read(struct file *filp, char __user *buff, size_t count, loff_t *f_pos)
{
    pr_info("[sma] %s: Read SMA output sequence - START\n", __func__);

    copy_to_user((void *)buff, &sma_buffer, count);

    pr_info("[sma] %s: Read SMA output sequence - COMPLETE\n", __func__);
    return count;
}

ssize_t sma_write(struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
    pr_info("[sma] %s: Write SMA input sequence - START\n", __func__);

    unsigned char sma_input_sequence[SMA_BUFFER_SIZE] = {};
    copy_from_user(sma_input_sequence, buff, count);

    int i = 0;
    for (i = 0; i < count; ++i) {
        int sum = 0;
        if (i < (SMA_WINDOW_SIZE - 1)) { /* for 1st 4 elements */
            int j;
            for (j = 0; j < (i + 1); ++j) {
                sum += sma_input_sequence[j];
            }
            sma_buffer[i] = sum / (i + 1);
        }
        else { /* for 5th element onwards */
            int j;
            for (j = i - (SMA_WINDOW_SIZE - 1); j < (i + 1); ++j) {
                sum += sma_input_sequence[j];
            }
            sma_buffer[i] = sum / SMA_WINDOW_SIZE;
        }
        pr_info("[sma] %s: sma_buffer[%d] = %d\n", __func__, i, sma_buffer[i]);
    }

    pr_info("[sma] %s: Write SMA input sequence - COMPLETE\n", __func__);
    return count;
}

struct file_operations sma_fops = {
    .read = sma_read,
    .write = sma_write
};

/* Class create */
struct class *sma_class;

/* Device create */
struct device *sma_device;

static int __init sma_init(void)
{
    pr_info("[sma] - INIT START\n");

    alloc_chrdev_region(&device_number, 0, 1, "sma_driver");

    cdev_init(&sma_cdev, &sma_fops);
    sma_cdev.owner = THIS_MODULE;

    cdev_add(&sma_cdev, device_number, 1);

    sma_class = class_create(THIS_MODULE, "sma_class");

    sma_device = device_create(sma_class, NULL, device_number, NULL, "sma");

    pr_info("[sma] - INIT SUCCESSFUL\n");
    return 0;
}

static void __exit sma_exit(void)
{
    pr_info("[sma] - EXIT START\n");
    device_destroy(sma_class, device_number);
    class_destroy(sma_class);
    cdev_del(&sma_cdev);
    unregister_chrdev_region(device_number, 1);
    pr_info("[sma] - EXIT SUCCESSFUL\n");
}

module_init(sma_init);
module_exit(sma_exit);