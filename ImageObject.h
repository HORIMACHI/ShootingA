#pragma once
#include <Windows.h>

class CImageObject
{
public:
	POINT m_Location;
protected:
	int m_ImageID;
	int m_Width;
	int m_Height;

public:
	CImageObject(void);
	CImageObject(int imageID);
	CImageObject(int x, int y, int imageID);

	void SetImageID(int image_ID);
	int GetWidth(){return m_Width;}
	int GetHeight(){return m_Height;}
	int GetCenterX(){return m_Location.x + m_Width / 2;}
	int GetCenterY(){return m_Location.y + m_Height / 2;}
	void SetCenterX(int x){m_Location.x = x - m_Width / 2;}
	void SetCenterY(int y){m_Location.y = y - m_Height / 2;}

	void DrawImage(void);



};
