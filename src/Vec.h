#ifndef SPACEINVADERS_VEC_H
#define SPACEINVADERS_VEC_H

#include <cstdio>

struct Vec2 {
    double x;
    double y;
};

struct Vec3 {
    float x{};
    float y{};
    float z{};

    Vec3() = default;

    Vec3(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vec3 &operator+=(const Vec3 &r) {
        x += r.x;
        y += r.y;
        z += r.z;

        return *this;
    }

    Vec3 &operator-=(const Vec3 &r) {
        x -= r.x;
        y -= r.y;
        z -= r.z;

        return *this;
    }

    Vec3 &operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;

        return *this;
    }

    Vec3 Cross(const Vec3 &v) const;

    Vec3 &Normalize();

    void Rotate(float Angle, const Vec3 &Axis);

    void Print() const {
        printf("(%.02f, %.02f, %.02f", x, y, z);
    }
};


inline Vec3 operator+(const Vec3 &l, const Vec3 &r) {
    Vec3 Ret(l.x + r.x,
             l.y + r.y,
             l.z + r.z);

    return Ret;
}

inline Vec3 operator-(const Vec3 &l, const Vec3 &r) {
    Vec3 Ret(l.x - r.x,
             l.y - r.y,
             l.z - r.z);

    return Ret;
}

inline Vec3 operator*(const Vec3 &l, float f) {
    Vec3 Ret(l.x * f,
             l.y * f,
             l.z * f);

    return Ret;
}

#endif //SPACEINVADERS_VEC_H
