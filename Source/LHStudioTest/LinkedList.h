// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

template <class ElementType>
class Node {

public:
	FORCEINLINE Node* GetNextLink() { return NextNode; };
	FORCEINLINE void SetNextLink(Node* node) { NextNode = node; };

private:
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
	bool Delete(int32 Index);
	bool Replace(int32 Index, ElementType Item);
	int32 FindIndex(ElementType Item);
	int32 Num();

private:
	Node<ElementType>* HeadNode;
	int32 ListSize;
};

