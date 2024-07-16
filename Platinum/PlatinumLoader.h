#pragma once
#include <DxLib.h>
#include <vector>


//�}�b�v�̍L�� * ���C���[���Ȃ̂ŁA2�̃x�N�^�[�����q�ɂ��Ă�
using MapData_t = std::vector < std::vector<unsigned char>>;


/// <summary>
/// Platinum�̃f�[�^�����[�h����
/// </summary>
class PlatinumLoader
{
public:
	// �}�b�v���
	struct MapInfo
	{
		// �}�b�v�̉���
		int mapWidth = 0;
		// �}�b�v�̏c��
		int mapHeight = 0;
		// �`�b�v�T�C�Y
		int chipSize = 0;
	};


public:
	PlatinumLoader();
	virtual ~PlatinumLoader();

public:

	/// <summary>
	/// fmf�t�@�C����ǂݍ����mapData_�ɒ��g������
	/// </summary>
	/// <param name="filePath">fmf�t�@�C���̃t�@�C���p�X</param>
	void Load(const TCHAR* filePath);
	

	/// <summary>
	/// �}�b�v�f�[�^���擾����
	/// </summary>
	/// <param name="layerNum">���C���[�ԍ�</param>
	/// <returns>�}�b�v�f�[�^��Ԃ�</returns>
	std::vector<std::vector<int>> GetMapData(const int& layerNum);


	/// <summary>
	/// �}�b�v����Ԃ�
	/// </summary>
	/// <returns>�}�b�v���(�}�b�v�̉���,�@�}�b�v�̏c��,�@�}�b�v�`�b�v�̃T�C�Y)</returns>
	MapInfo GetMapInfo() { return m_mapInfo; }



private:

	/// <summary>
	/// �t�@�C�������݂��邩�ǂ������m�F(�A�T�[�g)
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void FileExistsConfirmation(const TCHAR* filePath);


	/// <summary>
	/// ���̃��C���[�����݂���̂��m�F
	/// </summary>
	/// <param name="layerNum">���C���[</param>
	void LayerCheck(const int& layerNum);


private:

	// �v���`�i���f�[�^
	MapData_t m_platinumData;

	// �}�b�v���
	MapInfo m_mapInfo;

	// ���C���[��
	int m_layerMaxNum = 0;
};

