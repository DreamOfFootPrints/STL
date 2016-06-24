#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>//算法的头文件
/******************************************************************************************************************/
struct A
{
	int _a1;
	int _a2;
	
	A(int a1,int a2)
		:_a1(a1)
		, _a2(a2)
	{}



};

void TestThis()
{
	list<A> l;
	l.push_back(A(2, 3));
	l.push_back(A(3, 4));
	list<A>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << it->_a1 << " ";//指针->对象->数据，A这个对象未重载<<
		cout << it->_a2 << " ";
		++it;
	}
	cout << endl;
}




/******************************************************************************************************************/




void TestVector()//vector常用接口
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "size?  " << v.size() << endl;
	cout << "capacity?  " << v.capacity() << endl;
	cout << "max_size?  " << v.max_size() << endl;
	/*v.reserve(20);
	v.resize(10);
	v.insert(12,10);
	v.erase(3);
	v.assign();
	v.push_back(1);
	v.pop_back();
	v.swap();
	v.clear();
	v.at();
	v.operator[]();*/
}


void TestList_1()//list常用借口
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	/*l.front();
	l.back();
	l.push_back();
	l.pop_back();
	l.remove();
	l.remove_if();
	l.unique();
	l.merge();
	l.sort();
	l.begin();
	l.end();
	l.rbegin();
	l.rend();*/
}

void TestList2()//迭代器
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	//外面娶不到其数据
	//使用迭代器
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//使用迭代器，倒着访问
	list<int>::reverse_iterator rIt = l.rbegin();
	while (rIt != l.rend())
	{
		cout << *rIt << " ";
		++rIt;
	}
	cout << endl;

	list<int>::iterator ret = find(l.begin(), l.end(), 3);
	if (ret != l.end())
	{
		cout << "找到了" << *ret << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

}

void TestIterator_dead()//迭代器失效,下面程序崩溃
{
	//将所有偶数都删掉
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			l.erase(it);
		}
		++it;
	}
}


void Solution_1()//迭代器失效的解决方法
{
	//将所有偶数都删掉
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		list<int>::iterator del = it;
		it++;
		if (*del % 2 == 0)
		{
			l.erase(del);
		}
	}
}



void Solution_2()
{
	//将所有偶数都删掉
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it=l.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int main()
{
	/*TestVector();
	TestList2();*/
	//TestIterator();
	//Solution_1();
	//Solution_2();
	TestThis();
	system("pause");
	return 0;
}