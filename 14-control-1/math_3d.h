#ifndef MATH_3D_H
#define MATH_3D_H

#ifdef _WIN64
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <corecrt_math_defines.h>
#else
#include <math.h>
#endif
#include <stdio.h>

#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / M_PI))

struct Vector3f
{
    union {
        float x;
        float r;
    };

    union {
        float y;
        float g;
    };

    union {
        float z;
        float b;
    };

    Vector3f() {}

    Vector3f(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3f(const float* pFloat)
    {
        x = pFloat[0];
        y = pFloat[1];
        z = pFloat[2];
    }

    Vector3f(float f)
    {
        x = y = z = f;
    }

    Vector3f& operator+=(const Vector3f& r)
    {
        x += r.x;
        y += r.y;
        z += r.z;

        return *this;
    }

    Vector3f& operator-=(const Vector3f& r)
    {
        x -= r.x;
        y -= r.y;
        z -= r.z;

        return *this;
    }

    Vector3f& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;

        return *this;
    }

    bool operator==(const Vector3f& r)
    {
        return ((x == r.x) && (y == r.y) && (z == r.z));
    }

    bool operator!=(const Vector3f& r)
    {
        return !(*this == r);
    }

    operator const float*() const
    {
        return &(x);
    }

    Vector3f Cross(const Vector3f& v) const;

    Vector3f& Normalize();

    void print() const
    {
        printf("(%.02f, %.02f, %.02f)", x, y, z);
    }
};

inline Vector3f operator*(const Vector3f& l, float f)
{
    Vector3f Ret(l.x * f,
        l.y * f,
        l.z * f);

    return Ret;
}


struct PersProjInfo
{
    float FOV;
    float Width;
    float Height;
    float zNear;
    float zFar;
};


class Matrix4f
{
public:
    float m[4][4];

    Matrix4f()  {}

    Matrix4f(float a00, float a01, float a02, float a03,
             float a10, float a11, float a12, float a13,
             float a20, float a21, float a22, float a23,
             float a30, float a31, float a32, float a33)
    {
        m[0][0] = a00; m[0][1] = a01; m[0][2] = a02; m[0][3] = a03;
        m[1][0] = a10; m[1][1] = a11; m[1][2] = a12; m[1][3] = a13;
        m[2][0] = a20; m[2][1] = a21; m[2][2] = a22; m[2][3] = a23;
        m[3][0] = a30; m[3][1] = a31; m[3][2] = a32; m[3][3] = a33;
    }

    inline Matrix4f operator*(const Matrix4f& Right) const
    {
        Matrix4f Ret;

        for (unsigned int i = 0; i < 4; i++) {
            for (unsigned int j = 0; j < 4; j++) {
                Ret.m[i][j] = m[i][0] * Right.m[0][j] +
                    m[i][1] * Right.m[1][j] +
                    m[i][2] * Right.m[2][j] +
                    m[i][3] * Right.m[3][j];
            }
        }

        return Ret;
    }

    void InitScaleTransform(float ScaleX, float ScaleY, float ScaleZ);

    void InitRotateTransform(float RotateX, float RotateY, float RotateZ);

    void InitTranslationTransform(float x, float y, float z);

    void InitCameraTransform(const Vector3f& Target, const Vector3f& Up);

    void InitCameraTransform(const Vector3f& Pos, const Vector3f& Target, const Vector3f& Up);

    void InitPersProjTransform(const PersProjInfo& p);

    void print() const {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%6.3f, ", m[i][j]);
            }
            printf("\n");
        }
    }

private: 
    void InitRotationX(float RotateX);
    void InitRotationY(float RotateY);
    void InitRotationZ(float RotateZ);
};



#endif /* MATH_3D_H  */

