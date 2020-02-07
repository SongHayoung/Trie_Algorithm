#include <vector>
using namespace std;
int NUM[20],tot = 0,T, size;
vector<int> DP(1048576,-1);
int dp(int idx,int bit_mask){
    if(idx==size)
        return 0;
    if(DP[bit_mask]!=-1)
        return DP[bit_mask];
    if(bit_mask&1<<idx){
        DP[bit_mask] = dp(idx+1,bit_mask^1<<idx) - 2*NUM[idx];
        return DP[bit_mask];
    }
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

/*
 * 포인터 처리
#include <vector>
using namespace std;
vector<int> *NUM;
int *Target;
int answer;
void DFS(int sum,int n) {
    if(n >= NUM->size()){
        if(sum == *Target) answer++;
        return;
    }

    DFS(sum , n+1);
    DFS(sum - NUM->at(n)*2, n+1);
}

int solution(vector<int> numbers, int target) {
    int total = 0;
    for(int i=0;i<numbers.size();i++)
        total += numbers[i];
    NUM = &numbers;
    Target = &target;
    DFS(total , 1);
    DFS(total-2*numbers[0], 1);

    return answer;
}
 */