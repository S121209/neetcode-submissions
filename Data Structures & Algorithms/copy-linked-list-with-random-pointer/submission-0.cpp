/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        unordered_map<Node*, Node*> nodes;

        while(head) {
            // 대상 노드가 생성되지 않았다면
            Node* temp;
            if (!nodes.contains(head)) {
                temp = new Node(head->val);
                nodes[head] = temp;
            }
            else {
                temp = nodes.at(head);
            }
            // next 노드 생성 또는 추가
            if (head->next) {
                if (!nodes.contains(head->next)) {
                    Node* tempNext = new Node(head->next->val);
                    temp->next = tempNext;
                    nodes[head->next] = tempNext;
                }
                else {
                    temp->next = nodes.at(head->next);
                }
            }
            // random 노드 생성 또는 추가
            if (head->random) {
                if (!nodes.contains(head->random)) {
                    Node* tempRan = new Node(head->random->val);
                    temp->random = tempRan;
                    nodes[head->random] = tempRan;
                }
                else {
                    temp->random = nodes.at(head->random);
                }
            }

            curr->next = temp;
            curr = curr->next;
            head = head->next;
        }
        Node* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
