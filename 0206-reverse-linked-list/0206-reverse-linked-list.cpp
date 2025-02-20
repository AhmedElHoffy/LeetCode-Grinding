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
        ListNode* Curr=head,*Prev=nullptr,*temp;
        while(Curr!=nullptr){
            temp = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = temp;
        }
        head = Prev;
        return head;
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