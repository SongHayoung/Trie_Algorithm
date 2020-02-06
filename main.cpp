#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    for(int i=0;i<s.length();i++){
        for(int start=0;start<=i;start++){
            bool flag = true;
            for(int k=0;k<(s.length()-i)/2;k++){
                if(s[k+start]!=s[s.length()-1-i+start-k]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return s.length()-i;
        }
    }
    return -1;
}