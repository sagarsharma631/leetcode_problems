/*
Problem 300 :  Longest Increasing Subsequence
*/
#include<iostream>
#include<vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    // Build the DP array
    int result = 0;
    //int *dp = new int[nums.size()]{0};
    vector<int> dp(nums.size(), 0);
    for(int i = nums.size() - 1; i >= 0; --i){
        for(int j = i + 1; j < nums.size(); ++j){
            if(nums[j] > nums[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }   
        dp[i] += 1;
        result = max(result, dp[i]);
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({10,9,2,5,3,7,101,18,24});
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
