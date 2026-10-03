class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char w : word) {
            int i = w - 'a';

            if (curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode;
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;        
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* curr = root;

        for (int i = j; i < word.size(); i++) {
            char w = word[i];

            if (w == '.') {
                for (TrieNode* c : curr->children) {
                    if (c != nullptr && dfs(word, i+1, c)) { return true; }
                }
                return false;
            }
            else {
                if (curr->children[w-'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[w-'a'];
            }
        }
        return curr->endOfWord;
    }
};
