obj-m := sma.o
sma-objs := sma_driver.o sma_calculation.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

help:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) help
