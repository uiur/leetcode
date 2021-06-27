// Runtime: 8 ms, faster than 76.93% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 11.4 MB, less than 29.19% of C++ online submissions for Copy List with Random Pointer.

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
        unordered_map<Node*, int> m;
        int k = 0;
        for (Node* node = head; node != nullptr; node = node->next) {
            m[node] = k++;
        }
        m[nullptr] = k;
        
        vector<int> random_indexes;
        for (Node* node = head; node != nullptr; node = node->next) {
            random_indexes.push_back(m[node->random]);
        }
        
        vector<Node*> l;
        for (Node* node = head; node != nullptr; node = node->next) {
            l.push_back(new Node(node->val));
        }
        l.push_back(nullptr);
        
        for (int i = 0; i < l.size() - 1; i++) {
            l[i]->next = l[i+1];
            l[i]->random = l[random_indexes[i]];
        }
        
        return l[0];
    }
};
