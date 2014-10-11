#pragma once

class CImageObject
{
public:
	int m_ImageID;
	int m_x;
	int m_y;
	int m_Width;
	int m_Height;
	//POINT m_Location;’u‚«Š·‚¦

public:
	CImageObject(void);
	CImageObject(int id);
	CImageObject(int x, int y, int id);

	void SetImageID(int image_ID);
	int GetCenterX(){return m_x + m_Width / 2;}
	int GetCenterY(){return m_y + m_Height / 2;}

	void DrawImage(void);



};
