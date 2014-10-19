#include "ShotManager.h"
#include "Windows.h"


CShotManager::CShotManager(void)
{
	m_pShotFirst = NULL;
	m_ShotCount = 0;
}


CShotManager::~CShotManager(void)
{
}

CBullet* CShotManager::FindLast(void)
{
	if(m_pShotFirst == NULL)
	{
		return NULL;
	}
	CBullet* pShotBuffer = m_pShotFirst;
	while(pShotBuffer->m_pNextShot != NULL)
	{
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return pShotBuffer;
}

void CShotManager::Add(CBullet* pShot)
{
	CBullet* pShotLast = FindLast();
	if(pShotLast == NULL)
	{
		m_pShotFirst = pShot;
		return;
	}
	pShotLast->m_pNextShot = pShot;
	return;
}

void CShotManager::Remove(int nIndex)
{
	if(nIndex < 0)
	{
		return;
	}

	if(m_pShotFirst == NULL)
	{
		return;
	}

	CBullet* pShotFront = GetAt(nIndex - 1);
	CBullet* pShotRemove = GetAt(nIndex);
	CBullet* pShotBack = GetAt(nIndex + 1);

	if(pShotRemove == NULL)
	{
		return;
	}

	else if(pShotFront == NULL)
	{
		m_pShotFirst = pShotBack;
		delete pShotRemove;
	}

	else if(pShotBack == NULL)
	{
		pShotFront->m_pNextShot = pShotBack;
		delete pShotRemove;
	}

	else
	{
		pShotFront->m_pNextShot = pShotBack;
		delete pShotRemove;
	}
	return;
}

CBullet* CShotManager::GetAt(int nIndex)
{
	if(nIndex < 0)
	{
		return NULL;
	}

	if(m_pShotFirst == NULL)
	{
		return NULL;
	}

	CBullet* pShotBuffer = m_pShotFirst;
	for(int nCnt = 0; nCnt < nIndex; nCnt++)
	{
		if(pShotBuffer == NULL)
		{
			return NULL;
		}
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return pShotBuffer;
}

void CShotManager::DrawShot(void)
{
	CBullet* pShotBuffer = m_pShotFirst;
	while(pShotBuffer != NULL)
	{
		pShotBuffer->DrawImage();
		pShotBuffer = pShotBuffer->m_pNextShot;	
	}
}

void CShotManager::CheckShot(void)
{
	if(m_pShotFirst == NULL)
	{
		return;
	}

	int nCnt = 0;
	CBullet* pShotBuffer = m_pShotFirst;
	while(pShotBuffer == NULL)
	{
		if(pShotBuffer->m_x > 640)
		{
			pShotBuffer = m_pShotFirst;
			Remove(nCnt);
			nCnt = 0;
			continue;
		}
		pShotBuffer = pShotBuffer->m_pNextShot;
		nCnt++;
	}
	return;
}

void CShotManager::MoveShot(void)
{
	CBullet* pShotBuffer = m_pShotFirst;
	while(pShotBuffer != NULL)
	{
		pShotBuffer->Move();
		//pShotBuffer->m_y = pShotBuffer->m_y - 10;
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return;
}
