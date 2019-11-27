#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> weight) {
    int sum = 0;
    sort(weight.begin(), weight.end());
    for (int i = 0 ; i < weight.size() ; ++i) {
        if (weight[i] > sum + 1) return sum + 1;
        sum += weight[i];
    }
    return sum + 1;
}
