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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* Odd_Ptr=head;
        ListNode* Even_List_Head = Odd_Ptr->next;
        ListNode* Even_Ptr = Even_List_Head;

        while(Even_Ptr!=nullptr && Even_Ptr->next!=nullptr){
            Odd_Ptr->next = Even_Ptr->next;
            Odd_Ptr = Odd_Ptr->next;

            Even_Ptr->next = Odd_Ptr->next;
            Even_Ptr = Even_Ptr->next;
        }
        Odd_Ptr->next = Even_List_Head;
        return head;
    }
};








/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Edge Cases: If list has fewer than 3 nodes, return as is
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        // Initialize pointers
        ListNode* Start_Ptr = head;         // Tracks odd nodes
        ListNode* End_Ptr = head;           // Will track the end of the list
        int count = 1;                      // Total count of nodes

        // Step 1: Find the tail of the list
        while (End_Ptr->next != nullptr) {
            End_Ptr = End_Ptr->next;
            count++;
        }

        // Step 2: Rearrange nodes into odd and even groups
        ListNode* LastNode = End_Ptr;  // Save the original tail of the list
        int Idx = 1;                   // Index to track current position in the list

        while (Idx <= count / 2) {  // Process only the first half
            End_Ptr->next = Start_Ptr->next;        // Move even node to end
            Start_Ptr->next = Start_Ptr->next->next; // Skip to next odd node
            End_Ptr = End_Ptr->next;                // Update end pointer
            End_Ptr->next = nullptr;               // End the list temporarily
            Start_Ptr = Start_Ptr->next;           // Move to next odd node
            Idx++;
        }

        // Step 3: Return the reordered list
        return head;
    }
};
*/