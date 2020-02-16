#include <stdio.h>
#include <memory.h>

#define Alpha 26

inline int get_Index(char c);
inline bool is_Alpha(char c);
struct Trie{
    Trie *next[Alpha];
    bool is_Finish;
    Trie() : is_Finish(false){
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for(int i=0;i < Alpha; i++)
            if(next[i]!=0)
                delete next[i];
    }
    void insert(const char *key){
        if(is_Alpha(*key)){
            if(next[get_Index(*key)]==0)
                next[get_Index(*key)] = new Trie();
            next[get_Index(*key)]->insert(key+1);
        }
        else
            is_Finish = true;
    }
    bool is_Exsist(const char *key){
        if(is_Alpha(*key)){
            if(next[get_Index(*key)]==0)
                return false;
            return next[get_Index(*key)]->is_Exsist(key+1);
        }
        return is_Finish;
    }
    bool is_Prefix(const char *key){
        if(is_Alpha(*key)){
            if(next[get_Index(*key)]==0)
                return false;
            return next[get_Index(*key)]->is_Prefix(key+1);
        }
        return true;
    }
};
inline int get_Index(char c){
    return c-'a';
}
inline bool is_Alpha(char c){
    return 'a'<=c&&c<='z';
}
int main(int argc, char** argv)
{
    char input[10][26] = {"eevee", "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon", "pikachu"};
    char prefixes[10][26] = {"pika", "leaf", "monster", "eve", "espn", "umbrella", "flame", "grace", "sylveon", "poket"};
    Trie *root = new Trie();
    for(int i=0;i<10;i++){
        printf("INPUT %s\n",input[i]);
        root->insert(input[i]);
    }
    for(int i=0;i<10;i++){
        root->is_Prefix(prefixes[i]) ?
        printf("Is Prefix %s ? : YES\n",prefixes[i]) : printf("IS Prefix %s ? : NO\n",prefixes[i]);
    }
    for(int i=0;i<10;i++){
        root->is_Exsist(prefixes[i]) ?
        printf("Is Exsist %s ? : YES\n",prefixes[i]) : printf("IS Exsist %s ? : NO\n",prefixes[i]);
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
