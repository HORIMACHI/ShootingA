#pragma once
#include "Scene.h"
#include "ImageObject.h"
class CTitleScene : public CScene
{
public:
	CImageObject m_BackGroundImage;//”wŒi‰æ‘œ
	CImageObject m_TitleLogoImage;//ƒ^ƒCƒgƒ‹ƒƒS

	CImageObject m_h;


public:
	CTitleScene(void);
	~CTitleScene(void);
	void InitScene(void);
	void CheckKey(void);
	void DrawImage(void);
};

