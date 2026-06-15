/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
                parent_track[temp->left] = temp;
            }

            if(temp->right){
                q.push(temp->right);
                parent_track[temp->right] = temp;
            }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target]=true;
        int cur_level=0;

        while(!q.empty()){
            int size=q.size();
           
            if(cur_level++ == k) break;

            for(int i=0; i<size; i++){
                 TreeNode* current = q.front();
                 q.pop();

                 if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                 }

                 if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                 }

                 if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                 }
            }

        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            res.push_back(current->val);
        }

        return res;
        
    }
};