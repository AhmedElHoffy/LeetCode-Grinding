/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // Case 1: Empty List
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;  // Circular self-loop
            return newNode;
        }

        // Case 2: Single Node List
        if (head->next == head) {
            Node* newNode = new Node(insertVal, head);
            head->next = newNode;
            return head;
        }

        // Case 3: General Case (Find Insertion Point)
        Node* curr = head;

        while (true) {

            // Insert in the correct place in sorted order
            if (curr->val <= insertVal && insertVal <= curr->next->val) {
                break;
            }

            // Handle the max-to-min wraparound case (end of list)
            if (curr->val > curr->next->val && 
                (insertVal >= curr->val || insertVal <= curr->next->val)) {
                break;
            }

            // If we have completed one full loop, insert anywhere
            if (curr->next == head) {
                break;
            }

            curr = curr->next;
        }

        // Insert new node
        Node* newNode = new Node(insertVal, curr->next);
        curr->next = newNode;
        return head;
    }
    
};