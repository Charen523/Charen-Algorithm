#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// data : code / date / max / remain
// ext : 어떤 정보가 기준인가
// val_ext : 정보의 기준값
// sort_by : 정렬 기준
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ex_type;
    if (ext == "code") {
        ex_type = 0;
    }
    else if (ext == "date") {
        ex_type = 1;
    }
    else if (ext == "maximum") {
        ex_type = 2;
    }
    else if (ext == "remain") {
        ex_type = 3;
    }
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i][ex_type] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    int sort_type;
    if (sort_by == "code") {
        sort_type = 0;
    }
    else if (sort_by == "date") {
        sort_type = 1;
    }
    else if (sort_by == "maximum") {
        sort_type = 2;
    }
    else if (sort_by == "remain") {
        sort_type = 3;
    }
    
    sort(answer.begin(), answer.end(),
        [sort_type](const vector<int>& a, const vector<int>& b) {
            return a[sort_type] < b[sort_type];
        }
    );
    
    return answer;
}