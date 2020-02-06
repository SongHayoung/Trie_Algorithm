#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool mysort(vector<int> v1, vector<int> v2){
    if(v1[0]<v2[0])
        return true;
    else if(v1[0]==v2[0]){
        if(v1[1]<v2[1])
            return true;
    }
    return false;
}
int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(),jobs.end(),mysort);
    int answer = 0;
    int size = jobs.size();
    int start_time=0;
    while(jobs.size()!=0){
        int choose = 987654321;
        int during_time = 987654321;
        for(int i=0;i<jobs.size();i++){
            if(jobs[i][0]>start_time)
                break;
            if(during_time>jobs[i][1]){
                choose = i;
                during_time = jobs[i][1];
            }
        }
        if(choose<500){
            answer += jobs[choose][1]+start_time-jobs[choose][0];
            start_time += jobs[choose][1];
            jobs.erase(jobs.begin()+choose);
        }
        else{
            ++start_time;
        }
    }
    return answer/size;
}