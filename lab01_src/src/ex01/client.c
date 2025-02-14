#include <stdlib.h>
#include "sieve.h"

int main(int argc, char *argv[]) {
    sieve_init(atoi(argv[1]));
    sieve_run();
    sieve_finish();
}
