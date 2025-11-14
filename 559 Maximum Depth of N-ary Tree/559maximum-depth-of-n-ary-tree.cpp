/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            res++;
            int n=q.size();
            for (int _ = 0; _ < n; _++) {
                auto node = q.front();
                q.pop();
                for (auto child : node->children) {
                    if (child)
                        q.push(child);
                }
            }
        }
        return res;
    }
};