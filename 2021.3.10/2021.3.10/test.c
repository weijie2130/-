#include<stdio.h>
#include<stdlib.h>


typedef int LDataType;
//双向节点
typedef struct ListNode
{
	LDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
} ListNode;

//双向带头循环链表
typedef struct List
{
	struct ListNode* _head;
	
} List;
void initList(List* lst)
{
	//空的双向带头循环链表
	//构建循环结构 
	//创建头节点
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//循环
	lst->_head->_prev = lst->_head->_next = lst->_head;
}

struct ListNode* creatNode(LDataType val)
{
	struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}

//尾节点：head->_prev
//尾插(o(1))
void listPushBack(List* lst, LDataType val)
{
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* newNode = creatNode(val);

	//head  ..... tail  newNode
	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;

}
//尾删(o(1))
void listPopBack(List* lst)
{
	if (lst->_head->_prev == lst->_head)
		return;//空链表
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* prev =tail->_prev;

	free(tail);

	prev->_next = lst->_head;
	lst->_head->_prev = prev;
	
}
void printList(List* lst)
{
	struct ListNode* cur = lst->_head->_next;
	while (cur!= lst->_head)
	{
		printf("%d", cur->_data);
		cur =cur->_next;
	}
	printf("\n");
}

//头插：插在头的下一个位置

void listPushFront(List* lst, LDataType val)
{
	struct ListNode* newNode = creatNode(val);

	struct ListNode* next = lst->_head->_next;

	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	newNode->_next = next;
	next->_prev = newNode;
}
//头删
void listPopFront(List* lst)
{
	if (lst->_head->_prev == lst->_head)
		return;//空链表
	struct ListNode* next = lst->_head->_next;
	struct ListNode* nextnext = next->_next;
	//head next nextnext
	free(next);
	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;
	
}
//头插：insert(head->next,val)
//尾插：insert(head,val)
//新的数据放在当前节点的前面
void listInsert(ListNode* node, LDataType val)
{
	struct ListNode* newNode = creatNode(val);
	struct ListNode* prev = node->_prev;

	node->_prev = newNode;
	newNode->_next = node;

	prev->_next = newNode;
	newNode->_prev = prev;
}
void listErase(ListNode* node)
{
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;
	free(node);
	next->_prev = prev;
	prev->_next = next;
}
void listDestroy(List* lst)
{
	struct ListNode* cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		struct ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
void ListFind(List* lst, LDataType x)
{
	while (lst->_head)
	{
		if (lst->_head == x)
		{
			return lst->_head;
		}
		lst->_head = lst->_head->_next;
	}
}

void test()
{
	struct List lst;
	initList(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);


	printList(&lst);
}
int main()
{
	test();
	
	return 0;
}