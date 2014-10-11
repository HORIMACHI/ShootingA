#pragma once
#include "ImageObject.h"

class CShot:public CImageObject
{
public:
	int m_Speed;
	int m_Direction;
	CShot* m_pNextShot;

public:
	CShot(int nx, int ny, int nImageID);
};

