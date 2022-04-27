#include"LinkList.h"


//��ʼ��һ���յĵ���������ͷ���
bool InitList(LinkList& L) 
{
	L =NULL ;//�ձ���ʱû���κν��
	return true;

}
//��ʼ��һ���յĵ�������ͷ���
bool InitList_head(LinkList& L)
{
	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	if (L == NULL)//�ڴ治�㣬����ʧ��
		return false;
	L->next = NULL;
	return true;
}

//�жϵ������Ƿ�Ϊ��
bool Empty(LinkList L)
{
	return(L == NULL);
}

//��λ�����(��ͷ���)
bool ListInsert(LinkList& L, int i, ElemType e) 
{
	if (i < 1)//i��Χ����
		return false;
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;//��ǰpָ����ǵڼ������
	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ�����
	s->data = e;
	s->next = p->next;
	p->next = s;//�����s����p֮��
	return true;//����ɹ�
}

//��λ�����(����ͷ���)
bool Listinsert(LinkList& L, int i, ElemType e)
{
	if (i < 1)//iֵ�Ƿ�
		return false;
	if (i == 1) //�����1�����Ĳ�����������������ͬ
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));//����һ�����
		s->data = e;
		s->next =L;
		L = s;//�����s����p֮��
		return true;//����ɹ�
	}
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 1;//��ǰpָ����ǵڼ������
	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)//iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ�����
	s->data = e;
	s->next = p->next;
	p->next = s;//�����s����p֮��
	return true;//����ɹ�
}

//����������p�������Ԫ��e
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

//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode* p, ElemType e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//�ڴ����ʧ��
		return false;
	s->next = p->next;
	p->next = s;//�½��s���ӵ�p֮��
	s->data = p->data;//��p��Ԫ�ظ��Ƶ�s��
	p->data = e;//p��Ԫ�ظ���Ϊe
	return 0;
}

//ǰ���������p���֮ǰ������s
bool InsertPriorNode(LNode* p, LNode* s)
{
	if (p == NULL && s == NULL)
		return false;
	s->next = p->next;
	p->next = s;//s����p֮��
	ElemType temp = p->data;//���������򲿷�
	p->data = s->data;
	s->data = temp;
	return true;
}

//ɾ��������ɾ��L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	if (i < 1)
		return false;
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;//��ǰpָ����ǵڼ������
	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0�����
	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
	{
		p->next;
		j++;
	}
	if (p == NULL)//iֵ���Ϸ�
		return false;
	if(p->next==NULL)//��i-1�����֮�������������
		return false;
	LNode* q = p->next;//��qָ��ɾ���Ľ��
	e = q->data;//���ݱ��浽e��
	p->next = q->next;//��*q�Ͽ�
	free(p);//�ͷ�p
	return true;//ɾ���ɹ�
}

//ɾ��ָ�����p
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
	while (L != NULL )//ѭ���ҵ���i-1�����
	{
		L = L->next;
		cout << L->data << endl;
	}
	return true;
}
