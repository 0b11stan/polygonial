//
// Created by tristan on 04/04/19.
//

#include <cstdio>
#include <getopt.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
    printf("Hello World !\n");

    int count;
    int sides = 0;
    int right_angles = 0;
    int parallels_sides = 0;
    int same_length_sides = 0;

    while ((count = getopt(argc, argv, "s:r:p:l:")) != -1) {
        switch (count) {
            case 's':
                if (optarg) sides = atoi(optarg);
                break;
            case 'r':
                if (optarg) right_angles = atoi(optarg);
                break;
            case 'p':
                if (optarg) parallels_sides = atoi(optarg);
                break;
            case 'l':
                if (optarg) same_length_sides = atoi(optarg);
                break;
            default:
                printf("ERROR : no args provided.");
                return 0;
        }
    }

    printf("sides : %d\n", sides);
    printf("right angles : %d\n", right_angles);
    printf("parallels sides : %d\n", parallels_sides);
    printf("same length sides : %d\n", same_length_sides);

    return 0;
}
