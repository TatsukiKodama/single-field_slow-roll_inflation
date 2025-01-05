#ifndef SETTING_H
#define SETTING_H

#include <stdio.h>
#include <math.h>
#include "const.h" 
#include "utils/utils_numerical.h"
#include "utils/utils_init.h"

/***************
 * 数値計算の設定 
 ***************/

// ===== 数値計算　初期設定 ===== //
/**
 * num_step:    微分方程式の分割数
 * t_ini:       horizon-exit時刻
 * t_end:       インフレーション終了時刻
 * y_size:      方程式の数
 * y_init:      微分方程式の初期値
 */
typedef struct {
    int num_steps;
    double t_ini;
    double t_end;
    int y_size;
    double y_init[3];
} CalculationSettings;

CalculationSettings set_calculation();
double *set_init_cond();

// ===== 場 ===== //
typedef struct {
    double x;
    double dx;
    const double mass;
} Field;

Field set_field(double *y);

/************
 * パスの設定
 ************/
extern const char *PATH_OUTPUT_DAT_FILE;
extern const char *PATH_PYTHON_FIG_PHI_N;
extern const char *PATH_PYTHON_FIG_DOTPHI_N;
extern const char *PATH_PYTHON_FIG_PHI_DOTPHI;
 
#endif
