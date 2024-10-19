#pragma once
#include <iostream>

class myclass
{
public:
	myclass()
		: ptr(nullptr)
		, value(0)
	{
		std::cout << "������ ȣ��" << std::endl;

		ptr = new int;
	}
	myclass(int _value)
		: ptr(nullptr)
		, value(_value)
	{
		std::cout << "������ ȣ��" << std::endl;

		ptr = new int;
	}
	~myclass()
	{
		std::cout << "�Ҹ��� ȣ��" << std::endl;

		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
	myclass(const myclass& _other)
	{
		std::cout << "��������� ȣ��" << std::endl;

		ptr = new int(*(_other.ptr));
		value = _other.value;
	}
	myclass& operator=(const myclass& _other)
	{
		std::cout << "���� ���Կ����� ȣ��" << std::endl;

		if (ptr == nullptr)
			ptr = new int(*(_other.ptr));
		else
			*ptr = *_other.ptr;

		value = _other.value;

		return *this;
	}
	myclass(myclass&& _other) noexcept
	{
		std::cout << "�̵������� ȣ��" << std::endl;

		ptr = _other.ptr;
		value = _other.value;

		_other.ptr = nullptr;
	}
	myclass& operator=(myclass&& _other) noexcept
	{
		std::cout << "�̵� ���Կ����� ȣ��" << std::endl;

		if (this != &_other)
		{
			if (ptr != nullptr)
			{
				delete ptr;
				ptr = nullptr;
			}

			ptr = _other.ptr;
			value = _other.value;

			_other.ptr = nullptr;
		}

		return *this;
	}

	int GetValue()
	{
		return value;
	}


private:
	int* ptr;
	int value;
};

