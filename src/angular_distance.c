/*
 * angular_distance.c
 * 计算两个天体之间的角距离
 * 这是主程序源文件
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "astro_math.h"  // 自定义头文件

int main(int argc, char *argv[]) {
    printf("=================================\n");
    printf("  天体角距离计算器 v1.0\n");
    printf("=================================\n\n");
    
    // 示例：计算Ter5A和Ter5D之间的角距离
    // Ter5A: RA=17h48m04.80s, Dec=-24d46m49.0s
    // Ter5D: RA=17h48m04.85s, Dec=-24d46m45.2s
    
    // 将时分秒转换为度
    double ra1 = hms_to_deg(17, 48, 4.80);
    double dec1 = dms_to_deg(-24, 46, 49.0);
    
    double ra2 = hms_to_deg(17, 48, 4.85);
    double dec2 = dms_to_deg(-24, 46, 45.2);
    
    printf("Ter5A 坐标:\n");
    printf("  RA  = %.6f 度\n", ra1);
    printf("  Dec = %.6f 度\n\n", dec1);
    
    printf("Ter5D 坐标:\n");
    printf("  RA  = %.6f 度\n", ra2);
    printf("  Dec = %.6f 度\n\n", dec2);
    
    // 计算角距离
    double sep = angular_separation(ra1, dec1, ra2, dec2);
    
    printf("角距离: %.4f 角秒\n", sep);
    printf("        %.6f 度\n", sep / 3600.0);
    
    return 0;
}
