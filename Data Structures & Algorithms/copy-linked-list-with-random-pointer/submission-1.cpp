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
        // 6 steps
        // base case
        if (!head) {
            return nullptr;
        }
        // 1 inizialing a unorderd_map of Nodes to store both the val and random and next with O(1)
        // access
        unordered_map<Node*, Node*> old_new;
        Node* curr = head;  // make a copy of head
        // 2 stating to put the vals,if we put vals,random and next at the same time we would get
        // error because the list is not entirely created and we would point to something that does
        // not exist
        while (curr) {
            old_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        // 3 reset curr to make another while for putting random and next
        curr = head;
        // 4 We take the new Nodes and we add them next and random from the curr,because the key of
        // old_new is indeed the actual origni nodes
        while (curr) {
            // getting the right Node for putting the right random and next
            Node* new_node = old_new[curr];
            new_node->next = old_new[curr->next];

            new_node->random = old_new[curr->random];
            curr = curr->next;
        }
        return old_new[head];
    }
};
