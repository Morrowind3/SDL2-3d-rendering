//
// Created by Morrowind3 on 18/11/2021.
//

#ifndef LINALG_MATHSVECTOR_H
#define LINALG_MATHSVECTOR_H


#include <string>
#include <utility>

struct MathsVector {
    MathsVector(double _x, double _y, double _z): x(_x), y(_y), z(_z){};
    MathsVector operator+ (const MathsVector& vector) const;
    MathsVector operator- (const MathsVector& vector) const;
    MathsVector operator* (double scalar) const;
    MathsVector calculateCrossProduct(MathsVector &other) const;
    double calculateDotProduct(MathsVector &other) const ;
    MathsVector getUnitVector() const ;
    double x;
    double y;
    double z;
private:
    double getLength() const;
};


#endif //LINALG_MATHSVECTOR_H
