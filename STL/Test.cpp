//#include <iostream>
//using namespace std;
//
//#include <vector>
//#include <list>
//#include <algorithm>
//
//void TestVector()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	cout<<"size?"<<v.size()<<endl;
//	cout<<"capacity?"<<v.capacity()<<endl;
//	cout<<"maxsize?"<<v.max_size()<<endl;
//
//	vector<int>::iterator it = v.begin();
//	while(it != v.end())
//	{
//		cout<<*it<<" ";
//		++it;
//	}
//
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout<<v[i]<<" ";
//	}
//
//	cout<<endl;
//}
//
//void TestList()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout<<*it<<" ";
//		++it;
//	}
//	cout<<endl;
//
//	list<int>::reverse_iterator rIt = l.rbegin();
//	while (rIt != l.rend())
//	{
//		cout<<*rIt<<" ";
//		++rIt;
//	}
//	cout<<endl;
//
//	list<int>::iterator ret = find(l.begin(), l.end(), 5);
//	if (ret != l.end())
//	{
//		cout<<"找到了"<<*ret<<endl;
//	}
//	else
//	{
//		cout<<"没有找到"<<endl;
//	}
//
//	// 迭代器失效
//	// 删除所有偶数
//	it = l.begin();
//	while (it != l.end())
//	{
//		/*list<int>::iterator del = it;
//		++it;
//
//		if (*del %2 == 0)
//		{
//			l.erase(del);
//		}*/
//
//		if (*it %2 == 0)
//		{
//			it = l.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//
//	it = l.begin();
//	while (it != l.end())
//	{
//		cout<<*it<<" ";
//		++it;
//	}
//	cout<<endl;
//}
//
//int main()
//{
//	TestVector();
//	TestList();
//
//	return 0;
//}

//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//#include "List.h"
//#include "Vector.h"
//
//#include <list>
//
////struct A
////{
////	int _a1;
////	int _a2;
////
////	A(int a1, int a2)
////		:_a1(a1)
////		,_a2(a2)
////	{}
////};
////
////list<A> l;
////l.push_back(A(2,3));
////l.push_back(A(3,4));
////
////list<A>::iterator it = l.begin();
////while (it != l.end())
////{
////	//cout<<*it<<endl;
////	// it->operator-> ==> A* 
////	cout<<it->_a1<<":"<<it->_a2<<endl;
////	++it;
////}
//
//struct A
//{
//	int _a;
//
//	A(int a)
//		:_a(a)
//	{}
//};
//
//int main()
//{
//	//TestList();
//	TestVector();
//
//	return 0;
//}

#include <iostream>
#include <assert.h>
using namespace std;

#include "List.h"
#include "Vector.h"
#include "Iterator.h"

void TestIterator()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);

	// O(1)
	cout<<"Vector Distance?"<<Distance(v.Begin(), v.End())<<endl;
	// O(N)
	cout<<"List Distance?"<<Distance(l.Begin(), l.End())<<endl;
}

int main()
{
	TestIterator();

	return 0;
}