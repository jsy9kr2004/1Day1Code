#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> p_stack;
    for (int i = 0 ; i < prices.size() ; ++i) {
        while(!p_stack.empty() && prices[p_stack.top()] > prices[i]) {
            answer[p_stack.top()] = i - p_stack.top();
            p_stack.pop();
        }
        p_stack.push(i);
    }
    while (!p_stack.empty()) {
        answer[p_stack.top()] = prices.size() - p_stack.top() - 1;
        p_stack.pop();
    }
    return answer;
}
