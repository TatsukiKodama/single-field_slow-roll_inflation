#ifndef UTILS_NUMERICAL_H
#define UTILS_NUMERICAL_H

void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], int y_size, double dx);
int count_oscillation(double amp);

#endif /* UTILS_NUMERICAL_H */