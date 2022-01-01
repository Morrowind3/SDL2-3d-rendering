//
// Created by Morrowind3 on 18/11/2021.
//

#ifndef LINALG_MATHSVECTOR_H
#define LINALG_MATHSVECTOR_H


#include <string>
#include <utility>

class MathsVector {
public:
    MathsVector(double _x, double _y): x(_x), y(_y), colour("FFFFFF"){};
    MathsVector(double _x, double _y, std::string _colour): x(_x), y(_y), colour(std::move(_colour)){};;
    MathsVector operator+ (const MathsVector& vector) const;
    MathsVector operator- (const MathsVector& vector) const;
    MathsVector operator* (double scalar) const;
    double getX() const;
    double getY() const;
    std::string getColour();
private:
    double x;
    double y;
    std::string colour;
};


#endif //LINALG_MATHSVECTOR_H
