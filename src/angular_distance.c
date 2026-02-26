/*
 * angular_distance.c
 * 计算两个天体之间的角距离
 * 这是主程序源文件
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "astro_math.h"  // 自定义头文件

// 用户输入函数
void input_coordinates(const char* object_name, double* ra_h, double* ra_m, double* ra_s,
                      double* dec_d, double* dec_m, double* dec_s) {
    printf("\n请输入 %s 的坐标:\n", object_name);
    
    printf("  RA (时分秒): ");
    scanf("%lf %lf %lf", ra_h, ra_m, ra_s);
    
    printf("  Dec (度分秒): ");
    scanf("%lf %lf %lf", dec_d, dec_m, dec_s);
}

// 显示预设示例选择
void show_examples() {
    printf("\n可选的预设示例:\n");
    printf("  1. Ter5A vs Ter5D (脉冲星对)\n");
    printf("  2. Ter5A vs Ter5C (脉冲星对)\n");
    printf("  3. 自定义输入\n");
    printf("请选择 (1-3): ");
}

int main(int argc, char *argv[]) {
    printf("=================================\n");
    printf("  天体角距离计算器 v2.0\n");
    printf("=================================\n");
    
    int choice;
    double ra1_h, ra1_m, ra1_s, dec1_d, dec1_m, dec1_s;
    double ra2_h, ra2_m, ra2_s, dec2_d, dec2_m, dec2_s;
    
    show_examples();
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            // Ter5A vs Ter5D
            printf("\n使用预设: Ter5A vs Ter5D\n");
            ra1_h = 17; ra1_m = 48; ra1_s = 4.80;
            dec1_d = -24; dec1_m = 46; dec1_s = 49.0;
            
            ra2_h = 17; ra2_m = 48; ra2_s = 4.85;
            dec2_d = -24; dec2_m = 46; dec2_s = 45.2;
            break;
            
        case 2:
            // Ter5A vs Ter5C
            printf("\n使用预设: Ter5A vs Ter5C\n");
            ra1_h = 17; ra1_m = 48; ra1_s = 4.80;
            dec1_d = -24; dec1_m = 46; dec1_s = 49.0;
            
            ra2_h = 17; ra2_m = 48; ra2_s = 5.18;
            dec2_d = -24; dec2_m = 46; dec2_s = 47.7;
            break;
            
        case 3:
            // 用户自定义
            printf("\n自定义输入模式\n");
            input_coordinates("第一个天体", &ra1_h, &ra1_m, &ra1_s, &dec1_d, &dec1_m, &dec1_s);
            input_coordinates("第二个天体", &ra2_h, &ra2_m, &ra2_s, &dec2_d, &dec2_m, &dec2_s);
            break;
            
        default:
            printf("无效选择，使用默认 Ter5A vs Ter5D\n");
            ra1_h = 17; ra1_m = 48; ra1_s = 4.80;
            dec1_d = -24; dec1_m = 46; dec1_s = 49.0;
            ra2_h = 17; ra2_m = 48; ra2_s = 4.85;
            dec2_d = -24; dec2_m = 46; dec2_s = 45.2;
    }
    
    // 转换为度
    double ra1 = hms_to_deg(ra1_h, ra1_m, ra1_s);
    double dec1 = dms_to_deg(dec1_d, dec1_m, dec1_s);
    double ra2 = hms_to_deg(ra2_h, ra2_m, ra2_s);
    double dec2 = dms_to_deg(dec2_d, dec2_m, dec2_s);
    
    // 显示坐标
    printf("\n" + "="*50 + "\n");
    printf("天体1 坐标: %.0fh %.0fm %.2fs, %.0f° %.0f' %.1f\"\n", 
           ra1_h, ra1_m, ra1_s, dec1_d, dec1_m, dec1_s);
    printf("        = RA: %.6f°, Dec: %.6f°\n", ra1, dec1);
    
    printf("天体2 坐标: %.0fh %.0fm %.2fs, %.0f° %.0f' %.1f\"\n", 
           ra2_h, ra2_m, ra2_s, dec2_d, dec2_m, dec2_s);
    printf("        = RA: %.6f°, Dec: %.6f°\n", ra2, dec2);
    
    // 计算角距离
    double sep = angular_separation(ra1, dec1, ra2, dec2);
    
    printf("\n" + "="*50 + "\n");
    printf("计算结果:\n");
    printf("  角距离: %.4f 角秒\n", sep);
    printf("          %.6f 度\n", sep / 3600.0);
    printf("          %.4f 角分\n", sep / 60.0);
    
    return 0;
}
