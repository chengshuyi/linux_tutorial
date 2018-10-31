### [timestamp目录例程使用方法](./timestamp)

1. [timestamping.c](./timestamp/timestamping.c)

    * [源代码来自linux项目](https://github.com/torvalds/linux/blob/6f0d349d922ba44e4348a17a78ea51b7135965b1/tools/testing/selftests/networking/timestamping/timestamping.c)
    * 使用时注意，要想打印出软件或者硬件时间戳需要两步：1. 使能生成时间戳 2. 使能放入control消息队列   [参考来源](https://stackoverflow.com/questions/47313383/linux-udp-datagrams-and-kernel-timestamps-lots-of-examples-and-stackoversflow)