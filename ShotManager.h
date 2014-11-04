#pragma once
#include "Bullet.h"
#include <stdexcept>

template<typename T> class CMT_Node
{
public:
	T m_Data;
	CMT_Node* m_pNext;
	CMT_Node* m_pPrev;
public:
	CMT_Node(T data);
};

template<typename T>
CMT_Node<T>::CMT_Node(T data)
{
	m_Data = data;
	m_pNext = NULL;
	m_pPrev = NULL;
}

template<typename T> class CShotManager
{
protected:
	int m_ShotCount;			//
	CMT_Node<T>* m_pFirstNode;	// �擪�m�[�h
	CMT_Node<T>* m_pLastNode;	// �����m�[�h
	CMT_Node<T>* m_pCursor;		// �J�[�\��
	int m_Length;				// �m�[�h�̐�
public:
	CShotManager(void);				// �R���X�g���N�^
	~CShotManager(void);			// �f�X�g���N�^
	int GetLength(void);		// �m�[�h�̐����擾
	void Add(T data);			// ���X�g�̖����Ƀf�[�^��ǉ�
	T GetAt(int nIndex);		// index���g�p���ăm�[�h�̃f�[�^���擾
	void Remove(int nIndex);	// index���g�p���ăm�[�h���폜
	void RemoveAll(void);		// �S�Ẵm�[�h���폜
	void SetCursorStart(void);	// �J�[�\�������X�g�̐擪�ɃZ�b�g
	void SetCursorNext(void);	// ���̃m�[�h�փJ�[�\�����ړ�(�����܂���NULL�Ŏ��s���NULL)
	void SetCursorPrev(void);	// �O�̃m�[�h�փJ�[�\�����ړ�(�擪�܂���NULL�Ŏ��s���NULL)
	void SetCursorEnd(void);	// �J�[�\�������X�g�̖����ɃZ�b�g
	void InsertCursor(T data);	// ���݂̃m�[�h�̑O�Ƀm�[�h��ǉ�(�����ɂ͒ǉ��ł��Ȃ�)
	void RemoveCursor(void);	// ���݂̃m�[�h�폜�㎟�̃m�[�h�ֈړ�(�����폜���NULL)
	T GetCursorData(void);		// �J�[�\���w���m�[�h�̃f�[�^���擾
	void DrawShot(void);
	void CheckShot(void);
	void MoveShot(void);
	void DeleteShot(void);//�e�̍폜

};

template<typename T>
CShotManager<T>::CShotManager(void)
{
	m_ShotCount = 0;
	m_pFirstNode = NULL;
	m_pLastNode = NULL;
	m_pCursor = NULL;
	m_Length = 0;
}

template<typename T>
CShotManager<T>::~CShotManager(void)
{
	RemoveAll();
}

template<typename T>
int CShotManager<T>::GetLength(void)
{
	return m_Length;
}

template<typename T>
void CShotManager<T>::Add(T data)
{
	if (m_pFirstNode == NULL)
	{
		m_pFirstNode = new CMT_Node<T>(data);
		m_pLastNode = m_pFirstNode;
	}
	else
	{
		CMT_Node<T>* pNewNode = new CMT_Node<T>(data);
		pNewNode->m_pPrev = m_pLastNode;
		m_pLastNode->m_pNext = pNewNode;
		m_pLastNode = pNewNode;
	}
	m_Length++;
}

template<typename T>
T CShotManager<T>::GetAt(int nIndex)
{
	CMT_Node<T>* pNodeBuf;
	pNodeBuf = m_pFirstNode;
	int nCnt = 0;
	if (m_pFirstNode == NULL || m_Length < nIndex || nIndex < 0)
	{
		throw std::out_of_range("out of range");
	}
	while (pNodeBuf->m_pNext != NULL && nCnt < nIndex)
	{
		pNodeBuf = pNodeBuf->m_pNext;
		nCnt++;
	}
	return pNodeBuf->m_Data;
}

template<typename T>
void CShotManager<T>::Remove(int nIndex)
{
	CMT_Node<T>* pNodeBuf;
	pNodeBuf = m_pFirstNode;
	int nCnt = 0;
	if (m_pFirstNode == NULL || m_Length < nIndex || nIndex < 0)
	{
		throw std::out_of_range("out of range");
	}
	while (pNodeBuf->m_pNext != NULL && nCnt < nIndex)
	{
		pNodeBuf = pNodeBuf->m_pNext;
		nCnt++;
	}

	if (pNodeBuf == NULL)
	{
		return;
	}

	if (pNodeBuf == m_pCursor)
	{
		m_pCursor = NULL;
	}

	if (pNodeBuf == m_pFirstNode)
	{
		m_pFirstNode = m_pFirstNode->m_pNext;
		m_pFirstNode->m_pPrev = NULL;
		delete pNodeBuf;
	}
	else if (pNodeBuf == m_pLastNode)
	{
		m_pLastNode = m_pLastNode->m_pPrev;
		m_pLastNode->m_pNext = NULL;
		delete pNodeBuf;
	}
	else
	{
		pNodeBuf->m_pPrev->m_pNext = pNodeBuf->m_pNext;
		pNodeBuf->m_pNext->m_pPrev = pNodeBuf->m_pPrev;
		delete pNodeBuf;
	}
	m_Length--;
}

