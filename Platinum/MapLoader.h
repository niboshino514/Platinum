#pragma once
#include <DxLib.h>
#include <vector>
#include <memory>


class PlatinumLoader;

class MapLoader
{
public:

	struct MapData
	{
		// チップ番号の保存
		std::vector<std::vector<int>> m_currentData;

		// 列
		int dataColNum = 0;
		// 行
		int dataRowNum = 0;
		// マップチップサイズ
		int mapChipSize = 0;
	};

public:
	MapLoader();
	virtual ~MapLoader();

	void Init();

	void Draw();

	void Load(const TCHAR* fmfFilePath, int layerType);

private:

	// チップ番号の保存
	std::vector<std::vector<int>> m_currentData;

	// 列番号
	int m_width;
	// 行番号
	int m_height;


	// マップチップサイズ
	int m_mapChipSize;

	// クラスポインタ
	std::shared_ptr<PlatinumLoader>loader;
};