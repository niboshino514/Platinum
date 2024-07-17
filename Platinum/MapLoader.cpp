#include "MapLoader.h"
#include <vector>
#include "Vec2.h"

namespace
{
	// �t�B�[���h�f�[�^�t�@�C�����̔z��
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
	// ���[�h
	Load(kFieldDataFileName[0]);

	// �\������}�b�v���C���[
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
			// �`�b�v�ԍ��̑��
			int chipNum = m_mapData[m_mapLayer].mapData[x][y];

			// ���W�̑��
			pos1 = Vec2(x * m_mapChipSize , y * m_mapChipSize);


			pos2 = Vec2(pos1.x + m_mapChipSize, pos1.y + m_mapChipSize);


		
			
			int color = 0x00ff00;

			if (chipNum == 1)
			{
				color = 0xff0000;
			}
			
			Vec2 stringPos = Vec2(pos1.x + m_mapChipSize * 0.5, pos1.y + m_mapChipSize * 0.5);

			DrawFormatString(stringPos.x, stringPos.y, 0xffffff, "%d", chipNum);

			// �}�b�v�̕`��
			DrawBox(pos1.x, pos1.y, pos2.x, pos2.y, color, false);
		}
	}
}


void MapLoader::Load(const TCHAR* fmfFilePath)
{
	// �t�@�C�������[�h���A���g���݂�
	loader->Load(fmfFilePath);

	// �}�b�v�̂��ׂẴf�[�^���擾
	m_mapData = loader->GetMapAllData();

	// �`�b�v�T�C�Y�̎擾
	PlatinumLoader::MapInfo mapInfo = loader->GetMapInfo();

	m_mapChipSize = mapInfo.chipSize;
	m_height = mapInfo.mapHeight;
	m_width = mapInfo.mapWidth;

}
