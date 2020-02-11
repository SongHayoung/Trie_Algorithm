#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int,vector<int>,less<int>> pq;
    int idx = 0;
    int answer = 0;
    for(int i=0;i<k;i++){
        if(stock==0){
            for(;dates[idx]<=i;idx++)
                pq.push(supplies[idx]);

            stock += pq.top();
            pq.pop();
            ++answer;
        }
        --stock;
    }
    return answer;
}
