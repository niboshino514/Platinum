#pragma once
#include <DxLib.h>
#include <vector>
#include <memory>
#include "PlatinumLoader.h"

class PlatinumLoader;

class MapLoader
{


public:
	MapLoader();
	virtual ~MapLoader();

	void Init();

	void Draw();

	void Load(const TCHAR* fmfFilePath);

private:

	// マップデータ
	std::vector<PlatinumLoader::MapData> m_mapData;
	
	// マップレイヤー
	int m_mapLayer;

	// 列番号
	int m_width;
	// 行番号
	int m_height;
	// マップチップサイズ
	int m_mapChipSize;

	// クラスポインタ
	std::shared_ptr<PlatinumLoader>loader;
};