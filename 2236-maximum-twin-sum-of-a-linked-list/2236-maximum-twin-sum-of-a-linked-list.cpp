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
    int pairSum(ListNode* head) {
        int Max_twin_Sum=0;
        ListNode* Fast=head, *Slow=head;
        ListNode* Prev=nullptr, *temp;

        while(Fast!=nullptr && Fast->next!=nullptr){
            Fast=Fast->next->next;
            temp = Slow;
            Slow = Slow->next;
            temp->next = Prev;
            Prev = temp; 
        }

        while(Slow && Prev){
            if( (Slow->val + Prev->val) > Max_twin_Sum){
                Max_twin_Sum = Slow->val + Prev->val;
            }
            Slow = Slow->next;
            Prev = Prev->next;
        }
        return  Max_twin_Sum;
    }
};









/*
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head== nullptr){
            return 0l;
        }
        ListNode* temp_ptr=head;
        int count = 1;
  // Step 1: Find the middle and reverse the first half
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;

            // Reverse the first half while finding the middle
            ListNode* nextTemp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextTemp;
        }

        // Step 2: Calculate twin sums
        ListNode* firstHalf = prev; // Start of the reversed first half
        ListNode* secondHalf = (fast == nullptr) ? slow : slow->next; // Handle even/odd lengths

        
        ListNode* Left_ListIterator = firstHalf;
        ListNode* RightListIterator = secondHalf;
        int Max_TwinSum=INT_MIN;
        int Curr_Sum;
        while(Left_ListIterator!= nullptr  && RightListIterator!=nullptr){
            Curr_Sum =  Left_ListIterator->val + RightListIterator->val;
            cout<< "curr sum now is: "<< Left_ListIterator->val <<" + " <<RightListIterator->val <<" = "<< Curr_Sum<<endl;
            if(Curr_Sum > Max_TwinSum){
                Max_TwinSum = Curr_Sum;
            }
            Left_ListIterator = Left_ListIterator->next;
            RightListIterator = RightListIterator->next;
        }
        return Max_TwinSum;
        
    }
};



*/