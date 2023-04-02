
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
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

	for (int i = 0; i < progresses.size(); i++) {
		checker.push_back(ceil((100 - progresses[i]) / (double)speeds[i]));
	}

	for (int i = 0; i < checker.size(); i++) {
		cout << checker[i] << ", ";
	}

	cout << endl;

	for (int i = 0; i < checker.size(); i++) {
		if (i == 0) {
			answer.push_back(1);
		} else if (i < checker.size()) {
			if (checker[i - 1] >= checker[i]) {
				answer.back() += 1;
				checker[i] = checker[i - 1];
			}
			else 
				answer.push_back(1);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ", ";
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
		progresses.push_back(70);
		progresses.push_back(30);
		progresses.push_back(55);

		speeds.push_back(1);
		speeds.push_back(30);
		speeds.push_back(5);
	#pragma endregion

		
		solution(progresses, speeds);
	
	


	system("pause");

	return 0;
}
