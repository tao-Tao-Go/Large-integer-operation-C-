#include "bigData.h"
#include <iostream>
using namespace std;
template<class T>
List<T>::List()     // �����캯��ʵ��
{
	root = new node;
	root->prev = NULL;
	root->next = NULL;
	length = 0;
}
template<class T>
List<T>::~List()       //������������ʵ��
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
int List<T>::insert(List *ptr, int position, T member)  //����ڵ㺯��ʵ��
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
int List<T>::erase(List* ptr, int position)   //ɾ���ڵ㺯��ʵ��
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
int List<T>::getlength(List* ptr)   //�õ����Ⱥ���ʵ��
{
	return ptr->length;
}
template<class T>
void List<T>::display(List* ptr)    //��ʾ������ʵ��
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