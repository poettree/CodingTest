//���� ��ó:https://programmers.co.kr/job_positions/6376

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//���
	int answer = 0;
	int seconds = 0;

	//����
	bool finished = false;
	bool overweight = false;
	bool overlength = false;
	bool remainOnBridge = false;
	bool remainOnGround = false;

	//���� �� �߰� �Է� ��
	vector<int> wait_on_bridge = {};
	int sum_wait_on_bridge = 0;

	//!finished

	while (!finished) {
		
		//���� ����: ���� �ٸ� ��� Ʈ���� �̵� ������
		if (!remainOnGround && !remainOnBridge) {
			finished = true;
		}

		//Ʈ���� ��->�ٸ��� �̵��� �������� Ȯ��
		//Ʈ�� 1�밡 �߰��� �̵��� �����Ѱ�?
		if (bridge_length < wait_on_bridge.size() + 1)
			overlength = true;

		if (truck_weights.size() > 0)
			remainOnGround = true;
		else
			remainOnGround = false;

		if (wait_on_bridge.size() > 0)
			remainOnBridge = true;
		else
			remainOnBridge = false;

		for (int i = 0; i < wait_on_bridge.size(); i++) 
			sum_wait_on_bridge += wait_on_bridge[i];

		if (remainOnGround) {
			if (weight < sum_wait_on_bridge + truck_weights[0])
				overweight = true;
		}
		else if (weight < sum_wait_on_bridge) {
			if (weight < sum_wait_on_bridge)
				overweight = true;
		}
		else {
			overweight = false;
		}

		//Ʈ���� ������ �ٸ��� �ö�
		//����: Ʈ���� ���� �־���ϰ�, �ö����� Ʈ���� ���Կ� ����, �ٸ��� ���ؿ� �¾ƾ� ��
		if (remainOnGround && !overweight && !overlength) {
			wait_on_bridge.push_back(truck_weights.front());
			truck_weights.erase(truck_weights.begin());
		}

		//�ٸ��� �ִ� Ʈ���� �Ѿ
		//�ٸ��� Ʈ���� ���� �ִٸ�
		if (remainOnBridge)
		{
			wait_on_bridge.erase(wait_on_bridge.begin());
		}

		printf("%d | %d | %d\n", truck_weights.size(), wait_on_bridge.size(), seconds);
		printf("%d | %d\n\n", remainOnGround, remainOnBridge);

		seconds++;
	}

	answer = seconds;
	printf("Answer : %d ", answer);

	system("pause");
	return answer;
}

void main() {
	solution(2, 10, { 7,4,5,6 });
}