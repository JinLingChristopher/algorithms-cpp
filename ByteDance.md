## Network

- 数据库连接池技术
- HTTPS 连接过程
- HTTPS 如何确认收到的包就是 server 发来的
- 如何确定是用 HTTP 还是 HTTPS
- SSL 原理
- HTTPS 中 SSL 建立过程
- 对称加密、非对称加密、性能

- 接收窗口
- 确定发送窗口的大小，如何最大利用贷款，假设延迟 100ms，发送端 10MB/s，接收端 100Mb/s
- TCP 流量控制
- TCP 拥塞控制
- 滑动窗口大小

* TCP 和 UDP 的本质区别
* HTTP 可以使用 UDP 么

- 短域名如何映射到真正的域名
- SSO 原理
- cookie、session

## OS

- 用户态、内核态切换
- 为什么要分用户态和内核态
- 进程间通信方式，哪种最快，效率分析
  - shared memory
- 信号量怎么实现对共享资源的访问
- 如何同步 shared memory
- Linux 5 种 I/O 模型
- 协程的原理
- 爬虫适合多进程还是多线程
- CAS 有哪些问题、如何避免、底层原理
- CAS 为什么开销小、开销具体指的是什么
- 什么时候使用 spinlock
- 虚拟内存空间的布局

## C++

- 只有虚函数表的对象占用多少内存
- inline 函数一定会 inline 么？
- 为什么会出现 stack overflow
- map 的 key 如果是结构体须要注意什么问题

## Golang

- new 和 make 的区别
- error 和 panic 的区别
- golang 内存模型
- goroutine 调度模型
- interface assertion
- golang 并发模型
- 为什么 channel 做到线程安全
- 读写锁的原理
- 如何避免 goroutine leak
- context
- channel 的实现原理
- go 内存泄漏
- 用 channel 实现定时器
- clousure function
- Garbage Collection

## Docker

## K8s

- 有哪些组件
- 如何在 K8s 中实现负载均衡
- Kubernetes operator

## Git

- rebase
- merge
- cherry-pick
- 回滚

## Redis

- 容灾、备份、扩容
-
