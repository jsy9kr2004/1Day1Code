#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> print_out;
    for (int i = 0 ; i < priorities.size() ; i++)
        print_out.push(i);
    
    int result = 0;
    auto cur_max = max_element(priorities.begin(),priorities.end());
    while (!print_out.empty()) {
        int idx = print_out.front();
        print_out.pop();
        if (priorities[idx] == *cur_max) {
            result++;
            if (idx == location) break;
            priorities[idx] = 0;
            cur_max = max_element(priorities.begin(),priorities.end());
        } else {
            print_out.push(idx);
        }
    }
    return result;
}