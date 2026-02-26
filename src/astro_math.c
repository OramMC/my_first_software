/*
 * astro_math.c
 * 天文数学函数的实现
 * 这是一个库文件，包含可复用的函数
 */

#include <math.h>
#include "astro_math.h"

// 角度转弧度
double deg_to_rad(double deg) {
    return deg * M_PI / 180.0;
}

// 弧度转角度
double rad_to_deg(double rad) {
    return rad * 180.0 / M_PI;
}

// 时分秒转度 (RA)
double hms_to_deg(double h, double m, double s) {
    // 24小时 = 360度，所以1小时 = 15度
    double hours = h + m/60.0 + s/3600.0;
    return hours * 15.0;
}

// 度分秒转度 (Dec)
double dms_to_deg(double d, double m, double s) {
    // 注意处理负数
    double sign = (d < 0) ? -1.0 : 1.0;
    d = fabs(d);
    return sign * (d + m/60.0 + s/3600.0);
}

// 计算两点之间的角距离（使用Haversine公式）
// 返回值单位：角秒
double angular_separation(double ra1, double dec1, double ra2, double dec2) {
    // 转换为弧度
    double ra1_rad = deg_to_rad(ra1);
    double dec1_rad = deg_to_rad(dec1);
    double ra2_rad = deg_to_rad(ra2);
    double dec2_rad = deg_to_rad(dec2);
    
    // Haversine公式
    double delta_ra = ra2_rad - ra1_rad;
    double delta_dec = dec2_rad - dec1_rad;
    
    double a = sin(delta_dec/2) * sin(delta_dec/2) +
               cos(dec1_rad) * cos(dec2_rad) * 
               sin(delta_ra/2) * sin(delta_ra/2);
    
    double c = 2 * asin(sqrt(a));
    
    // 转换为角秒
    return rad_to_deg(c) * 3600.0;
}
