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
        if (headA == nullptr) return headA;
        if (headB == nullptr) return headB;

        unordered_set<ListNode*> nodeAddress;

        while (headA != nullptr) {
            nodeAddress.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (nodeAddress.find(headB) != nodeAddress.end())
                return headB;

            headB = headB->next;
        }

        return nullptr;
    }

    ListNode* getIntersectionNodeLength(ListNode* headA, ListNode* headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);

        while (lenA > lenB) {
            lenA--;
            headA = headA->next;
        }

        while (lenB > lenA) {
            lenB--;
            headB = headB->next;
        }

        // Now both heads are at the same distance from intersection
        // Start moving them both until they meet
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    int getListLength(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            len++;
            head = head->next;
        }

        return len;
    }
};