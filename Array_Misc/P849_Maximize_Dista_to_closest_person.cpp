/*

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int maxDistToClosest(vector<int>& seats) {
    vector<int> availed_seats;
    for (int i = 0; i < seats.size(); ++i) {
        if (seats[i] == 1) {
            availed_seats.push_back(i);
        }
    }
    int result = INT_MIN;
    if (availed_seats.size() == 1) {
        int local_result = max(availed_seats[0] - 0,
                               int(seats.size() - 1 - availed_seats[0]));
        result = max(result, local_result);
    } else {
        if (seats[0] == 0) {
            // This means that alex can sit on first seat.
            result = availed_seats[0];
        }
        if (seats[seats.size() - 1] == 0) {
            // This means alex can sit on last seat.
            result =
                max(result, int(seats.size() - 1 -
                                availed_seats[availed_seats.size() - 1]));
        }
        for (int i = 1; i < availed_seats.size(); ++i) {
            // Alex can sit in middle of 2 consecutive to maximise distance
            int local_result =
                (availed_seats[i] + availed_seats[i - 1]) / 2;
            local_result = min(availed_seats[i] - local_result,
                               local_result - availed_seats[i - 1]);
            result = max(result, local_result);
        }
    }
    return result;
}

int main(int argc, char *argv[]){
    vector<int> seats1({1,0,0,0,1,0,1});
    vector<int> seats2({1,0,0,0});
    vector<int> seats3({0,1});
    vector<int> seats4({1,0,0,1});
    vector<int> seats5({0,0,1,0,1,1});
    vector<int> seats6({0,1,1,1,0,0,1,0,0});
    vector<vector<int>> examples({
        seats1,
        seats2,
        seats3,
        seats4,
        seats5
    });
    
    for(int i = 0; i < 5; ++i){
        cout<<maxDistToClosest(examples[i])<<endl;
    }
    return 0;
}
