#include "graphFunctions.h"


int32_t main(int argc, char *argv[]) {

    graphInterpreter(argv[1]);

    system("dot -Tpng -O stdout.dot");

    return 0;
}
