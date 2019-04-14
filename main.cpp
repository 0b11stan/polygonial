//
// Created by tristan on 04/04/19.
//

#include <cstdio>
#include <getopt.h>
#include <cstdlib>
#include <iostream>
#include "src/core/Record.h"
#include "src/core/RulesEngine.h"
#include "src/core/FactsEngine.h"
#include "src/core/InferenceEngine.h"
#include "src/cli/cli.h"


void start_gui() {
    printf("GUI NOT IMPLEMENTED YET\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        CLI cli(argc, argv);
        cli.start();
    }
    else start_gui();

    return 0;
}
