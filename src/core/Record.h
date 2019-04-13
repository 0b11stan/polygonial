//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_RECORD_H
#define POLYGONIAL_RECORD_H

enum Label {
    NONE,
    TRIANGLE,
    RIGHT_TRIANGLE,
    ISOSCELES_TRIANGLE,
    RIGHT_ISOSCELES_TRIANGLE,
    EQUILATERAL_TRIANGLE,
    TETRAGON,
    SQUARE,
    RECTANGLE,
    TRAPEZIUM,
    ISOSCELES_TRAPEZIUM,
    PARALLELOGRAM,
    RHOMBUS,
    PENTAGON,
    HEXAGON,
    HEPTAGON,
    OCTAGON,
    NONAGON,
    DECAGON
};

class Record {

private:
    int sides;
    int right_angles;
    int parallels_sides;
    int same_length_sides;
    Label label = NONE;

public:
    Record(int sides, int right_angles, int parallels_sides, int same_lenght_sides) : sides(sides),
                                                                                      right_angles(right_angles),
                                                                                      parallels_sides(parallels_sides),
                                                                                      same_length_sides(
                                                                                              same_lenght_sides) {}

    int get_sides() const { return sides; }

    int get_right_angles() const { return right_angles; }

    int get_parallels_sides() const { return parallels_sides; }

    int get_same_length_sides() const { return same_length_sides; }

    Label get_label() const { return label; }

    void set_label(Label p_label) { this->label = p_label; }

    bool is_filled() { return label != NONE; }
};


#endif //POLYGONIAL_RECORD_H
