class Node {
public:
    Node* children[26];
    bool endOfWord = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree(){
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for (char w : word) {
            int i = w - 'a';
            if (curr->children[i] == nullptr) {
                curr->children[i] = new Node();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for (char w : word) {
            int i = w - 'a';
            if (curr->children[i] == nullptr) {
                return false;
            }
            curr = curr->children[i];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for (char w : prefix) {
            int i = w - 'a';
            if (curr->children[i] == nullptr) {
                return false;
            }
            curr = curr->children[i];
        }
        return true;
    }
};
