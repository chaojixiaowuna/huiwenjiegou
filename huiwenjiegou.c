//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��


//����˼· Ѱ���м��� ����벿�ַ�ת��������ǰ�벿�ֱȽ� ��ͬ��Ϊ���Ľṹ
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
	while(fast&&fast->next)//���ÿ���ָ�� �ҵ��м���
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	mid=slow;
	// ��ת��������
	while(slow)
	{
		tmp=slow->next;//����һ���ڵ�ַ
		slow->next=headback;//ͷ��
		headback=slow;
		slow=tmp;
	}


	while(cur!=mid)//��ǰ����ߵ�mid�ڵ�ʱ ֹͣ�ж�
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
		printf("�ǻ��Ľṹ");
	else printf("���ǻ��Ľṹ");
	ListDestroy(&n1);
	return 0;
}