# I. Introduction

This project demonstrates a Linux kernel device driver that performs a Simple Moving Average (SMA) calculation.

Example behavior for an SMA with window size = 5:

* Input sequence = 10, 10, 50, 100, 100, 200, 100, 1
* Expected output sequence = 10, 10, 23, 43, 54, 92, 110, 100

# II. Environment Setup

This project was tested to work with below environment:
| Environment Setting | Value |
| ------ | ------ |
|Operating System| Ubuntu 20.04.3 LTS|
|Kernel Release| 5.11.0-27-generic|
|Linux Headers Package| linux-headers-5.11.0-27-generic (Version: 5.11.0-27.29~20.04.1)|
|Secure Boot in BIOS| OFF (to be able to load out-of-tree Kernel modules)|

# III. Linux Kernel Driver

The SMA driver code is located at /driver directory where below commands are to be executed.

* Compilation
  > make clean

  > make all

* Loading the SMA kernel module
  > sudo insmod sma.ko

* Unloading the SMA kernel module
  > sudo rmmod sma.ko

# IV. Userland Applications

The user space applications consist of the following:
1. Main app
    - Executable file location: /bin/sma_main
    - This demonstrates a simple interaction with the driver through a simple C++ program to write and read data to the driver.
2. Test app
    - Executable file location: /bin/sma_tests
    - This executes tests using the Google Test framework to test usage of the kernel driver under three categories:
      - Moving Average calculation
      - Read operation
      - Write oepration

The user space main and test app are located at /src and /test directories, respectively.

* Compilation
  
  In the project root directory, execute the following:
  > mkdir build
  > 
  > cd build
  > 
  > make all

* Execution
  
  To execute the main app from project root directory, run:
  > ./bin/sma_main

  To execute the test app from project root directory, run:
  > ./bin/sma_tests

# V. Assumptions and Limitations
1. In the provided sample sequences below,
    * Input = 10, 10, 50, 100, 100, 200, 100, 1
    * Output = 10, 10, 23, 43, 54, 92, 110, 100

    The 4th element of the output sequence is actually 42.5.

    In current implementation of the Kernel driver, regular integer division was used and the result would give 42 and not 43.

    Any decimal and remainders in SMA calculations were not handled.

2. In the kernel driver, the window size for calculating the moving average is fixed to be 5.

3. In the kernel driver, the maximum sequence length that is supported is set to 128 bytes.

4. The kernel driver was tested with unsigned values. So each element's value would be in the range of 0-255.

5. Error-handling is focused on handling EFAULT in cases of invalid memory range accesses.

6. In the userland applications, the write and read operations are always consecutive. There is currently no handling for race conditions in both user space or kernel space in the case of write and read processes at the same tim.
