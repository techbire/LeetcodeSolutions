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
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(left==right)return head;
//         ListNode* a=nullptr;
//         ListNode* b=nullptr;
//         ListNode* c=nullptr;
//         ListNode* d=nullptr;
//         ListNode* temp=head;
//         int n=1;
//         while(temp){
//             if(n==left-1) a=temp;
//             if(n==left)b =temp;
//             if(n==right)c=temp;
//             if(n==right+1)d=temp;
//             temp=temp->next;
//             n++;
//             }
//         if(a) a->next=nullptr;
//         c->next=nullptr;
//         c=reverseList(c);
//         if(a) a->next=c;
//         b->next=d;
//         if(a) return head;
//         return c;
//     }
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i = 0; i < left - 1; i++)    
        prev = prev->next;
        ListNode *curr = prev->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;

    }
};