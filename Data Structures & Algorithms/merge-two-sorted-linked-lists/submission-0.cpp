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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         // Create a dummy node to act as the head of the new list
        ListNode* dummy = new ListNode();
        // 'current' will be our pointer to build the new list
        ListNode* current = dummy;

        // Traverse both lists until one of them is empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                // Append the smaller node from list1
                current->next = list1;
                // Move list1 pointer forward
                list1 = list1->next;
            } else {
                // Append the smaller node from list2
                current->next = list2;
                // Move list2 pointer forward
                list2 = list2->next;
            }
            // Move the current pointer to the newly added node
            current = current->next;
        }

        // At this point, one of the lists is empty.
        // Append the remaining part of the other list.
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The merged list starts after the dummy node
        ListNode* mergedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return mergedHead;
    }
};
