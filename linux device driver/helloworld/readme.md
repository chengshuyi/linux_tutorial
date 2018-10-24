### NOTES

1. <linux/version.h>

    * UTS_RELEASE = "2.6.10"
    * LINUX_VERSION_CODE = 132618 #2.6.10 binary representation of the kernel version
    * KERNEL_VERSION(major,minor,release) # KERNEL_VERSION(2,6,10) expands to 132618.

2. We normally hate to use goto , but in our opinion, this is one situation where it is useful.

3. <linux/errno.h> perror

### COMMAND

1. make

make -Wall -C /lib/modules/4.15.0-36-generic/build M=/home/cheng/gitworkspace/linux_module_tutorial/helloworld modules
make[1]: 进入目录“/usr/src/linux-headers-4.15.0-36-generic”
  CC [M]  /home/cheng/gitworkspace/linux_module_tutorial/helloworld/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/cheng/gitworkspace/linux_module_tutorial/helloworld/hello.mod.o
  LD [M]  /home/cheng/gitworkspace/linux_module_tutorial/helloworld/hello.ko
make[1]: 离开目录“/usr/src/linux-headers-4.15.0-36-generic”

2. sudo insmod hello.ko

3. sudo rmmod hello

4. dmesg

[27014.881479] Hello, world
[27188.303694] Goodbye, cruel world

### Q&A

1. printk

Kernel Function: After `insmod` has loaded it, the module is linked to the kernel and can access the kernel’s public symbols.

2. Kernel Modules Versus Applications

* A module, on the other hand, is linked only to the kernel, and the only functions it can call are the ones exported by the kernel; there are no libraries to link to.

* A module runs in kernel space, whereas applications run in user space.

3. Concurrency in the Kernel

* Linux kernel code, including driver code, must be reentrant—it must be capable of running in more than one context at the same time.

* If you do not write your code with concurrency in mind, it will be subject to catastrophic failures that can be exceedingly difficult to debug.

4. modprobe

* `modprobe` functions in much the same way as `insmod`, but it also loads any other modules that are required by the module you want to load.

* Thus, one `modprobe` command can sometimes replace several invocations of `insmod` (although you’ll still need `insmod` when loading your own modules from the current directory, because `modprobe` looks only in the standard installed module directories).

5. __init & __exit

* it is a hint to the kernel that the given function is used only at initialization time. The module loader drops the initialization function after the module is loaded, making its memory available for other uses. 

* There is a similar tag ( __initdata ) for data used only during initialization. Use of __init and __initdata is optional, but it is worth the trouble. Just be sure not to use them for any function (or data structure) you will be using after initialization completes. 

* You may also encounter __devinit and __devinitdata in the kernel source; these trans- late to __init and __initdata only if the kernel has not been configured for hotplug-gable devices.

* cleanup function cannot be marked __exit when it is called by nonexit code.


### OTHER COMMANDS

insmod 
modprobe 
rmmod 
lsmod(/proc/modules /sys/module)