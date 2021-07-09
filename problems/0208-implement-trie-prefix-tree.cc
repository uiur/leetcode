struct Node {
    string value;
    unordered_map<char, Node*> children;
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        root->value = "";
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                Node* child = new Node();
                node->children[c] = child;
            }
            node = node->children[c];
        }
        node->value = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->value != "";
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
