#include<iostream>
#include<vector>

using namespace std;

class MinStack {
    vector<int> main_stack;
    vector<int> min_stack;
public:
    MinStack() {}

    void push(int val) {
        main_stack.push_back(val);
        if (min_stack.empty() || val <= min_stack[min_stack.size() - 1]) {
            min_stack.push_back(val);
        }
        return;
    }

    void pop() {
        if (main_stack[main_stack.size() - 1] ==
            min_stack[min_stack.size() - 1]) {
            min_stack.pop_back();
        }
        main_stack.pop_back();
        return;
    }

    int top() { return main_stack[main_stack.size() - 1]; }

    int getMin() { return min_stack[min_stack.size() - 1]; }
};

int main(int argc, char *argv[]){
    return 0;
}
