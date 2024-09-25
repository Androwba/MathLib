#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_NAN 0.0 / 0.0
#define s21_POS_INF 1.0 / 0.0
#define s21_NEG_INF -1.0 / 0.0
#define s21_EPS 1e-9
#define s21_PI 3.14159265358979323846264338327950288
#define s21_PI_2 1.57079632679489661923132169163975144
#define s21_EXP 2.7182818284590452353602874713526624
#define s21_DBL_MAX 1.79769313486231470e+308
#define s21_Cos_135_degrees 0.7071067811865475244008
#define s21_Radian_45_degrees 0.7853981633974480L
#define s21_Atan_Half_PI 1.003884821853887214L  // arc tangent π / 2
#define s21_Tan_90_degrees 16331239353195370L   // 1.5708 radians
#define s21_is_finite(x) __builtin_isfinite(x)  // if argument is finite
#define s21_is_inf(x) __builtin_isinf(x)        // if argument is infinite
#define s21_is_nan(x) __builtin_isnan(x)        // checks if x = number

int s21_abs(int x);               // computes absolute value of an integer value
long double s21_fabs(double x);   // absolute value of a floating-point value
long double s21_ceil(double x);   // returns the nearest integer > value
long double s21_floor(double x);  // returns the nearest integer = value
long double s21_log(double x);    // computes natural logarithm
long double s21_exp(double x);    // returns e raised to the given power
long double s21_sqrt(double x);   //  computes square root
long double s21_fmod(double x, double y);  // remainder of the floating division
long double s21_pow(double base, double exp);  // raises a number to given power
long double s21_factor(int n);   // computes the factorial using while loop
long double s21_sin(double x);   // computes sine
long double s21_cos(double x);   // computes cosine
long double s21_tan(double x);   // computes tangent
long double s21_atan(double x);  // computes arc tangent
long double s21_acos(double x);  // computes arc cosine
long double s21_asin(double x);  // computes arc sine

#endif  //  SRC_S21_MATH_H_
