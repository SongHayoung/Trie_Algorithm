#include <vector>
using namespace std;
int NUM[20];
vector<int> DP(1048576,-1);
int tot = 0;
int T, size;
int dp(int idx,int bit_mask){
    if(idx==size)
        return 0;
    if(bit_mask&1<<idx){
        if(DP[bit_mask]!=-1)
            return DP[bit_mask];
        DP[bit_mask] = dp(idx+1,bit_mask^1<<idx) - 2*NUM[idx];
        return DP[bit_mask];
    }
    else
        return dp(idx+1,bit_mask);
}
int DFS(int idx,int bit_mask){
    if(idx==size){
        if(T == tot + dp(0,bit_mask))
            return 1;
        return 0;
    }
    return DFS(idx+1,bit_mask)+DFS(idx+1,bit_mask|1<<idx);
}
int solution(vector<int> numbers, int target) {
    T = target; size = numbers.size();
    for(int i=0;i<numbers.size();i++)
        tot += NUM[i] = numbers[i];
    return DFS(0,0);
}