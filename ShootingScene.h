#pragma once
#include "Scene.h"
#include "Player.h"
#include "ShotManager.h"
#include "Enemy.h"

class CShootingScene : public CScene
{
public:
	CPlayer m_Player;
	int m_shotid;
	int m_charid;
	CShotManager m_ShotManager;
	CEnemy m_Enemy;
	//CEnemyManager EnemyManager;

	
	CImageObject m_BackGroundImageLeft;
	CImageObject m_BackGroundImageRight;

	CImageObject m_h;
	

public:
	CShootingScene(void);
	~CShootingScene(void);
	void CheckKey(void);
	void DrawImage(void);
};

