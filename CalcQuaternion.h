#pragma once
#include "Vector3.h"
#include "MakeMatrix.h"
struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};
class CalcQuaternion
{
public:
	CalcQuaternion();
	~CalcQuaternion();
	// 乗算
	Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
	// 単位クォータニオン
	Quaternion Identity();
	// 共役クォータニオン
	Quaternion Conjugate(const Quaternion& quaternion);
	// クォータニオンの長さ
	float Norm(const Quaternion& q);
	// クォータニオンの正規化
	Quaternion Normalize(const Quaternion& q);
	// 逆クォータニオン
	Quaternion Inverse(const Quaternion& quaternion);

	// 任意軸回転を表すクォータニオンを生成
	Quaternion MakeRoteteQuaternion(const Vector3& axis, float angle);

	// ベクトルをクォータニオンで回転させた結果のベクトルを返す
	Vector3 RotateVector(const Vector3& v, const Quaternion& q);

	// クォータニオン空間行列を求める
	Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

	// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Quaternion& axis);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Vector3& axis);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Vector3& axis, const Vector3& center);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Quaternion& axis, const Vector3& center);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Vector3& axis, const Vector3& center);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Quaternion& axis, const Vector3& center);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Vector3& axis);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Quaternion& axis);
	//// クォータニオンの回転
	//Quaternion RotateQuaternion(const Quaternion& q, float radian, const Vector3& axis, const Vector3& center);
};

