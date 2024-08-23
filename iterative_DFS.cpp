// lets take a look into a iterative approach of the DFS

# include <vector>
# include <iostream>

using std :: vector;
using std :: cout;
using std :: endl;

// // now lets start with defining the treeNode which takes in the values at node, left and right child
class treeNode {
    public:
        int val_;
        treeNode* left_;
        treeNode* right_;

        treeNode(int val, treeNode* left, treeNode* right) : val_(val), left_(left), right_(right) {}
};

// lets start with the inorder traversal
void inorder(treeNode* root) {
    // lets initialize a stack to keep track of nodes
    vector<treeNode* >stack;
    // initially we set the current node to the root
    treeNode* curr = root;

    // now we will iterate till our curr and stack are not NULL
    while (curr || stack.size()) {
        // if our curr is not None
        if (curr) {
            // hen we just push the node into the stack
            stack.push_back(curr);
            // and move our current pointer to the leftmost node
            curr = curr->left_;
        }
        // if somehow our current pointer goes to None
        else {
            // then we remove the most recent node
            curr = stack.back();
            stack.pop_back();
            // // and we print the value
            cout << curr->val_ << endl;
            // then we just move to the right child
            curr = curr->right_;

        }   
    }
}

// lets see the preorder traversal
void preOrder(treeNode* root) {
    // now initialize the stack to keep track of node
    vector<treeNode* > stack;
    // and the current pointer to the root
    treeNode* curr = root;

    //  now if the current pointer and stack are not None
    while (curr || stack.size()) {
        // if current value is not None
        if (curr) {
            // then we print the current value 
            cout << curr->val_ << endl;
            // now we check if thee exists a right child
            if (curr->right_) {
                // if there is then we just append it to the stack because we want to visit it later
                stack.push_back(curr->right_);
            }
            // now we continue the left side traversal
            curr = curr->left_;
            // if the current and stack is not None
        }else {
            // then we just pop the value because we have reached the end of the tree
            curr = stack.back();
            stack.pop_back();
        }
    }
}

// now lets see the post order traversal
void postOrder(treeNode* root) {
    // stack will hold the node that is to be processed
    vector<treeNode* >stack = {root};
    // another stack which checks if the node is visited or not
    vector<bool> visit = {false};

    // now we traverse till the stack is not empty
    while(stack.size()) {
        // the top node and the corresponding visited status are popped out
        treeNode* curr = stack.back();
        bool visited = visit.back();
        stack.pop_back();
        visit.pop_back();

        // if the current is not None
        if (curr) {
            //  we will check if the node has been visited before
            if (visited) {
                // if it is already visited then we print true
                cout << curr->val_ << endl;
            } else {
                //  we push the current node back into the stack with 
                // a marker indicating that it has been visited
                stack.push_back(curr);
                visit.push_back(true);

                // add the right child to the stack
                stack.push_back(curr->right_);
                visit.push_back(false);

                // add the left child to the stack
                stack.push_back(curr->left_);
                visit.push_back(false);
            }
        
        }
    }
}

