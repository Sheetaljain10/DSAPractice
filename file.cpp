#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == "-1") return nullptr;

    TreeNode* root = new TreeNode(stoi(levelOrder[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while (!q.empty() && index < levelOrder.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (index < levelOrder.size() && levelOrder[index] != "-1") {
            node->left = new TreeNode(stoi(levelOrder[index]));
            q.push(node->left);
        }
        index++;

        if (index < levelOrder.size() && levelOrder[index] != "-1") {
            node->right = new TreeNode(stoi(levelOrder[index]));
            q.push(node->right);
        }
        index++;
    }

    return root;
}

int sumOfNodesWithoutSiblings(TreeNode* root) {
    if (!root) return -1;

    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if ((node->left && !node->right) || (!node->left && node->right)) {
            sum += node->left ? node->left->val : node->right->val;
        }

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return sum == 0 ? -1 : sum;
}

int main() {
    int height;
    cin >> height;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> levelOrder;
    string value;

    while (ss >> value) {
        levelOrder.push_back(value);
    }

    if (height == 0 || levelOrder.empty() || (levelOrder.size() == 1 && levelOrder[0] == "-1")) {
        cout << -1 << endl;
        return 0;
    }

    TreeNode* root = buildTree(levelOrder);
    int result = sumOfNodesWithoutSiblings(root);
    cout << result << endl;

    return 0;
}
