# 模板使用的方式
## 基础的控制命令
- `make`命令会执行整个编译流程 对于修改过的文件会自动进行重新编译
- `make test`命令会执行编译流程 并将`test`文件夹下的所有c文件逐个作为输入 将输出结果写到对应的res文件中
- `make clean`清理生成的文件
## 同学们需要做的事情
1. 根据`tree.h`写出自己的`tree.cpp` 自行添加更多的功能 
2. 修改`main.l` `main.y`完善整个语法分析流程
3. 如果想要做额外工作自己进行更多修改
# 模板项目结构说明
```
.
├── Makefile 
├── README.md
├── common.h 
├── lex.yy.cc
├── main.cpp
├── main.l
├── main.out
├── main.output
├── main.tab.cc
├── main.tab.hh
├── main.y
├── test
│   ├── 0.c
│   ├── 1.c
│   ├── 2.c
│   └── 3.c
├── tree.cpp
└── tree.h
```
- `common.h`包含自定义的结点头文件 模板中只提供了简单的语法树结点`tree.h` 在其他文件中通过引用`common.h`即可使用自定义结点的各类方法
- `main.l`词法分析文件 通过flex编译后生成`lex.yy.cc` 在文件中引用`common.h`来使用自定义语法树结点的方法 引用`main.tab.hh`来使用语法分析过程中声明的token 配合语法分析器使用 生成的整个过程通过`yylex()`进行调用
- `main.y`语法分析文件 通过bison编译生成`main.tab.hh` `main.tab.cc` **注意为了生成头文件需要在文件中加入`%option defines`** 在文件中引用`common.h`来使用自定义语法树结点方法 加入`yylex()`函数声明来允许调用词法分析方法 生成的整个过程通过`yyparse()`进行调用
- `main.cpp`主体程序 包含`main()`函数 通过引用`main.tab.hh`来调用`yyparse()`开始语法分析过程 通过引用`common.h`来调用自定义语法树结点方法
- `main.output` bison编译时通过加入`-v`参数而生成的文法分析说明文件
- `main.out` 最后编译得到的可执行文件
- `tree.h` `tree.cpp`自定义语法树结点的声明与实现
- `.gitignore` 控制git管理文件时忽略文件的规则
- `Makefile` Makefile命令声明
# 关于Makefile命令的解释
简单解释一下命令的结构
```
目标:依赖1 依赖2 ...
    命令
    ...
```
## 目标
很好理解 平时输入`make 目标`其实就是会去当前的Makefile文件中找到我们声明的目标 并执行包含的命令 而当我们只输入`make`时 实际执行的默认的第一个目标 对应到我们模板的Makefile则是等价于执行`make all`(`.PHONY`的问题我们下面来讨论)
## 伪目标
`.PHONY`是说明伪目标而存在的 对于有些目标 比如`clean` 一般来说它并不是为了生成真的clean文件 它只是一个标签 但遇到有些特殊的情况 比如真的存在`clean`文件时make会出现问题 而`.PHONY`会显式的指明目标是一个伪目标 防止其他意外情况出现
## 依赖
但我们的`all`目标其实没有写任何命令 只写了一个依赖`run` 这又是怎么发挥效果的呢？

目标的依赖项可以是文件也可以是其他目标 在执行当前目标时make会查看当前目标的所有依赖项 如果有依赖项比当前目标还要新 那么就可以认为当前目标已经‘过时’了 需要重新生成对应的依赖项以及当前目标
## Makefile函数
实际上Makefile也提供一系列自带的函数来方便我们使用 例如模板中的`$(shell )`指调用一个shell命令 模板中的`main`目标 执行的命令`$(shell ls *.cpp *.cc)` 效果就是找到当前目录下所有的cpp与cc文件 实际最终效果相当于`g++ lex.yy.cc main.cpp main.tab.cc tree.cpp -o main.out` 而`$(basename $(shell find test/*.c))`就是两个函数的调用 先找到test文件夹下所有的c文件 再去掉它们的文件名后缀 在我们的模板中结果即为`test/0 test/1 test/2 test/3`
## 循环
在Makefile中`\`用来连接两行 表示两行虽然分开写但实际效果与连续写一致 我们通过使用循环 实现了逐个测试test文件夹下的文件的效果
# 关于结点类型的说明
在不进行声明的情况下 bison默认会定义YYSTYPE宏为int类型 若我们自行定义了YYSTYPE类型 那么自然flex中的`yylval`和bison中的`$$ $0 $1 $2...`会变为我们定义的类型 若我们使用`%union{}`之后通过`%token<type> %type<type>`的方式使用union中的类型 则不要定义YYSTYPE宏 bison会自动包含我们声明的union