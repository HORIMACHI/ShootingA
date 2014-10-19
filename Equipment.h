#pragma once
#include "Bullet.h"

class CEquipment
{
public:
	CBullet* m_pShotFirst;
	double m_Direction;
	double m_ShotSpeed;
	int m_ShotCount;
	int m_ShotInterval;
protected:
	int m_LastShootingTime;

public:
	CEquipment(void);
	~CEquipment(void);

	CBullet* CreateShot(int x, int y, int imageID);
};

