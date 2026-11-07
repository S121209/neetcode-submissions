/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr) {
            return nullptr;
        }

        if (visited.find(node) != visited.end()) {
            return nullptr;
        }
        
        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for (Node* n : node->neighbors) {
            dfs(n, visited);
        }

        for (Node* n : node->neighbors) {
            newNode->neighbors.push_back(visited[n]);
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        
        Node* clone = dfs(node, visited);

        return clone;
    }
};






















