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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = slow->next; 
        slow->next = nullptr;

        ListNode* curr = secondHead;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* nx = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = nx;
        }
        secondHead = prev;

        ListNode* p1 = head;
        ListNode* p2 = secondHead;

        while(p2 != nullptr){
            ListNode* p1_next = p1->next;
            ListNode* p2_next = p2->next;

            p1->next = p2;
            p2->next = p1_next;

            p1 = p1_next;
            p2 = p2_next ;
        }
    }
};
