#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> prefix;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            string s = operations[i].substr(2,operations[i].length()-2);
            prefix.push_back(atoi(s.c_str()));
        }
        else{
            if(prefix.size()==0)
                continue;
            if(operations[i].length()==3){
                prefix.erase(prefix.begin()+prefix.size()-1);
            }
            else
                prefix.erase(prefix.begin());
        }
        sort(prefix.begin(),prefix.end());
    }
    vector<int> answer;
    if(prefix.size()!=0){
        answer.push_back(prefix[prefix.size()-1]);
        answer.push_back(prefix[0]);}
    else{
        answer.push_back(0); answer.push_back(0);
    }
    return answer;
}