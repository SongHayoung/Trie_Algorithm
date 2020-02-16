#include <stdio.h>
#include <memory.h>

#define Alpha_N_Nums 62
#define INPUTS 20
#define LETTERS 20

inline int get_Index(char c);
inline bool is_Alpha(char c);

struct Trie{
    Trie *next[Alpha_N_Nums];
    bool is_Finish;
    Trie() : is_Finish(false){
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for(int i=0;i < Alpha_N_Nums; i++)
            if(next[i]!=0)
                delete next[i];
    }
    void insert(const char *key){
        if(is_Alpha(*key)!=0){
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
    if('A'<=c&&c<='Z')
        return c-'A';
    else if('a'<=c&&c<='z')
        return 26 + c - 'a';
    else
        return 52 + c - '0';
}

inline bool is_Alpha(char c){
    return ('a'<=c&&c<='z')||('A'<=c&&c<='Z')||('0'<=c&&c<='9');
}

int main(int argc, char** argv){
    char input[INPUTS][26] = {"eevee", "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon", "pikachu",
                          "Charizard", "Butterfree", "Dragonite", "Mewtwo", "Mew", "Persian", "001Bulbasaur", "002bulbasaur", "Venusaur003", "5011"};

    char prefixes[LETTERS][26] = {"pika", "leaf", "monster", "eve", "espn", "umbrella", "flame", "grace", "sylveon", "poket",
                             "Butter", "001B", "Venusaur003", "50", "Mew", "p", "003", "Vinus", "Hayoung", "KOREA"};
    Trie *root = new Trie();
    for(int i=0;i<INPUTS;i++){
        printf("INPUT %s\n",input[i]);
        root->insert(input[i]);
    }
    printf("\n\n\n");
    for(int i=0;i<LETTERS;i++){
        root->is_Prefix(prefixes[i]) ?
        printf("Is Prefix %s ? : YES\n",prefixes[i]) : printf("IS Prefix %s ? : NO\n",prefixes[i]);
    }
    printf("\n\n\n");
    for(int i=0;i<LETTERS;i++){
        root->is_Exsist(prefixes[i]) ?
        printf("Is Exsist %s ? : YES\n",prefixes[i]) : printf("IS Exsist %s ? : NO\n",prefixes[i]);
    }
    delete root;
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
