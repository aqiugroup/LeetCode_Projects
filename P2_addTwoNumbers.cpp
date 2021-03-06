/*
给出两个非空的链表用来表示两个非负的整数。其中,它们各自的位数是按照逆序的方式存储的，
并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *head = new ListNode(0), *curr = head;
		while (l1 != NULL || l2 != NULL) {
			int x = (l1 == NULL) ? 0 : l1->val;
			int y = (l2 == NULL) ? 0 : l2->val;
			int sum = x + y + carry;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (l1 != NULL)l1 = l1->next;
			if (l2 != NULL)l2 = l2->next;
		}
		if (carry > 0)curr->next = new ListNode(carry);
		return head->next;
	}
};