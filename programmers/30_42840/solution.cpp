#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> a2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> a3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> result(3, 0);
    for (int i = 0 ; i < answers.size() ; ++i) {
        if (answers[i] == a1[i % a1.size()]) ++result[0];
        if (answers[i] == a2[i % a2.size()]) ++result[1];
        if (answers[i] == a3[i % a3.size()]) ++result[2];
    }
    for (int i = 0 ; i < 3 ; i++)
      if(*max_element(result.begin(), result.end()) == result[i])
          answer.push_back(i+1);
    return answer;
}
