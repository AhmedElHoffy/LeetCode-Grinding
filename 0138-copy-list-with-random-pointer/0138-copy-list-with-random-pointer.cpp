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
        if (!head) return nullptr; // Edge case: empty list

        unordered_map<Node*,Node*>Old_to_Copy_Map;
        
        Node* Curr = head;
        while(Curr!=nullptr){
            Node* NewCopy = new  Node(Curr->val);
            Old_to_Copy_Map[Curr] = NewCopy;
            //Old_to_Copy_Map[Curr] = new  Node(Curr->val);
            Curr = Curr->next;
        }

        Curr = head;
        while(Curr!=nullptr){
            Node* temp = Old_to_Copy_Map[Curr];
            
            temp->next   = (Curr->next)   ?  Old_to_Copy_Map[Curr->next] : nullptr;
            temp->random = (Curr->random) ?  Old_to_Copy_Map[Curr->random] : nullptr;

            //Old_to_Copy_Map[Curr]->next = Old_to_Copy_Map[Curr->next] ;
            //Old_to_Copy_Map[Curr]->random = Old_to_Copy_Map[Curr->random] ;

            Curr = Curr->next;
        }
        Node* NewHead = Old_to_Copy_Map[head];
        return NewHead;
    }
};