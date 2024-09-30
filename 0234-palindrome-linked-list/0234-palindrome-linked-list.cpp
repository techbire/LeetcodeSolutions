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

//method-1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode* curr = head;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            if(arr[s]==arr[e]){  
                s++;
                e--;    
            }
            else{
                return false;
            }
           
            
        }
        return true;
    }
};



//method-2
// class Solution {
//   public:
//     // Function to check whether the list is palindrome.
// ListNode* findMid(ListNode* head){
//         ListNode* slow=head,*fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next;
//             if(fast) fast=fast->next;
//         }
//         return slow;
//     }
    
//     ListNode* reverseList(ListNode* head) {
//     if (head == NULL) return NULL;
//     ListNode* prev = NULL;ListNode* curr = head;ListNode* nexti = head->next;
//     while (curr != NULL) {
//         curr->next = prev;
//         prev = curr;
//         curr = nexti;
//         if(nexti!=NULL)nexti=nexti->next;
//     }
    
//     return prev;
//    }
  
//     bool compareList(ListNode* head1, ListNode* head2){
//         while(head1!=NULL && head2!=NULL){
//             if(head1->data != head2->data) return false;
//             head1=head1->next;
//             head2=head2->next;
//         }
//         return true;
        
//            if(head1 == NULL && head2 == NULL) {
//         return true;
//     }
    
//     }

//     bool isPalindrome(ListNode *head) {
//         if(head==NULL || head->next==NULL) return true;
//         ListNode* h=head;
//         ListNode* mid = findMid(h);
//         ListNode* h2=reverseList(mid);
//         return compareList(head,h2);
//     }
// };


//method-3
// class Solution {
//   public:
//     // Function to check whether the list is palindrome.
//     bool isPalindrome(ListNode *head) {
       
//         vector<int> v;
//         while(head)
//         {
//             v.push_back(head->data);
//             head=head->next;
//         }
        
//         vector<int> v1;
//         v1=v;
//         reverse(v1.begin(),v1.end());
//         return v==v1;
//     }
// };