#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    stack<int> tops;
    vector<int> answer(heights.size(), 0);
    for (int i = heights.size() - 1 ; i >= 0 ; --i) {
        while (!tops.empty() && heights[tops.top()] < heights[i]) {
            answer[tops.top()] = i + 1;
            tops.pop();
        }
        tops.push(i);
    }
    return answer;
}
