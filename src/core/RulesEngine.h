//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_RULESENGINE_H
#define POLYGONIAL_RULESENGINE_H

#include "Record.hpp"

class RulesEngine {
 public:
  /*
   * Go trough the rules to fill the record's label.
   */
  void fill(Record &record);

 private:
  void fill_three(Record &record);
  void fill_four(Record &record);
  void fill_five(Record &record);
  // void fill_geater_than_five(Record &record);
};

#endif  // POLYGONIAL_RULESENGINE_H
