//CNode.h
template <class T> class CNode{
public:
	CNode();
	CNode(T val);
	~CNode();
	void setValue(T val);
	T getValue();
public:
	T m_TValue;
	CNode<T> *m_pNext;
	CNode<T> *m_pPrev;
};
//ŽÀ‘••”
template <class T>
CNode<T>::CNode(){
	m_TValue = NULL;
	m_pNext = nullptr;
	m_pPrev = nullptr;
};

template <class T>
CNode<T>::CNode(T val){
	m_TValue = val;
	m_pNext = nullptr;
	m_pPrev = nullptr;
};

template <class T>
CNode<T>::~CNode(){};

template <class T>
void CNode<T>::setValue(T val){
	m_TValue = val;
}
template <class T>
T CNode<T>::getValue(){
	return m_TValue;
}