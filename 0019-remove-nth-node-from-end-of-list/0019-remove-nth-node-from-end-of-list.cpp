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
 int len(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
   ListNode* removeNthFromEnd(ListNode* head, int n) {
    int L = len(head);

    // Delete head node
    if (n == L) {
        ListNode* temp = head->next;
        delete head;
        return temp;
    }

    int front = L - n;
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (front--) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}
};