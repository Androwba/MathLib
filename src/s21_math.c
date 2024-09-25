#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) {
    x = x * (-1);
  }
  return x;
}

long double s21_fabs(double x) { return x < 0 ? -x : x; }

long double s21_ceil(double x) {
  long double Ceiling = (long long int)x;
  if (s21_is_inf(x) || s21_is_nan(x)) {
    Ceiling = x;
  }
  if (s21_fabs(x) > 0.0 && x != Ceiling) {
    if (x > 0.0) {
      Ceiling += 1;
    }
  }
  return Ceiling;
}

long double s21_floor(double x) {
  long double Floor = (long long int)x;
  if (!s21_is_finite(x) || s21_is_nan(x)) {
    Floor = x;
  }
  if (s21_fabs(x) > 0.0 && x != Floor) {
    if (x < 0.0) {
      Floor -= 1;
    }
  }
  return Floor;
}

long double s21_log(double x) {
  double res = 0.0;
  double check = 0.0;
  if (x == s21_POS_INF) {
    res = s21_POS_INF;
  } else if (x < 0.0 || s21_is_nan(x)) {
    res = s21_NAN;
  } else if (x == 0.0) {
    res = s21_NEG_INF;
  } else if (x == 1) {
    res = 0.0;
  } else {
    int power_exp = 0.0;
    for (; x >= s21_EXP; x /= s21_EXP, power_exp++) continue;
    for (int i = 0; i < 100; i++) {
      check = res;  // ↓ Halley's method formula ↓
      res = check + 2 * (x - s21_exp(check)) / (x + s21_exp(check));
    }
    res += power_exp;
  }
  return res;
}

