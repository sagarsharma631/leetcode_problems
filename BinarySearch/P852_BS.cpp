/*

Problem 852. Peak Index in a mountain array

*/

#include<iostream>
#include<vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr, int lo, int hi){
    int result = 0;
    int mid = (lo + hi)/2;
    if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
        result = mid;
    }
    else if(arr[mid] > arr[mid + 1]){
        // The array is decreasing from this index. Search for peak in left subarray.
        result = peakIndexInMountainArray(arr, lo, mid - 1);
    }
    else{
        // arr[mid] > arr[mid - 1]
        result = peakIndexInMountainArray(arr, mid + 1, hi);
    }
    return result;
}

int peakIndexInMountainArray(vector<int>& arr) {
    return peakIndexInMountainArray(arr, 0, arr.size());
}

int main(int argc, char *argv[]){
    vector<int> arr({0,10,5,2});
    return peakIndexInMountainArray(arr);
}
