//CDList.h
#include <stdio.h>
#include "Node.h"

template <class T> class CDList{
private:
	CNode<T> *p_head = NULL;

public:
	int m_length;

public:
	CDList();
	~CDList();
	CNode<T>* FindLast();
	void Add(CNode<T> *n);
	void Remove(int index);
	CNode<T>* GetAt(int index);
	void GetAtPrint(int index);//デバッグ用関数
	
	void DrawShot(void);
	void CheckShot(void);
	void MoveShot(void);
};
/* 実装 */
template <class T> CDList<T>::CDList() :m_length(0){};
template <class T> CDList<T>::~CDList(){};

template <class T>
CNode<T> *CDList<T>::FindLast(){
	CNode<T> *follow = p_head;
	if (p_head == NULL){
		return NULL;
	}
	else{
		while (follow->m_pNext != nullptr){
			follow = follow->m_pNext;
		}
		return follow;
	}
};

template <class T>
void CDList<T>::Add(CNode<T> *n){
	CNode<T> *p_last = FindLast();
	if (p_head == NULL){
		p_head = n;
		m_length++;
	}
	else{
		p_last->m_pNext = n;
		n->m_pPrev = p_last;
		m_length++;
	}
}

template <class T>
void CDList<T>::Remove(int index){
	CNode<T> *p_follow = p_head;
	CNode<T> *tmp_pPrev = nullptr;
	CNode<T> *tmp_pNext = nullptr;
	if (index > m_length - 1){
		return;
	}
	else{
		if (p_head == NULL)return;
		for (int i = 0; i < index; i++){
			if (i == index - 1)tmp_pPrev = p_follow;
			p_follow = p_follow->m_pNext;
		}
		tmp_pNext = p_follow->m_pNext;
		//p_head
		if (tmp_pPrev == nullptr){
			if (tmp_pNext == nullptr){
				p_head = NULL;
			}
			else{
				p_head = tmp_pNext;
				p_head->tmp_pPrev = nullptr;
				delete p_follow;
			}
		}
		//last
		else if (p_follow->m_pNext == nullptr){
			tmp_pPrev->m_pNext = nullptr;
			delete p_follow;
		}
		else{
			tmp_pPrev->m_pNext = tmp_pNext;
			tmp_pNext->m_pPrev = tmp_pPrev;
			delete p_follow;
		}
		m_length--;
	}
}
template <class T>
CNode<T>* CDList<T>::GetAt(int index){
	CNode<T> *p_follow = p_head;
	if (index > m_length - 1){
		return NULL;
	}
	for (int i = 0; i < index; i++){
		p_follow = p_follow->m_pNext;
	}
	return p_follow;
}
template <class T>
void CDList<T>::GetAtPrint(int index){
	CNode<T> *p_follow = p_head;
	if (index > m_length - 1){
		return;
	}
	for (int i = 0; i < index; i++){
		p_follow = p_follow->m_pNext;
	}
	if (p_follow == nullptr)return;
	if (p_follow->m_pNext == nullptr)
		printf("GetAt(%d): here:%p m_pPrev:%p m_pNext:%p\n", index, p_follow, p_follow->m_pPrev, NULL);
	else if (p_follow->m_pPrev == nullptr)
		printf("GetAt(%d): here:%p m_pPrev:%p m_pNext:%p\n", index, p_follow, NULL, p_follow->m_pNext);
	else
		printf("GetAt(%d): here:%p m_pPrev:%p m_pNext:%p\n", index, p_follow, p_follow->m_pPrev, p_follow->m_pNext);
}