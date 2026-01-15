#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> cnt;
    cnt.reserve(participant.size() * 2);

    for (const string& name : participant) cnt[name]++;
    for (const string& name : completion) cnt[name]--;

    for (const auto& kv : cnt)
    {
        if (kv.second != 0) return kv.first;
    }

    return "";
}
