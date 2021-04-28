#include "bigData.h"
#include <iostream>
using namespace std;
template<class T>
List<T>::List()     // 链表构造函数实现
{
	root = new node;
	root->prev = NULL;
	root->next = NULL;
	length = 0;
}
template<class T>
List<T>::~List()       //链表析构函数实现
{
	node* p = root;
	while (root)
	{
		root = root->next;
		delete p;
		p = root;
	}
}
template<class T>
int List<T>::insert(List *ptr, int position, T member)  //插入节点函数实现
{
	node<T>* nodeinsert = new node;
	nodeinsert->data = member;
	if (ptr->getlength(ptr) == 0)
	{
		root->next = nodeinsert;
		nodeinsert->prev = root;
		nodeinsert->next = NULL;
		ptr->length++;
		return 0;
	}
	else
	{
		if (position == 0)
		{
			nodeinsert->prev = root;
			nodeinsert->next = root->next;
			root->next->prev = nodeinsert;
			root->next = nodeinsert;
			ptr->length++;
			return 0;
		}
		else
		{
			node<T>* current = root->next;
			for (int i = 0; i < position; i++)
			{
				current = current->next;
			}
			nodeinsert->next = current;
			nodeinsert->prev = current->prev;
			current->prev->next = nodeinsert;
			current->prev = nodeinsert;
			ptr->length++;
			return 0;
		}
	}
}
template<class T>
int List<T>::erase(List* ptr, int position)   //删除节点函数实现
{
	if (ptr->getlength(ptr) == 0)
	{
		return 0;
	}
	else
	{
		if (ptr->getlength(ptr) == 1)
		{
			ptr->root->next = NULL;
			ptr->length--;
		}
		else
		{
			node<T>* deletenode = root->next;
			for (int i = 0; i < position; i++)
			{
				deletenode = deletenode->next;
			}
			deletenode->prev->next = deletenode->next;
			deletenode->next->prev = deletenode->prev;
			delete deletenode;
			ptr->length--;
		}
	}
}
template<class T>
int List<T>::getlength(List* ptr)   //得到长度函数实现
{
	return ptr->length;
}
template<class T>
void List<T>::display(List* ptr)    //显示链表函数实现
{
	node<T>* current = root->next;
	int num = length;
	for (int i = 0; i < num; i++)
	{
		cout << current->data;
		current = current->next;
	}
	cout << endl;
}