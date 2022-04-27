#include"LinkList.h"


//初始化一个空的单链表，不带头结点
bool InitList(LinkList& L) 
{
	L =NULL ;//空表，暂时没有任何结点
	return true;

}
//初始化一个空的单链表，带头结点
bool InitList_head(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
	if (L == NULL)//内存不足，分配失败
		return false;
	L->next = NULL;
	return true;
}

//判断单链表是否为空
bool Empty(LinkList L)
{
	return(L == NULL);
}

//按位序插入(带头结点)
bool ListInsert(LinkList& L, int i, ElemType e) 
{
	if (i < 1)//i范围错误
		return false;
	LNode* p;//指针p指向当前扫描到的结点
	int j = 0;//当前p指向的是第几个结点
	p = L;//L指向头结点，头结点是第0个结点(不含数据)
	while (p != NULL && j < i - 1)//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//i值不合法
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//申请一个结点
	s->data = e;
	s->next = p->next;
	p->next = s;//将结点s连接p之后
	return true;//插入成功
}

//按位序插入(不带头结点)
bool Listinsert(LinkList& L, int i, ElemType e)
{
	if (i < 1)//i值非法
		return false;
	if (i == 1) //插入第1个结点的操作和其他结点操作不同
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));//申请一个结点
		s->data = e;
		s->next =L;
		L = s;//将结点s连接p之后
		return true;//插入成功
	}
	LNode* p;//指针p指向当前扫描到的结点
	int j = 1;//当前p指向的是第几个结点
	p = L;//L指向头结点，头结点是第0个结点(不含数据)
	while (p != NULL && j < i - 1)//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//i值不合法
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//申请一个结点
	s->data = e;
	s->next = p->next;
	p->next = s;//将结点s连接p之后
	return true;//插入成功
}

//后插操作；在p结点后插入元素e
bool InsertNextNode(LNode* p, ElemType e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode* p, ElemType e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//内存分配失败
		return false;
	s->next = p->next;
	p->next = s;//新结点s连接到p之后
	s->data = p->data;//将p中元素复制到s中
	p->data = e;//p中元素覆盖为e
	return 0;
}

//前插操作：在p结点之前插入结点s
bool InsertPriorNode(LNode* p, LNode* s)
{
	if (p == NULL && s == NULL)
		return false;
	s->next = p->next;
	p->next = s;//s连到p之后
	ElemType temp = p->data;//交换数据域部分
	p->data = s->data;
	s->data = temp;
	return true;
}

//删除操作：删除L中第i个位置的元素，并用e返回删除元素的值
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	if (i < 1)
		return false;
	LNode* p;//指针p指向当前扫描到的结点
	int j = 0;//当前p指向的是第几个结点
	p = L;//L指向头结点，头结点是第0个结点
	while (p != NULL && j < i - 1)//循环找到第i-1个结点
	{
		p->next;
		j++;
	}
	if (p == NULL)//i值不合法
		return false;
	if(p->next==NULL)//第i-1个结点之后已无其他结点
		return false;
	LNode* q = p->next;//令q指向删除的结点
	e = q->data;//数据保存到e中
	p->next = q->next;//将*q断开
	free(p);//释放p
	return true;//删除成功
}

//删除指定结点p
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true;
}

bool PrintList(LNode* L)
{
	while (L != NULL )//循环找到第i-1个结点
	{
		L = L->next;
		cout << L->data << endl;
	}
	return true;
}
