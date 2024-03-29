#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int val) {
    Node *node = new Node;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str;) ip.push_back(str);

    // Creating root of the tree
    Node *root = newNode(stoi(ip[0]));
    
    // Push root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Staring from the second element
    unsigned int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // if the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Ordinary Traversal 
/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
/*vector<int> inOrder(Node* root) {
    //code here
    vector<int> inorder;
    stack<Node*> st;
    Node* node = root;
    if(node == NULL) return inorder;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}*/

// Morris Traversal 
/*
    Time Complexity: O(N) (nearly)
    Space Complexity: O(1)
*/

vector<int> inOrder(Node *root) {
    vector<int> inorder;
    Node *curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }

            else {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    vector<int> inorder = inOrder(root);
    for(unsigned int i = 0; i < inorder.size(); i++) 
        cout << inorder[i] << " ";
    return 0;
}