/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool cyclefound=false;
        while(fast&&fast->next){
            slow=slow->next;//1
            fast=fast->next->next;//2
            if(slow==fast){
                cyclefound=true;
                break;
            }
        }
        if(!cyclefound) return NULL;
        //if cycle is found ->move both pointer by one step -> when u reach the start of the cycle (for this shift any one pointer to head )
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};