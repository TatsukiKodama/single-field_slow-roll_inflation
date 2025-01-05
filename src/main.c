#include <stdio.h>
#include <stdlib.h>
#include "setting.h"      
#include "utils/utils_file.h"
#include "utils/utils_init.h"         
#include "run.h"          

int main(void) {

    // 前処理
    FILE *fp = open_file(PATH_OUTPUT_DAT_FILE);

    // 計算を実行
    run_rk4(fp);

    // 後処理
    fclose(fp);

    // Pythonを実行
    run_make_fig();
    return 0;
}
