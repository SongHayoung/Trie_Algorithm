#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    vector<int> inyoung(10001,0);
    int max_inyoung = 0;
    int total_inyoung = 0;
    for(int i=0;i<citations.size();i++){
        inyoung[citations[i]]+=1;
        max_inyoung = max_inyoung < citations[i] ? citations[i]:max_inyoung;
        total_inyoung += 1;
    }
    int answer = 0;
    int cur_inyoung = total_inyoung;
    for(int i=0;i<=max_inyoung;i++){
        if(cur_inyoung>=i&&total_inyoung-cur_inyoung<=i)
            answer = i;
        cur_inyoung -= inyoung[i];
    }
    return answer;
}