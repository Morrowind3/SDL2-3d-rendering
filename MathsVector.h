//
// Created by Morrowind3 on 18/11/2021.
//

#ifndef LINALG_MATHSVECTOR_H
#define LINALG_MATHSVECTOR_H


#include <string>
#include <utility>

class MathsVector {
public:
    MathsVector(float _x, float _y): x(_x), y(_y), colour("FFFFFF"){};
    MathsVector(float _x, float _y, std::string _colour): x(_x), y(_y), colour(std::move(_colour)){};;
    MathsVector operator+ (const MathsVector& vector);
    MathsVector operator- (const MathsVector& vector);
    MathsVector operator* (float scalar);
    float getX();
    float getY();
    std::string getColour();
private:
    float x;
    float y;
    std::string colour;
};


#endif //LINALG_MATHSVECTOR_H
