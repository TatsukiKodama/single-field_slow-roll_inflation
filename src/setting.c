#include "setting.h"

/***************
 * 数値計算の設定 
 ***************/

// ===== 数値計算　初期設定 ===== //
/**
 * 構造体に数値計算の情報を設定する関数：
 * num_step:    微分方程式の分割数（あまり使わないので適当に設定してOK）
 * t_ini:       計算の初期時刻（通常horizon-exit）
 * t_end:       計算の終了時刻（run.cでスカラー場が100回振動したら終了するように設定してあるので、ほとんど気にしなくてOK）
 * y_size:      方程式の数
 * y_init:      微分方程式の初期値
 *              左からスケール因子、スカラー場、スカラー場の時間微分（Mpl unit）
 */
CalculationSettings set_calculation() {
    CalculationSettings params = {
        .num_steps = 100,
        .t_ini = 0.0,
        .t_end = 1.0e8,
        .y_size = 3,
        .y_init = {1, 15.5, 0.0}
    };
    return params;
}

/**
 * 初期値を設定する関数
 */
double *set_init_cond() {
    CalculationSettings params = set_calculation();
    double *y = init_array(params.y_size);
    for (int i = 0; i < params.y_size; i++) {
        y[i] = params.y_init[i];
    }
    return y;
}

/**
 * 構造体に場の情報を設定する関数
 */
Field set_field(double *y) {
    Field field = {
        .x = y[1],
        .dx = y[2], 
        .mass = 1.0e-5  // インフラトンの質量 [Mpl unit]
    };
    return field;
}

/************
 * パスの設定
 ************/
const char *PATH_OUTPUT_DAT_FILE = "./output/dat/data.dat";
const char *PATH_PYTHON_FIG_PHI_N = "./output/make_fig/phi_N.py";
const char *PATH_PYTHON_FIG_DOTPHI_N = "./output/make_fig/dotphi_N.py";
const char *PATH_PYTHON_FIG_PHI_DOTPHI = "./output/make_fig/phi_dotphi.py";
