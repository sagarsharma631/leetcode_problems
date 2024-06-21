/*
Problem 528: Random Pick with Weight
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    vector<int> prefix_sum;

public:
    Solution(vector<int>& w) {
        for (auto item : w) {
            if (prefix_sum.empty()) {
                prefix_sum.push_back(item);
            } else {
                prefix_sum.push_back(item + prefix_sum.back());
            }
        }
    }

    int pickIndex() {
        int target = rand() % prefix_sum.back();
        return upper_bound(prefix_sum.begin(), prefix_sum.end(), target) -
               prefix_sum.begin();
    }
};

int main(int argc, char *argv[]){
    vector<int> vec({1,2,5});
    Solution obj(vec);
    for(int i = 0; i < 20; ++i){
        cout<<vec[obj.pickIndex()]<<endl;
    }
    return 0;
}
