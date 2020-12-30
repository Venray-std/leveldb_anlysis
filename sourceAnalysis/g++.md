编译
g++ -o leveldbT test.cpp libleveldb.a -lpthread
-o 制定目标名称
-lpthread will make compiler execute with pthread.h library.
libleveldb.a是静态库文件

用g++编译链接C++程序时，当我们其中有包含第三方库的时候，需要我们手动的指定我们需要的库文件。库文件有两种，一种为动态库，一种为静态库

g++ -g -o  leveldbT test.cpp libleveldb.a -lpthread 可以生成gdb调试

gdb 调试命令
打印基本类型变量，数组，字符数组
最常见的使用便是使用print（可简写为p）打印变量内容。
例如，打印基本类型，数组，字符数组等直接使用p 变量名即可：
```
(gdb) p a
$1 = 10
(gdb) p *d
$2 = 0
(gdb) p *d@10
$3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```

对于简单的数据，print默认的打印方式已经足够了，它会根据变量类型的格式打印出来，但是有时候这还不够，我们需要更多的格式控制。常见格式控制字符如下：
x 按十六进制格式显示变量。
d 按十进制格式显示变量。
o 按八进制格式显示变量。
t 按二进制格式显示变量。
p/x c
$19 = {0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x73, 0x68, 0x6f, 0x75, 0x77, 0x61, 
  0x6e, 0x67, 0x0}

examine(简写为x)可以用来查看内存地址中的值。语法如下：
n 表示要显示的内存单元数，默认值为1
f 表示要打印的格式，前面已经提到了格式控制字符
u 要打印的单元长度 常用b表示字节
addr 内存地址

假如要把float变量e按照二进制方式打印，并且打印单位是一字节：
(gdb) x/4tb &e
0x7fffffffdbd4:    00000000    00000000    00001000    01000001

假设我们希望程序断住时，就显示某个变量的值，可以使用display命令。
display e
1: e = 8.5
如果想要清除可以使用
delete display num #num为前面变量前的编号,不带num时清除所有。

查看寄存器内容
gdb)info registers

list 列出源码
next命令（可简写为n）用于在程序断住后，继续执行下一条语句，
想跟踪add函数内部的情况，可以使用step命令（可简写为s）
使用continue命令 执行到下个断点

查看当前位置 where
类型信息 whatis db
