/*
Problem 1570. Dot Product of Two Sparse Vectors
*/
#include<iostream>
#include<vector>

using namespace std;

class SparseVector {
    vector<int> non_sparse_indices;
    vector<int>& nums_vec; 
public:
    
    SparseVector(vector<int> &nums): nums_vec(nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                non_sparse_indices.push_back(i);
            }
        }
    }
    
    vector<int>& get_non_sparse_indices(){
        return non_sparse_indices;
    }

    int operator[](int index){
        return this->nums_vec[index];
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        if(this->non_sparse_indices.size() < vec.get_non_sparse_indices().size()){
            for(auto iter : non_sparse_indices){
                result += nums_vec[iter] * vec[iter];
            }
        }
        else{
            for(auto iter : vec.get_non_sparse_indices()){
                result += nums_vec[iter] * vec[iter];
            }
        }
        return result;
    }
};


int main(int argc, char *argv[]){
    vector<int> norm_vec({1,0,0,2,3});
    vector<int> norm_vec_2({0,3,0,4,0});
    SparseVector vec1(norm_vec);
    SparseVector vec2(norm_vec_2);
    cout<<vec1.dotProduct(vec2)<<endl;
    return 0;
}
