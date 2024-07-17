#include "MapLoader.h"
#include <vector>
#include "Vec2.h"

namespace
{
	// フィールドデータファイル名の配列
	std::vector<const char*> kFieldDataFileName=
	{
		"data/test.fmf",
	};
}


MapLoader::MapLoader():
	m_mapData(),
	m_mapLayer(0),
	m_width(0),
	m_height(0),
	m_mapChipSize(0),
	loader(std::make_shared<PlatinumLoader>())
{
}

MapLoader::~MapLoader()
{
}

void MapLoader::Init()
{
	// ロード
	Load(kFieldDataFileName[0]);

	// 表示するマップレイヤー
	m_mapLayer = 1;
}

void MapLoader::Draw()
{

	Vec2 pos1;
	Vec2 pos2;


	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			// チップ番号の代入
			int chipNum = m_mapData[m_mapLayer].mapData[x][y];

			// 座標の代入
			pos1 = Vec2(x * m_mapChipSize , y * m_mapChipSize);


			pos2 = Vec2(pos1.x + m_mapChipSize, pos1.y + m_mapChipSize);


		
			
			int color = 0x00ff00;

			if (chipNum == 1)
			{
				color = 0xff0000;
			}
			
			Vec2 stringPos = Vec2(pos1.x + m_mapChipSize * 0.5, pos1.y + m_mapChipSize * 0.5);

			DrawFormatString(stringPos.x, stringPos.y, 0xffffff, "%d", chipNum);

			// マップの描画
			DrawBox(pos1.x, pos1.y, pos2.x, pos2.y, color, false);
		}
	}
}


void MapLoader::Load(const TCHAR* fmfFilePath)
{
	// ファイルをロードし、中身をみる
	loader->Load(fmfFilePath);

	// マップのすべてのデータを取得
	m_mapData = loader->GetMapAllData();

	// チップサイズの取得
	PlatinumLoader::MapInfo mapInfo = loader->GetMapInfo();

	m_mapChipSize = mapInfo.chipSize;
	m_height = mapInfo.mapHeight;
	m_width = mapInfo.mapWidth;

}
