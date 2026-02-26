/*
 * astro_math.h
 * 天文数学函数的头文件
 * 
 * 头文件的作用：
 * 1. 声明函数原型，让其他文件知道有哪些函数可用
 * 2. 定义常量和数据结构
 * 3. 不包含具体实现（实现在.c文件中）
 */

#ifndef ASTRO_MATH_H  // 防止重复包含
#define ASTRO_MATH_H

// ============ 常量定义 ============
#define PI 3.14159265358979323846
#define ARCSEC_PER_DEG 3600.0

// ============ 函数声明 ============

// 角度单位转换
double deg_to_rad(double deg);
double rad_to_deg(double rad);

// 坐标格式转换
double hms_to_deg(double h, double m, double s);  // 时分秒→度
double dms_to_deg(double d, double m, double s);  // 度分秒→度

// 角距离计算
double angular_separation(double ra1, double dec1, double ra2, double dec2);

#endif // ASTRO_MATH_H
