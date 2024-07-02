/*
Problem 560: Subarray Sum Equals K
*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    int running_sum = 0;
    unordered_map<int, int> prefix_sum_map;
    for (int i = 0; i < nums.size(); ++i) {
        running_sum += nums[i];
        if (running_sum == k) {
            result += 1;
        }

        if (prefix_sum_map.find(running_sum - k) != prefix_sum_map.end()) {
            result += prefix_sum_map[running_sum - k];
        }
        prefix_sum_map[running_sum] += 1;
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({7, 7, 7, -6, -1, 7});
    cout<<subarraySum(nums, 7);
    return 0;
}
