//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_RECORD_H
#define POLYGONIAL_RECORD_H

#include <string>

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
  EQUILATERAL_PENTAGON,
  SATANISTIC_PENTAGON,
  HEXAGON,
  REGULAR_HEXAGON,
  HEPTAGON,
  OCTAGON,
  REGULAR_OCTAGON,
  NONAGON,
  DECAGON,
  REGULAR_DECAGON
};

class Record {
 private:
  int sides;
  int right_angles;
  int parallels_sides;
  int same_length_sides;
  Label label = NONE;

 public:
  Record(int sides, int right_angles, int parallels_sides,
         int same_lenght_sides)
      : sides(sides),
        right_angles(right_angles),
        parallels_sides(parallels_sides),
        same_length_sides(same_lenght_sides) {}

  int get_sides() const { return sides; }

  int get_right_angles() const { return right_angles; }

  int get_parallels_sides() const { return parallels_sides; }

  int get_same_length_sides() const { return same_length_sides; }

  Label get_label() const { return label; }

  void set_label(Label p_label) { this->label = p_label; }

  bool is_filled() { return label != NONE; }

  std::string to_string() {
    switch (this->label) {
      case TRIANGLE:
        return "TRIANGLE";
      case RIGHT_TRIANGLE:
        return "RIGHT TRIANGLE";
      case ISOSCELES_TRIANGLE:
        return "ISOSCELES TRIANGLE";
      case EQUILATERAL_TRIANGLE:
        return "EQUILATERAL TRIANGLE";
      case RIGHT_ISOSCELES_TRIANGLE:
        return "RIGHT ISOSCELES TRIANGLE";
      case TETRAGON:
        return "TETRAGON";
      case SQUARE:
        return "SQUARE";
      case TRAPEZIUM:
        return "TRAPEZIUM";
      case ISOSCELES_TRAPEZIUM:
        return "ISOSCELES TRAPEZIUM";
      case RECTANGLE:
        return "RECTANGLE";
      case PARALLELOGRAM:
        return "PARALLELOGRAM";
      case RHOMBUS:
        return "RHOMBUS";
      case PENTAGON:
        return "PENTAGON";
      case EQUILATERAL_PENTAGON:
        return "EQUILATERAL PENTAGON";
      case SATANISTIC_PENTAGON:
        return "SATANISTIC PENTAGON";
      case HEXAGON:
        return "HEXAGON";
      case REGULAR_HEXAGON:
        return "REGULAR_HEXAGON";
      case HEPTAGON:
        return "HEPTAGON";
      case OCTAGON:
        return "OCTAGON";
      case REGULAR_OCTAGON:
        return "REGULAR_OCTAGON";
      case NONAGON:
        return "NONAGON";
      case DECAGON:
        return "DECAGON";
      case REGULAR_DECAGON:
        return "REGULAR_DECAGON";
      case NONE:
      default:
        return "UNKNOWN POLYGON";
    }
  }
};

#endif  // POLYGONIAL_RECORD_H
