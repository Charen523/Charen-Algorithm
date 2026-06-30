#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    int v_size = phone_book.size();
    
    unordered_set<string> us;
    int min_len = 20;
    for (int i = 0; i < v_size; i++) {
        string s = phone_book[i];
        int str_size = s.size();
        min_len = min(min_len, str_size);
        us.insert(s);
    }
    
    for (int i = 0; i < v_size; i++) {
        string s = phone_book[i];
        int str_size = s.size();
        if (str_size == min_len) continue;
        
        for (int j = min_len; j < str_size; j++) {
            string sub_str = s.substr(0, j);
            if (us.find(sub_str) != us.end()) {
                return false;
            }
        }
    }
    
    return true;
}