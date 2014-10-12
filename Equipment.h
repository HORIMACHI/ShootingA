#pragma once
#include "Shot.h"

class CEquipment
{
public:
	CShot* m_pShotFirst;
	int m_ShotCount;
	int m_ShotInterval;

public:
	CEquipment(void);
	~CEquipment(void);

	CShot* CreateShot(int imageID, int x, int y);
};

