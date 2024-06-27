/*
Problem 560 : Subarray sum equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int subarraySum(vector<int>& arr, int k) {
    int n = arr.size(); // take the size of the array

    int prefix[n]; // make a prefix array to store prefix sum

    prefix[0] = arr[0]; // for element at index at zero, it is same

    // making our prefix array
    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }
    unordered_map<int, int> mp; // declare an unordered map

    int ans = 0; // to store the number of our subarrays having sum as 'k'

    for (int i = 0; i < n; i++) // traverse from the prefix array
    {
        if (prefix[i] ==
            k) // if it already becomes equal to k, then increment ans
            ans++;

        // now, as we discussed find whether (prefix[i] - k) present in map
        // or not
        if (mp.find(prefix[i] - k) != mp.end()) {
            ans += mp[prefix[i] - k]; // if yes, then add it our answer
        }

        mp[prefix[i]] += 1; // put prefix sum into our map
    }

    return ans; // and at last, return our answer
}

int main(int argc, char *argv[]){
    vector<int> nums({3, 4, 7, 2, -3, 1, 4, 2});
    cout<<subarraySum(nums, 7);
    return 0;
}
