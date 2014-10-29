#include "ShootingScene.h"

#define SHOOTING_FIELD_WIDTH 400
#define SHOOTING_FIELD_HEIGHT 480
//x640,y480 (最大値)

CShootingScene::CShootingScene(void)
{

}


CShootingScene::~CShootingScene(void)
{
}

void CShootingScene::InitScene(void)
{
	m_shotid = LoadGraph(_T("Image\\弾00.png"));
	m_Player.SetImageID(LoadGraph(_T("Image\\吹雪.png")));
	m_Player.m_Speed = 3;
	m_Player.SetCenterX(200);
	m_Player.SetCenterY(400);

	m_Player.m_pEquipment.m_ShotInterval = 100;
	m_Player.m_pEquipment.m_ShotSpeed = 10;

	
	m_BackGroundImageLeft.SetImageID( LoadGraph(_T("Image\\海.png")));
	m_BackGroundImageRight.SetImageID(LoadGraph(_T("Image\\背景.png")));
	m_BackGroundImageRight.m_x = 400;

	//バックグラウンド再生
	LoadBackgroundMusic(_T("Sound\\BGM\\rinkai.wav"));
	ChangeVolumeSoundMem(50, m_BackgroundMusic);		//音量調節
	PlaySoundMem(m_BackgroundMusic, DX_PLAYTYPE_LOOP,TRUE);

	m_Enemy.SetImageID(LoadGraph(_T("Image\\ボス258.png")));
	m_Enemy.SetCenterX(200);
	m_Enemy.SetCenterY(130);

	m_h.SetImageID(LoadGraph(_T("Image\\吹雪立ち絵.png")));
	m_h.m_x = 450;
	m_h.m_y = 120;

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
		m_Player.SetCenterX(0);
	if(m_Player.GetCenterX() > SHOOTING_FIELD_WIDTH)
		m_Player.SetCenterX(SHOOTING_FIELD_WIDTH);
	if(m_Player.GetCenterY() < 0 )
		m_Player.SetCenterY(0);
	if(m_Player.GetCenterY() > SHOOTING_FIELD_HEIGHT)
		m_Player.SetCenterY(SHOOTING_FIELD_HEIGHT);

	if(CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		CBullet* shot = m_Player.m_pEquipment.CreateShot(m_Player.GetCenterX(), m_Player.GetCenterY(),m_shotid);
		if(shot != NULL)
		{
			m_PlayerShotManager.Add(shot);
		}
	}
}

void CShootingScene::DrawImage(void)
{
	CheckKey();
	m_BackGroundImageLeft.DrawImage();
	m_Player.DrawImage();
	
	m_PlayerShotManager.DrawShot();

	
	m_Enemy.DrawImage();
	m_BackGroundImageRight.DrawImage();
	m_h.DrawImage();
	m_PlayerShotManager.MoveShot();
	m_PlayerShotManager.CheckShot();
}
