#pragma once
#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <math.h>
#include <corecrt_math.h>
#include <corecrt_math_defines.h>
#include<Novice.h>
#include"Vector3.h"
#include"algorithm"
#include"MathStruct.h"


struct Matrix4x4 {
    float m[4][4];
};

//Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2) {
//    Matrix4x4 result;
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            result.m[i][j] = m1.m[i][j] + m2.m[i][j];
//        }
//    }
//    return result;
//}
//
//Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2) {
//    Matrix4x4 result;
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            result.m[i][j] = m1.m[i][j] - m2.m[i][j];
//        }
//    }
//    return result;
//}
//
//Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2) {
//    Matrix4x4 result = {};
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            for (int k = 0; k < 4; ++k) {
//                result.m[i][j] += m1.m[i][k] * m2.m[k][j];
//            }
//        }
//    }
//    return result;
//}
//
//Matrix4x4& operator+=(Matrix4x4& m1, const Matrix4x4& m2) {
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            m1.m[i][j] += m2.m[i][j];
//        }
//    }
//    return m1;
//}

//加算
Matrix4x4 Add(const Matrix4x4& mt1, const Matrix4x4& mt2);
//減算
Matrix4x4 Subtract(const Matrix4x4& mt1, const Matrix4x4& mt2);
//乗算
Matrix4x4 Multiply(const Matrix4x4& mt1, const Matrix4x4& mt2);
//除算
Matrix4x4 Inverse(const Matrix4x4& mt1);
//転置行列
Matrix4x4 Transpose(const Matrix4x4& mt1);
//単位行列
Matrix4x4 MakeIdentity4x4();
// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
// 回転軸X
Matrix4x4 MakeRotateXMatrix(float radian);
// 回転軸Y
Matrix4x4 MakeRotateYMatrix(float radian);
// 回転軸Z
Matrix4x4 MakeRotateZMatrix(float radian);
//回転の集合
Matrix4x4 MakeRotateMatrixXYZ(Vector3& angle);
//アフィン変換
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
//透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
//ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);
// 任意軸回転行列
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);
// 任意軸の回転行列
Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);
// 同時座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
// クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2);
// 正射影ベクトル
Vector3 Project(const Vector3 v1, const Vector3& v2);
// 最近接点
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);


//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
//正規化
Vector3 Normalize(const Vector3& v);
//内積
float Dot(const Vector3& v1, const Vector3& v2);
//長さ(ノルム)
float Length(const Vector3& v);
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
//
Vector3 Multiply(float scalar, const Vector3& v);


// 行列の表示
void PrintMatrix(const Matrix4x4& matrix, int startX, int startY, const char* label);
// ベクトルの表示
void PrintVector3(const Vector3& v, int startX, int startY, const char* label);

