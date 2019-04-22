//
// Created by tristan on 04/04/19.
//

#include <cstdio>
#include <getopt.h>
#include <cstdlib>
#include <iostream>
#include <QApplication>
#include <src/gui/mainwindow.h>
#include "src/core/Record.hpp"
#include "src/core/RulesEngine.h"
#include "src/core/FactsEngine.h"
#include "src/core/InferenceEngine.h"
#include "src/cli/cli.h"

int start_gui(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}

int main(int argc, char *argv[]) {
    int return_value;

    if (argc > 1) {
        CLI cli(argc, argv);
        cli.start();
    }
    else return_value = start_gui(argc, argv);

    return return_value;
}
