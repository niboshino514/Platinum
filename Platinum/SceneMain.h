#pragma once
#include "SceneBase.h"
#include <memory>


class MapLoader;
class SceneMain : public SceneBase
{
public:
	SceneMain();

	virtual ~SceneMain();


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:

	// マップローダークラス
	std::shared_ptr<MapLoader>m_pMapLoader;




};