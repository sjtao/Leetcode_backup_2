/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    TreeNode* deserializeHelper(string& data) {
        if(data[0] == '#'){
            if(data.size() > 1) data = data.substr(2); //#,1, skip 2 places
            return NULL;
        }
        
        int pos = data.find(','); //find the place of first comma
        int val = stoi(data.substr(0,pos)); //number after pos
        TreeNode* node = new TreeNode(val);
        
        data = data.substr(pos+1);
        node->left = deserializeHelper(data);
        node->right = deserializeHelper(data);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root)); 