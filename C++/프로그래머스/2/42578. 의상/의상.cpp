#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> cloth_types;
    
    int row = clothes.size();
    int col = clothes[0].size();
    for (int i = 0; i < row; i++) {
        string _name = clothes[i][0];
        string _type = clothes[i][1];
        
        if (!cloth_types.contains(_type)) {
            cloth_types[_type] = 1;
        }
        else cloth_types[_type]++;
    }
    
    for (auto& [key, value] : cloth_types) {
        answer *= value + 1;
    }
    
    return answer - 1;
}