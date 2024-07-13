/*
  Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    bool result = false;
    unordered_map<int, int> subarray_mod_map;
    int prefix_sum = nums[0];
    subarray_mod_map[prefix_sum % k] = 0;

    for (int i = 1; i < nums.size(); ++i) {
        prefix_sum += nums[i];
        if ((subarray_mod_map.find(prefix_sum % k) !=
                 subarray_mod_map.end() &&
             i - subarray_mod_map[prefix_sum % k] > 1) ||
            prefix_sum % k == 0) {
            result = true;
            break;
        }
	// Why the following condition is needed
	/*
	Consider this scenario [5, 0, 0, 0]
	The prefix_sum will always remain 5 as all numbers in the vector are 0 except 5.
	If the if condition is removed than the hash_map will always be updated with the curent index
	and in the next iteration the length of the subarray will never be more than 1.
	*/
        if (nums[i] != 0) {
            subarray_mod_map[prefix_sum % k] = i;
        }
    }

    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({5, 0, 0, 0});
    checkSubarraySum(nums, 3);
    return 0;
}
