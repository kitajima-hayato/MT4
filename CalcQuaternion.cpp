#include "CalcQuaternion.h"
#include <cmath> 
using namespace std;
CalcQuaternion::CalcQuaternion()
{
}

CalcQuaternion::~CalcQuaternion()
{
}

Quaternion CalcQuaternion::Multiply(const Quaternion& lhs, const Quaternion& rhs)
{
	// クォータニオンの乗算
	Quaternion result;
	result.x = lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y + lhs.w * rhs.x;
	result.y = -lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x + lhs.w * rhs.y;
	result.z = lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w + lhs.w * rhs.z;
	result.w = -lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z + lhs.w * rhs.w;
	return result;
	
}

Quaternion CalcQuaternion::Identity()
{
	// 単位クォータニオン
	Quaternion q;
	q.x = 0.0f;
	q.y = 0.0f;
	q.z = 0.0f;
	q.w = 1.0f;
	return q;
}

Quaternion CalcQuaternion::Conjugate(const Quaternion& quaternion)
{
	// 共役クォータニオン
	Quaternion q;
	q.x = -quaternion.x;
	q.y = -quaternion.y;
	q.z = -quaternion.z;
	q.w = quaternion.w;
	return q;
}

float CalcQuaternion::Norm(const Quaternion& q)
{
	// クォータニオンの長さ（ノルム）を計算
	return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

Quaternion CalcQuaternion::Normalize(const Quaternion& q)
{
	// クォータニオンの正規化
	float norm = Norm(q);
	Quaternion result;
	result.x = q.x / norm;
	result.y = q.y / norm;
	result.z = q.z / norm;
	result.w = q.w / norm;
	return result;
}

Quaternion CalcQuaternion::Inverse(const Quaternion& quaternion)
{
	// 逆クォータニオン
	Quaternion q = Conjugate(quaternion);
	float norm = Norm(quaternion);
	Quaternion result;
	result.x = q.x / (norm * norm);
	result.y = q.y / (norm * norm);
	result.z = q.z / (norm * norm);
	result.w = q.w / (norm * norm);
	return result;
}

Quaternion CalcQuaternion::MakeRoteteQuaternion(const Vector3& axis, float angle)
{
	// 任意軸回転を表すクォータニオンを生成
	Quaternion q;
	float halfAngle = angle * 0.5f;
	float sinHalfAngle = sin(halfAngle);
	q.x = axis.x * sinHalfAngle;
	q.y = axis.y * sinHalfAngle;
	q.z = axis.z * sinHalfAngle;
	q.w = cos(halfAngle);
	return q;
}

Vector3 CalcQuaternion::RotateVector(const Vector3& v, const Quaternion& q)
{
	// ベクトルをクォータニオンで回転させた結果のベクトルを返す
	Quaternion p;
	p.x = v.x;
	p.y = v.y;
	p.z = v.z;
	p.w = 0.0f;
	Quaternion qConjugate = Conjugate(q);
	Quaternion p2 = Multiply(Multiply(q, p), qConjugate);
	Vector3 result;
	result.x = p2.x;
	result.y = p2.y;
	result.z = p2.z;
	return result;
}

Matrix4x4 CalcQuaternion::MakeRotateMatrix(const Quaternion& quaternion)
{
	// クォータニオン空間行列を求める
	Matrix4x4 result;
	result.m[0][0] = 1.0f - 2.0f * quaternion.y * quaternion.y - 2.0f * quaternion.z * quaternion.z;
	result.m[0][1] = 2.0f * quaternion.x * quaternion.y - 2.0f * quaternion.z * quaternion.w;
	result.m[0][2] = 2.0f * quaternion.x * quaternion.z + 2.0f * quaternion.y * quaternion.w;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w;
	result.m[1][1] = 1.0f - 2.0f * quaternion.x * quaternion.x - 2.0f * quaternion.z * quaternion.z;
	result.m[1][2] = 2.0f * quaternion.y * quaternion.z - 2.0f * quaternion.x * quaternion.w;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 2.0f * quaternion.x * quaternion.z - 2.0f * quaternion.y * quaternion.w;
	result.m[2][1] = 2.0f * quaternion.y * quaternion.z + 2.0f * quaternion.x * quaternion.w;
	result.m[2][2] = 1.0f - 2.0f * quaternion.x * quaternion.x - 2.0f * quaternion.y * quaternion.y;
	result.m[2][3] = 0.0f;
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;
	return result;
}

