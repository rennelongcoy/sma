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