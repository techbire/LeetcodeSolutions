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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        // Create a dummy node
        ListNode* dummy = new ListNode(-1); // Use ListNode instead of Node<int>
        ListNode* temp = dummy;

        // Traverse both lists and merge them
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                temp->next = first;
                temp = first;
                first = first->next;
            } else {
                temp->next = second;
                temp = second;
                second = second->next;
            }
        }

        // Attach the remaining nodes from either list
        if (first != nullptr) {
            temp->next = first;
        } else {
            temp->next = second;
        }

        // Return the merged list starting from dummy's next
        return dummy->next;
    }
};
