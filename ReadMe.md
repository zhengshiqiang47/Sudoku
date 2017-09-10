# 第二次软工实践

## 下载运行

    执行BIN目录下的sudoku.exe文件。(注:exe为64位程序)

[项目github地址](https://github.com/zhengshiqiang47/Sudoku)

## 项目需求

利用程序随机构造出N个已解答的数独棋盘 。

**输入**

数独棋盘题目个数N（0<N<=1000000）

**输出**

随机生成N个**不重复**的**已解答完毕的**数独棋盘，并输出到sudoku.txt中，输出格式见下输出示例。
**[2017.9.4 新增要求]** 在生成数独矩阵时，左上角的第一个数为：（学号后两位相加）% 9 + 1。例如学生A学号后2位是80，则该数字为（8+0）% 9 + 1 = 9，那么生成的数独棋盘应如下（x表示满足数独规则的任意数字）：

```
9 x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
x x x x x x x x x
```

**输入示例**

```
3
```

**输出示例**（输出文件示例[戳我](https://files.cnblogs.com/files/easteast/%E7%A4%BA%E4%BE%8B%E8%BE%93%E5%87%BA.rar)）

```
2 6 8 4 7 3 9 5 1
3 4 1 9 6 5 2 7 8
7 9 5 8 1 2 3 6 4
5 7 4 6 2 1 8 3 9
1 3 9 5 4 8 6 2 7
8 2 6 3 9 7 4 1 5
9 1 7 2 8 6 5 4 3
6 8 3 1 5 4 7 9 2
4 5 2 7 3 9 1 8 6

4 5 1 7 8 2 3 6 9
7 8 6 4 9 3 5 2 1
3 9 2 1 5 6 4 8 7
5 2 7 6 4 9 8 1 3
9 6 8 5 3 1 2 7 4
1 3 4 2 7 8 6 9 5
8 1 5 3 6 7 9 4 2
6 7 3 9 2 4 1 5 8
2 4 9 8 1 5 7 3 6

9 5 8 3 6 7 1 2 4
2 3 7 4 5 1 9 6 8
1 4 6 9 2 8 3 5 7
6 1 2 8 7 4 5 9 3
5 7 3 6 1 9 4 8 2
4 8 9 2 3 5 6 7 1
7 2 4 5 9 3 8 1 6
8 9 1 7 4 6 2 3 5
3 6 5 1 8 2 7 4 9
```



## PSP分析

|                                         |                                  |          |          |
| --------------------------------------- | -------------------------------- | -------- | -------- |
| PSP2.1                                  | Personal Software Process Stages | 预估耗时（分钟） | 实际耗时（分钟） |
| Planning                                | 计划                               | 15       | 10       |
| · Estimate                              | · 估计这个任务需要多少时间                   | 15       | 10       |
| Development                             | 开发                               | 400      | 425      |
| · Analysis                              | · 需求分析 (包括学习新技术)                 | 40       | 35       |
| · Design Spec                           | · 生成设计文档                         | 30       | 35       |
| · Design Review                         | · 设计复审 (和同事审核设计文档)               | 0        | 0        |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范)           | 10       | 15       |
| · Design                                | · 具体设计                           | 110      | 90       |
| · Coding                                | · 具体编码                           | 100      | 160      |
| · Code Review                           | · 代码复审                           | 20       | 30       |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）             | 90       | 60       |
| Reporting                               | 报告                               | 55       | 62       |
| · Test Report                           | · 测试报告                           | 15       | 20       |
| · Size Measurement                      | · 计算工作量                          | 15       | 12       |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划                | 25       | 30       |
| 合计                                      |                                  | 470      | 500      |





## 解题思路

​	想法应该就是dfs去搜索满足行、列、块三个互斥条件的终盘，至于附加需求就只需在找到一个可行的棋盘后将左上角的数字全盘和自己需要的数字调换位置。每个dfs调用里，先取出需要放置的数，遍历判断行是否满足，满足的话判断那行对应的三个小块是否满足，最终判断那一行那一块的三个列是否满足，都满足的话就将数字放置进去，进行下一个数字的dfs。最终生成终盘。



## 设计实现

​	由于这次实践涉及的主要是算法，其次加了个文件操作，c++也挺长时间没写了，所以我封装了一个文件输出类(最终没用到)，大部分代码写到了主类里。



## 代码说明

for (int row = 0; row < 9; row++)//从第一行开始往下扫描

```
{
	if (!rows[t][row]) {
		int b = row / 3;
		for (int block = b*3; block < b*3+3; block++)//每行会有3块九宫格可以扫描
		{
			if (!blocks[t][block])
			{
				int k = block % 3;
				for (int cloumn = k*3; cloumn < (k + 1) * 3; cloumn++)//每行每块会有3列可以扫描
				{
					if (!cloumns[t][cloumn]&&!sudoku[row][cloumn])
					{
						sudoku[row][cloumn] = t;
						blocks[t][block]  = 1;
						rows[t][row] = 1;
						cloumns[t][cloumn] = 1;
						find(index + 1);
						blocks[t][block] =0;
						rows[t][row] = 0;
						cloumns[t][cloumn] = 0;
						sudoku[row][cloumn] = 0;
					}
				}
			}
		}
		break;
	}
}
```

## 测试运行

 

## 性能分析

代码覆盖率的插件[CoverageValidator](https://www.softwareverify.com/cpp-coverage.php)安装了之后运行闪退，最终还是没有测出代码覆盖率





