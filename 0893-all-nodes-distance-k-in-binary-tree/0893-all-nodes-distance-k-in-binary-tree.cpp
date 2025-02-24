class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;

    // Step 1: Build the Graph Iteratively (Using BFS)
    void buildGraph(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (node->left) {
                graph[node].push_back(node->left);
                graph[node->left].push_back(node);
                q.push(node->left);
            }

            // Process right child
            if (node->right) {
                graph[node].push_back(node->right);
                graph[node->right].push_back(node);
                q.push(node->right);
            }
        }
    }

    // Step 2: BFS to find nodes at distance K
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        // Build the graph iteratively
        buildGraph(root);

        // BFS setup
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (distance == k) break; // Stop when we reach distance K

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                for (TreeNode* neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            distance++;
        }

        // Collect all nodes that are exactly distance K
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
