#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class pq_comp {
public:
    bool operator()(pair<int, int> before, pair<int, int> after) {
        return before.second >= after.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq_map;
    for (auto num : nums) {
        freq_map[num] += 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, pq_comp> pq;
    for (auto iter : freq_map) {
        pq.push(iter);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }

    return result;
}

int main(int argc, char *argv[]){
    vector<int> nums({1,1,1,1,2,2,2,2,3});
    vector<int> result = topKFrequent(nums, 2);
    for(auto iter : result){
        cout<<iter<<" ";
    }
    return 0;
}
