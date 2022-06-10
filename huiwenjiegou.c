//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。


//解题思路 寻找中间结点 将后半部分反转过来，与前半部分比较 相同即为回文结构
#include<stdio.h>
#include<stdlib.h>
 struct ListNode 
 {
      int val;
     struct ListNode *next;
 };
 
void ListDestroy(struct ListNode** tmp)
{
	struct ListNode* cur=*tmp;
	while(cur)
	{
		*tmp=(*tmp)->next;
		free(cur);
		cur=(*tmp);
	}
}
int chkPalindrome(struct ListNode* A)
{
	struct ListNode* cur=A;
	struct ListNode* slow=A;
	struct ListNode* fast=A;
	struct ListNode* mid=NULL;
	struct ListNode* newnode;
	struct ListNode* headback=NULL;
	struct ListNode* tmp=NULL;
	while(fast&&fast->next)//利用快慢指针 找到中间结点
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	mid=slow;
	// 反转后半段链表
	while(slow)
	{
		tmp=slow->next;//存下一个第地址
		slow->next=headback;//头插
		headback=slow;
		slow=tmp;
	}


	while(cur!=mid)//当前半段走到mid节点时 停止判断
	{
		if(cur->val!=headback->val)
		{
			return 0;
		}
		cur=cur->next;
		headback=headback->next;
	}
	return 1;
}
int main()
{
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
	int tmp;
	int x;
	n1->val=1;
	n2->val=2;
	n3->val=4;
	n4->val=3;
	n5->val=2;
	n6->val=1;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	tmp=chkPalindrome(n1);
	if(tmp==1)
		printf("是回文结构");
	else printf("不是回文结构");
	ListDestroy(&n1);
	return 0;
}