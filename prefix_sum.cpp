// so lets understand the concept of prefix sum
// as the word suggest prefix means at the start
// we pick the starting element and continue the operation

// so lets assume that we have an array of values and we need to 
// design a system that can query the sum of subarray of values

# include <vector>

using std :: vector;

// define a class
class PrefixSum {
    public:
        // an empty array to store the prefix values
        vector<int> prefix_;

        // a method to compute the total and store the values in the array
        PrefixSum(vector<int>& nums) {
            // initialize the total to zero for better computation
            int total = 0;
            // now we iterate through all the values in the array
            for (int n : nums) {
                // adding all the values one by one
                total += n;
                // psuhing it into the array after computing each total 
                prefix_.push_back(total);
            }
        }

        // now we will define a method that takes in the left and right pointer
        // and compute the result for the range between the pointers
        int RangeSum(int right, int left) {
            // we will define a variable that takes the values from start to the right 
            int preRight = prefix_[right];
            // now we need another variable to store the value between the let and right pointer 
            // we dont want to include the values before left
            // so we use a conditional operator (similar functionality as if-else)
            int preLeft = left > 0 ? prefix_[left - 1] : 0;
            // now we can return the difference of right and left pointer 
            return preRight - preLeft;
        }
};

