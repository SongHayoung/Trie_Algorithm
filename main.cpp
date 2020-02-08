#include <string>
#include <vector>
#include <math.h>
using namespace std;
int number[10]={0,};
int answer = 0,size;
int cur_size;
void calc(int d,int &s,vector<bool> &Primes){
    if(d==cur_size){
        if((s&1)&Primes[s/2])
            ++answer;
        return ;
    }
    for(int i=0;i<=9;i++){
        if(number[i]!=0){
            --number[i];    s *=10 + i;
            calc(d + 1, s, Primes);
            s /= 10;    ++number[i];
        }
    }
}

int solution(string numbers) {
    size = numbers.length();
    int MAXLEN = pow(10,size);
    vector<bool> Primes(MAXLEN/2,true);
    for(int i=0;i<size;i++)
        ++number[numbers[i]-48];

    Primes[0] = false;
    for(long long i=3;i*i<MAXLEN;i+=2){
        if(!Primes[i/2])
            continue;
        for(long long j=i*i;j<MAXLEN;j+=i*2)
            Primes[j/2] = false;
    }
    if(number[2]>0)
        ++answer;
    for(cur_size=1;cur_size<=size;cur_size++)
        for (int i = 1; i <= 9; i++)
            if (number[i] != 0) {
                --number[i];
                calc(1, i, Primes);
                ++number[i];
            }
    return answer;
}