#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    auto uniq_prior = priorities;
    sort(uniq_prior.begin(),  uniq_prior.end(), greater<int>());
    auto it = unique(uniq_prior.begin(), uniq_prior.end());
    uniq_prior.resize(distance(uniq_prior.begin(),it) );

    int upper_prior_cnt = 0;
    for (int i = 0; i < priorities.size() ; i++)
        if (priorities[i] > priorities[location]) upper_prior_cnt++;

    int idx =  priorities.size() - 1;
    for (int i = 0 ; uniq_prior[i] != priorities[location]; ++i)
        for (; priorities[idx] != uniq_prior[i] ; --idx) 
            if (idx == 0) idx = priorities.size() ;

    if (upper_prior_cnt == 0) idx = 0;
    int same_prior_idx = 0;
    for (int i = idx ; i % priorities.size() != location ; i++)
        if (priorities[i % priorities.size()] == priorities[location])  same_prior_idx ++;
    
    return upper_prior_cnt + same_prior_idx + 1;
}