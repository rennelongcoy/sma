#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Moving Average (SMA) Device Driver");
MODULE_AUTHOR("Rennel Ongcoy");

/* Device Number */
dev_t device_number;

/* cdev variable */
struct cdev sma_cdev;

/* File operations */
struct file_operations sma_fops;

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