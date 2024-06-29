/*
Problem 2340. Minimum Adjacent Swaps to Make a Valid Array
*/
#include<iostream>
#include<vector>

using namespace std;

int minimumSwaps(vector<int>& nums) {
    /* Consider the following example for understanding subtraction from the
       result.
       Input: nums = [3,4,5,5,3,1] Output: 6 Explanation: Perform the following
       swaps:
        - Swap 1: Swap the 3rd and 4th elements, nums is then [3,4,5,3,5,1].
        - Swap 2: Swap the 4th and 5th elements, nums is then [3,4,5,3,1,5].
        - Swap 3: Swap the 3rd and 4th elements, nums is then [3,4,5,1,3,5].
        - Swap 4: Swap the 2nd and 3rd elements, nums is then [3,4,1,5,3,5].
        - Swap 5: Swap the 1st and 2nd elements, nums is then [3,1,4,5,3,5].
        - Swap 6: Swap the 0th and 1st elements, nums is then [1,3,4,5,3,5].
        It can be shown that 6 swaps is the minimum swaps required to make a valid
        array.
        In the above example index of small_integer is greater than large_integer.
        Hence, swap #2 is common i.e. it brings 5 closer to the rightmost position 
        and brings 1 closer to the leftmost position.
        Hence, we will subtract 1 from the answer
    */
    int small_index = 0;
    int large_index = 0;
    int smallest_element = 100001;
    int largest_element = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < smallest_element) {
            small_index = i;
            smallest_element = nums[i];
        }

        if (nums[i] >= largest_element) {
            large_index = i;
            largest_element = nums[i];
        }
    }

    int result;

    if (small_index == large_index) {
        result = 0;
    } else if (small_index > large_index) {
        // If small_index is larger than large_index, then we decrese the
        // answer by one. Because there will be a swap, which will be common
        // between bringing largest to rightmost poristion and smallest to
        // the leftmost position.
        result = (small_index) + (nums.size() - 1 - large_index) - 1;
    } else {
        // When the small_index is smaller than the large_index then, all
        // the swaps will be unique, there will be common swap.
        result = (small_index) + (nums.size() - 1 - large_index);
    }

    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({3,4,5,5,3,1});
    cout<<minimumSwaps(nums)<<endl;
    return 0;
}
