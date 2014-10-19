#pragma once
#include <Windows.h>
#include <math.h>

#define PI 3.14159

class CImageObject
{
public:
	double m_x;
	double m_y;
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
	int GetCenterX(){return (int)(m_x + m_Width / 2);}
	int GetCenterY(){return (int)(m_y + m_Height / 2);}
	void SetCenterX(int x){m_x = x - m_Width / 2;}
	void SetCenterY(int y){m_y = y - m_Height / 2;}

	void DrawImage(void);



};
