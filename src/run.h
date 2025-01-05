#ifndef RUN_H
#define RUN_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "setting.h"
#include "utils/utils_init.h"
#include "utils/utils_numerical.h"
#include "infl_params.h"

void run_rk4(FILE *fp);
void run_python(const char *script_name);
void run_make_fig(void);

#endif
