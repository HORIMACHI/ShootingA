#include "ShootingScene.h"

#define SHOOTING_FIELD_WIDTH 400
#define SHOOTING_FIELD_HEIGHT 480
//x640,y480 (�ő�l)

CShootingScene::CShootingScene(void)
{
	m_shotid = LoadGraph(_T("Image\\�e00.png"));
	m_Player.SetImageID(LoadGraph(_T("Image\\����.png")));
	m_Player.m_Speed = 3;
	m_Player.m_Location.x = 200 - m_Player.GetWidth() / 2;
	m_Player.m_Location.y = 360;

	
	m_BackGroundImageLeft.SetImageID( LoadGraph(_T("Image\\�C.png")));
	m_BackGroundImageRight.SetImageID(LoadGraph(_T("Image\\�w�i.png")));
	m_BackGroundImageRight.m_Location.x = 400;

	m_Enemy.SetImageID(LoadGraph(_T("Image\\�{�X258.png")));
	m_Enemy.m_Location.x = 200 - m_Enemy.GetWidth() / 2;
	m_Enemy.m_Location.y = 30;

	m_h.SetImageID(LoadGraph(_T("Image\\���ᗧ���G.png")));
	m_h.m_Location.x = 450;
	m_h.m_Location.y = 120;

}


CShootingScene::~CShootingScene(void)
{
}

void CShootingScene::CheckKey(void)
{
	if(CheckHitKey(KEY_INPUT_UP) == 1)
		m_Player.m_Location.y -= m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_DOWN) == 1)
		m_Player.m_Location.y += m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_LEFT) == 1)
		m_Player.m_Location.x -= m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_RIGHT) == 1)
		m_Player.m_Location.x += m_Player.m_Speed ;

	if(m_Player.GetCenterX() < 0 )
		m_Player.SetCenterX(0);
	if(m_Player.GetCenterX() > SHOOTING_FIELD_WIDTH)
		m_Player.SetCenterX(SHOOTING_FIELD_WIDTH);
	if(m_Player.GetCenterY() < 0 )
		m_Player.SetCenterY(0);
	if(m_Player.GetCenterY() > SHOOTING_FIELD_HEIGHT)
		m_Player.SetCenterY(SHOOTING_FIELD_HEIGHT);

	if(CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		m_ShotManager.Add(m_Player.m_pEquipment.CreateShot(m_Player.GetCenterX(), m_Player.GetCenterY(),m_shotid));
	}
}

void CShootingScene::DrawImage(void)
{
	CheckKey();
	m_BackGroundImageLeft.DrawImage();
	m_Player.DrawImage();
	
	m_ShotManager.DrawShot();

	
	m_Enemy.DrawImage();
	m_BackGroundImageRight.DrawImage();
	m_h.DrawImage();
	m_ShotManager.MoveShot();
	m_ShotManager.CheckShot();
}
