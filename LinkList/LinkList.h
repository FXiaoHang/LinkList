#ifndef _LinkList_h
#define _LinkList_h

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define ElemType int

typedef struct LNode {//���嵥����ڵ�����
	ElemType data;//ÿ���ڵ���һ������Ԫ��
	struct LNode* next;//ָ��ָ����һ���ڵ�
}LNode,*LinkList;
//LNde *L;����һ��ָ�������һ���ڵ��ָ��
//LinkList L;����һ��ָ�������һ���ڵ��ָ��

bool InitList(LinkList& L);//��ʼ��һ���յĵ���������ͷ���
bool InitList_head(LinkList& L);//��ʼ��һ���յĵ�������ͷ���
bool Empty(LinkList L);//�ж������Ƿ�Ϊ��
bool ListInsert(LinkList& L, int i, ElemType e);//��λ�����(��ͷ���)��ƽ��ʱ�临�Ӷ�O(n)
bool Listinsert(LinkList& L, int i, ElemType e);//��λ�����(����ͷ���)
bool InsertNextNode(LNode* p, ElemType e);//����������p�������Ԫ��e
bool InsertPriorNode(LNode* p, ElemType e);//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode* p, LNode* s);//ǰ���������p���֮ǰ������s
bool ListDelete(LinkList& L, int i, ElemType &e);//ɾ������(��ͷ���)��ɾ��L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ
bool DeleteNode(LNode* p);//ɾ��ָ�����p
bool PrintList(LNode* L);
#endif

