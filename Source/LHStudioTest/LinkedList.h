// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

template <class ElementType>
class Node {

public:
	ElementType Data;
	//Node* PrevNode = nullptr;
	Node<ElementType>* NextNode = nullptr;
};
/**
 * 
 */
template <class ElementType>
class LHSTUDIOTEST_API LinkedList
{
public:
	LinkedList() 
	{
		HeadNode = nullptr;
		ListSize = 0;
	};
	~LinkedList() {};

public:
	bool Add(ElementType Item);
	bool Insert(int32 Index, ElementType Item);
	bool Delete(int32 Index);
	bool Replace(int32 Index, ElementType Item);
	int32 FindIndex(ElementType Item);
	void Print();
	int32 Num();

private:
	Node<ElementType>* HeadNode;
	int32 ListSize;
};

template <class ElementType>
bool LinkedList<ElementType>::Insert(int32 Index, ElementType Item)
{
	if (Index >= ListSize)
	{
		Add(Item);
		return true;
	}

	Node<ElementType>* New = new Node<ElementType>;
	New->Data = Item;
	New->NextNode = nullptr;



	Node<ElementType>* PrevNode = nullptr;
	auto CurrentNode = HeadNode;

	for (int32 CurrentIndex = 0; ; CurrentIndex++)
	{
		if (CurrentIndex < Index)
		{
			PrevNode = CurrentNode;
			CurrentNode = CurrentNode->NextNode;
			continue;
		}
		else if (CurrentIndex == Index)
		{
			if (!HeadNode || Index == 0)
			{
				New->NextNode = HeadNode;
				HeadNode = New;
				ListSize += 1;
				break;
			}

			if(PrevNode)
				PrevNode->NextNode = New;
			New->NextNode = CurrentNode->NextNode;
			break;
		}
	}
	return true;
}

template <class ElementType>
bool LinkedList<ElementType>::Add(ElementType Item)
{
	Node<ElementType> *New = new Node<ElementType>;
	New->Data = Item;
	New->NextNode = nullptr;
	if (!HeadNode)
	{
		HeadNode = New;
		ListSize = 1;
		return true;
	}
	auto CurrentNode = HeadNode;
	for (int32 CurrentIndex = 0; ; CurrentIndex++)
	{
		if (CurrentIndex < ListSize - 1)
		{
			CurrentNode = CurrentNode->NextNode;
			continue;
		}
		CurrentNode->NextNode = New;
		break;
	}
	ListSize += 1;
	return true;
}

template <class ElementType>
bool LinkedList<ElementType>::Delete(int32 Index)
{
	if (ListSize == 0 || !HeadNode)
		return false;

	if (Index > ListSize)
		return false;

	Node<ElementType>* PrevNode = nullptr;
	Node<ElementType>* CurrentNode = HeadNode;
	for (int32 CurrentIndex = 0; ; CurrentIndex++)
	{
		if (CurrentIndex < Index)
		{
			PrevNode = CurrentNode;
			CurrentNode = CurrentNode->NextNode;
			continue;
		}
		else if (CurrentIndex == Index)
		{
			if (PrevNode)
			{
				PrevNode->NextNode = nullptr;
				if (CurrentNode->NextNode)
					PrevNode->NextNode = CurrentNode->NextNode;
			}
			if (CurrentIndex == 0)
			{
				if (HeadNode->NextNode)
					HeadNode = HeadNode->NextNode;
			}
			delete CurrentNode;
			ListSize -= 1;
			break;
		}
	}
	return true;
}

template <class ElementType>
bool LinkedList<ElementType>::Replace(int32 Index, ElementType Item)
{
	if (Delete(Index))
	{
		if (Insert(Index, Item))
			return true;
	}
	return false;
}

template <class ElementType>
int32 LinkedList<ElementType>::FindIndex(ElementType Item)
{
	if (!HeadNode)
		return 0;
	int32 CurrentIndex = 0;
	auto CurrentNode = HeadNode;
	while (CurrentNode)
	{
		if (CurrentNode->Data == Item)
			return CurrentIndex;
		else
			CurrentNode = CurrentNode->NextNode;
		CurrentIndex += 1;
	}
	return 0;
}

template <class ElementType>
int32 LinkedList<ElementType>::Num()
{
	return ListSize;
}

template <class ElementType>
void LinkedList<ElementType>::Print()
{
	if (!HeadNode)
		return;
	auto CurrentNode = HeadNode;
	for (int32 i = 0; i < ListSize; i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Index : %d, Address : %p"), i, CurrentNode);
		if (CurrentNode->NextNode)
			CurrentNode = CurrentNode->NextNode;
	}
}
