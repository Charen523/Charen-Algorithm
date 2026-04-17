#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<char> st;
    st.reserve(s.size());

    for (char c : s)
    {
        if (!st.empty() && st.back() == c)
        {
            st.pop_back();
        }
        else
        {
            st.push_back(c);
        }
    }

    return st.empty() ? 1 : 0;
}