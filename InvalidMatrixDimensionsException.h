//
// Created by Morrowind3 on 28/11/2021.
//

#ifndef LINALG_INVALIDMATRIXDIMENSIONSEXCEPTION_H
#define LINALG_INVALIDMATRIXDIMENSIONSEXCEPTION_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>


class InvalidMatrixDimensionsException : public std::runtime_error {
    std::string msg;
public:
    InvalidMatrixDimensionsException(const std::string &arg, const char *file, int line) :
            std::runtime_error("The columns of a matrix must equal the rows of the multiplier") {
        std::ostringstream o;
        o << file << ":" << line << ": " << arg;
        msg = o.str();
    }
    ~InvalidMatrixDimensionsException() noexcept {}
    const char *what() const throw() {
        return msg.c_str();
    }
};


#endif //LINALG_INVALIDMATRIXDIMENSIONSEXCEPTION_H
