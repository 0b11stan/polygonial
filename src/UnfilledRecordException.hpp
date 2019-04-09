//
// Created by tristan on 07/04/19.
//

#ifndef POLYGONIAL_UNFILLEDRECORDEXCEPTION_HPP
#define POLYGONIAL_UNFILLEDRECORDEXCEPTION_HPP

#include <exception>
#include "Record.h"
#include <string>

class UnfilledRecordException : virtual public std::exception {

    const char *what() const noexcept override {
        return "Un unfilled record was provided where a filled one was expected.";
    }

};

#endif //POLYGONIAL_UNFILLEDRECORDEXCEPTION_HPP
