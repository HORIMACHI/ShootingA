#include "Character.h"
#include "DxLib.h"

CImageObject::CImageObject(void)
{
	SetImageID(-1);
	m_Location.x = 0;
	m_Location.y = 0;
}

CImageObject::CImageObject(int imageID)
{
	SetImageID(imageID);
	m_Location.x = 0;
	m_Location.y = 0;
}

CImageObject::CImageObject(int x, int y, int imageID)
{
	SetImageID(imageID);
	m_Location.x = x;
	m_Location.y = y;
}

void CImageObject::SetImageID(int imageID)
{
	m_ImageID = imageID;
	GetGraphSize(imageID, &m_Width, &m_Height);
}

void CImageObject::DrawImage(void)
{
	DrawGraph(m_Location.x, m_Location.y, m_ImageID, TRUE);
}



