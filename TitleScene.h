#pragma once
#include "Scene.h"
#include "ImageObject.h"
class CTitleScene : public CScene
{
public:
	CImageObject m_BackGroundImage;//�w�i�摜
	CImageObject m_TitleLogoImage;//�^�C�g�����S

	CImageObject m_h;


public:
	CTitleScene(void);
	~CTitleScene(void);
	void InitScene(void);
	void CheckKey(void);
	void DrawImage(void);
};

