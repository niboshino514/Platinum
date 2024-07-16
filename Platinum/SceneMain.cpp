#include <DxLib.h>
#include "SceneMain.h"
#include "Vec2.h"
#include "game.h"
#include "Pad.h"
#include "MapLoader.h"

namespace
{
	// �e�L�X�g�̈ʒu
	const Vec2 kTextPos = { 0.0f, 0.0f};

	// �e�L�X�g
	const char* const kText = "Platinum���g�����߂̃v���O����";

	// �e�L�X�g�F
	constexpr int kTextColor = 0xffffff;

	// �w�i�F
	constexpr int kBackGroundColor = 0x000000;

	// �w�i�̃��l(255���ő��0�ɋ߂Â����A�����ɂȂ�)
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
	// �����ɂ��ĕ\������
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, kBackGroundAlpha);
	// �w�i
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackGroundColor, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �e�L�X�g�`��
	DrawString(kTextPos.x, kTextPos.y, kText, kTextColor);

	////////////////////////
	// �������珈�������� //
	////////////////////////


	m_pMapLoader->Draw();




}