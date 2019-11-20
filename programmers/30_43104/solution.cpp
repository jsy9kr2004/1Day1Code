#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    if (N == 1) return 4;
    else if (N == 2) return 6;
    vector<long long> cal = {2, 1};
    for (int i = 3 ; i < N ; ++i)
        cal.insert(cal.begin(), cal[0] + cal[1]);
    return cal[0] * 4 + cal[1] * 2;
}
