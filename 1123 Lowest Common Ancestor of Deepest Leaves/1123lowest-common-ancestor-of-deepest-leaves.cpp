#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> deepestLeaves;
        
        q.push(root);
        parent[root] = nullptr;
        
        while (!q.empty()) {
            int levelSize = q.size();
            deepestLeaves.clear(); // Store nodes at current level
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                deepestLeaves.push_back(node);
                
                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        
        // Now find LCA of all deepest leaves
        while (deepestLeaves.size() > 1) {
            unordered_set<TreeNode*> parents;
            for (TreeNode* node : deepestLeaves) {
                parents.insert(parent[node]);
            }
            deepestLeaves.assign(parents.begin(), parents.end());
        }
        
        return deepestLeaves[0];
    }
};