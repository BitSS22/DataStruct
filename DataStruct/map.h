#pragma once

#define INNER_CLASS

using T1 = int;
using T2 = int;
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
		MyNode* CurIndicateNode = RootNode;

		while (CurIndicateNode != nullptr)
		{
			if (_key == CurIndicateNode->Data.first)
				return Iterator(this, CurIndicateNode);
			else if (_key < CurIndicateNode->Data.first)
				CurIndicateNode = CurIndicateNode->LeftChild;
			else
				CurIndicateNode = CurIndicateNode->RightChild;
		}

		return end();
	}
	bool insert(MyPair _newData)
	{
		// TODO. ���Ҹ� �����ϴ� �ڵ�
		MyNode* CurIndicateNode = RootNode;

		if (CurIndicateNode == nullptr)
			RootNode = new MyNode(_newData);
		else
		{
			MyNode* PrevIndicateNode = CurIndicateNode;
			bool IsLeft = true;

			while (CurIndicateNode != nullptr)
			{
				PrevIndicateNode = CurIndicateNode;

				if (_newData.first == CurIndicateNode->Data.first)
					return false;
				else if (_newData.first < CurIndicateNode->Data.first)
				{
					CurIndicateNode = CurIndicateNode->LeftChild;
					IsLeft = true;
				}
				else
				{
					CurIndicateNode = CurIndicateNode->RightChild;
					IsLeft = false;
				}
			}

			MyNode* CreateNode = new MyNode(_newData);

			CreateNode->Parent = PrevIndicateNode;
			if (IsLeft == true)
				PrevIndicateNode->LeftChild = CreateNode;
			else
				PrevIndicateNode->RightChild = CreateNode;
		}

		++DataCount;
		return true;

		// 1. �����Ͱ� �ϳ��� ������ (RootNode�� nullptr�� ��)
		// 1-1. ���ο� ��带 �����ϰ� RootNode�� ���ο� ���� ����
		//
		// 2. �����Ͱ� 1�� �̻� ������ ��
		// 2-1. ���� ������ ����� key�� ���� ����� key ���� ������ ��尡 ���� �� �� -> ��带 ������ �ʰ� false return
		// 2-2. ���� ������ ����� key���� ���� ����� key ������ ���� �� -> LeftChild�� �̵� �� �ݺ�
		// 2-3. ���� ������ ����� key���� ���� ����� key ������ Ŭ �� -> RightChild�� �̵� �� �ݺ�
		// 2-4. �̵��� ��尡 nullptr�϶� -> CreateNode�� Parent�� ���� ���� ����, ���� ����� LeftChild Ȥ�� RightChild�� ���� CreateNode�� ����
	}
	Iterator erase(Iterator _iter)
	{
		// TODO. ���Ҹ� �����ϴ� �ڵ�
	}
	void clear()
	{
		// TODO. ��� ���Ҹ� �����ϴ� �ڵ�
	}
	Iterator begin()
	{
		return Iterator(this, nullptr);
		// TODO. ù��° ���Ҹ� �����ϴ� ���ͷ����� �ۼ�
	}
	Iterator end()
	{
		return Iterator(this, nullptr);
	}
private:

public:
	INNER_CLASS
	class Iterator
	{
	public:
		Iterator(MyMap* _map, MyNode* _node)
			: Owner(_map)
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
			return *this;
		}
		bool operator==(const Iterator& _other) const
		{
			if (Owner == _other.Owner && Indicate == _other.Indicate)
				return true;
			return false;
		}
		bool operator!=(const Iterator& _other) const
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