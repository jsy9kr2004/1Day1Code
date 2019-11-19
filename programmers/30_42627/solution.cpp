#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur_idx = 0;
    int tick = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(jobs.begin(), jobs.begin() + jobs.size());
    while (!pq.empty() || cur_idx < jobs.size()) {
        while (cur_idx < jobs.size() && tick >= jobs[cur_idx][0]) {
            pq.push(pair<int,int>(jobs[cur_idx][1], jobs[cur_idx][0]));
            ++cur_idx;
        }
        if (pq.empty()) {
             ++tick;
        } else {
            answer = answer + tick - pq.top().second + pq.top().first;
            tick += pq.top().first;
            pq.pop();
        }
    }
    return answer / jobs.size();
}
