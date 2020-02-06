#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int MAP[101][101] = {0,};
    int DP[101][101];
    for(int i=0;i<puddles.size();i++){
        MAP[puddles[i][1]][puddles[i][0]] = -1;}
    DP[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(MAP[i][j]==-1)
                DP[i][j]=0;
            else
                DP[i][j] = (DP[i-1][j]+DP[i][j-1])%1000000007;
        }
    }
    return DP[n][m];
}