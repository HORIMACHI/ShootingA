#include "Shot.h"
#include "DxLib.h"


CShot::CShot(int nx, int ny, int nImageID)
{
	m_ImageID = nImageID;
	GetGraphSize(nImageID,&m_Width,&m_Height);
	m_Location.x = nx - m_Width / 2;
	m_Location.y = ny - m_Height / 2 - 30;
	m_pNextShot = NULL;
}


