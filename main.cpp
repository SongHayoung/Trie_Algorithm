
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class INFO {
public:
    string genre;
    int play;
    int code;
    INFO(string g, int p, int c) : genre(g), play(p), code(c) {}
};
struct cmp_second {
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second > p2.second;
    }
};
struct cmp_myclass {
    bool operator()(INFO info1, INFO info2) {
        if (info1.genre == info2.genre) {
            if (info1.play == info2.play) {
                return info1.code < info2.code;
            }
            else
                return info1.play > info2.play;
        }
        else
            return info1.genre < info2.genre;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> Ranking;
    vector<pair<string, int>>vectorRanking;
    vector<INFO> songlist;
    map<string,int>::iterator it;
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++) {
        Ranking[genres[i]] += plays[i];
        songlist.push_back(INFO(genres[i], plays[i], i));
    }
    for (auto it = Ranking.begin(); it != Ranking.end(); it++) {
        vectorRanking.emplace_back(make_pair(it->first, it->second));
    }
    sort(vectorRanking.begin(), vectorRanking.end(), cmp_second());
    sort(songlist.begin(), songlist.end(),cmp_myclass());
    map<string, int> index_info;
    string cur_string = songlist[0].genre;
    index_info[cur_string] = 0;
    for (int i = 1; i < songlist.size(); i++) {
        if (songlist[i].genre == cur_string)
            continue;
        cur_string = songlist[i].genre;
        index_info[cur_string] = i;
    }
    for (int i = 0; i < vectorRanking.size(); i++) {
        int cnt = 0;
        for (int j = index_info[vectorRanking[i].first]; j < songlist.size(); j++) {
            if (songlist[j].genre == vectorRanking[i].first&&cnt != 2) {
                answer.push_back(songlist[j].code);
                ++cnt;
            }
            else
                break;
        }
    }
    return answer;
}