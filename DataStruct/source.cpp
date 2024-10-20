#include <vector>
#include <list>
#include <map>
#include "vector.h"
#include "list.h"
#include "map.h"
#include "myclass.h"

#include <crtdbg.h>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::map;
using std::make_pair;

void TestFunc();
void VectorTestfunc();
void ListTestfunc();
void MapTestfunc();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	// TestFunc();

	// VectorTestfunc();
	// ListTestfunc();
	MapTestfunc();

	return 0;
}

void TestFunc()
{
	vector<myclass> vec = {};

	vec.reserve(2);

	for (size_t i = 0; i < 3; ++i)
	{
		cout << i << " 실행 결과" << endl;
		vec.push_back({});
		cout << endl;
	}


	cout << endl << "reserve 실행" << endl;
	vec.reserve(30);

	cout << endl << "TestFunc 함수 종료" << endl;
}

void VectorTestfunc()
{
	cout << "VectorTestfunc 시작" << endl << endl;

	MyVector<myclass> myvec = {};

	myvec.reserve(10);

	for (int i = 0; i < 100; i++)
	{
		cout << i << "번째 for문 시작" << endl;
		myvec.push_back(i);

		printf_s("value = %u, size = %u, capacity = %u\n", static_cast<unsigned int>(myvec[i].GetValue()), static_cast<unsigned int>(myvec.size()), static_cast<unsigned int>(myvec.capacity()));
		cout << endl;
	}
	
	auto value = myvec[0].GetValue();
	value = myvec[99].GetValue();

	cout << endl;

	for (size_t i = 0; i < 100; i++)
		printf_s("value = %u, size = %u, capacity = %u\n", static_cast<unsigned int>(myvec[i].GetValue()), static_cast<unsigned int>(myvec.size()), static_cast<unsigned int>(myvec.capacity()));

	cout << "VectorTestfunc 종료" << endl;

	return;
}

void ListTestfunc()
{
	cout << "ListTestfunc 시작" << endl << endl;

	MyList<myclass> mylist = {};

	for (int i = 0; i < 4; i++)
	{
		mylist.push_back(i);
	}

	cout << endl;

	for (MyList<myclass>::Iterator iter = mylist.begin(); iter != mylist.End(); ++iter)
	{
		cout << (*iter).GetValue() << endl;
	}

	mylist.Clear();

	cout << "ListTestfunc 종료" << endl;

	return;
}

void MapTestfunc()
{
	MyMap<myclass, float> m = {};

	bool insertTest = true;

	insertTest = m.insert(MyMap<myclass, float>::MyPair(8, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(12, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(4, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(6, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(2, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(10, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(14, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(3, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(1, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(5, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(7, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(13, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(11, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(9, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(15, 0));

	insertTest = m.insert(MyMap<myclass, float>::MyPair(2, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(3, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(7, 0));

	MyMap<myclass, float>::Iterator iter = {&m, nullptr};

	iter = m.find(4);
	iter = m.find(1);
	iter = m.find(2);
	iter = m.find(5);
	iter = m.find(0);

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first.GetValue() << endl;

	m.clear();

	insertTest = m.insert(MyMap<myclass, float>::MyPair(8, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(12, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(4, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(6, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(2, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(10, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(14, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(3, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(1, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(5, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(7, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(13, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(11, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(9, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(15, 0));

	insertTest = m.insert(MyMap<myclass, float>::MyPair(2, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(3, 0));
	insertTest = m.insert(MyMap<myclass, float>::MyPair(7, 0));

	for (iter = m.begin(); iter != m.end();)
		iter = m.erase(iter);

	return;
}