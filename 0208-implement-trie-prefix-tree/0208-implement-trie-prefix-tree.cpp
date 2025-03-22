class Trie {
private:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* Children[26]; // Array for 26 lowercase English letters

        TrieNode() : isEndOfWord(false) {
            fill(begin(Children), end(Children), nullptr);
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; // Map character to array index
            if (!curr->Children[index]) {
                curr->Children[index] = new TrieNode();
            }
            curr = curr->Children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->Children[index]) {
                return false;
            }
            curr = curr->Children[index];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->Children[index]) {
                return false;
            }
            curr = curr->Children[index];
        }
        return true;
    }
};
