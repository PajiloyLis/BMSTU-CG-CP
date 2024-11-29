#ifndef CP_CG_POINT_H
#define CP_CG_POINT_H

#include<cmath>
#include<fstream>
#include <compare>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "conversions.h"

class point {
public:
    point(const point &p);

    point(point &p);

    point(point &&p) noexcept;

    point(float x, float y, float z);

    point() { p.x = p.y = p.z = 0; }

    float distance(const point &a) const;

    friend std::ostream &operator<<(std::ostream &os, point const &m);

    float getX() const {
        return p.x;
    }

    float getY() const {
        return p.y;
    }

    float getZ() const {
        return p.z;
    }

    void setX(float _x) {
        this->p.x = _x;
    }

    void setY(float _y) {
        this->p.y = _y;
    }

    void setZ(float _z) {
        this->p.z = _z;
    }

    bool operator==(const point &p) const {
        return this->p.x == p.p.x && this->p.y == p.p.y && this->p.z == p.p.z;
    }

    bool operator!=(const point &p) const {
        return this->p.x != p.p.x || this->p.y != p.p.y || this->p.z != p.p.z;
    }

    bool operator<(const point &p) const {
        return this->p.x < p.p.x || (this->p.x == p.p.x && this->p.y < p.p.y) ||
               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z < p.p.z);
    }

    bool operator<=(const point &p) const {
        return this->p.x <= p.p.x || (this->p.x == p.p.x && this->p.y <= p.p.y) ||
               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z <= p.p.z);
    }

    bool operator>(const point &p) const {
        return this->p.x > p.p.x || (this->p.x == p.p.x && this->p.y > p.p.y) ||
               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z > p.p.z);
    }

    bool operator>=(const point &p) const {
        return this->p.x >= p.p.x || (this->p.x == p.p.x && this->p.y >= p.p.y) ||
               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z >= p.p.z);
    }

    point &operator=(const point &p);

    point rotate(const rotate_t &rotate);

    float dot(const point &a);

    point cross(const point &a);

    point normalize();

    friend point normalize(const point &p) {
        const_cast<point &>(p).p = glm::normalize(p.p);
        return p;
    }

    friend point normalize(point &&p) {
        return glm::normalize(p.p);
    }

    point operator-(const point &a) const;

    point operator+(const point &a) const;

private:
    point(const glm::vec3 &p);

    glm::vec3 p;

    void rotate_point_x(const rotate_t &rotate);

    void rotate_point_y(const rotate_t &rotate);

    void rotate_point_z(const rotate_t &rotate);
};


#endif //CP_CG_POINT_H
