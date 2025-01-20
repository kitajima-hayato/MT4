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

	Quaternion rotation1 = calcQuaternion.MakeRoteteAxisAngleQuaternion({ 0.71f,0.71f,0.0f }, 0.3f);
	Quaternion rotation2 = { -rotation1 };


	Quaternion interpolation0 = calcQuaternion.Slerp(rotation1, rotation2, 0.0f);
	Quaternion interpolation1 = calcQuaternion.Slerp(rotation1, rotation2, 0.3f);
	Quaternion interpolation2 = calcQuaternion.Slerp(rotation1, rotation2, 0.5f);
	Quaternion interpolation3 = calcQuaternion.Slerp(rotation1, rotation2, 0.7f);
	Quaternion interpolation4 = calcQuaternion.Slerp(rotation1, rotation2, 1.0f);

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


		calcQuaternion.PrintQuaternion(interpolation0, 10, 10, "interpolation0");
		calcQuaternion.PrintQuaternion(interpolation1, 10, 30, "interpolation1");
		calcQuaternion.PrintQuaternion(interpolation2, 10, 50, "interpolation2");
		calcQuaternion.PrintQuaternion(interpolation3, 10, 70, "interpolation3");
		calcQuaternion.PrintQuaternion(interpolation4, 10, 90, "interpolation4");


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