long double s21_exp(double x) {
  long double result = 1.0;
  if (s21_is_nan(x)) {
    result = s21_NAN;
  } else if (x == s21_POS_INF) {
    result = x;
  } else if (x == s21_NEG_INF) {
    result = 0.0;
  } else {
    long double arg = 1.0, i = 1.0;
    int flag = 0;
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    while (s21_fabs(arg) > s21_EPS) {  // Maclaurin series
      arg *= x / i;
      i++;
      result += arg;
      if (result > s21_DBL_MAX) {
        result = s21_POS_INF;
        break;
      }
    }
    if (flag != 0) {
      if (result > s21_DBL_MAX)
        result = 0.0;
      else
        result = 1.0 / result;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double res = 4.0;
  if (x < 0 || x != x || s21_fabs(x) == s21_POS_INF) {
    res = s21_NAN;
  } else {
    long double arg = 0.0;
    while (s21_fabs(res - arg) > s21_EPS) {
      arg = res;  // Halving the Interval Method
      res = (arg + x / arg) / 2;
    }
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (s21_is_nan(x) || s21_is_nan(y) || x == s21_POS_INF ||
      s21_fabs(y) < s21_EPS) {
    res = s21_NAN;
  } else if (s21_fabs(x) < s21_EPS) {
    res = 0;
  } else if (y == s21_POS_INF) {
    res = x;
  } else {
    long long int mod = x / y;
    long double longx = x;
    long double longy = y;
    res = longx - mod * longy;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  if (base < 0) {
    if ((long int)exp == exp) {
      if (exp > 0) {
        res = base;
        for (long int i = 0; i < (long int)exp - 1; i++) res *= base;
      } else if (exp == 0) {
        res = 1.0;
      } else {
        res = 1.0 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) res /= base;
      }
    } else {
      if (s21_fabs(exp) == s21_POS_INF) {
        if (base * (-1) < 1) {
          res = 0.0;
        } else if (base * (-1) == 1) {
          res = 1.0;
        } else {
          if (exp == s21_NEG_INF)
            res = 0.0;
          else
            res = s21_POS_INF;
        }
      } else {
        res = s21_NAN;
      }
    }
  } else if (base == 0) {
    if (exp == 0)
      res = 1.0;
    else if (exp < 0)
      res = s21_POS_INF;
    else
      res = 0.0;
  } else if (base == 1) {
    res = 1.0;
  } else {
    if ((long int)exp == exp) {
      if (exp > 0) {
        res = base;
        for (long int i = 0; i < (long int)exp - 1; i++) {
          res *= base;
        }
      } else if (exp == 0) {
        res = 1.0;
      } else {
        res = 1.0 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
          res /= base;
        }
      }
    } else {
      res = s21_exp(exp * s21_log(base));  // main formula
    }
  }
  return res;
}

long double s21_factor(int n) {
  long double fac = 0.0;
  if (n == 0 || n == 1)
    fac = 1;
  else
    fac = n * s21_factor(n - 1);
  return fac;
}

long double s21_sin(double x) {
  long double sine = 0;
  long double res = 0.0;
  int n = 1;
  if (x == s21_NAN || x == s21_NEG_INF || x == s21_POS_INF) {
    res = s21_NAN;
  } else if (x == s21_PI) {
    res = 1e-50;
  } else if (x == -s21_PI) {
    res = -1e-50;
  } else if (x == 0) {
    res = 0;
  } else {
    while (x < -2 * s21_PI || x > 2 * s21_PI) {
      if (x > 2 * s21_PI) {
        x -= 2 * s21_PI;
      } else {
        x += 2 * s21_PI;
      }
    }
    if (x < 0) {
      x = -x;
      n = -1;
    }
    for (double i = 0; i < 100; i++) {
      sine += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factor(2 * i + 1);
    }
    res = sine * n;
  }
  return res;
}

long double s21_cos(double x) {
  long double cosine = 0;
  if (x == s21_NAN || x == s21_NEG_INF || x == s21_POS_INF) {
    cosine = s21_NAN;
  } else {
    for (; x < -2 * s21_PI || x > 2 * s21_PI;) {
      if (x > 2 * s21_PI) {
        x -= 2 * s21_PI;
      } else {
        x += 2 * s21_PI;
      }
    }
    if (x < 0) {
      x = -x;
    }
    for (int i = 0; i < 100; i++) {
      cosine += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factor(2 * i);
    }
  }
  return cosine;
}

long double s21_tan(double x) {
  long double res = 0.0;
  if (x == s21_PI_2) {
    res = s21_Tan_90_degrees;
  } else if (x == -s21_PI_2) {
    res = -s21_Tan_90_degrees;
  } else if (x == 0) {
    res = 0;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_atan(double x) {
  long double atan = 0.0;
  if (s21_is_nan(x)) {
    atan = s21_NAN;
  } else if (x == 1) {
    atan = s21_Radian_45_degrees;
  } else if (x == -1) {
    atan = -s21_Radian_45_degrees;
  } else if (x == s21_PI / 2) {
    atan = s21_Atan_Half_PI;
  } else if (x == -s21_PI / 2) {
    atan = -s21_Atan_Half_PI;
  } else if (x == s21_POS_INF || x == s21_NEG_INF) {
    atan = x < 0 ? -s21_PI_2 : s21_PI_2;
  } else if (-1.0 < x && x < 1.0) {
    for (int i = 0; i < 5000; i++) {
      atan += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 7000; i++) {
      atan += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    atan = s21_PI * s21_sqrt(x * x) / (2 * x) - atan;
  }
  return atan;
}

long double s21_acos(double x) {
  long double acos = 0.0;
  if (x == 1.0) {
    acos = 0.0;
  } else if (x == -1.0) {
    acos = s21_PI;
  } else if (x == 0) {
    acos = s21_PI_2;
  } else if (x == s21_Cos_135_degrees) {
    acos = s21_PI / 4;
  } else if (x == -s21_Cos_135_degrees) {
    acos = 3 * s21_PI / 4;
  } else if (0.0 < x && x < 1.0) {
    acos = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (-1. < x && x < 0.0) {
    acos = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    acos = s21_NAN;
  }
  return acos;
}

long double s21_asin(double x) {
  long double asin = 0.0;
  if (x == 1.0) {
    asin = s21_PI_2;
  } else if (x == -1.0) {
    asin = -s21_PI_2;
  } else if (s21_fabs(x) < s21_EPS) {
    asin = 0.0;
  } else if (x == s21_Cos_135_degrees) {
    asin = s21_PI / 4;
  } else if (x == -s21_Cos_135_degrees) {
    asin = -s21_PI / 4;
  } else if (-1.0 < x && x < 1.0) {
    asin = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    asin = s21_NAN;
  }
  return asin;
}
