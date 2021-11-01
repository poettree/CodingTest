
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
#pragma region Various
	vector<int> checker;
	vector<int> answer;
	bool finish = true;
	int count = 0;
	int num = 1;
#pragma endregion


	//Error Check
	if (progresses.size() != speeds.size())
	{
		cout << "ERROR: progress != speeds"<<endl;
		system("Pause");
	}

	while (finish) {
		count++;

		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];

			if (progresses.front() >= 100) {
				checker.push_back(count);
				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());
			}

			if (progresses.empty()) {
				finish = false;
			}

		}
	}

	for (int i = 0; i < checker.size(); i++)
	{
		cout << checker[i] << ", ";
	}

	for (int i = 0; i < checker.size(); i++) {
		if (checker.size() > i + 1) {
			if (checker[i] == checker[i + 1]) {
				num++;
			}
			else {
				answer.push_back(num);
				num = 1;
			}
		}
		else {
			answer.push_back(1);
		}
	}

	return answer;
}

int main() {
	
	vector<int> progresses;
	vector<int> speeds;
	vector<int> checker;
	vector<int> answer;

	int num = 1;

	#pragma region PutData
		progresses.push_back(95);
		progresses.push_back(90);
		progresses.push_back(99);
		progresses.push_back(99);
		progresses.push_back(80);
		progresses.push_back(99);

		speeds.push_back(1);
		speeds.push_back(1);
		speeds.push_back(1);
		speeds.push_back(1);
		speeds.push_back(1);
		speeds.push_back(1);
	#pragma endregion

		for (int i = 0; i < solution(progresses, speeds).size(); i++)
		{
			cout << solution(progresses, speeds)[i]<<endl;
		}
	
	


	system("pause");

	return 0;
}
