/*
Problem 948 : Bag Of tokens
You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.

******************************
Example 2:

Input: tokens = [200,100], power = 150

Output: 1

Explanation: Play token1 (100) face-up, reducing your power to 50 and increasing your score to 1.

There is no need to play token0, since you cannot play it face-up to add to your score. The maximum score achievable is 1.

******************************
Example 3:

Input: tokens = [100,200,300,400], power = 200

Output: 2

Explanation: Play the tokens in this order to get a score of 2:

Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
The maximum score achievable is 2.

Explanation - 
This seems to be a dynamic programming problem, but this problem will not have any overlapping subproblems.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    // By default sorts in ascending order
    sort(tokens.begin(), tokens.end());
    int lo = 0;
    int hi = tokens.size() - 1;
    int score = 0;
    while (lo <= hi) {
        if (power >= tokens[lo]) {
            // We can play face up
            power -= tokens[lo];
            score += 1;
            ++lo;
        } else if (score >= 1) {
            // We can play face down
            if (lo != hi) {
                // Do not play this token, if we are left with just one
                // token, as this will decrease the score
                power += tokens[hi];
                score -= 1;
            }
            --hi;
        } else {
            // Can't play either of them
            break;
        }
    }
    return score;
}

int main(int argc, char *argv[]){
    vector<int> tokens({100, 300, 200, 400});
    cout<<bagOfTokensScore(tokens, 200);
    return 0;
}
