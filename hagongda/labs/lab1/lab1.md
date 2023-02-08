## la1 实验
### 0x01 修改启动是打印的开机 Logo 信息
> 要求：修改目前在屏幕上显示的开机 Logo 信息，要求显示一段自己设计的提示信息。比如 "LOS is booting ..."。

在这之前首先介绍一下 `int 0x10` 中断

| AH | 功能 | 调用参数 | 返回参数 |
| -- | --   |   --    |    --   |
| 03 |读光标位置 | BH = 页号 | CH = 光标开始行<br/>CL = 光标结束行<br/>DH = 行、DL = 列|
|13| 显示字符串|ES:BP = 串地址<br/>CX = 串长度<br/>DH DL = 起始行列、BH = 页号<br/>AL = 0，BL = 属性 串：Char，char，……，char 显示后光标位置不变<br/>AL = 1，BL = 属性 串：Char，char，……，char 显示后，光标位置改变<br/>











在 `bootsect.s` 文件中修改 `msg1` 字符串 `Loading system ...` 为 `LOS is booting ......`：

```arm
msg1:
	.byte 13,10
	.ascii "LOS is booting ....."
	.byte 13,10,13,10
```

注意在 `Print some inane message` 处修改打印字符串的长度为 `26`：

```arm
	mov	ah,#0x03		! read cursor pos
	xor	bh,bh
	int	0x10
	
	mov	cx,#26
	mov	bx,#0x0007		! page 0, attribute 7 (normal)
	mov	bp,#msg1
	mov	ax,#0x1301		! write string, move cursor
	int	0x10
```

然后编译，`run` 即可。

### 0x02 完成 setup 文件的载入并跳转执行打印信息
> 要求：`bootsect.s` 能完成 `setup.s` 的载入，并跳转到 `setup.s` 开始地址执行，在 `setup.s` 开始执行时，需要向屏幕输出一行 `Now we are in SETUP` 信息。




## 参考

- [汇编中的10H中断int 10h详细说明](https://www.itzhai.com/assembly-int-10h-description.html)
- [BIOS INT 10中断功能详解](https://blog.csdn.net/qq_28256699/article/details/121103977)
- [BIOS INT 10-13功能调用的“另类”玩法(显示颜色)](https://www.cnblogs.com/ljf9201314/archive/2008/07/21/1247653.html)
- [操作系统实验一到实验九合集(哈工大李治军)](https://blog.csdn.net/leoabcd12/article/details/122268321)
