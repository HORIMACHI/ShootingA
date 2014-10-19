#pragma once
#include "Equipment.h"
#include "ImageObject.h"

class CCharacter : public CImageObject
{
public:
	//プレイヤーか敵の属性
	//装備
	//体力
	//あたり判定範囲
	int m_HitPoint;
	int m_Speed;
	CEquipment m_pEquipment;


public:
	CCharacter(void);
	~CCharacter(void);
	//移動				バーチャル
	//ショットを打つ
};

