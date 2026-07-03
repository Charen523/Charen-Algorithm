#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

string upper_case(string s) {
    string result = "";
    int delta = 'a' - 'A';
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a') c -= delta;
        result += c;
    }
    return result;
}

int solution(int cacheSize, vector<string> cities) {
    int v_size = cities.size();
    if (cacheSize == 0) return (v_size) * 5;
    
    int answer = 0;
    list<string> LRU;
    unordered_map<string, list<string>::iterator> dict;
    for (int i = 0; i < v_size; i++) {
        string s = upper_case(cities[i]);
        
        if (dict.find(s) != dict.end()) {
            LRU.erase(dict[s]);
            answer++;
        }
        else {
            answer += 5;
        }
        
        LRU.push_front(s);
        dict[s] = LRU.begin();
        
        if (LRU.size() > cacheSize) {
            dict.erase(LRU.back());
            LRU.pop_back();
        }
    }
    
    return answer;
}