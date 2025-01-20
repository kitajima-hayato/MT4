#pragma once
#include "Vector3.h"
#include "MakeMatrix.h"
struct Quaternion {
	float x;
	float y;
	float z;
	float w;

	// 演算子オーバーロードの追加
	Quaternion operator*(float scalar) const {
		return { x * scalar, y * scalar, z * scalar, w * scalar };
	}

	Quaternion operator+(const Quaternion& other) const {
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}

	Quaternion operator/(float scalar) const {
		return { x / scalar, y / scalar, z / scalar, w / scalar };
	}

	// 正規化メソッドの追加
	Quaternion Normalized() const {
		float norm = sqrt(x * x + y * y + z * z + w * w);
		return { x / norm, y / norm, z / norm, w / norm };
	}

	// 単項マイナス演算子のオーバーロードの追加
	Quaternion operator-() const {
		return { -x, -y, -z, -w };
	}
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
	Quaternion MakeRoteteAxisAngleQuaternion(const Vector3& axis, float angle);

	// ベクトルをクォータニオンで回転させた結果のベクトルを返す
	Vector3 RotateVector(const Vector3& v, const Quaternion& q);

	// クォータニオン空間行列を求める
	Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

	// 球面線形補間 // Spherical Linear Interpolation
	Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t);

	// クォータニオンの表示
	void PrintQuaternion(const Quaternion& q, int x, int y, const char* label);

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

