#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
	int index;
	int xPos;
	int yPos;
	int energy;
	bool isEny;

	Node(int idx, int x, int y, int erg, bool eny) : index(idx), xPos(x), yPos(y), energy(erg), isEny(eny) {}
};

class Graph {
private:
	/*노드 간 연결관계*/
	vector<vector<int>> linkedList;
	/*각 노드의 상세정보*/
	vector<Node> nodeInfo;

	double startErg; //탑의 시작 에너지
	int range; //탑의 사거리 * 사거리 (거리 측정 쉽게 하기 위해 제곱.)
	int graphSize; //그래프의 노드 개수

	double BFS(int nodeIdx) {
		double resultErg = startErg;

		vector<bool> visitedIdx(graphSize, false);
		queue<int> nextVisit;
		
		visitedIdx[nodeIdx] = true;
		nextVisit.push(nodeIdx);

		while (!nextVisit.empty()) {
			int curSize = nextVisit.size();
			for (int i = 0; i < curSize; i++) { //현재 단계 우선 탐색
				int curNode = nextVisit.front();
				nextVisit.pop();

				for (const int& idx : linkedList[curNode]) {
					if (!visitedIdx[idx]) {
						visitedIdx[idx] = true;
						if (nodeInfo[idx].isEny) {
							return resultErg;
						}
						else {
							nextVisit.push(idx);
						}
					}
				}
			}
			resultErg /= 2; //이번 방문에서 enemy가 없으면 반으로 나누기
		}

		return 0; //모든 노드를 방문했는데 enemy를 못찾는 경우.
	}

public:
	Graph(double erg, int r) : startErg(erg), range(r * r), graphSize(0) {}

	void insertNode(int x, int y, bool isEnemy = false) {
		Node newNode(graphSize, x, y, startErg, isEnemy); //노드 선언
		graphSize++; //사이즈 증가

		linkedList.emplace_back(); //연결리스트 행 추가

		/*새 노드의 범위에 닿는 노드에 간선 추가*/
		for (const Node& n : nodeInfo) { 
			if (range >= (newNode.xPos - n.xPos) * (newNode.xPos - n.xPos)
				+ (newNode.yPos - n.yPos) * (newNode.yPos - n.yPos)) {
				linkedList[newNode.index].push_back(n.index); 
				linkedList[n.index].push_back(newNode.index);
			}
		}

		nodeInfo.push_back(newNode); //새 노드 정보 저장
	}

	void printGraph() {
		for (int i = 0; i < linkedList.size(); i++) {
			for (int j = 0; j < linkedList[i].size(); j++) {
				cout << linkedList[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void attackEnemy() {
		double result = 0;
		for (int i = 1; i < graphSize; i++) {
			result += BFS(i);
		}
		
		cout << fixed << setprecision(2) << result; 
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	/*목표 : 최대한 적게 에너지를 전송하고 적에게 데미지를 주자.*/

	//탑 개수, 탑 범위, 시작 에너지, 적 위치(x, y)
	//0 <= {towerCount <= 50, range <= 500, startErg <= 100}
	//0 <= (x, y) <= 1000
	int towerCount, range, startErg, enyXPos, enyYPos;
	cin >> towerCount >> range >> startErg >> enyXPos >> enyYPos;

	//탑들 + 적 위치를 그래프로 만들기.
	Graph towerGraph(startErg, range);
	towerGraph.insertNode(enyXPos, enyYPos, true); //적 위치

	//탑 위치 입력 & 그래프 생성
	for (int i = 0; i < towerCount; i++) {
		int x, y;
		cin >> x >> y;
		towerGraph.insertNode(x, y);
	}

	///*그래프 디버그용 코드 : 삭제 필요*/
	//cout << endl;
	//towerGraph.printGraph();
	//cout << endl;

	//모든 탑으로부터 적까지의 최단거리(에너지) 계산.
	towerGraph.attackEnemy();
}