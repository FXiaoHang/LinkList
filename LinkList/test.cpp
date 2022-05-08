#include"test.h"
#include"LinkList.h"
/*void test(int& x) {
	for (int i = 1; i <= 200; i++) {
		if ((i - 1) % 2 == 0 && (i - 1) % 3 == 0 && (i - 1) % 4 == 0 && (i - 1) % 6 == 0 && i % 11 == 0) {
			x = i;
			cout << x << endl;
		}
	}
}*/
void testDeleteNode()
{
	LNode* L;
	InitList_head(L);
	for (int i = 0; i < 4; i++)
	{
		L->data = i;
		L = L->next;
	}



}