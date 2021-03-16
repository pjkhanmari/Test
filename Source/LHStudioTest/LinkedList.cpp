// Fill out your copyright notice in the Description page of Project Settings.


#include "LinkedList.h"

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
	;
	for (int32 CurrentIndex = 0; ; CurrentIndex++)
	{
		if (CurrentIndex < ListSize - 1)
		{
			CurrentNode = CurrentNode->GetNextLink();
			continue;
		}
		CurrentNode->SetNextLink(New);
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

	Node<ElementType>* CurrentNode = HeadNode;
	for (int32 CurrentIndex = 0; ; CurrentIndex++)
	{
		if (CurrentIndex < Index - 1)
		{
			CurrentNode = CurrentNode->GetNextLink();
			continue;
		}
		else if (CurrentIndex == Index - 1)
		{
			delete CurrentNode->GetNextLink();
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
		if(Add(Item))
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
			CurrentNode = CurrentNode->GetNextLink();
		CurrentIndex += 1;
	}
	return 0;
}

template <class ElementType>
int32 LinkedList<ElementType>::Num()
{
	return ListSize;
}