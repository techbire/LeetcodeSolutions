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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        // Create a dummy node to act as the head of the merged list
        ListNode* dummy = new ListNode(-1);
        
        // Pointer to the current node in the new list
        ListNode* current = dummy;
        
        // Traverse both lists while both are non-empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // Attach list1's node to the merged list
                current->next = list1;
                // Move list1 pointer forward
                list1 = list1->next;
            } else {
                
                current->next = list2;
                // Move list2 pointer forward
                list2 = list2->next;
            }
            // Move the current pointer forward
            current = current->next;
        }
        
        // If there are remaining nodes in list1, attach them
        if (list1 != nullptr) {
            current->next = list1;
        }
        
        // If there are remaining nodes in list2, attach them
        if (list2 != nullptr) {
            current->next = list2;
        }
        
        // The merged list starts from the next node after the dummy
        ListNode* mergedHead = dummy->next;

        delete dummy;
        
        return mergedHead;
    }
};
