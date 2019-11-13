#include <string>
#include <vector>

using namespace std;

#define arr arrangement
int solution(string arrangement) {
    int answer = 0;
    int left_cnt = 0;
    for (int i = 0 ; i < arr.length() ; ++i) {
        if (arr[i] == '(') {
            ++left_cnt;
        } else {
            if(arr[i-1] == '(') { // laser
                --left_cnt;
                answer += left_cnt;
            } else {
                ++answer;
                --left_cnt;
            }
        }
    }
    return answer;
}
