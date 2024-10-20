#pragma once

#define INNER_CLASS

using T1 = int;
using T2 = float;
//template<typename T1, typename T2>
class MyMap
{
public:
	INNER_CLASS class MyPair;
	INNER_CLASS class MyNode;
	INNER_CLASS class Iterator;
public:
	MyMap()
		: RootNode(nullptr)
		, DataCount(0)
	{}
	~MyMap()
	{
		clear();
	}
private:
	MyNode* RootNode;
	size_t DataCount;

public:
	Iterator find(T1 _key)
	{
		// TODO. ���Ҹ� ã�� �ڵ�
	}
	bool insert(MyPair _newData)
	{
		MyNode* CreateNode = new MyNode(_newData);
		MyNode* CurNode = RootNode;

		if (RootNode == nullptr)
		{
			RootNode = CreateNode;
		}
		else if (CurNode == nullptr)
		{
			
		}
		else if
		{
			
		}

		// 1. �����Ͱ� �ϳ��� ������ (RootNode�� nullptr�� ��)
		// 1-1. ���ο� ��带 �����ϰ� RootNode�� ���ο� ���� ����
		//
		// 2. �����Ͱ� 1�� �̻� ������ ��
		// 2-1. ���� ������ ����� key�� ���� ����� key ���� ������ ��尡 ���� �� �� -> ��带 ������ �ʰ� false return
		// 2-2. ���� ������ ����� key���� ���� ����� key ������ ���� �� -> LeftChild�� �̵� �� 2�� �ݺ�
		// 2-3. ���� ������ ����� key���� ���� ����� key ������ Ŭ �� -> RightChild�� �̵� �� 2�� �ݺ�
		// 2-4. �̵��� ��尡 nullptr�϶� -> CreateNode�� Parent�� ���� ���� ����, ���� ����� Left Ȥ�� RightChild�� ���� CreateNode�� ����
		

		++DataCount;
		return true;
	}
	Iterator erase(Iterator _iter)
	{
		// TODO. ���Ҹ� �����ϴ� �ڵ�
	}
	void clear()
	{
		// TODO. ��� ���Ҹ� �����ϴ� �ڵ�
	}
private:

public:
	INNER_CLASS
	class Iterator
	{
	public:
		Iterator(MyMap* _list, MyNode* _node)
			: Owner(_list)
			, Indicate(_node)
		{}

	private:
		MyMap* Owner;
		MyNode* Indicate;

	public:
		Iterator& operator=(const Iterator& _other)
		{
			Owner = _other.Owner;
			Indicate = _other.Indicate;
		}
		bool operator==(const Iterator& _other)
		{
			if (Owner == _other.Owner && Indicate == _other.Indicate)
				return true;
			return false;
		}
		bool operator!=(const Iterator& _other)
		{
			return !(*this == _other);
		}
		MyPair& operator*()
		{
			return Indicate->Data;
		}
		MyPair* operator->()
		{
			return &Indicate->Data;
		}
		Iterator& operator++()
		{
			// TODO.
		}
		Iterator operator++(int)
		{
			Iterator Temp = *this;
			++(*this);
			return Temp;
		}
		Iterator& operator--()
		{
			// TODO.
		}
		Iterator operator--(int)
		{
			Iterator Temp = *this;
			--(*this);
			return Temp;
		}
	};

public:
	INNER_CLASS
	class MyPair
	{
	public:
		MyPair(T1 _first, T2 _second)
			: first(_first)
			, second(_second)
		{}

	public:
		T1 first;
		T2 second;
	};
private:
	INNER_CLASS
	class MyNode
	{
		friend class MyMap;
		friend class Iterator;
	private:
		MyNode(MyPair _data)
			: Data(_data)
			, Parent(nullptr)
			, LeftChild(nullptr)
			, RightChild(nullptr)
		{}

	private:
		MyPair Data;
		MyNode* Parent;
		MyNode* LeftChild;
		MyNode* RightChild;
	};
};