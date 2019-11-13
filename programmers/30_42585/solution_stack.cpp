#include <stack>
#include <string>
#include <vector>

using namespace std;

#define arr arrangement
int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    for (int i = 0 ; i < arr.length() ; ++i) {
        if (arr[i] == '(') {
            s.push(arr[i]);
        } else {
            s.pop();
            if (arr[i-1] == '(') answer += s.size();
            else  ++answer;
        }
    }
    return answer;
}
