#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> visited;
        ListNode *p = head;
        while (p != NULL)
        {
            if (find(visited.begin(), visited.end(), p) != visited.end())
            {
                return true;
            }
            visited.push_back(p);
            p = p->next;
        }
        return false;
    }
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};