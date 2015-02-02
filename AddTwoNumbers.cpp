/**
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 * Definition for singly-linked list.
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode * result = new ListNode(0);
		ListNode * FinalResult = result;
		ListNode * ll = l1;
		ListNode * rl = l2;
		while (ll != NULL || rl != NULL)	
		{
			if (ll != NULL)	
				result->val += ll->val;
			if (rl != NULL)	
				result->val += rl->val;

			if (result->val >= 10)
			{
				int tmp = result->val; 
				result->val = tmp % 10;
				result->next = new ListNode(tmp/10);
			}


			if (ll == NULL && rl == NULL)
				break;

			if (ll)
				ll = ll->next != NULL ? ll->next : NULL;
			if (rl)
				rl = rl->next != NULL ? rl->next : NULL;

			if (result->next == NULL && (ll || rl))
				result->next = new ListNode(0);
			result = result->next;
		}
		return FinalResult;
    }

	ListNode* createList(const vector<int> & list)
	{
		ListNode* lst = new ListNode(0);
		ListNode* fistNode = lst;
		for (size_t i = 0; i<list.size(); ++i)
		{
			lst->val = list.at(i);
			if (list.size() == i+1)
			{
				lst->next = NULL;
				break;
			}
			else 
			{
				lst->next = new ListNode(0);
				lst = lst->next;
			}
		}

		return fistNode;
	}
};

int main()
{
	Solution s;
	// vector<int> Initialization list c++11 
	vector<int> a{2,4,3};
//	a.push_back(2);
//	a.push_back(4);
//	a.push_back(3);

	vector<int> b{ 5,6,4};
//	b.push_back(5);
//	b.push_back(6);
//	b.push_back(4);
	ListNode* l1 = s.createList(a);	
	ListNode* l2 = s.createList(b);	
	ListNode* l3 = s.addTwoNumbers(l1, l2);
	
	while (l3 != NULL)
	{
		cout << l3->val ; 
		if (l3->next != NULL)
			cout << " -> "; 

		l3 = l3->next;
	}
	cout << endl;
	return 0;
}
