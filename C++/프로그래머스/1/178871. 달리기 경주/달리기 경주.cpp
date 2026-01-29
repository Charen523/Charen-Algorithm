#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    unordered_map<string, int> player_order;
    for (int i = 0; i < players.size(); i++) {
        player_order.insert({players[i], i});
    }
    
    for (int i = 0; i < callings.size(); i++) {
        string upper_name = callings[i];
        int idx = player_order[upper_name];
        string lower_name = players[idx - 1];
        
        players[idx] = lower_name;
        player_order[lower_name] = idx;
        
        players[idx - 1] = upper_name;
        player_order[upper_name] = idx - 1;
    }
    
    answer = players;
    return answer;
}