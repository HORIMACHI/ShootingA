#pragma once
#include "Shot.h"

class CEquipment
{
public:
	CShot* m_pShotFirst;
	int ShotCount;

public:
	CEquipment(void);
	~CEquipment(void);

	CShot* CreateShot(int imageID, int x, int y);
};

