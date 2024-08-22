// lets try to understand the concept of Segment Trees
// Segment Trees are considered to be one of the most complex tree structures

# include <vector>

using std :: vector;
// first lets start with defining the class

class SegmentTree {
    public:
        // a variable sum to store the total value
        int sum_;
        // left and right pointer
        SegmentTree* left_;
        SegmentTree* right_;
        // left and right node
        int L_;
        int R_;

        // define a function for segment tree
        SegmentTree(int total, int L, int R) {
            sum_ = total;
            left_ = nullptr;
            right_ = nullptr;
            L_ = L;
            R_ = R;
        }

        // a static method to build a segment tree
        // which takes in an array ,left and right nodes
        static SegmentTree* build(vector<int>& nums, int L, int R) {
            // if left and right nodes are equal
            if (L == R) {
                // then it is a leaf node / the last node
                // and we just return th value 
                return new SegmentTree(nums[L], L, R);
            }

            // calculate the mid value
            int M = (L + R) / 2;
            // now we define the root node with initial value at 0 and left and right node
            SegmentTree *root = new SegmentTree(0, L, R);
            // now we compute the left side
            root->left_ = SegmentTree::build(nums, L, M);
            // now we compute the right side
            root->right_ = SegmentTree::build(nums, M + 1, R);
            // now we calculate the sum of left and right 
            root->sum_ = root->right_->sum_ + root->left_->sum_;
            return root;
        }

        // now lets see how we can update the value in the segement tree in O(log n)
        void update(int index, int val) {
            // we will check if the node is a leaf node
            if (L_ == R_) {
                // then we just update the value
                sum_ = val;
                return;
            }

            // if it is not a leaf node then we first calculate the mid value to traversw down
            int M = (L_ + R_) / 2;
            // if the index to be updated is greater than mid then we recursively call the update function
            
            if (index > M) {
                right_->update(index, val);
            } 
            // if the index is smaller then we recursively call the update on left side
            else {
                left_->update(index, val);
            }
            // now we calculate the sum of the left and the right child
            sum_ = left_->sum_ + right_->sum_;
        }

        
        int rangeQuery(int L, int R) {
            // if the query range matches the current node then we return the sum
            if (L == L_ && R == R_) {
                return sum_;
            }

            // now lets calculate the mid value
            int M = (L_ + R_) / 2;
            // if the left bound is greater than mid then the range lies on right side
            if (L > M) {
                return right_->rangeQuery(L, R);
            }
            // if the right bound is less than or equal to mid then the range lies on left side
            else if (R <= M) {
                return left_->rangeQuery(L, R);
            } 
            // if neither of the conditons are satisfied then we split the query in 2 parts: 
            // right and left
            // and return the sum of those parts
            else {
                return (left_->rangeQuery(L, M) + right_->rangeQuery(M + 1, R));
            }
        }
};