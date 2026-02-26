# 天体角距离计算器

这是一个学习软件编译流程的示例项目。

## 项目结构

```
my_first_software/
├── README.md          # 项目说明（你正在读的文件）
├── Makefile           # 构建配置文件
├── include/           # 头文件目录
│   └── astro_math.h   # 函数声明
└── src/               # 源代码目录
    ├── angular_distance.c  # 主程序
    └── astro_math.c        # 数学函数库
```

## 编译和运行

### 方法1：手动编译（理解每一步）

```bash
# 步骤1: 编译源文件为目标文件（.c → .o）
gcc -Wall -I./include -c src/astro_math.c -o src/astro_math.o
gcc -Wall -I./include -c src/angular_distance.c -o src/angular_distance.o

# 步骤2: 链接目标文件为可执行程序
gcc src/astro_math.o src/angular_distance.o -o angular_calc -lm

# 步骤3: 运行
./angular_calc
```

### 方法2：使用Makefile（推荐）

```bash
# 编译
make

# 运行
./angular_calc

# 清理编译产物
make clean

# 安装到系统（需要sudo）
sudo make install

# 卸载
sudo make uninstall
```

## 编译流程详解

```
┌─────────────┐
│ 源代码 .c   │
└──────┬──────┘
       │ gcc -c（编译）
       ▼
┌─────────────┐
│ 目标文件 .o │  ← 机器码，但还不能运行
└──────┬──────┘
       │ gcc（链接）
       ▼
┌─────────────┐
│ 可执行文件  │  ← 可以运行了！
└─────────────┘
```

## 各命令解释

| 命令 | 作用 |
|------|------|
| `gcc -c file.c` | 编译：把C代码转成机器码（目标文件.o） |
| `gcc file.o -o prog` | 链接：把多个.o文件合并成可执行程序 |
| `-Wall` | 显示所有编译警告 |
| `-I./include` | 告诉编译器去哪找头文件 |
| `-lm` | 链接数学库（libm），使用sin/cos等函数需要 |
| `make` | 读取Makefile，自动执行编译命令 |
| `make install` | 把程序复制到系统目录，方便全局使用 |

## 为什么需要Makefile？

想象你有100个.c文件：
- **没有Makefile**：每次都要输入100条编译命令
- **有Makefile**：只需输入 `make`

而且Makefile会：
1. 只重新编译**修改过的**文件
2. 自动处理文件依赖关系
3. 提供clean、install等便捷命令
