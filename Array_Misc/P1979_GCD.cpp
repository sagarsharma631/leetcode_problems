/*
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findGCD(vector<int>& nums) {
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());
    auto findLCM = [&]() -> int{
        int pivot = 1;
        while(1){
            if( ((max_num * pivot) % min_num) == 0){
                break;
            }
            ++pivot;
        }
        return pivot * max_num;
    };
    int GCD;
    int LCM = findLCM();
    GCD = (min_num * max_num) / LCM;
    return GCD;
}

int main(int argc, char *argv[]){
    vector<int> nums({2, 5, 6, 9, 10});
    vector<int> nums2({7, 5, 6, 8, 3});
    cout<<findGCD(nums2);
    return 0;
}
