//
// Created by tristan on 07/04/19.
//

#include "UnfilledRecordException.h"


const char *UnfilledRecordException::what() const noexcept {
    char *message = nullptr;
    sprintf(message, "The following record has no label : Record(%d, %d, %d, %d)", record.get_sides(),
            record.get_right_angles(), record.get_parallels_sides(), record.get_same_length_sides());
    return message;
}
