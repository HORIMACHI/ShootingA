#include "Equipment.h"
#include "DxLib.h"

CEquipment::CEquipment(void)
{
	m_pShotFirst = NULL;
	m_Direction = 0;
	m_ShotCount = 0;
	m_ShotInterval = 0;
	m_ShotSpeed = 0;
	m_LastShootingTime = 0;
}

CEquipment::~CEquipment(void)
{

}

CBullet* CEquipment::CreateShot( int x, int y, int imageID)
{
	if(GetNowCount() - m_LastShootingTime > m_ShotInterval)
	{
		CBullet* shot = new CBullet(x, y, imageID);
		shot->m_Direction = m_Direction;
		shot->m_Speed = m_ShotSpeed;
		m_LastShootingTime = GetNowCount();
		m_Direction = m_Direction + 30;
		return shot;
	}
	return NULL;	
}