/*
Problem 2171 : Removing Minimum Number of Magic Beans
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long minimumRemoval(vector<int>& beans) {
    if (beans.size() == 1)
        return 0;
    long long result = 0;
    // This question is actually asking us to convert the numbers, below
    // a particular value to 0 and make the numbers larger than the specific
    // number equal.
    sort(beans.begin(), beans.end());

    // Calculate the prefix sum std::array<, N> ;
    vector<long long> prefix_sum;
    long long curr_sum = 0;
    for (int i = 0; i < beans.size(); ++i) {
        curr_sum += beans[i];
        prefix_sum.push_back(curr_sum);
    }
    long long hi = beans.size() - 1;
    result = (prefix_sum[hi] - prefix_sum[0]) - (hi * beans[0]);
    for (int i = 1; i < beans.size(); ++i) {
        result = min(result, prefix_sum[i - 1] +
                                 (prefix_sum[hi] - prefix_sum[i]) -
                                 ((hi - i) * beans[i]));
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums1({4,1,6,5});
    vector<int> nums2({2,10,3,2});
    vector<int> nums3({4,4});
    cout<<minimumRemoval(nums3);
    return 0;
}
