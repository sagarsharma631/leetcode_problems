/*
Problem 1658 : Minimum Operations to reduce X to 0.
This seems to be a DP question, but guess what, it isn't.
The solution to this is to find the longest subarray which is equal to sum of vector - X.
*/
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

using namespace std;

int minOperations(vector<int>& nums, int x) {
    if (x == nums[0] || x == nums[nums.size() - 1]) {
        return 1;
    }

    if (x < nums[0] && x < nums[nums.size() - 1]) {
        return -1;
    }

    int k = std::reduce(nums.begin(), nums.end()) - x;

    if (k < 0) {
        return -1;
    }

    if(k == 0){
        // This means that the total sum of the array is equal to x
        return nums.size();
    }

    int result = 0;
    int i = 0;
    int j = 0;
    int curr_sum = 0;
    while (j < nums.size()) {
        curr_sum += nums[j];
        if (curr_sum == k) {
            // We found a subarray which is equal to k. Update result
            result = max(result, j - i + 1);
        } else if (curr_sum > k) {
            while (curr_sum > k) {
                curr_sum -= nums[i];
                ++i;
            }
            if (curr_sum == k) {
                result = max(result, j - i + 1);
            }
        }
        ++j;
    }

    return (result == 0) ? -1 : nums.size() - result;
}

int main(int argc, char *argv[]){
    vector<int> nums({3,2,20,2,3});
    minOperations(nums, 10);
    return 0;
}
