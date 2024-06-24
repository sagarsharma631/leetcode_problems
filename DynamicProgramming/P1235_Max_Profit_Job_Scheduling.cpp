/*
Problem 1235: Maximum Profit In Job Scheduling 
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define DEBUG

using namespace std;

unordered_map<int, unordered_map<int, int>> memoization;

class interval_sort_comp{
    public:
    bool operator()(pair<int, pair<int,int>>& one, pair<int, pair<int,int>>& two){
        return one.first <= two.first;
    };
};

int jobSchedulingUtil(vector<pair<int, pair<int, int>>>& sorted_intervals, 
                      int curr_index,
                      int last_end_time) {
                          
    if (memoization.find(curr_index) != memoization.end() &&
            memoization[curr_index].find(last_end_time) !=
                memoization[curr_index].end()) {
            return memoization[curr_index][last_end_time];
    }
                          
    if (curr_index >= sorted_intervals.size()) {
        return 0;
    }

    int include = 0;
    int exclude = 0;

    if (sorted_intervals[curr_index].first >= last_end_time) {
        // We can include this.
        include = jobSchedulingUtil(sorted_intervals,
                                    curr_index + 1, sorted_intervals[curr_index].second.first) +
                  sorted_intervals[curr_index].second.second;
    }

    exclude = jobSchedulingUtil(sorted_intervals, curr_index + 1,
                                last_end_time);

    memoization[curr_index][last_end_time] = max(include, exclude);
    return memoization[curr_index][last_end_time];
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    // vector<startTime, pair<endTime, profit>>
    vector<pair<int, pair<int,int>>> sorted_intervals;
    
    // Populate the sorted_intervals
    for(int i = 0; i < startTime.size(); ++i){
        sorted_intervals.push_back(make_pair(startTime[i], make_pair(endTime[i], profit[i])));
    }
    
    sort(sorted_intervals.begin(), sorted_intervals.end(), interval_sort_comp());
    
    int result = jobSchedulingUtil(sorted_intervals, 0, 0);
    
#ifdef DEBUG
    for(int i = 0; i < sorted_intervals.size(); ++i){
        cout<<"Start Time -> "<<sorted_intervals[i].first<<", End Time -> "<<sorted_intervals[i].second.first
        <<", Profit -> "<<sorted_intervals[i].second.second<<endl;
    }
#endif
    
    return result;
}

int main(int argc, char *argv[]){
    vector<int> startTime({15,7,11,1});
    vector<int> endTime({18,19,16,10});
    vector<int> profit({9,1,19,5});
    cout<<jobScheduling(startTime, endTime, profit)<<endl;
    return 0;
}
