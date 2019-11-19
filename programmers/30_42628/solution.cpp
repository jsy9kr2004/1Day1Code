#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> q;
    bool need_sort = false;
    for (int i = 0 ; i < operations.size() ; i++) {
        if (operations[i].substr(0, 1) == "D") {
            if (q.size() == 0) continue;
            if (need_sort) sort(q.begin(), q.end());
            need_sort = false;
            if (operations[i] == "D 1") q.pop_back();
            else q.erase(q.begin());
        } else {
            q.push_back(stoi(operations[i].substr(2, operations[i].length())));
            need_sort = true;
        }
    }
    if (q.size() == 0)
        return {0, 0};
    if (need_sort) sort(q.begin(), q.end());
    return {q.back(),  q.front()};
}
