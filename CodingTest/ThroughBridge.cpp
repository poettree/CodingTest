//문제 출처:https://programmers.co.kr/job_positions/6376

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
	bool remainOnBridge = false;
	bool remainOnGround = false;

	//변수 및 추가 입력 값
	vector<int> wait_on_bridge = {};
	vector<int> through_bridge = {};
	int sum_wait_on_bridge = 0;

	//wait_on_bridge.size() = bridge_length()만큼 만들어줌
	for (int i = 0; i < bridge_length; i++) {
		wait_on_bridge.push_back(0);
	}

	//!finished

	while (!finished) {

		

		for (int i = 0; i < wait_on_bridge.size(); i++) 
			sum_wait_on_bridge += wait_on_bridge[i];

		if (remainOnGround) {
			if (weight < sum_wait_on_bridge + truck_weights[0])
				overweight = true;
		}
		else if (weight < sum_wait_on_bridge) {
				overweight = true;
				//만약 overwait라서 트럭이 못올라간다면 빈칸 추가
				wait_on_bridge.push_back(0);
		}
		else {
			overweight = false;
		}

		//트럭이 땅->다리로 이동이 가능한지 확인
		//트럭 1대가 추가로 이동이 가능한가?
		if (bridge_length < wait_on_bridge.size())
			overlength = true;

		if (truck_weights.size() > 0)
			remainOnGround = true;
		else
			remainOnGround = false;

		//다리위에 트럭이 올라온 무게로 확인
		if (sum_wait_on_bridge > 0)
			remainOnBridge = true;
		else
			remainOnBridge = false;

		//최종 조건: 땅과 다리 모든 트럭이 이동 했을때
		if (!remainOnGround && !remainOnBridge) {
			finished = true;
			break;
		}

		//트럭이 땅에서 다리로 올라감
		//조건: 트럭이 땅에 있어야하고, 올라갔을때 트럭의 무게와 수가, 다리의 기준에 맞아야 함
		if (remainOnGround && !overweight && !overlength) {
			wait_on_bridge.erase(wait_on_bridge.begin());
			wait_on_bridge.push_back(truck_weights.front());
			truck_weights.erase(truck_weights.begin());
		}

		if (!overlength)
		{
			wait_on_bridge.push_back(0);
		}

		//다리에 있는 트럭이 넘어감
		//조건:다리에 트럭이 남아 있다면
		if (remainOnBridge)
		{
			wait_on_bridge.erase(wait_on_bridge.begin());
			if (wait_on_bridge.size()>0)
			{
				through_bridge.push_back(wait_on_bridge.front());
			}
		}

		printf("%d | %d | %d\n", truck_weights.size(), wait_on_bridge.size(), seconds);
		printf("%d | %d \n", remainOnGround, remainOnBridge);
		printf("%d | %d \n\n", overweight, overlength);

		seconds++;

		//초기화
		sum_wait_on_bridge = 0;
		overweight = false;
		overlength = false;
		remainOnBridge = false;
		remainOnGround = false;
	}

	answer = seconds;
	printf("Answer : %d ", answer);

	system("pause");
	return answer;
}

void main() {
	solution(2,10, { 7,4,5,6 });
}