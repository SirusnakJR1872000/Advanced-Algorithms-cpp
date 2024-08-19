// now lets understand sliding window algorithm where the window is of variable size

// lets consider an example in this case :
// we have to find the length of longest subarray with the same value in each position
// that is we need to make sure that we do not have any holes in the subarray or the window

# include <vector>
# include <algorithm>
# include <climits>

using std :: vector;
using std :: max;
using std :: min;

//we define a function which takes an array as the input
int longestSubarray(vector<int>& nums) {
    // we define the initial length of subarray as 0
    int length = 0;
    // and set the left pointer to 0
    int L = 0;

    // now iterate through the loop till the size of the array
    for (int R = 0; R < nums.size(); R++) {
        // now if the element at left and right pointer at now same
        if (nums[L] != nums[R]) {
            // we bring both at same location
            L = R;
        }
        // then we calculate the length by choosing a max value
        length = max(length, R - L + 1);
    }
    // now we just return the length
    return length;
}

// now lets consider another example where we want to find the length of 
// minimum subarray where the sum is greater than or equal to the target
// assume all values are psoitive

// lets define a function which takes an array and the target value
int shortestSubarray(vector<int>& nums, int target) {
    // initialize the left and target pointer to 0
    int L = 0, total = 0;
    // and length to the maximum value
    int length = INT_MAX;

    // now lets iterate through the loop till the size of the array
    for (int R = 0; R < nums.size(); R++) {
        // now we can compute the total by adding all the elements at the right pointer
        total += nums[R];
        // we reach our condition where total should be greater than or equal to target
        if (total >= target) {
            // then we just compute the length by finding the minimum
            // between the window and the defined length
            length = min(R - L + 1, length);
            // then we just remove the left value from the total
            total -= nums[L];
            // and increment the left pointer
            L++;
        }
    }
    // now if the length of the array is equal to the initiallu defines value of maximum
    // that means we never found the total of greater than or equal to the target
    if (length == INT_MAX) {
        // then we return 0
        return 0;
    }
    // otherwise we return the length
    return length;

}