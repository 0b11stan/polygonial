//
// Created by tristan on 07/04/19.
//

#ifndef POLYGONIAL_UNFILLEDRECORDEXCEPTION_H
#define POLYGONIAL_UNFILLEDRECORDEXCEPTION_H

#include <exception>
#include "Record.h"
#include <string>

class UnfilledRecordException : public std::exception {

private:
    Record &record;

public:
    explicit UnfilledRecordException(Record &record) : record(record) {}
    const char *what() const noexcept override;

};


#endif //POLYGONIAL_UNFILLEDRECORDEXCEPTION_H
