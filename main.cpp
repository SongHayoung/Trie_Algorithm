#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool mysort(vector<int> v1, vector<int> v2){
    if(v1[1]<v2[1])
        return true;
    if(v1[1]==v2[1])
        return v1[0]<v2[0];
    return false;
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end(),mysort);
    int pos = routes[0][1];
    for(int i=0;i<routes.size();i++){
        if(pos<routes[i][0]) {
            pos = routes[i][1];
            answer++;

        }
    }
    return answer;
}