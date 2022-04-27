#ifndef _LinkList_h
#define _LinkList_h

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define ElemType int

typedef struct LNode {//定义单链表节点类型
	ElemType data;//每个节点存放一个数据元素
	struct LNode* next;//指针指向下一个节点
}LNode,*LinkList;
//LNde *L;声明一个指向单链表第一个节点的指针
//LinkList L;声明一个指向单链表第一个节点的指针

bool InitList(LinkList& L);//初始化一个空的单链表，不带头结点
bool InitList_head(LinkList& L);//初始化一个空的单链表，带头结点
bool Empty(LinkList L);//判断链表是否为空
bool ListInsert(LinkList& L, int i, ElemType e);//按位序插入(带头结点)，平均时间复杂度O(n)
bool Listinsert(LinkList& L, int i, ElemType e);//按位序插入(不带头结点)
bool InsertNextNode(LNode* p, ElemType e);//后插操作；在p结点后插入元素e
bool InsertPriorNode(LNode* p, ElemType e);//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode* p, LNode* s);//前插操作：在p结点之前插入结点s
bool ListDelete(LinkList& L, int i, ElemType &e);//删除操作(带头结点)：删除L中第i个位置的元素，并用e返回删除元素的值
bool DeleteNode(LNode* p);//删除指定结点p
bool PrintList(LNode* L);
#endif

