#include "Equipment.h"
#include "DxLib.h"

CEquipment::CEquipment(void)
{
	m_pShotFirst = NULL;
	int ShotCount = 0;
}

CEquipment::~CEquipment(void)
{

}

CShot* CEquipment::CreateShot(int imageID, int x, int y)
{
	CShot* shot = new CShot(imageID, x, y);
	return shot;
}