//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
//
//
//
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */

class Solution {
	public:
	    ListNode* removeElements(ListNode* head, int val) {
			ListNode* lst = new ListNode(0);
			lst->next = head;
			ListNode* node = lst;
			while (NULL != node->next)
			{
				if (node->next->val == val)
				{
					node->next = node->next->next;
				}
				else 
				{
					node = node->next;  
				}
			}
			head = lst->next;
			delete lst;
			return head;
		}
};
