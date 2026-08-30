class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // {column, row, value}
        vector<tuple<int, int, int>> nodes;
        
        // DFS: node, row, column
        function<void(TreeNode*, int, int)> dfs =
            [&](TreeNode* node, int row, int col) {
                
                if (node == nullptr)
                    return;
                
                nodes.push_back({col, row, node->val});
                
                dfs(node->left, row + 1, col - 1);
                dfs(node->right, row + 1, col + 1);
            };
        
        dfs(root, 0, 0);
        
        sort(nodes.begin(), nodes.end());
        
        vector<vector<int>> result;
        
        int currentCol = INT_MIN;
        
        for (auto &[col, row, value] : nodes) {
            
            // New column
            if (col != currentCol) {
                result.push_back({});
                currentCol = col;
            }
            
            result.back().push_back(value);
        }
        
        return result;
    }
};