// Fill out your copyright notice in the Description page of Project Settings.


#include "LinkedList.h"

template <class ElementType>
LinkedList<ElementType>::LinkedList()
{
	HeadNode = nullptr;
	ListSize = 0;
}

template <class ElementType>
LinkedList<ElementType>::~LinkedList()
{
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
	int32 CurrentIndex = 0;
	for (;;)
	{
		if (CurrentIndex < ListSize - 1)
		{
			CurrentNode = CurrentNode->GetNextLink();
			CurrentIndex++;
			continue;
		}
		CurrentNode->SetNextLink(New);
		break;
	}
	ListSize += 1;
	return true;
}

template <class ElementType>
void LinkedList<ElementType>::Delete(int32 Index)
{

}

template <class ElementType>
void LinkedList<ElementType>::Replace(int32 Index, ElementType Item)
{

}

template <class ElementType>
void LinkedList<ElementType>::Find(ElementType Item)
{

}