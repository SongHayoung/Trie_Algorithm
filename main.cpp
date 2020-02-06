#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        if(phone_book[i].length()>phone_book[i+1].length())
            continue;
        for(int j=0;j<phone_book[i].length();j++){
            if(phone_book[i][j]!=phone_book[i+1][j])
                break;
            if(j==phone_book[i].length()-1)
                return false;
        }
    }
    return true;
}