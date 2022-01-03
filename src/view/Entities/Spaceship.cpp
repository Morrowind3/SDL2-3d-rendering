#include "Spaceship.h"

#include <utility>

Spaceship::Spaceship(const MathsVector& pos, std::string _colour): Entity(std::move(_colour)) {
    Matrix matrix { {
                       {30, 50, 50, 30, 30, 50, 50, 30},
                       {50, 50, 30, 30, 50, 50, 30, 30},
                       {10, 10, 10, 10, 40, 40, 40, 40},
                       {1,   1,  1,  1,  1,  1,  1, 1}}};

    for(auto& coord : matrix.getRow(0)){
        coord = coord + pos.x;
    }
    for(auto& coord : matrix.getRow(1)){
        coord = coord + pos.y;
    }
    for(auto& coord : matrix.getRow(2)){
        coord = coord + pos.z;
    }

    mesh.setMatrix(std::move(matrix));
}

