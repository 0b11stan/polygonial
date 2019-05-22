//
// Created by tristan on 14/04/19.
//
#include "cli.h"

CLI::CLI(int argc, char **argv) {
  for (int x = 0; x < argc; x++) {
    arguments.emplace_back(argv[x]);
  }
}

void CLI::start() {
  cout << "Welcome to Polygonial !\n" << endl;
  if (arguments[1] == "--shell")
    start_shell();
  else
    start_one_liner();
}

void CLI::start_shell() {
  string command;
  string path("/tmp/polygonial");
  FactsEngine factsEngine(path);
  RulesEngine rulesEngine;
  InferenceEngine inferenceEngine(factsEngine, rulesEngine);

  while (command != "exit") {
    cout << "polygonial> ";
    getline(cin, command);
    if (command == "help") {
      cout << "usage :" << endl;
      cout << "  request    Start an interactive new polygon request." << endl;
      cout << "  tree       Show the fact database." << endl;
      cout << "  help       Show this help." << endl;
    } else if (command == "request") {
      int sides = 0;
      int right_angles = 0;
      int parallels_sides = 0;
      int same_length_sides = 0;

      cout << "Number of sides : ";
      cin >> sides;
      cout << "Number of right angles : ";
      cin >> right_angles;
      cout << "Number of sides which are parallel with another one : ";
      cin >> parallels_sides;
      cout << "Maximum number of sides which have the same size : ";
      cin >> same_length_sides;
      Record record(sides, right_angles, parallels_sides, same_length_sides);
      inferenceEngine.process(record);
      cout << "Your polygon is a : " << record.to_string() << endl;
    } else if (command == "tree") {
      factsEngine.display();
    }
    cout << endl;
  }
}

void CLI::start_one_liner() {
  cout << "ONE LINER IS NOT IMPLEMENTED YET" << endl;
  //    cout << "Your polygon :" << endl;
  //    int count;
  //    int sides = 0;
  //    int right_angles = 0;
  //    int parallels_sides = 0;
  //    int same_length_sides = 0;
  //
  //    while ((count = getopt(argc, argv, "s:r:p:l:")) != -1) {
  //        switch (count) {
  //            case 's':
  //                if (optarg) sides = atoi(optarg);
  //                break;
  //            case 'r':
  //                if (optarg) right_angles = atoi(optarg);
  //                break;
  //            case 'p':
  //                if (optarg) parallels_sides = atoi(optarg);
  //                break;
  //            case 'l':
  //                if (optarg) same_length_sides = atoi(optarg);
  //                break;
  //            default:
  //                printf("ERROR : no args provided.\n");
  //                return;
  //        }
  //    }
  //
  //    printf("sides : %d\n", sides);
  //    printf("right angles : %d\n", right_angles);
  //    printf("parallels sides : %d\n", parallels_sides);
  //    printf("same length sides : %d\n", same_length_sides);
  //
  //    Record record(sides, right_angles, parallels_sides, same_length_sides);
  //    RulesEngine rulesEngine;
  //    FactsEngine factsEngine("/tmp/polygonial");
  //    InferenceEngine inferenceEngine(factsEngine, rulesEngine);
  //    inferenceEngine.process(record);
  //
  //    printf("\nYour polygon is a %s\n",
  //    to_string(record.get_label()).c_str());
}

