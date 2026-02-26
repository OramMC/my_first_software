# =====================================================
# Makefile - 自动化构建配置文件
# =====================================================
# 
# Makefile 的作用：
# 1. 定义如何编译程序
# 2. 管理文件依赖关系（修改一个文件，只重新编译相关部分）
# 3. 简化编译命令（只需输入 make）
#
# 基本语法：
# 目标: 依赖
#     命令（必须用Tab缩进！）
# =====================================================

# ---------- 变量定义 ----------
# CC: 编译器
CC = gcc

# CFLAGS: 编译选项
#   -Wall: 显示所有警告
#   -g: 包含调试信息
#   -I: 指定头文件搜索路径
CFLAGS = -Wall -g -I./include

# LDFLAGS: 链接选项
#   -lm: 链接数学库（使用sin, cos等函数需要）
LDFLAGS = -lm

# 源文件目录
SRC_DIR = src

# 目标程序名
TARGET1 = angular_calc
TARGET2 = external_test

# 源文件列表
SOURCES1 = $(SRC_DIR)/angular_distance.c $(SRC_DIR)/astro_math.c
SOURCES2 = $(SRC_DIR)/external_test.c

# 目标文件（.c → .o）
OBJECTS1 = $(SOURCES1:.c=.o)
OBJECTS2 = $(SOURCES2:.c=.o)

# 安装目录（make install 会把程序复制到这里）
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

# ---------- 构建规则 ----------

# 默认目标：编译所有程序
# 输入 make 时执行这个
all: $(TARGET1) $(TARGET2)
	@echo "✓ 全部编译完成！"
	@echo "运行方式:"
	@echo "  ./$(TARGET1)    # 角距离计算器"
	@echo "  ./$(TARGET2)    # 外部程序测试"

# 链接：把所有.o文件合并成可执行程序
$(TARGET1): $(OBJECTS1)
	@echo ">> 链接 $(TARGET1)..."
	$(CC) $(OBJECTS1) -o $(TARGET1) $(LDFLAGS)

$(TARGET2): $(OBJECTS2)
	@echo ">> 链接 $(TARGET2)..."
	$(CC) $(OBJECTS2) -o $(TARGET2) $(LDFLAGS)

# 编译规则：.c → .o
# $<: 第一个依赖文件
# $@: 目标文件
%.o: %.c
	@echo ">> 编译 $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译产物
clean:
	@echo ">> 清理编译文件..."
	rm -f $(OBJECTS1) $(OBJECTS2) $(TARGET1) $(TARGET2)
	@echo "✓ 清理完成"

# 安装到系统目录（需要sudo权限）
install: $(TARGET1) $(TARGET2)
	@echo ">> 安装到 $(BINDIR)..."
	install -d $(BINDIR)
	install -m 755 $(TARGET1) $(BINDIR)
	install -m 755 $(TARGET2) $(BINDIR)
	@echo "✓ 安装完成！现在可以在任何地方运行程序"

# 卸载
uninstall:
	@echo ">> 从 $(BINDIR) 移除..."
	rm -f $(BINDIR)/$(TARGET1)
	rm -f $(BINDIR)/$(TARGET2)
	@echo "✓ 卸载完成"

# 声明伪目标（这些不是真实文件）
.PHONY: all clean install uninstall

# ---------- 依赖关系 ----------
# 如果头文件修改了，相关的.c文件需要重新编译
$(SRC_DIR)/angular_distance.o: include/astro_math.h
$(SRC_DIR)/astro_math.o: include/astro_math.h
