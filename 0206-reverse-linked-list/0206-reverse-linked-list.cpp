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
    ListNode* reverseList(ListNode* head) {
       ListNode* Prev = nullptr, *temp;
       while(head!=nullptr){
        temp=head;
        head=head->next;
        temp->next = Prev;
        Prev = temp;
       }
       return Prev;
    }
};






/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev, *curr;
        curr = head;
        prev = curr;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * temp=curr->next;
        prev->next = nullptr;
        while(temp !=nullptr){
            curr = temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }
};
*/