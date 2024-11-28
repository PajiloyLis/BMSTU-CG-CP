#ifndef CP_CG_POINT_H
#define CP_CG_POINT_H

#include<cmath>
#include<fstream>

class point {
public:
    point(float x, float y, float z);

    point() { x = y = z = 0; }

    float distance(const point &a) const;

    friend std::ostream &operator<<(std::ostream &os, point const &m);

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }

    void setX(float _x) {
        this->x = _x;
    }

    void setY(float _y) {
        this->y = _y;
    }

    void setZ(float _z) {
        this->z = _z;
    }

private:
    float x, y, z;
};


#endif //CP_CG_POINT_H
