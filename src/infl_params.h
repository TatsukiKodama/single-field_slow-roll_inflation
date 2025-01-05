#ifndef INFL_PARAMS_H
#define INFL_PARAMS_H

#include "setting.h"

// ===== ポテンシャル系の物理量の設定 ===== //
double potential(Field);
double deriv_potential(Field);

// ===== ポテンシャルに依存する物理量 ===== //
double energy_density(Field);
double hubble(Field);
double get_time_step(Field);

// ===== 単一場スローロールインフレーションの運動方程式 ===== //
double diffeqs_single_field(double, double [], int);

#endif /* INFL_PARAM_H */
