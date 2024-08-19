// lets understand the two pointers concept
// so lets check if the given string is a palindrome or not

# include <vector>
# include <string>

using std :: vector;
using std :: string;

// defining a function which takes in a string
bool isPalindrome(string word) {
    // now define a left and right variable
    // left will start from 0th position and R from last
    int L = 0, R = word.length() - 1;

    // now we will run the loop till the pointers have not crosses each other
    while (L < R) {
        // if the elements at the pointers don't match 
        // then it is not a palindrome
        // we return false
        if (word[L] != word[R]) {
            return false;
        }
        // increment the left and decrement the right pointer if there is a match
        L++;
        R--;
    }
    return true;
}

// now lets consider another example where we are given a sorted array of integers
// we have to return the indices of 2 elements that sum up to the target value. 

// lets start with defining a function with which takes in the array and the target value
vector<int> targetSum(vector<int>& nums, int target) {
    // lets define the left and right pointer
    int L = 0, R = nums.size() - 1;

    // now we will iterate through the loop till the left and right pointers have not crossed each other
    while (L < R) {
        // now we will check if the sum of left and right pointer is greater than target
        if (nums[L] + nums[R] > target) {
            // we will decrement the right pointer because we know that array is sorted
            R--;
        }
        // now we check if the sum is less than target value
        else if (nums[L] + nums[R] < target) {
            // we will increment the left pointer
            L++;
        }
        // now if it is equal then we return the pointers
        else {
            return vector<int>{L, R};
        }
    }
}