template<typename T>
void CShotManager<T>::RemoveAll(void)
{
	CMT_Node<T>* pNodeBuf;
	pNodeBuf = m_pFirstNode;
	if (m_pFirstNode == NULL)
	{
		return;
	}
	while (pNodeBuf->m_pNext != NULL)
	{
		pNodeBuf = pNodeBuf->m_pNext;
		delete pNodeBuf->m_pPrev;
	}
	delete m_pLastNode;
	m_pFirstNode = NULL;
	m_pLastNode = NULL;
	m_pCursor = NULL;
	m_Length = 0;
}

template<typename T>
void CShotManager<T>::SetCursorStart(void)
{
	m_pCursor = m_pFirstNode;
}

template<typename T>
void CShotManager<T>::SetCursorNext(void)
{
	if (m_pCursor == m_pLastNode || m_pCursor == NULL)
	{
		m_pCursor = NULL;
	}
	else
	{
		m_pCursor = m_pCursor->m_pNext;
	}
}

template<typename T>
void CShotManager<T>::SetCursorPrev(void)
{
	if (m_pCursor == m_pFirstNode || m_pCursor == NULL)
	{
		m_pCursor = NULL;
	}
	else
	{
		m_pCursor = m_pCursor->m_pPrev;
	}
}

template<typename T>
void CShotManager<T>::SetCursorEnd(void)
{
	m_pCursor = m_pLastNode;
}

template<typename T>
T CShotManager<T>::GetCursorData(void)
{
	return m_pCursor->m_Data;
}

template<typename T>
void CShotManager<T>::InsertCursor(T data)
{
	if (m_pCursor == NULL)
	{
		return;
	}

	if (m_pCursor == m_pFirstNode)
	{
		CMT_Node<T>* pNewNode = new CMT_Node<T>(data);
		pNewNode->m_pNext = m_pCursor;
		m_pCursor->m_pPrev = pNewNode;
		m_pFirstNode = pNewNode;
	}
	else
	{
		CMT_Node<T>* pNewNode = new CMT_Node<T>(data);
		pNewNode->m_pNext = m_pCursor;
		pNewNode->m_pPrev = m_pCursor->m_pPrev;
		m_pCursor->m_pPrev->m_pNext = pNewNode;
		m_pCursor->m_pPrev = pNewNode;
	}
	m_Length++;
}

template<typename T>
void CShotManager<T>::RemoveCursor(void)
{
	if (m_pCursor == NULL)
	{
		return;
	}

	if (m_pCursor == m_pFirstNode)
	{
		m_pCursor = m_pCursor->m_pNext;
		delete m_pCursor->m_pPrev;
		m_pCursor->m_pPrev = NULL;
		m_pFirstNode = m_pCursor;
	}
	else if (m_pCursor == m_pLastNode)
	{
		m_pCursor = m_pCursor->m_pPrev;
		delete m_pCursor->m_pNext;
		m_pCursor->m_pNext = NULL;
		m_pLastNode = m_pCursor;
		m_pCursor = NULL;
	}
	else
	{
		CMT_Node<T>* pNodeBuf;
		pNodeBuf = m_pCursor->m_pPrev;
		m_pCursor = m_pCursor->m_pNext;
		delete m_pCursor->m_pPrev;
		m_pCursor->m_pPrev = pNodeBuf;
		pNodeBuf->m_pNext = m_pCursor;
	}
	m_Length--;
}
template <typename T>
void CShotManager<T>::DrawShot(void)
{
	CMT_Node<T>* pShotBuffer = m_pFirstNode;
	while (pShotBuffer != NULL)
	{
		pShotBuffer->m_Data->DrawImage();
		pShotBuffer = pShotBuffer->m_pNext;
	}
}
template <typename T>
void CShotManager<T>::CheckShot(void)
{
	if (m_pFirstNode == NULL)
	{
		return;
	}
	int nCnt = 0;
	CMT_Node<T>* pShotBuffer = m_pFirstNode;
	while (pShotBuffer == NULL)
	{
		if (pShotBuffer->m_Data->m_x > 640)
		{
			pShotBuffer = m_pFirstNode;
			Remove(nCnt);
			nCnt = 0;
			continue;
		}
		pShotBuffer = pShotBuffer->m_pNext;
		nCnt++;
	}
	return;
}
template <typename T>
void CShotManager<T>::MoveShot(void)
{
	CMT_Node<T>* pShotBuffer = m_pFirstNode;
	while (pShotBuffer != NULL)
	{
		pShotBuffer->m_Data->Move();
		pShotBuffer = pShotBuffer->m_pNext;
	}
	return;
}
template <typename T>
void CShotManager<T>::DeleteShot(void)
{
	SetCursorStart();
	CMT_Node<T>* pShotBuffer = m_pFirstNode;
	
	while (m_pCursor != m_pLastNode){
		if (m_pCursor->m_Data->DeleteBullet() == NULL)
		{
			delete GetCursorData();
			RemoveCursor();
		}
		else
		{
			SetCursorNext();
		}
	}
	return;
}

///////////////////////////////////////////////////////

//                       �e�X�g                      //

///////////////////////////////////////////////////////






///////////////////////////////////////////////////////

//                       ������                      //

///////////////////////////////////////////////////////
