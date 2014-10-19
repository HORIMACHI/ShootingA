#include "Character.h"
#include "DxLib.h"

CImageObject::CImageObject(void)
{
	SetImageID(-1);
	m_x = 0;
	m_y = 0;
}

CImageObject::CImageObject(int imageID)
{
	SetImageID(imageID);
	m_x = 0;
	m_y = 0;
}

CImageObject::CImageObject(int x, int y, int imageID)
{
	SetImageID(imageID);
	m_x = x;
	m_y = y;
}

void CImageObject::SetImageID(int imageID)
{
	m_ImageID = imageID;
	GetGraphSize(imageID, &m_Width, &m_Height);
}

void CImageObject::DrawImage(void)
{
	DrawGraph((int)m_x, (int)m_y, m_ImageID, TRUE);
}



