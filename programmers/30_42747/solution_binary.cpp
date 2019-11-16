#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int search(int min, int max, vector<int>& v) {
    if (max - min <= 1)
        return v[max - 1] >= max ? max : min;
    int mid = (max + min) / 2;
    if (v[mid - 1] >= mid)
        return search(mid, max, v);
    else return search(min, mid, v);
}

int solution(vector<int> citations) {
    sort(citations.begin(),  citations.end(), greater<int>());
    return search(0, citations.size(), citations);
}
