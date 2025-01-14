#include <Novice.h>
#include "MakeMatrix.h"
#include "MathStruct.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 axis = Normalize({ 1.0f,1.0f,1.0f });
	float angle = 0.44f;



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
		Matrix4x4 rotate = MakeRotateAxisAngle(axis, angle);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 計算結果を描画
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				Novice::ScreenPrintf(100 * i, 20 * j, "%.3f", rotate.m[i][j]);
			}
		}


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
