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
	bool remainOnGround = true;

	//���� �� �߰� �Է� ��
	vector<int> bridge_state = {};
	vector<int> through_bridge = {};
	int sum_wait_on_bridge = 0;

	//wait_on_bridge.size() = bridge_length()��ŭ �������
	for (int i = 0; i < bridge_length; i++) {
		bridge_state.push_back(0);
	}

	//!finished

	while (!finished) {
		seconds++;
		
		//1. ����Ȯ��
		//1-1. ������ ������ �� �ִ� Ʈ���� ���� �ִ���?
		if (truck_weights.size() > 0)
		{
			remainOnBridge = true;
		}

		//1-2. �ٸ����� Ʈ���� ���� �ִ���?
		if (through_bridge.size() > 0)
		{
			remainOnGround = true;
		}

		

		//�ٸ��� �ö� �� �� �ִ���?
		//1-3. ���̻� �����ϼ� �ִ� Ʈ���� �������� ���� ���
		if (!remainOnBridge&&!remainOnGround)
		{
			finished = true;
		}

		//1-4. �ö� ���� ����
		//�ٸ����� Ʈ���� �ٸ����̺��� ������
		if (bridge_length < through_bridge.size())
		{
			overlength = true;
		}
		
		//1-5-1. �ö� ���� ���� ���ϱ�
		for (int i = 0; i < through_bridge.size(); i++)
		{
			sum_wait_on_bridge += through_bridge[i];
		}


		//1-5-2. �ö� ���� ���԰� �ٸ��� �ߵ� �� �ִ� ���Ժ��� Ŭ�� 
		//������ Ʈ���� �ִٸ�
		if (remainOnGround)
		{
			sum_wait_on_bridge += truck_weights[0];
			// ���� 
			if (weight < sum_wait_on_bridge)
			{
				overweight = true;
			}
		}
		//������ Ʈ���� ���ٸ� ����� ���ʿ䰡 ����.
		else
		{
			overweight = false;
		}



		//2. ����
		//2-1. ������ Ʈ���� �ٸ����� �̵��Ѵ�.
		//����, ������ Ʈ���� �����ְ�, �ٸ����� �ö� �� �ִ� ��Ȳ(���Կ� ���̰� �´� �ٸ�)�̶��
		if (remainOnGround && !overweight && !overlength)
		{
			//�������� �ٸ��� �̵�
			through_bridge.push_back(truck_weights.front());
			bridge_state.push_back(truck_weights.front());
			truck_weights.erase(truck_weights.begin());	
		}
		else
		{
			bridge_state.push_back(0);
		}

		//2-2. �ٸ����� �ִ� Ʈ���� 1ĭ�� �̵��Ѵ�. 
		bridge_state.erase(bridge_state.begin());

		//�ʱ�ȭ
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