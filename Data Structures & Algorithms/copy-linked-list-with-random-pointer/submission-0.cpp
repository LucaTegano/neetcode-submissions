/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> old_to_new;

        // making the base of the list
        //{3:3,7:7,4:4}
        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        // put the next and random
        //{3:null}, {7,3}
        curr = head;
        while (curr) {
            Node* new_node = old_to_new[curr];
            if (curr->next) {
                new_node->next = old_to_new[curr->next];
            } else {
                new_node->next = nullptr;
            }

            if (curr->random) {
                new_node->random = old_to_new[curr->random];
            } else {
                new_node->random = nullptr;
            }
            curr = curr->next;
        }
        return old_to_new[head];
    }
};
