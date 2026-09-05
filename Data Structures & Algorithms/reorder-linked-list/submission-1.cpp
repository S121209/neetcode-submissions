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
    void reorderList(ListNode* head) {
        if (!head->next) return;

        int len = 0;
        ListNode* chkLen = head;

        // 길이 확인
        while (chkLen) {
            chkLen = chkLen->next;
            len++;
        }

        int half = len/2;
        ListNode* curr = head;
        ListNode* prev;
        ListNode* head2;

        for (int i = 0; i < half; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;

        // curr은 linked list2의 head
        head2 = curr;
        ListNode* prev2 = nullptr;
        ListNode* next2 = head2->next;

        while (head2) {
            head2->next = prev2;
            prev2 = head2;
            head2 = next2;
            next2 = head2->next;
        }
        head2 = prev2;
        

        // 이제 list 1, 2 교차, list1이 항상 1 적음
        ListNode* nextL1;
        ListNode* nextL2;
        while (head2) {
            nextL1 = head->next;
            nextL2 = head2->next;

            head->next = head2;

            if (nextL1 == nullptr) {
                break;
            }

            head2->next = nextL1;

            head = nextL1;
            head2 = nextL2;
        }
    }
};
