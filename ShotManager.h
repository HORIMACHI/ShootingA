#pragma once
#include "Shot.h"

class CShotManager
{
public:
	CShot* m_pShotFirst;
	int m_ShotCount;

public:
	CShotManager(void);
	~CShotManager(void);

	CShot* FindLast(void);
	void Add(CShot* pShot);
	void Remove(int nIndex);
	CShot* GetAt(int nIndex);

	void DrawShot(void);
	void CheckShot(void);
	void MoveShot(void);

};

