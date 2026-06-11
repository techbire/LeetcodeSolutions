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

    // reverse a linked list and return new head
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Find kth node from current node
    ListNode* findKthNode(ListNode* head, int k) {
        while (head && --k) {
            head = head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* prevGroupTail = NULL;

        while (curr) {

            // Find kth node
            ListNode* kth = findKthNode(curr, k);

            // Less than k nodes left
            if (!kth) {
                if (prevGroupTail)
                    prevGroupTail->next = curr;
                break;
            }

            ListNode* nextGroup = kth->next;
            kth->next = NULL;

            // Reverse current group
            ListNode* newHead = reverse(curr);

            // First group
            if (curr == head)
                head = newHead;
            else
                prevGroupTail->next = newHead;

            // curr becomes tail after reversal
            prevGroupTail = curr;
            curr = nextGroup;
        }

        return head;
    }
};