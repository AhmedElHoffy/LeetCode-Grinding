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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* Slow_Ptr=head, *Fast_Ptr=head,*Prev=nullptr;

        while(Fast_Ptr!=nullptr && Fast_Ptr->next!=nullptr){
            Prev=Slow_Ptr;
            Slow_Ptr = Slow_Ptr->next;
            Fast_Ptr = Fast_Ptr->next->next;
        }
        Prev->next = Slow_Ptr->next;

        Slow_Ptr->next = nullptr;
        delete Slow_Ptr;
        return head;

    }
};













/*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list has only one node, return nullptr
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // Do NOT delete head explicitly
        }

        // Step 1: Use two pointers to find the middle
        ListNode* slow = head;  // Slow pointer (moves 1 step)
        ListNode* fast = head;  // Fast pointer (moves 2 steps)
        ListNode* prev = nullptr; // Tracks node before 'slow'

        // Move 'fast' twice as fast as 'slow' to find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Remove the middle node
        prev->next = slow->next; // Skip the middle node
        // No need for manual `delete` to avoid double free errors

        return head;
    }
};

*/