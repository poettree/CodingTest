
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

	//���� �� �߰� �Է� ��
	vector<int> wait_on_bridge;
	int sum_wait_on_bridge = 0;



	while (finished)
	{
		seconds++;

		//��� Ʈ���� �̵� ������ �Ϸ�
		if ((truck_weights.size() == 0)&&(wait_on_bridge.size()==0))
		{
			finished = true;
		}

		//������� Ʈ���� �ٸ����� �ö�����
		wait_on_bridge.push_back(truck_weights[0]);
		truck_weights.erase(truck_weights.begin());
		

		//wait_on_bridge�� ���� '�ٸ� ����' �ִ� Ʈ���� �����̱⿡, Ʈ���� ���� �ٸ��� ���̺��� ��ٸ�, overlength�� true�� ��ȯ
		if (bridge_length > wait_on_bridge.size()) {
			overlength = true;
		}

		//'�ٸ� ����'�ִ� Ʈ���� �� ���԰� �ٸ��� ��ƿ �� �ִ� ���Ժ��� ũ�ٸ�, overweight�� true�� ��ȯ
		for (int i = 0; i < wait_on_bridge.size(); i++) {
			sum_wait_on_bridge += wait_on_bridge[i];
		}

		if (weight > sum_wait_on_bridge) {
			overweight = true;
		}

		//���� �ٸ� �� Ʈ���� ���� ���� �˻�
		if (overlength && overweight) {
			continue;
		}

		//�ٸ����� Ʈ���� �ٸ��� ����������
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