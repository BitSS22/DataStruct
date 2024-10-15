#include <vector>
// #include "vector.h"
#include <crtdbg.h>
#include "myvec.h"
#include <iostream>


//class myclass
//{
//public:
//	myclass()
//		: ptr(nullptr)
//	{
//		std::cout << "������ ȣ�� ����" << std::endl;
//
//		ptr = new int;
//
//		++callCountConstructor;
//
//		std::cout << "������ ȣ�� ����, count : " << callCountConstructor << std::endl;
//	}
//	~myclass()
//	{
//		std::cout << "�Ҹ��� ȣ�� ����" << std::endl;
//
//		if (ptr != nullptr)
//		{
//			delete ptr;
//			ptr = nullptr;
//		}
//
//		++callCountDestructor;
//
//		std::cout << "�Ҹ��� ȣ�� ����, count : " << callCountDestructor << std::endl;
//	}
//
//	myclass(const myclass& other)
//	{
//		ptr = new int;
//	}
//
//	// ���� ������
//	myclass(const myclass& other)
//	{
//		if (other.ptr != nullptr)
//		{
//			ptr = new int(*other.ptr); // ���� ����
//		}
//		else
//		{
//			ptr = nullptr;
//		}
//	}
//
//	myclass& operator=(const myclass& other)
//	{
//		ptr = new int;
//
//		return *this;
//	}
//
//	myclass& operator=(const myclass& other)
//	{
//		if (this != &other)
//		{
//			delete ptr; // ���� �޸� ����
//			if (other.ptr != nullptr)
//			{
//				ptr = new int(*(other.ptr)); // ���� ����
//			}
//			else
//			{
//				ptr = nullptr;
//			}
//		}
//
//		return *this;
//	}
//
//private:
//	int* ptr;
//
//	static size_t callCountConstructor;
//	static size_t callCountCopyConstructor;
//	static size_t callCountDestructor;
//};
//
//
//class myclass
//{
//public:
//	myclass() : ptr(nullptr) {
//		std::cout << "������ ȣ�� ����" << std::endl;
//		++callCountConstructor;
//		std::cout << "������ ȣ�� ����, count : " << callCountConstructor << std::endl;
//	}
//
//	~myclass() {
//		std::cout << "�Ҹ��� ȣ�� ����" << std::endl;
//		if (ptr != nullptr) {
//			delete ptr;
//			ptr = nullptr;
//		}
//		++callCountDestructor;
//		std::cout << "�Ҹ��� ȣ�� ����, count : " << callCountDestructor << std::endl;
//	}
//
//	// ���� ������
//	myclass(const myclass& other) {
//		std::cout << "���� ������ ȣ��" << std::endl;
//		if (other.ptr != nullptr) {
//			ptr = new int(*other.ptr); // ���� ����
//		}
//		else {
//			ptr = nullptr;
//		}
//		++callCountCopyConstructor;
//		std::cout << "���� ������ ȣ�� ����, count : " << callCountCopyConstructor << std::endl;
//	}
//
//	// �̵� ������
//	myclass(myclass&& other) noexcept : ptr(other.ptr) {
//		other.ptr = nullptr; // �̵� �� ���� ��ü�� �����͸� nullptr�� ����
//		std::cout << "�̵� ������ ȣ��" << std::endl;
//	}
//
//	myclass& operator=(const myclass& other) {
//		std::cout << "���� �Ҵ� ������ ȣ��" << std::endl;
//
//		if (this != &other) { // �ڱ� �ڽŰ��� ���� ����
//			delete ptr; // ���� �޸� ����
//			if (other.ptr != nullptr) {
//				ptr = new int(*other.ptr); // ���� ����
//			}
//			else {
//				ptr = nullptr;
//			}
//		}
//		return *this;
//	}
//
//	// �̵� �Ҵ� ������
//	myclass& operator=(myclass&& other) noexcept {
//		std::cout << "�̵� �Ҵ� ������ ȣ��" << std::endl;
//
//		if (this != &other) { // �ڱ� �ڽŰ��� ���� ����
//			delete ptr; // ���� �޸� ����
//			ptr = other.ptr; // ���ҽ� �̵�
//			other.ptr = nullptr; // �ٸ� ��ü�� �� �̻� �������� ����
//		}
//		return *this;
//	}
//
//private:
//	int* ptr;
//	static size_t callCountConstructor;
//	static size_t callCountCopyConstructor;
//	static size_t callCountDestructor;
//};
//
//size_t myclass::callCountCopyConstructor = 0;
//size_t myclass::callCountConstructor = 0;
//size_t myclass::callCountDestructor = 0;


class myclass
{
public:
	myclass()
		:ptr(nullptr)
	{
		ptr = new int;
		*ptr = 100;
	}
	~myclass()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}

	myclass(const myclass& other)
	{
		ptr = new int(*(other.ptr));
	}

	myclass& operator=(const myclass& other)
	{
		ptr = new int(*(other.ptr));
		return *this;
	}

private:
	int* ptr;
};

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









	//std::vector<myclass> vec = {};

	UVector<myclass> vec = {};

	






	
	
	// vec.reserve(1);
	// vec.reserve(2);
	// vec.reserve(3);
	// vec.reserve(4);
	// vec.reserve(5);
	// vec.reserve(6);
	// vec.reserve(7);


	for (size_t i = 0; i < 100; ++i)
	{
		std::cout << "i : " << i << " (for�� ���� ����)" << std::endl;
		vec.push_back(myclass());
		printf_s("i : %d, vec.size : %d, vec.capacity : %d \n\n", i, vec.size(), vec.capacity());
	}

	std::cout << "main �Լ� ����" << std::endl;
	return 0;
}