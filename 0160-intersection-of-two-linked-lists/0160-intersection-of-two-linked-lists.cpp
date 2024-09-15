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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //PRO
        
        
       // ListNode *t1=headA;
       //  while(t1!=nullptr){
       //      ListNode *t2=headB;
       //      while(t2!=nullptr){
       //          if(t1==t2){
       //              return t1;
       //          }
       //          t2=t2->next;
       //      }
       //      t1=t1->next;
       //  }
       //  return NULL;
        
        
        //NOOB
        
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int lenA=0; //finding the length
        while(tempA!=NULL){
           lenA++;
            tempA=tempA->next;
        }
        int lenB=0; 
        while(tempB!=NULL){
           lenB++;
            tempB=tempB->next;
        }
        //length ka kaam ho gya, ab reset karna h traversing 
        tempA=headA;    
        tempB=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
        for(int i=1;i<=diff;i++){
            tempA=tempA->next;
        }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        
        
       
          else{
            int diff=lenB-lenA;
        for(int i=1;i<=diff;i++){
            tempB=tempB->next;
        }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        
        
    }
};