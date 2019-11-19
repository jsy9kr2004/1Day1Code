#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int cur_idx = 0;
    priority_queue<int> pq;
    while (stock < k) {
        while (cur_idx < dates.size() && dates[cur_idx] <= stock)
            pq.push(supplies[cur_idx++]);
        stock += pq.top();
        pq.pop();
        ++answer;
    }
    return answer;
}
