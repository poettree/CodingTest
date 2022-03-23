
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//결과
	int answer = 0;
	int seconds = 0;

	//조건
	bool finished = false;
	bool overweight = false;
	bool overlength = false;

	//변수 및 추가 입력 값
	vector<int> wait_on_bridge;
	int sum_wait_on_bridge = 0;



	while (finished)
	{
		seconds++;

		//모든 트럭이 이동 했을때 완료
		if ((truck_weights.size() == 0)&&(wait_on_bridge.size()==0))
		{
			finished = true;
		}

		//대기중인 트럭이 다리위에 올라갔을때
		wait_on_bridge.push_back(truck_weights[0]);
		truck_weights.erase(truck_weights.begin());
		

		//wait_on_bridge는 현재 '다리 위에' 있는 트럭의 정보이기에, 트럭의 수가 다리의 길이보다 길다면, overlength를 true로 변환
		if (bridge_length > wait_on_bridge.size()) {
			overlength = true;
		}

		//'다리 위에'있는 트럭의 총 무게가 다리가 버틸 수 있는 무게보다 크다면, overweight를 true로 변환
		for (int i = 0; i < wait_on_bridge.size(); i++) {
			sum_wait_on_bridge += wait_on_bridge[i];
		}

		if (weight > sum_wait_on_bridge) {
			overweight = true;
		}

		//현재 다리 위 트럭의 수와 무게 검사
		if (overlength && overweight) {
			continue;
		}

		//다리위의 트럭이 다리를 지나갔을때
		wait_on_bridge.erase(wait_on_bridge.begin());


		printf("%d %d, %d", truck_weights.size(), wait_on_bridge.size(),seconds);
	}
	system("pause");

	answer = seconds;

	return answer;
}

void main() {
	solution();
}