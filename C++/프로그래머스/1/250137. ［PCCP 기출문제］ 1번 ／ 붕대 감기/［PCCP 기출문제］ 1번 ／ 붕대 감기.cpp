#include <string>
#include <vector>

using namespace std;

//bandage : [시전시간, 초당 회복량, 추가 회복량]
//health : 최대체력
//attacks : [공격시간, 피해량]
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int heal_charge = bandage[0];
    int per_heal = bandage[1];
    int bonus_heal = bandage[2];
    int max_heal = per_heal * heal_charge + bonus_heal;
    
    int heal_time = attacks[0][0]; //붕대시작시간
    int cur_health = health - attacks[0][1]; //현재 체력
    
    int attack_count = attacks.size();
    for (int i = 1; i < attack_count; i++) {
        int attack_time = attacks[i][0]; //공격받은 시간
        int damage = attacks[i][1];
        
        int healed_time = attack_time - heal_time - 1; //연속 치료 시간
        
        //붕대 완전히 감은 시간.
        int heal_count = healed_time / heal_charge;
        cur_health += max_heal * heal_count; 
        
        //charge 미완료 시간.
        int left_heal = healed_time % heal_charge; 
        cur_health += left_heal * per_heal; 
        
        //최대체력 이상인지 검사
        cur_health = min(cur_health, health); 
        
        cur_health -= damage; //데미지 적용
        if (cur_health <= 0) return -1; //사망
        
        heal_time = attack_time; //공격 직후 새로운 붕대감기
    }
    
    return cur_health;
}