# If KERNELRELEASE is defined, we've been invoked from the kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o
# Otherwise we were called directly from the command line; invoke the kernel build system.
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

all:
	$(MAKE) -Wall -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions .cache.mk *.symvers *.order
endif

# NOTE:
# makefile的文件名必须是大写的M，不然会出现 `～/gitworkspace/linux_module_tutorial/helloworld/Makefile: 没有那个文件或目录`