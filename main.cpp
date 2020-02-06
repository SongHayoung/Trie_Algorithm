#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool compare(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    s1 += s1; s1 += s1;
    s2 += s2; s2 += s2;
    int idx = 0;
    while (idx != 4) {
        if (s1[idx] > s2[idx])
            return true;
        else if (s1[idx] < s2[idx])
            return false;
        else
            ++idx;
    }
    return n1 <= n2 ? false : true;
}
string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    if (numbers[0] == 0)
        return "0";
    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}