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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;

        // 해당 원소를 지워야하기 때문에 목표 원소 전에 멈춰야함
        // 따라서 slow는 목표보다 한칸 전에 멈춰야함
        // n > size인 경우가 없으므로 예외처리 x
        while (fast) {
            if (count > n) {
                slow = slow->next;
            }
            fast = fast->next;
            count++;
        }

        if (n == count) {
            head = head->next;
            delete slow;
        }
        else {
            ListNode* temp = slow->next->next;
            delete slow->next;
            slow->next = temp;
        }

        return head;
    }
};
