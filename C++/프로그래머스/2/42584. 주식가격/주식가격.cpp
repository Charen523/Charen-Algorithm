#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    int vSize = prices.size();
    vector<int> answer(vSize);
    
    for (int i = 0; i < vSize; i++) {
        answer[i] = vSize - i - 1; //default.
    }
    
    priority_queue<pair<int, int>> pq; //{ 현재 가격, 시간 }
    
    for (int i = 0; i < vSize; i++) {
        int curPrice = prices[i];
        
        while (!pq.empty() && pq.top().first > curPrice) {
            pair<int, int> p = pq.top();
            answer[p.second] = i - p.second;
            pq.pop();
        }
        pq.push({curPrice, i});
    }
    
    return answer;
}