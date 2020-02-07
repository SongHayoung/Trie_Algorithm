#include <vector>
using namespace std;
int NUM[20];
int tot = 0;
int T, size;
int DFS(int idx,int bit_mask){
    if(idx==size){
        int ans = tot;
        for(int i=0;i<idx;i++)
            if(bit_mask&1<<i)
                ans -= 2*NUM[i];
        if(T == ans)
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