#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class INFO{
public:
    int solved;
    int number;
    int score;
    vector<int> questions;
    INFO(int n) : number(n) {
        solved = 0;
    }
    void insert(int s){
        questions.push_back(s);
        solved += s;
    }
    void calculate_score(vector<int> T){
        score = 0;
        for(int i=0;i<questions.size();i++){
            if(questions[i]==1){
                score+=T[i];
            }
        }
    }
};
bool SortByINFO(INFO i1, INFO i2){
    if(i1.score==i2.score){
        if(i1.solved==i2.solved)
            return i1.number<i2.number;
        return i1.solved>i2.solved;
    }
    return i1.score>i2.score;
}

void solution(int tc){
    int N,T,P;
    char score;
    scanf("%d%d%d",&N,&T,&P);
    getchar();
    vector<int> Tests(T,N);
    vector<INFO> peoples;
    for(int i=1;i<=N;i++){
        peoples.push_back(INFO(i));
        for(int j=0;j<T;j++){
            score = getchar();
            getchar();
            if(score=='0'){
                peoples[i-1].insert(0);
            }else{
                peoples[i-1].insert(1);
                Tests[j]-=1;
            }
        }
    }
    peoples[P-1].calculate_score(Tests);
    int standard_score = peoples[P-1].score;
    int standard_solv = peoples[P-1].solved;
    int rank = 1;
    for(int i=0;i<peoples.size();i++){
        peoples[i].calculate_score(Tests);}
    for(int i=0;i<peoples.size();i++){
        if(peoples[i].score>standard_score)
            ++rank;
        else if(peoples[i].score==standard_score){
            if(peoples[i].solved>standard_solv)
                ++rank;
            else if(peoples[i].solved==standard_solv)
                if(peoples[i].number<P)
                    ++rank;
        }
    }
    /*
    vector<INFO>::iterator new_it;
    for(vector<INFO>::iterator it = peoples.begin(); it!=peoples.end();it++){
        it->calculate_score(Tests);
        if(it->score>standard_score){
            ++rank;
        }
        else if(it->score==standard_score){
            if(it->solved>standard_solv)
                ++rank;
            else if(it->solved==standard_solv){
                if(it->number<P)
                    ++rank;
            }
        }
    }*/
    printf("#%d %d %d\n",tc,standard_score,rank);
    return ;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        solution(test_case);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}