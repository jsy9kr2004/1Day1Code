#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> path(m + 1, vector<int> (n + 1, 0));
    for (int i = 0 ; i < puddles.size() ; ++i)
        path[puddles[i][0]][puddles[i][1]] = -1;
    path[1][1] = 1;
    for (int i = 1 ; i <= m ; ++i) {
    	for (int j = 1 ; j <= n ; ++j) {
            if (i == 1 && j == 1) continue;
            if (path[i][j] == -1) continue;
            if (path[i - 1][j] != -1)
            	path[i][j] = path[i - 1][j];
            if (path[i][j - 1] != -1)
            	path[i][j] = (path[i][j] + path[i][j - 1]) % 1000000007;
        }
    }
    return path[m][n];
}
