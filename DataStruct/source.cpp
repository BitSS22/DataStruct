#include <vector>
// #include "vector.h"
#include <crtdbg.h>
#include "myvec.h"
#include <iostream>

class myclass
{
public:
	myclass()
		: ptr(nullptr)
	{
		std::cout << "������ ȣ�� ����" << std::endl;

		ptr = new int;

		++callCountConstructor;

		std::cout << "������ ȣ�� ����, count : " << callCountConstructor << std::endl;
	}
	~myclass()
	{
		std::cout << "�Ҹ��� ȣ�� ����" << std::endl;

		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}

		++callCountDestructor;

		std::cout << "�Ҹ��� ȣ�� ����, count : " << callCountDestructor << std::endl;
	}

	/*myclass(const myclass& other)
	{
		std::cout << "���� ������ ȣ��" << std::endl;

		ptr = new int;

		++callCountCopyConstructor;

		std::cout << "���� ������ ȣ�� ����, count : " << callCountCopyConstructor << std::endl;
	}*/

private:
	int* ptr;

	volatile static size_t callCountConstructor;
	volatile static size_t callCountCopyConstructor;
	volatile static size_t callCountDestructor;
};

volatile size_t myclass::callCountCopyConstructor = 0;
volatile size_t myclass::callCountConstructor = 0;
volatile size_t myclass::callCountDestructor = 0;

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	////func();

	//UVector<myclass> vec = {};

	//vec.reserve(3);

	//for (size_t i = 0; i < 100; ++i)
	//{
	//	vec.push_back(myclass());
	//	std::cout << "i : " << i << std::endl;
	//}

	//return 0;



	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//func();

	std::vector<myclass> vec = {};

	// vec.reserve(1);

	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << "i : " << i << " (for�� ���� ����)" << std::endl;
		vec.push_back(myclass());
		printf_s("i : %d, vec.size : %d, vec.capacity : %d \n", i, vec.size(), vec.capacity());
	}

	std::cout << "main �Լ� ����" << std::endl;
	return 0;
}