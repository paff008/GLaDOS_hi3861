# GLaDOS_hi3861
1.基于Pegasus以及Taurus套件的智能小车，代码凑合看吧，没什么参考价值。  
2.大概结构最后更新时间大概是5.26日，临近期末考试月，之后便没有再改过，所以好多东西都没有写，以后大概也不会补罢。  
3.因为hi3861的代码是一人完工的，所以有好多数据的名字都是自己瞎起的，大概作者也没想到要上传github。  
4.由于这个里面有两个并行的进程（大概能这么描述），在任务调度上使用了好多互斥锁以及通信队列，所以进程很乱，但是能正常运行（某天晚上因为加了一行东西导致熬夜改代码），悲  
5.作者能力有限，导致有很多bug，如果有时间可能会完善下（大概吧）  
6.这些代码能实现的也不过是接收Taurusu发送的数据处理之后控制一些个外设（舵机，超声波，气泵），然后把数据通过云上报以及下发给小车驱动板，流程还是很简单的  
7.代码附件中还有部分是arduino的代码，这个是配合cnc shield v3驱动板和drv8825来驱动步进电机，虽然实际用时候并没有需要这么高精度，但是它能让电机唱歌！！！！满分  
8.以上大部分都是废话，在这里我要隆重感谢下我的两个不到死线不干活的队友，感谢他们的大缺大德，谢谢   
9.bang15便士  
