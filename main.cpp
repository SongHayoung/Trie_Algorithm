#include <string>
#include <vector>
#include <iostream>
using namespace std;
class INFO{
public:
    string name;
    int from;
    int to;
    INFO(string s, int f, int t) : from(f), to(t), name(s) {}
};
vector<INFO> info;
vector<vector<string>> TICKET;
vector<vector<string>> answer;
bool mysort(vector<string> v1, vector<string> v2){
    if(v1[0]<v2[0])
        return true;
    else if(v1[0]==v2[0])
        return v1[1]<v2[1];
    else
        return false;
}

void DFS(string from, int visit,int total, vector<bool> visited, vector<string> ans){
    ans.push_back(from);
    if(visit==total){
        answer.push_back(ans);
        return ;
    }
    int info_idx;
    for(int i=0;i<info.size();i++){
        if(info[i].name==from){
            info_idx = i;
            break;
        }
    }

    for(int to=info[info_idx].from;to<=info[info_idx].to;to++){
        if(!visited[to]){
            visited[to]=true;
            DFS(TICKET[to][1],visit+1,total,visited,ans);
            visited[to]=false;
        }
    }

    return ;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end(),mysort);
    TICKET = tickets;
    string name = tickets[0][0];
    int from = 0;
    int to = -1;
    for(int i=0;i<tickets.size();i++) {
        if (name != tickets[i][0]) {
            INFO infomation(name,from,to);
            info.push_back(infomation);
            name = tickets[i][0];
            from = i;
            to = i-1;
        }
        ++to;
    }
    INFO infomation(name,from,to);
    info.push_back(infomation);
    vector<bool> used(tickets.size(),false);
    vector<string> ans;
    DFS("ICN",0,tickets.size(),used,ans);
    sort(answer.begin(),answer.end());
    return answer[0];
}