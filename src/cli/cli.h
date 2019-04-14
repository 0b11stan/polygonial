//
// Created by tristan on 14/04/19.
//

#ifndef POLYGONIAL_CLI_H
#define POLYGONIAL_CLI_H

using namespace std;

class CLI {

private:
    vector<string> arguments;
    static string to_string(Label label);

    void start_one_liner();
    void start_shell();

public:
    explicit CLI(int argc, char *argv[]);

    void start();

};

#endif //POLYGONIAL_CLI_H
