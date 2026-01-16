#include <string>
#include <vector>

using namespace std;

//출근시간 + 10분까지 출근해야 함. 토/일은 무관.
//시간 = 시 * 100 + 분. 

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    //n : 직원 수
    //schedules : 희망시각
    //timelogs : 실제출근
    //startday : 이벤트 요일
    
    int answer = 0; //상품을 받을 직원의 수.
    
    vector<pair<int, int>> hour_min(schedules.size());
    for (int i = 0; i < schedules.size(); i++) {
        int h = schedules[i] / 100;
        int min = schedules[i] % 100;
        hour_min[i] = {h, min};
    }
    
    vector<bool> successDays(schedules.size(), true); 
    for (int i = 0; i < 7; i++) { //이벤트 N일차
        /*요일 확인*/
        bool isWeekend = startday == 6 || startday == 7;
        startday++; //요일증가.
        if (startday == 8) startday = 1; //요일 초기화.
        if (isWeekend) continue; //주말일 때 패스. 
        
        for (int j = 0; j < timelogs.size(); j++) { //직원별 적합성 검사
            if (!successDays[j]) continue; //한번이라도 실패하면 out.
            
            /*계획 시간 로드*/
            int sch_h = hour_min[j].first;
            int sch_m = hour_min[j].second;
            
            /*출근 시간 로드*/
            int timestamp = timelogs[j][i];
            int time_h = timestamp / 100;
            int time_m = timestamp % 100;
            
            if (sch_h == time_h) {
                if (time_m - sch_m > 10) {
                    successDays[j] = false;
                }
            }
            else if (sch_h < time_h) {
                if (time_h - sch_h > 1) successDays[j] = false;
                else if (time_m + (60 - sch_m) > 10) successDays[j] = false;
            }
        }
    }
    
    for (int i = 0; i < schedules.size(); i++) {
        if (successDays[i]) answer++;
    }
    return answer;
}









