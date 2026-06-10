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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* root = new ListNode(0);
        ListNode* curr = root;

        while (l1 || l2 || carry) {
            int v1 = 0, v2 = 0;

            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            int val = sum % 10;

            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return root->next;
    }
};