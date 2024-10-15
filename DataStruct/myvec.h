#pragma once
#include <assert.h>

template<typename DataType>
class UVector
{
public:
	~UVector()
	{
		if (nullptr != Datas)
		{
			delete[] Datas;
			Datas = nullptr;
		}
	}

	void reserve(size_t _capacity)
	{
		printf_s("������ �� �Ҵ� ����\n");

		if (CapacityValue > _capacity)
		{
			return;
		}

		DataType* PrevData = Datas;

		Datas = new DataType[_capacity];

		if (nullptr != PrevData)
		{
			// ���� �����͸� ��������� �Ѵ�.
			for (size_t i = 0; i < SizeValue; i++)
			{
				Datas[i] = PrevData[i];
			}

			delete[] PrevData;
			PrevData = nullptr;
		}

		CapacityValue = _capacity;

		printf_s("������ �� �Ҵ� ����\n");
	}

	size_t capacity() const
	{
		return CapacityValue;
	}

	size_t size() const
	{
		return SizeValue;
	}

	void claer()
	{
		SizeValue = 0;
	}

	void push_back(DataType _Data)
	{
		//if (sizevalue + 1 > capacityvalue)
		//{
		//	// ��Ȯ������ �𸣰ڽ��ϴ�.
		//	reserve(capacityvalue * 1.5);
		//}

		if (SizeValue >= CapacityValue)
		{
			size_t value = CapacityValue * 2 <= 0 ? 1 : CapacityValue * 2;
			reserve(value);
		}

		// ���� ������ �ȳ��ϴ�.
		// �׷��� ���鶧�� Typedef DataType���� ����°ɼ�ȣ�մϴ�.
		// _Data->B;

		Datas[SizeValue] = _Data;

		++SizeValue;
	}

	DataType& operator[](size_t _index)
	{
		if (SizeValue <= _index)
		{
			assert(false);
		}

		return Datas[_index];
	}


private:
	DataType* Datas = nullptr;
	size_t CapacityValue = 0;
	size_t SizeValue = 0;
};

