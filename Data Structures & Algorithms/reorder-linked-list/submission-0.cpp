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
    void reorderList(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=nullptr;
        ListNode* current=slow->next;
        while(current){
            ListNode* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        slow->next=nullptr;

        ListNode* first=head;
        ListNode* second=prev;

        while(first && second){
            ListNode* t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;
            first=t1;
            second=t2;
        }
        
    }
};
