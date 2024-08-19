// lets understand the slinding window algorithm where window is of fixed length

// let us consider a simple example where we are given an array and
// we have to return true if there are 2 elements within a window of size k
// that are equal

// Approach - 1: Brute Force

# include <vector>
# include <algorithm>
# include <unordered_set>

using std :: vector;
using std :: min;
using std :: unordered_set;

// lets first define the function which takes the array and the target variable
bool bruteForce(vector<int>& nums, int k) {
    // define a size varible for our array
    int size = static_cast<int>(nums.size());
    // now lets iterate through the loop till the length of the array
    for (int L = 0; L < size; L++) {
        // and right pointer will start from the next of left pointer
        // because the first element is going to be the same if L and R are on same location
        // we will go till the minimum of next position to L and L + k
        for (int R = L + 1; R < min(size, L + k); R++) {
            // now we compare the value
            if (nums[L] == nums[R]) {
                // if they are same we return True
                return true;
            }
        }
    }
    // otherwise we return False
    return false;
}

// we define a fucntion which takes in the array and the window size
bool slidingWindow(vector<int>& nums, int k) {
    // now we define a hash set
    unordered_set<int> window;
    // and left pointer to 0
    int L = 0;

    // now we iterate the right pointer till the length of the array
    for (int R = 0; R < nums.size(); R++) {
        // now we check the size of window if it is greater than the defined one
        if (R - L + 1 > k) {
            // if it is greater then we remove the left most element from the window
            // and increment the left pointer
            window.erase(nums[L]);
            L++;
        }
        // now we check if the element at R is in the hash or not
        if (window.count(nums[R] > 0)) {
            // if it is already in hash we return true value
            return true;
        }
        // otherwise we add it to the hash set
        window.insert(nums[R]);
    }
    return false;
}