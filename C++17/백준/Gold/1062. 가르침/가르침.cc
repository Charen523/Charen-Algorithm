#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxCount;
int result;
int baseMask;
vector<int> wordMasks;
vector<int> candidates;

void dfs(int idx, int selectCount, int learnMask) {
    if (selectCount == maxCount) {
        int readable = 0;

        for (int w : wordMasks) {
            if (!(w & ~learnMask)) readable++;
        }

        result = max(result, readable);
        return;
    }

    int candidateSize = candidates.size();
    if (idx == candidateSize) return; 
    if (maxCount > selectCount + (candidateSize - idx)) return;

    dfs(idx + 1, selectCount + 1, learnMask | (1 << candidates[idx]));
    dfs(idx + 1, selectCount, learnMask);
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;

    //anta tica 는 기본 포함. 
    //->a, c, i, n, t
    if (K < 5) {
        cout << 0; 
        return 0;
    }
    else if (K >= 26) {
        cout << N; 
        return 0;
    }

    maxCount = K - 5;
    result = 0;

    //baseMask 초기화
    baseMask = 0;
    baseMask |= (1 << ('a' - 'a'));
    baseMask |= (1 << ('c' - 'a'));
    baseMask |= (1 << ('i' - 'a'));
    baseMask |= (1 << ('n' - 'a'));
    baseMask |= (1 << ('t' - 'a'));

    //wordMask 세팅
    wordMasks.reserve(N);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int mask = 0;

        int len = s.size();
        for (int j = 0; j < len; j++) { 
            int bit = 1 << (s[j] - 'a');
            if (bit & baseMask) continue;
            mask |= bit;
        }

        wordMasks.push_back(mask);
    }

    //candidate 초기화
    candidates.reserve(21);
    for (int i = 0; i < 26; i++) {
        int bit = 1 << i;
        if (!(bit & baseMask)) {
            candidates.push_back(i);
        }
    }

    dfs(0, 0, baseMask);
    
    cout << result;
	return 0;
}