#include "infl_params.h"

// ===== ポテンシャル系の物理量の設定 ===== //
/**
 * V(\phi), \frac{dV}{d\phi}, \frac{d^2V}{d\phi^2}を収録
 */
double potential(Field field) {
    return 0.5*field.mass*field.mass*field.x*field.x;
}
double deriv_potential(Field field) {
    return field.mass*field.mass*field.x;
}
double deriv2_potential(Field field) {
    return field.mass*field.mass;
}

// ===== ポテンシャルに依存する物理量 ===== //
/**
 * エネルギー密度
 * \rho = \frac{1}{2}\dot{\phi}^2 + V(\phi)
 */
double energy_density(Field field) {
    return 0.5*field.dx*field.dx + potential(field);
}

/**
 * ハッブルパラメタ
 * H^2 = \frac{\rho}{3M_{Pl}^2} where Mpl = 1
 */
double hubble(Field field) {
    double rho = energy_density(field);
    return sqrt(rho/3.0);
}

double get_time_step(Field field) {
    double hub = hubble(field);
    double m_eff = sqrt(deriv2_potential(field));
    if (hub >= m_eff) {
        return (1.0/hub)/100.0;
    }else {
        return (1.0/m_eff)/100.0;
    }
}

// ===== 単一場スローロールインフレーションの運動方程式 ===== //
double diffeqs_single_field(double t, double y[], int i) {
    double a = y[0];
    Field field = set_field(y);
    double hub = hubble(field);
    double dv = deriv_potential(field);
    if (i == 0) {
        return hub*a;
    }
    if (i == 1) {
        return field.dx;
    }
    if (i == 2) {
        return - 3*hub*field.dx - dv;
    }
    else return 0;
}