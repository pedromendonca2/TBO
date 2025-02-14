#include <stdbool.h>
#include <stdlib.h>
#include "joseph.h"

int main(int argc, char *argv[]) {
    joseph_init(atoi(argv[1]), atoi(argv[2]));
    //joseph_run(true);
    joseph_run(false);
    joseph_finish();
}
