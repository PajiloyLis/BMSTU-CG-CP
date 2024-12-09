#ifndef CP_CG_MY_VEC3F_H
#define CP_CG_MY_VEC3F_H

#include<cmath>
#include<fstream>
#include <iostream>
#include <compare>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "conversions.h"

using namespace std;
using namespace glm;

class my_vec3f {
public:
    my_vec3f(const my_vec3f &p);

    my_vec3f(my_vec3f &p);

    my_vec3f(my_vec3f &&p) noexcept;

    my_vec3f(float x, float y, float z);

    my_vec3f() { p.x = p.y = p.z = 0; }

    float distance(const my_vec3f &a) const;

    friend std::ostream &operator<<(std::ostream &os, my_vec3f const &m);

    [[nodiscard]] float getX() const {
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

    bool operator==(const my_vec3f &p) const {
        return this->p.x == p.p.x && this->p.y == p.p.y && this->p.z == p.p.z;
    }

    bool operator!=(const my_vec3f &p) const {
        return this->p.x != p.p.x || this->p.y != p.p.y || this->p.z != p.p.z;
    }
//
//    bool operator<(const my_vec3f &p) const {
//        return this->p.x < p.p.x || (this->p.x == p.p.x && this->p.y < p.p.y) ||
//               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z < p.p.z);
//    }
//
//    bool operator<=(const my_vec3f &p) const {
//        return this->p.x <= p.p.x || (this->p.x == p.p.x && this->p.y <= p.p.y) ||
//               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z <= p.p.z);
//    }
//
//    bool operator>(const my_vec3f &p) const {
//        return this->p.x > p.p.x || (this->p.x == p.p.x && this->p.y > p.p.y) ||
//               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z > p.p.z);
//    }
//
//    bool operator>=(const my_vec3f &p) const {
//        return this->p.x >= p.p.x || (this->p.x == p.p.x && this->p.y >= p.p.y) ||
//               (this->p.x == p.p.x && this->p.y == p.p.y && this->p.z >= p.p.z);
//    }

    my_vec3f &operator=(const my_vec3f &p);

    my_vec3f &rotate(const rotate_t &rotate_v);

    [[nodiscard]] float dot(const my_vec3f &a) const;

    my_vec3f cross(const my_vec3f &a) const;

    my_vec3f normalize();

    friend my_vec3f normalize(const my_vec3f &p) {
        const_cast<my_vec3f &>(p).p = glm::normalize(p.p);
        return p;
    }

    friend my_vec3f normalize(my_vec3f &&p) {
        return glm::normalize(p.p);
    }

    my_vec3f operator-(const my_vec3f &a) const;

    my_vec3f operator+(const my_vec3f &a) const;

    my_vec3f operator*(const float &) const;

    my_vec3f operator*=(const float &) const;
    
    my_vec3f operator-() const;    

    my_vec3f(const glm::vec3 &p);

    glm::vec3 p;

    void rotate_point_x(const rotate_t &rotate);

    void rotate_point_y(const rotate_t &rotate);

    void rotate_point_z(const rotate_t &rotate);

    void move_point(const move_t &move);
};


#endif //CP_CG_MY_VEC3F_H
