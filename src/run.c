#include "./run.h"

/**
 * 4次のRunge-Kutta法で微分方程式を解くためのコード。
 * 引数はファイルポインタ。
 * スカラー場がだいたい100回振動した時点で計算が終了する。
 */
const int MAX_OSCL_NUM = 100;
void run_rk4(FILE *fp) {

    // 初期値を設定
    CalculationSettings params = set_calculation();
    double *y = set_init_cond();

    // スカラー場が100回振動するまで動かし続ける
    int count_oscl = 0;
    double t = params.t_ini;
    while (t <= params.t_end) {
        Field field = set_field(y);
        fprintf(fp, "%e %e %e %e\n", t, y[0], y[1], y[2]);
        double dt = get_time_step(field);
        runge_kutta_4(diffeqs_single_field, t, y, params.y_size, dt);
        t += dt;
        count_oscl = count_oscillation(y[1]);
        if (count_oscl >= MAX_OSCL_NUM) break;
    }

    // メモリを解放
    free(y);
}

/**
 * Pythonを実行する関数。
 * 例）
 * >>> const char *PATH = "./foo/foo.dat";
 * >>> run_python(PATH)
 * でディレクトリfooの中のfoo.pyが実行される
 */
void run_python(const char *script_name) {
    char cmd[256] = "python ";
    strcat(cmd, script_name);
    int result = system(cmd);
    if (result == 0) {
        printf("[run_python]: SUCCESS %s\n", script_name);
    } else {
        printf("[run_python]: ERROR %s\n", script_name);
    }
}

/**
 * setting.cで設定したPythonファイルを実行している。
 * 図の種類を増やすたびに、ここにパスを付け加えればよろしい。
 */
void run_make_fig(void) {
    run_python(PATH_PYTHON_FIG_PHI_N);
    run_python(PATH_PYTHON_FIG_DOTPHI_N);
    run_python(PATH_PYTHON_FIG_PHI_DOTPHI);
}