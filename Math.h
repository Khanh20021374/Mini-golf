#ifndef _MATH_H
#define _MATH_H

#include <iostream>
#include <SDL.h>

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

    Vector2f& operator =(const Vector2f& rhs) {
        x = rhs.x;
        y = rhs.y;

        return *this;
    }

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

inline Vector2f RotateVector(Vector2f& vec, float angle) {
    //converting the angle to radians to be used in sin and cos functions
    float radAngle = (float)(angle*DEG_TO_RAD);

    return Vector2f((float)(vec.x * SDL_cosf(radAngle) - vec.y * SDL_sinf(radAngle)), (float)(vec.x * SDL_sinf(radAngle) + vec.y * SDL_cosf(radAngle)));
}

#endif
