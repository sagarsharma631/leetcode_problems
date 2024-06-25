/*
Problem 413 : An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
*/
#include<iostream>
#include<vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    int curr_sum = 0;
    int i = 0;
    int result = 0;
    while(i < nums.size()){
        for(int j = i + 1; j < nums.size(); ++j){
            if(j == i + 1){
                curr_sum = nums[j] - nums[i];
            }
            else{
                if((nums[j] - nums[j - 1]) != curr_sum){
                    break;
                }
                else{
                    if((j - i + 1) >= 3){
                        result += 1;
                    }
                }
            }
        }
        ++i;
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({1,2,3,4});
    cout<<numberOfArithmeticSlices(nums)<<endl;
    return 0;
}
