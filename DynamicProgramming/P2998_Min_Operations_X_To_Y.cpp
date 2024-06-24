/*
P2998 : Minimum Number of Operations to Make X and Y Equal
*/
#include<iostream>

using namespace std;

int minimumOperationsToMakeEqualUtil(int x, int y){
    if(x <= y){
        return y - x;
    }
    int result = abs(x - y);
    if(x % 5 == 0){
        result = min(result, minimumOperationsToMakeEqualUtil(x / 5, y) + 1);
    }
    else{
        // We should bound the next or previous multiple of 5 and check, minimum steps
        result = min(result, minimumOperationsToMakeEqualUtil(x / 5, y) + 1 + (x % 5));
        
        result = min(result, minimumOperationsToMakeEqualUtil(x / 5 + 1, y) + 1 + (5 - (x % 5)));
    }

    if(x % 11 == 0){
        result = min(result, minimumOperationsToMakeEqualUtil(x / 11, y) + 1);
    }
    else{
        // We should bound the next or previous multiple of 5 and check, minimum steps
        result = min(result, minimumOperationsToMakeEqualUtil(x / 11, y) + 1 + (x % 11));
        
        result = min(result, minimumOperationsToMakeEqualUtil(x / 11 + 1, y) + 1 + (11 - (x % 11)));
    }
    return result;
}

int minimumOperationsToMakeEqual(int x, int y) {
    return minimumOperationsToMakeEqualUtil(x ,y);
}

int main(int argc, char *argv[]){
    cout<<minimumOperationsToMakeEqual(10, 2);
    return 0;
}
