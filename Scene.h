#pragma once
#include "Windows.h"
#include "DxLib.h"
class CScene
{
public:
	int m_BackgroundImage;
	int m_BackgroundMusic;

public:
	CScene(void);
	~CScene(void);

	virtual void InitScene(void) = 0;
	void LoadBackgroundImage(LPCTSTR);
	void LoadBackgroundMusic(LPCTSTR);
	void CheckKey(void);
};

