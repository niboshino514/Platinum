#include <DxLib.h>
#include "SceneMain.h"
#include "Vec2.h"
#include "game.h"
#include "Pad.h"
#include "MapLoader.h"

namespace
{
	// テキストの位置
	const Vec2 kTextPos = { 0.0f, 0.0f};

	// テキスト
	const char* const kText = "Platinumを使うためのプログラム";

	// テキスト色
	constexpr int kTextColor = 0xffffff;

	// 背景色
	constexpr int kBackGroundColor = 0x000000;

	// 背景のα値(255が最大で0に近づく程、透明になる)
	constexpr int kBackGroundAlpha = 255;
}



SceneMain::SceneMain():
	m_pMapLoader(std::make_shared<MapLoader>())
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
	m_pMapLoader->Init();
}

SceneBase* SceneMain::update()
{


	return this;
}

void SceneMain::draw()
{
	// 透明にして表示する
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, kBackGroundAlpha);
	// 背景
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackGroundColor, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// テキスト描画
	DrawString(kTextPos.x, kTextPos.y, kText, kTextColor);

	////////////////////////
	// ここから処理を書く //
	////////////////////////


	m_pMapLoader->Draw();




}