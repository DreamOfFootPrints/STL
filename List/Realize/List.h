#include<iostream>
using namespace std;


template<class T>
struct __ListNode
{
	__ListNode<T>* _next;
	__ListNode<T>* _prev;
	T _data;
public:
	__ListNode(const T& x = T())
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};





template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> ListNode;
	typedef Ptr Pointer;
	typedef Ref Reference;
	typedef __ListIterator<T, T&, T*> Iterator;//迭代器
	typedef __ListIterator<T, const T&, const T*> const_Iterator;//迭代器
	typedef __ListIterator<T, Ref, Ptr> self;//自己
public:
	ListNode* _node;
public:
	__ListIterator(ListNode* x)
		:_node(x)
	{}
	__ListIterator()
	{}

	Reference operator*()const
	{
		return _node->_data;
	}

	Pointer operator->()const//不是节点的指针是对象的指针
	{
		return &(operator*());
	}

	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	self operator++(int)
	{
		self tmp = *this;
		++*this;
		return tmp;
	}


	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	self operator--(int)
	{
		self tmp = *this;
		--*this;
		return tmp;
	}

	bool operator==(const self& x)const
	{
		return _node == x._node;
	}

	bool operator!=(const self& x)const
	{
		return _node != x._node;
	}

};




template<class T>//有头结点
class List
{
public:
	typedef __ListNode<T> ListNode;
	typedef __ListIterator<T, T&, T*> Iterator;//迭代器
protected:
	ListNode* _head;
public:
	List()
	{
		_head = new ListNode();
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		ListNode* tmp = new ListNode(x);
		ListNode* tail = _head->_prev;
		tail->_next = tmp;
		tmp->_prev = tail;
		tmp->_next = _head;
		_head->_prev = tmp;
	}

	Iterator Begin()
	{
		return _head->_next;
		//return -Iterator(_head->_next);
	}

	Iterator end()
	{ 
		return _head;
	}
};




