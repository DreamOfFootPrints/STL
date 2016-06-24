#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>//�㷨��ͷ�ļ�
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
		cout << it->_a1 << " ";//ָ��->����->���ݣ�A�������δ����<<
		cout << it->_a2 << " ";
		++it;
	}
	cout << endl;
}




/******************************************************************************************************************/




void TestVector()//vector���ýӿ�
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


void TestList_1()//list���ý��
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

void TestList2()//������
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	//����Ȣ����������
	//ʹ�õ�����
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//ʹ�õ����������ŷ���
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
		cout << "�ҵ���" << *ret << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

}

void TestIterator_dead()//������ʧЧ,����������
{
	//������ż����ɾ��
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


void Solution_1()//������ʧЧ�Ľ������
{
	//������ż����ɾ��
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
	//������ż����ɾ��
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