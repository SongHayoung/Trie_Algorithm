#include <vector>
#include <math.h>
#include <queue>
#include <iostream>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N;
int MAXGroup;
class INFO{
public:
    int from;
    int to;
    int cost;
    INFO(int f, int t, int c) : from(f), to(t), cost(c) {}
};

class cmp{
public:
    bool operator()(INFO a, INFO b){
        return a.cost>b.cost;
    }
};
priority_queue<INFO,vector<INFO>,cmp> pq;
vector<int> V;

void makeGroup(int groupnum,vector<vector<int>> MAP,int H){
    vector<vector<int>> Group(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(Group[i][j]==0){
                Group[i][j]=groupnum;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int near_x = x + dx[k];
                        int near_y = y + dy[k];
                        if(0<=near_x&&near_x<N && 0<=near_y&&near_y<N){
                            if(Group[near_y][near_x]==0&&abs(MAP[near_y][near_x]-MAP[y][x])<=H){
                                q.push(make_pair(near_y,near_x));
                                Group[near_y][near_x]=groupnum;
                            }
                        }
                    }
                }
                ++groupnum;
            }
        }
    }
    MAXGroup = groupnum;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=1;k<=2;k++){
                int near_x = j + dx[k];
                int near_y = i + dy[k];
                if(0<=near_x&&near_x<N && 0<=near_y&&near_y<N){
                    if(Group[i][j]!=Group[near_y][near_x]){
                        INFO info(Group[i][j],Group[near_y][near_x],abs(MAP[i][j]-MAP[near_y][near_x]));
                        pq.push(info);
                    }
                }
            }
        }
    }
}

int findGroup(int idx){
    if(V[idx]==idx)
        return idx;
    return V[idx] = findGroup(V[idx]);
}

int solution(vector<vector<int>> land, int height) {
    N = land.size();
    makeGroup(1,land,height);
    int answer = 0;
    V.resize(MAXGroup);
    for(int i=0;i<V.size();i++)
        V[i]=i;
    while(!pq.empty()){
        if(findGroup(pq.top().to)!=findGroup(pq.top().from)){
            answer += pq.top().cost;
            int change = min(findGroup(pq.top().to),findGroup(pq.top().from));
            V[findGroup(pq.top().to)] = V[findGroup(pq.top().from)] = change;
        }
        pq.pop();
    }
    return answer;
}