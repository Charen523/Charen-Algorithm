#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    int turn = 1;
    int hID = 0;
    char lastWord = '0';
    unordered_set<string> usedList;
    for (const string& w : words) {
        if (hID == n) {
            hID = 0;
            turn++;
        }
        
        //게임 끗.
        if (usedList.find(w) != usedList.end()
           || (lastWord != '0' && lastWord != w[0])) { 
            answer[0] = hID + 1;
            answer[1] = turn;
            break;
        }
        
        usedList.insert(w);
        hID++;
        lastWord = w[w.size() - 1];
    }

    return answer;
}