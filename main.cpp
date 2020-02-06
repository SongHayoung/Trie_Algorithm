#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<long long> psum;
vector<long long> need_total;
void is_Possible(vector<int> budgets){
    long long total = 0;
    for(int i=0;i<budgets.size();i++){
        total += budgets[i];
        psum.push_back(total);
        need_total.push_back(total+(budgets[i]*(budgets.size()-1-i)));
    }
}
int solution(vector<int> budgets, int M) {
    sort(budgets.begin(),budgets.end());
    is_Possible(budgets);
    if(psum.back()<=(long long)M){
        return budgets.back();
    }
    if(need_total[0]>(long long)M){
        long long min_Val = need_total[0];
        for(int i=1;i<100000;i++){
            min_Val -= budgets.size();
            if(min_Val<=M)
                return budgets[0]-i;
        }
    }
    int idx, left;
    long long cur_total;
    for(int i=0;i<need_total.size();i++){
        if(need_total[i]>M){
            idx = i-1;
            left = need_total.size()-i;
            cur_total = need_total[idx];
            break;
        }
    }
    for(int i=0;i<10000;i++){
        cur_total += left;
        if(cur_total>M)
            return budgets[idx]+i;
    }
}