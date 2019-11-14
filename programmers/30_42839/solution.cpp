#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
void check_prime(int p_num, int& answer) {
    if (p_num == 0 || p_num == 1 || (p_num % 2 == 0 && p_num != 2) ) return;
    for (int i = 3 ; i < sqrt(p_num + 1) ; i += 2) 
        if (p_num % i == 0) return;
    ++answer;
}

int solution(string numbers) {
    int answer = 0;
    set<int> uniq;
    vector<int> elem(numbers.begin(), numbers.end());
    for(auto& it : elem) it -= 48;
    
    for (int i = 0 ; i < elem.size() ; ++i) {
    	vector<int> idxs(elem.size() - i - 1, 0);
        for (int j = 0; j <= i ; ++j)
            idxs.push_back(j + 1);
    	do {
            int p_num = 0;
            for (int j = 1 ; j < i + 2 ; ++j) {
                for (int k = 0 ; k < elem.size() ; ++k) {
                    if (idxs[k] == j) {
                        p_num = p_num * 10 + elem[k];
                        break;
                    }
                }
            }
            if (uniq.insert(p_num).second)
                check_prime(p_num, answer);
        } while (next_permutation(idxs.begin(), idxs.end()));
    }
    return answer;
}
