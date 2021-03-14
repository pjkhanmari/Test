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
	LinkedList();
	~LinkedList();

public:
	bool Add(ElementType Item);
	void Delete(int32 Index);
	void Replace(int32 Index, ElementType Item);
	void Find(ElementType Item);

private:
	Node<ElementType>* HeadNode;
	int32 ListSize;
};
