#include <vector>

using namespace std;

// 1: 빵, 2: 야채, 3: 고기
// 1-2-3-1 이 연속되면 햄버거 1개
int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> st;
    st.reserve(ingredient.size());

    for (int x : ingredient) {
        st.push_back(x);

        if (st.size() >= 4) {
            int n = st.size();
            if (st[n-4] == 1 &&
                st[n-3] == 2 &&
                st[n-2] == 3 &&
                st[n-1] == 1) {

                // 햄버거 제거
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.pop_back();
                answer++;
            }
        }
    }

    return answer;
}