#include <vector>
#include <list>
#include <map>
#include "vector.h"
#include "list.h"
// #include "map.h"
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

	vector<int> vec = {};
	auto temp = vec.begin();
	list<int> li = {};

	VectorTestfunc();
	ListTestfunc();
	// MapTestfunc();

	return 0;
}

void TestFunc()
{
	vector<myclass> vec = {};

	vec.reserve(2);

	for (size_t i = 0; i < 3; ++i)
	{
		cout << i << " ���� ���" << endl;
		vec.push_back({});
		cout << endl;
	}


	cout << endl << "reserve ����" << endl;
	vec.reserve(30);

	cout << endl << "TestFunc �Լ� ����" << endl;
}

void VectorTestfunc()
{
	cout << "VectorTestfunc ����" << endl << endl;

	MyVector<myclass> myvec = {};

	myvec.reserve(10);

	for (int i = 0; i < 100; i++)
	{
		cout << i << "��° for�� ����" << endl;
		myvec.push_back(i);

		printf_s("value = %u, size = %u, capacity = %u\n", static_cast<unsigned int>(myvec[i].GetValue()), static_cast<unsigned int>(myvec.size()), static_cast<unsigned int>(myvec.capacity()));
		cout << endl;
	}
	
	auto value = myvec[0].GetValue();
	value = myvec[99].GetValue();

	cout << endl;

	for (size_t i = 0; i < 100; i++)
		printf_s("value = %u, size = %u, capacity = %u\n", static_cast<unsigned int>(myvec[i].GetValue()), static_cast<unsigned int>(myvec.size()), static_cast<unsigned int>(myvec.capacity()));

	cout << "VectorTestfunc ����" << endl;

	return;
}

void ListTestfunc()
{
	cout << "ListTestfunc ����" << endl << endl;

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

	cout << "ListTestfunc ����" << endl;

	return;
}