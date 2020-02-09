#include <vector>
#include <algorithm>
using namespace std;
int b[3], d[3];
int strike = 0, ball = 0;
vector<int> possible;
bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1]==v2[1])    return v1[2]>v2[2];
    return v1[1]>v2[1];
}
inline bool is_Possible(vector<int> &baseball){
    strike = 0, ball = 0;
    for(int f=0;f<3;f++){
        for(int l=0;l<3;l++) {
            if (b[f] == d[l]) {
                if (f != l)
                    ++ball;
                else
                    ++strike;
            }
            //if(ball>baseball[2]||strike>baseball[1])  return false;
        }
    }
    if(strike == baseball[1] && ball == baseball[2])    return true;
    return false;
}
int solution(vector<vector<int>> baseball) {
    possible.reserve(1000);
    //sort(baseball.begin(),baseball.end(),cmp);
    b[0] = baseball[0][0]/100;
    b[1] = (baseball[0][0]/10)%10;
    b[2] =  baseball[0][0]%10;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i==j)
                continue;
            for(int k=1;k<=9;k++){
                if(j==k||i==k)
                    continue;
                d[0] = i, d[1] = j, d[2] = k;
                if(is_Possible(baseball[0])){
                    possible.push_back(i*100+j*10+k);
                }
            }
        }
    }
    for(int i=1;i<baseball.size();i++){
        for(int j=0;j<possible.size();j++){
            strike = 0, ball = 0;
            b[0] = baseball[i][0]/100;
            b[1] = (baseball[i][0]/10)%10;
            b[2] = baseball[i][0]%10;
            d[0] = possible[j]/100;
            d[1] = (possible[j]/10)%10;
            d[2] = possible[j]%10;

            if(!is_Possible(baseball[i])){
                possible.erase(possible.begin()+j);
                --j;
            }
        }
    }
    return possible.size();
}