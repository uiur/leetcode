// Runtime: 16 ms, faster than 89.13% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 17.7 MB, less than 6.73% of C++ online submissions for Populating Next Right Pointers in Each Node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        vector<Node*> current { root };
        while (current.size() > 0) {
            vector<Node*> next;
            for (int i = 0; i < current.size() - 1; i++) {
                current[i]->next = current[i+1];
            }
            for (int i = 0; i < current.size(); i++) {
                if (current[i]->left) next.push_back(current[i]->left);
                if (current[i]->right) next.push_back(current[i]->right);
            }
            current = next;
        }

        return root;
    }
};
