#include <iostream>
using namespace std;
int D,W,K;
int film[13][20];

bool check(){
    int cnt;
    for(int i=0;i<W;i++){
        cnt = 1;
        for(int j=1;j<D;j++){
            if(film[j][i]==film[j-1][i])
                ++cnt;
            else if(j>=D-K+1)
                return false;
            else
                cnt = 1;
            if(cnt==K)
                break;
        }
        if(cnt!=K)
            return false;
    }
    return true;
}
bool choose(int choosed,int idx){
    if(choosed==0)
        return check();

    if(idx>=D||D-idx<choosed)
        return false;

    int arr[20];
    for(int i = 0; i < W; i++){
        arr[i] = film[idx][i];
        film[idx][i]=0;
    }
    if(choose(choosed-1,idx+1))
        return true;

    for(int i=0;i<W;i++)
        film[idx][i] = 1;
    if(choose(choosed-1,idx+1))
        return true;

    for(int i=0;i<W;i++)
        film[idx][i] = arr[i];
    if(choose(choosed,idx+1))
        return true;

    return false;
}

int solution(){
    cin>>D>>W>>K;
    for(int i=0;i<D;i++)
        for(int j=0;j<W;j++)
            cin>>film[i][j];

    if(K==1)
        return 0;

    for(int i=0;i<K;i++){
        if(choose(i,0))
            return i;
    }
    return K;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(int test_case=1;test_case<=T;test_case++){
        cout<<"#"<<test_case<<" "<<solution()<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}