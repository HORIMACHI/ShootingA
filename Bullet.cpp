#include "Bullet.h"
#include "DxLib.h"


CBullet::CBullet(int nx, int ny, int nImageID)
{
	m_ImageID = nImageID;
	GetGraphSize(nImageID,&m_Width,&m_Height);
	m_x = nx - m_Width / 2;
	m_y = ny - m_Height / 2 - 30;
	m_pNextShot = NULL;
}
CBullet::CBullet(int nx, int ny, double Direction, double shotSpeed, int nImageID)
{
	m_ImageID = nImageID;
	GetGraphSize(nImageID,&m_Width,&m_Height);
	m_x = nx - m_Width / 2;
	m_y = ny - m_Height / 2 - 30;
	m_pNextShot = NULL;
	m_Direction = Direction;
	m_Speed = shotSpeed;

}


void CBullet::Move(void)
{
	double degree = m_Direction * PI / 180;
	m_x = m_x + sin(degree) * m_Speed;
	m_y = m_y + cos(degree) * m_Speed;
}




