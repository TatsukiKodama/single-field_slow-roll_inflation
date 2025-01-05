#include "utils_numerical.h"

/**
 * 4次のRunge-Kutta法のルーティン。
 * 第1引数は解きたい微分方程式を代入する箇所である。
 */
void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], int y_size, double dx) {
    double h = dx/2.0;
    double t1[y_size], t2[y_size], t3[y_size];             
    double k1[y_size], k2[y_size], k3[y_size], k4[y_size];          
    int i;
    for (i = 0; i < y_size; i++) {
        k1[i] = dx*pf(x, y, i);
        t1[i] = y[i] + 0.5*k1[i];
    }
    for (i = 0; i < y_size; i++) {
        k2[i] = dx*pf(x + h, t1, i);
        t2[i] = y[i] + 0.5*k2[i];
    } 
    for (i = 0; i < y_size; i++) {
        k3[i] = dx*pf(x + h, t2, i);
        t3[i] = y[i] + k3[i];
    }
    for (i = 0; i<y_size; i++) {
        k4[i] = dx*pf(x + dx, t3, i);
    }
    for (i = 0; i < y_size; i++) y[i] += (k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6.0;
}

/**
 * ルンゲクッタで解く微分方程式の解の振動の回数を数える関数
 */
int count_oscillation(double amp) {
    static int count_oscll = 0; // 振動の回数のカウント
    static double old_amp = 0;
    static int trigger = 0;

    int is_negative = (amp - old_amp < 0);
    if (is_negative && trigger == 0) {
        count_oscll++;
        trigger = 1;
    }

    int is_positive = (amp - old_amp > 0);
    if(is_positive && trigger == 1) {
        trigger = 0;
    }
    return count_oscll;
}
