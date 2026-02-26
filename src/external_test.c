#include <stdio.h>
#include <stdlib.h>
#include "astro_math.h"

int main() {
    printf("🌌 测试外部程序调用\n\n");
    
    // 测试系统命令
    printf("1. 当前目录:\n");
    system("ls -l");
    
    printf("\n2. Git版本:\n");
    int ret = system("git --version");
    
    printf("\n3. 检查天文工具:\n");
    system("which tempo 2>/dev/null && echo '✅ TEMPO可用' || echo '❌ TEMPO未找到'");
    system("which prepfold 2>/dev/null && echo '✅ PRESTO可用' || echo '❌ PRESTO未找到'");
    
    printf("\n4. 角距离计算:\n");
    double sep = angular_separation(267.02, -24.78, 267.021, -24.779);
    printf("角距离: %.4f 角秒\n", sep);
    
    return 0;
}
