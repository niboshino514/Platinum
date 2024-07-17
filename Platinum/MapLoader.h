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

	// �}�b�v�f�[�^
	std::vector<PlatinumLoader::MapData> m_mapData;
	
	// �}�b�v���C���[
	int m_mapLayer;

	// ��ԍ�
	int m_width;
	// �s�ԍ�
	int m_height;
	// �}�b�v�`�b�v�T�C�Y
	int m_mapChipSize;

	// �N���X�|�C���^
	std::shared_ptr<PlatinumLoader>loader;
};