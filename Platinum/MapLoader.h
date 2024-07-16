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
		// �`�b�v�ԍ��̕ۑ�
		std::vector<std::vector<int>> m_currentData;

		// ��
		int dataColNum = 0;
		// �s
		int dataRowNum = 0;
		// �}�b�v�`�b�v�T�C�Y
		int mapChipSize = 0;
	};

public:
	MapLoader();
	virtual ~MapLoader();

	void Init();

	void Draw();

	void Load(const TCHAR* fmfFilePath, int layerType);

private:

	// �`�b�v�ԍ��̕ۑ�
	std::vector<std::vector<int>> m_currentData;

	// ��ԍ�
	int m_width;
	// �s�ԍ�
	int m_height;


	// �}�b�v�`�b�v�T�C�Y
	int m_mapChipSize;

	// �N���X�|�C���^
	std::shared_ptr<PlatinumLoader>loader;
};