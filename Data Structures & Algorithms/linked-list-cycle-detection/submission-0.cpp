/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        //Edge case
        if (head == nullptr || head->next == nullptr) 
        {
            return false;
        }
        ListNode *slow = head; // The "tortoise"
        ListNode *fast = head; // The "hare"

        while (fast != nullptr && fast->next != nullptr) 
        {
            // Move slow pointer by one step.
            slow = slow->next;
            
            // Move fast pointer by two steps.
            fast = fast->next->next;

            // If the pointers meet, we have found a cycle.
            if (slow == fast) 
            {
                return true;
            }
        }


        return false;
    }
};
