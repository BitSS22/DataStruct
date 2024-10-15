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
		std::cout << "생성자 호출 시작" << std::endl;

		ptr = new int;

		++callCountConstructor;

		std::cout << "생성자 호출 종료, count : " << callCountConstructor << std::endl;
	}
	~myclass()
	{
		std::cout << "소멸자 호출 시작" << std::endl;

		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}

		++callCountDestructor;

		std::cout << "소멸자 호출 종료, count : " << callCountDestructor << std::endl;
	}

	myclass(const myclass& other)
	{
		std::cout << "복사 생성자 호출" << std::endl;

		ptr = new int;

		++callCountCopyConstructor;

		std::cout << "복사 생성자 호출 종료, count : " << callCountCopyConstructor << std::endl;
	}

	myclass& operator=(const myclass& other)
	{
		ptr = other.ptr;

		return *this;
	}

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

	UVector<myclass*> vec = {};
	
	vec.reserve(1);
	vec.reserve(2);
	vec.reserve(3);
	vec.reserve(4);
	vec.reserve(5);
	vec.reserve(6);
	vec.reserve(7);


	for (size_t i = 0; i < 100; ++i)
	{
		std::cout << "i : " << i << " (for문 실행 시작)" << std::endl;
		myclass* ptr = new myclass();
		vec.push_back(ptr);
		printf_s("i : %d, vec.size : %d, vec.capacity : %d \n\n", i, vec.size(), vec.capacity());
	}

	std::cout << "main 함수 종료" << std::endl;
	return 0;
}