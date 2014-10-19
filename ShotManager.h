#pragma once
#include "Bullet.h"

class CShotManager
{
public:
	CBullet* m_pShotFirst;
	int m_ShotCount;

public:
	CShotManager(void);
	~CShotManager(void);

	CBullet* FindLast(void);
	void Add(CBullet* pShot);
	void Remove(int nIndex);
	CBullet* GetAt(int nIndex);

	void DrawShot(void);
	void CheckShot(void);
	void MoveShot(void);

};



