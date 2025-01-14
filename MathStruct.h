#pragma once
#include"Vector3.h"

//平面
struct Plane {
	Vector3 normal;//法線
	float distance;//距離(原点方向に離れている距離)
};
struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};
struct Line {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};
struct Ray {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};
struct Segment {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};
struct Sphere {
	Vector3 center;	//!<中心点
	float radius;	//!<半径 
};