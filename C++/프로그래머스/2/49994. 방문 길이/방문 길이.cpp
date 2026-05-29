#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

unordered_map<char, pair<int, int>> dir_map = { {'U', {0, 1}}, {'D', {0, -1}},
                                               {'R', {1, 0}}, {'L', {-1, 0}} };

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

bool isInRange(const pair<int, int>& p) {
    return -5 <= p.first && p.first <= 5 &&
           -5 <= p.second && p.second <= 5;
}

string ptos(pair<int, int> p) {
    return to_string(p.first) + " " + to_string(p.second);
}

int solution(string dirs) {
    int answer = 0;
    
    pair<int, int> s_point = {0, 0};
    pair<int, int> e_point = {0, 0};
    
    unordered_set<string> used_set;
    
    for (char d : dirs) {
        e_point = s_point + dir_map[d];
        string s_str = ptos(min(s_point, e_point));
        string e_str = ptos(max(s_point, e_point));
        string line_str = s_str + "*" + e_str;
        
        if (used_set.find(line_str) == used_set.end()) {    
            if (isInRange(s_point) && isInRange(e_point)) {
                used_set.insert(line_str);  
                answer++;    
            }
            else {
                e_point = s_point;
            }
        }
        
        s_point = e_point;
    }
    
    return answer;
}