#pragma once
#include "ImageObject.h"
#include <stdio.h>
class CBullet:public CImageObject
{
public:
	double m_Speed;
	double m_Direction;
	CBullet* m_pNextShot;

public:
	CBullet(int nx, int ny, int nImageID);
	CBullet(int nx, int ny, double Direction, double shotSpeed, int nImageID);
	
	void Move(void);
};

