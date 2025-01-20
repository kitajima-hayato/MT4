#include <Novice.h>
#include "MakeMatrix.h"
#include "MathStruct.h"
#include "CalcQuaternion.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	CalcQuaternion calcQuaternion;

	Quaternion rotation = calcQuaternion.MakeRoteteAxisAngleQuaternion(Normalize(Vector3{1.0f,0.4f,-0.2f}),0.45f);
	Vector3 pointY = { 2.1f,-0.9f,1.3f };
	Matrix4x4 rotateMatrix = calcQuaternion.MakeRotateMatrix(rotation);
	Vector3 rotateByQuaternion = calcQuaternion.RotateVector(pointY, rotation);
	Vector3 rotateByMatrix = Transform(pointY, rotateMatrix);
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
