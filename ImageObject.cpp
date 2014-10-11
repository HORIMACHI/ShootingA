#include "Character.h"
#include "DxLib.h"

CImageObject::CImageObject(void)
{
	m_ImageID = -1;
	m_x = 0;
	m_y = 0;
}

CImageObject::CImageObject(int id)
{
	m_ImageID = id;
	m_x = 0;
	m_y = 0;
}

CImageObject::CImageObject(int x, int y, int id)
{
	m_ImageID = id;
	m_x = x;
	m_y = y;
}

void CImageObject::SetImageID(int image_ID)
{
	m_ImageID = image_ID;
	GetGraphSize(image_ID,&m_Width,&m_Height);
}

void CImageObject::DrawImage(void)
{
	DrawGraph(m_x, m_y, m_ImageID, TRUE);
}



