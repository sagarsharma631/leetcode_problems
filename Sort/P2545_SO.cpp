/*

Problem 2545: Sort the Students by Their Kth Score

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class comp {
public:
    int i;
    bool operator()(vector<int>& first, vector<int>& second) {
        return first[this->i] > second[this->i];
    }
};

vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    comp comp_object;
    comp_object.i = k;
    sort(score.begin(), score.end(), comp_object);
    return score;
}

int main(int argc, char *argv[]){
    vector<vector<int>> vec({{10,6,9,1},
                            {7,5,11,2},
                            {4,8,3,15}});
                            
    sortTheStudents(vec, 2);
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec[i].size(); ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
