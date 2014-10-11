#include "ShootingScene.h"

#define SHOOTING_FIELD_WIDTH 640
#define SHOOTING_FIELD_HEIGHT 480
//x640,y480

CShootingScene::CShootingScene(void)
{
	m_shotid = LoadGraph(_T("Image\\íe00.png"));
	m_Player.SetImageID(LoadGraph(_T("Image\\êÅê·.png")));
	m_Player.m_Speed = 3;
	m_Player.m_x = 200 - m_Player.m_Width / 2;
	m_Player.m_y = 360;

	
	m_BackGroundImageLeft.m_ImageID = LoadGraph(_T("Image\\äC.png"));
	m_BackGroundImageRight.m_ImageID = LoadGraph(_T("Image\\îwåi.png"));
	m_BackGroundImageRight.m_x = 400;

	m_Enemy.SetImageID(LoadGraph(_T("Image\\É{ÉX258.png")));
	m_Enemy.m_x = 200 - m_Enemy.m_Width / 2;
	m_Enemy.m_y = 30;

	m_h.m_ImageID = LoadGraph(_T("Image\\êÅê·óßÇøäG.png"));
	m_h.m_x = 450;
	m_h.m_y = 120;

}


CShootingScene::~CShootingScene(void)
{
}

void CShootingScene::CheckKey(void)
{
	if(CheckHitKey(KEY_INPUT_UP) == 1)
		m_Player.m_y -= m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_DOWN) == 1)
		m_Player.m_y += m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_LEFT) == 1)
		m_Player.m_x -= m_Player.m_Speed;
	if(CheckHitKey(KEY_INPUT_RIGHT) == 1)
		m_Player.m_x += m_Player.m_Speed ;

	if(m_Player.GetCenterX() < 0 )
		m_Player.m_x = 0 - m_Player.m_Width / 2;
	if(m_Player.GetCenterX() > 400)
		m_Player.m_x = 400 - m_Player.m_Width / 2;
	if(m_Player.GetCenterY() < 0 )
		m_Player.m_y = 0 - m_Player.m_Height / 2;
	if(m_Player.GetCenterY() > 480)
		m_Player.m_y = 480 - m_Player.m_Height / 2;

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
