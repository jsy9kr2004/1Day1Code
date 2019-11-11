#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  int pre_due = (100 - progresses[0]) / speeds[0];
  int release_cnt = 0;
  int due = 0;
  for (int i = 0; i < progresses.size(); ++i) {
    due = (100 - progresses[i]) / speeds[i];
    if (pre_due < due) {
      answer.push_back(release_cnt);
      release_cnt = 0;
      pre_due = due;
    }
    release_cnt ++;
  }
  answer.push_back(release_cnt);
  return answer;
}
