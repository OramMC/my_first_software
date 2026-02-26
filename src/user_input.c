#include <stdio.h>
#include <stdlib.h>
#include "astro_math.h"

int main() {
    printf("🌌 交互式角距离计算器\n\n");
    
    double ra1, dec1, ra2, dec2;
    char name1[50], name2[50];
    
    printf("输入第一个天体名称: ");
    scanf("%s", name1);
    printf("输入%s的RA (度): ", name1);
    scanf("%lf", &ra1);
    printf("输入%s的Dec (度): ", name1);
    scanf("%lf", &dec1);
    
    printf("\n输入第二个天体名称: ");
    scanf("%s", name2);
    printf("输入%s的RA (度): ", name2);
    scanf("%lf", &ra2);
    printf("输入%s的Dec (度): ", name2);
    scanf("%lf", &dec2);
    
    double sep = angular_separation(ra1, dec1, ra2, dec2);
    
    printf("\n========== 结果 ==========\n");
    printf("%s: RA=%.6f°, Dec=%.6f°\n", name1, ra1, dec1);
    printf("%s: RA=%.6f°, Dec=%.6f°\n", name2, ra2, dec2);
    printf("角距离: %.4f 角秒\n", sep);
    
    return 0;
}
