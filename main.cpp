#include <string>
#include <vector>
#include <math.h>
using namespace std;
int number[10]={0,};
int answer = 0,size;
int cur_size;
void calc(int d,string &s,vector<bool> &Primes){
    if(d==cur_size){
        if((atoi(s.c_str())&1)==0)
            return ;
        if(Primes[atoi(s.c_str())/2]){
            ++answer;
        }
        return ;
    }
    for(int i=0;i<=9;i++){
        if(number[i]!=0){
            --number[i];
            s[d] = i + 48;
            calc(d + 1, s, Primes);
            ++number[i];
        }
    }
}

int solution(string numbers) {
    size = numbers.length();
    string s;
    int MAXLEN = pow(10,size);
    vector<bool> Primes(MAXLEN/2,true);
    for(int i=0;i<size;i++){
        s+=" ";
        ++number[numbers[i]-'0'];
    }
    Primes[0] = false;
    for(int i=3;i<MAXLEN;i+=2){
        if(!Primes[i/2])
            continue;
        for(int j=i*3;j<MAXLEN;j+=i*2){
            Primes[j/2] = false;
        }
    }
    if(number[2]>0)
        ++answer;
    for(cur_size=1;cur_size<=size;cur_size++) {
        for (int i = 1; i <= 9; i++) {
            if (number[i] != 0) {
                --number[i];
                s[0] = i + 48;
                calc(1, s, Primes);
                ++number[i];
            }
        }
    }
    return answer;
}