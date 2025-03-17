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
        // Case 1: Empty List → Create a new circular node
        if (!head) {
            head = new Node(insertVal);
            head->next = head; // Circular reference
            return head;
        }

        // Case 2: Single-node List → Insert new node and link it
        if (!head->next) {
            Node* newNode = new Node(insertVal, head);
            head->next = newNode;
            return head;
        }

        // Case 3: General case (Find insertion point)
        Node* Curr = head, *Prev = nullptr;

        while (true) {

            // Insert in correct sorted position
            if (Curr->val <= insertVal && insertVal <= Curr->next->val) {
                break;
            }

            // Handle wrap-around case (max-to-min transition)
            if (Curr->val > Curr->next->val && 
                (insertVal >= Curr->val || insertVal <= Curr->next->val)) {
                break;
            }

            // If we have completed a full loop without inserting, insert anywhere
            if (Curr->next == head) {
                break;
            }

            Prev = Curr;
            Curr = Curr->next;
        }

        // Insert new node
        Node* newNode = new Node(insertVal, Curr->next);
        Curr->next = newNode;

        return head;
    }
};
