#ifndef _MATH_H
#define _MATH_H

#include <iostream>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

struct Vector2f {
    float x, y;

    Vector2f()
    :x(0.0f), y(0.0f)
    {}

    Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

    Vector2f& operator +=(const Vector2f& rhs) {
        x += rhs.x;
        y += rhs.y;

        return *this;
    }

    Vector2f& operator -=(const Vector2f& rhs) {
        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }
    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};

inline Vector2f operator +(const Vector2f& lhs, const Vector2f& rhs) {
    return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2f operator -(const Vector2f& lhs, const Vector2f& rhs) {
    return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2f operator *(const Vector2f& lhs, const float& rhs) {
    return Vector2f(lhs.x * rhs, lhs.y * rhs);
}

#endif // _MATH_H
