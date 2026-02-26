#!/bin/bash
# 简单的安装脚本

echo "🔧 编译程序..."
gcc -Wall -I./include src/astro_math.c src/external_test.c -o external_test -lm
gcc -Wall -I./include src/astro_math.c src/user_input.c -o user_input -lm

echo "📦 安装到系统..."
sudo install -m 755 external_test user_input /usr/local/bin/

echo "✅ 安装完成！可以在任何地方运行："
echo "  external_test"
echo "  user_input"
