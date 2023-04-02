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
	bool remainOnGround = true;

	//변수 및 추가 입력 값
	vector<int> bridge_state = {};
	vector<int> through_bridge = {};
	int sum_wait_on_bridge = 0;

	//wait_on_bridge.size() = bridge_length()만큼 만들어줌
	for (int i = 0; i < bridge_length; i++) {
		bridge_state.push_back(0);
	}

	//!finished

	while (!finished) {
		seconds++;
		
		//1. 조건확인
		//1-1. 땅위에 움직일 수 있는 트럭이 남아 있는지?
		if (truck_weights.size() > 0)
		{
			remainOnBridge = true;
		}

		//1-2. 다리위에 트럭이 남아 있는지?
		if (through_bridge.size() > 0)
		{
			remainOnGround = true;
		}

		

		//다리에 올라 갈 수 있는지?
		//1-3. 더이상 움직일수 있는 트럭이 남아있지 않을 경우
		if (!remainOnBridge&&!remainOnGround)
		{
			finished = true;
		}

		//1-4. 올라간 후의 길이
		//다리위의 트럭이 다리길이보다 많을때
		if (bridge_length < through_bridge.size())
		{
			overlength = true;
		}
		
		//1-5-1. 올라간 후의 무게 구하기
		for (int i = 0; i < through_bridge.size(); i++)
		{
			sum_wait_on_bridge += through_bridge[i];
		}


		//1-5-2. 올라간 후의 무게가 다리가 견딜 수 있는 무게보다 클때 
		//땅위에 트럭이 있다면
		if (remainOnGround)
		{
			sum_wait_on_bridge += truck_weights[0];
			// 만약 
			if (weight < sum_wait_on_bridge)
			{
				overweight = true;
			}
		}
		//땅위에 트럭이 없다면 계산을 할필요가 없다.
		else
		{
			overweight = false;
		}



		//2. 진행
		//2-1. 땅위의 트럭이 다리위로 이동한다.
		//만약, 땅위에 트럭이 남아있고, 다리위에 올라갈 수 있는 상황(무게와 길이가 맞는 다면)이라면
		if (remainOnGround && !overweight && !overlength)
		{
			//땅위에서 다리로 이동
			through_bridge.push_back(truck_weights.front());
			bridge_state.push_back(truck_weights.front());
			truck_weights.erase(truck_weights.begin());	
		}
		else
		{
			bridge_state.push_back(0);
		}

		//2-2. 다리위에 있는 트럭이 1칸씩 이동한다. 
		bridge_state.erase(bridge_state.begin());

		//초기화
		bool finished = false;
		bool overweight = false;
		bool overlength = false;

	}

	answer = seconds;
	printf("Answer : %d ", answer);

	system("pause");
	return answer;
}

void main() {
	solution(2,10, { 7,4,5,6 });
}