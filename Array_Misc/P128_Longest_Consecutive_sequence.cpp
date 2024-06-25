/*
Problem 128 : Longest Consecutive Sequence
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> elements_map;
    for (int i = 0; i < nums.size(); ++i) {
        elements_map[nums[i]] = false;
    }

    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (elements_map.find(nums[i] - 1) == elements_map.end() &&
            !elements_map[nums[i]]) {
            int local_result = 0;
            int curr_elem = nums[i];
            while (elements_map.find(curr_elem) != elements_map.end()) {
                local_result += 1;
                curr_elem += 1;
            }
            result = max(result, local_result);
            elements_map[nums[i]] = true;
        }
    }

    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({100,4,200,1,3,2});
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}
