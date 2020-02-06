#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> myMAP;
    map<string, int>::iterator it;
    int answer = 1;
    for (int i = 0; i<clothes.size(); i++) {
        myMAP[clothes[i][1]] += 1;
    }
    for (it = myMAP.begin(); it != myMAP.end(); it++) {
        answer *= it->second+1;
    }
    return answer-1;
}