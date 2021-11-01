
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> solution(queue<int> progresses, queue<int> speeds) {
#pragma region Various
	vector<int> answer;
	bool finish = true;
	int count = 0;
#pragma endregion


	//Error Check
	if (progresses.size() != speeds.size())
	{
		cout << "ERROR: progress != speeds"<<endl;
		system("Pause");
	}

	while (finish) {

		for (int i = 0; i < progresses.size(); i++)
		{
			count++;

			progresses.front() += speeds.front();

			if (progresses.front() >= 100)
			{
				answer.push_back(count);
				progresses.pop();
				speeds.pop();
				count = 0;
			}

			if (progresses.empty())
			{
				finish = false;
			}
		}
	}

	unique(answer.begin(), answer.end());

	return answer;
}

int main() {
	
	queue<int> progresses;
	queue<int> speeds;

	vector<int> answer;

	progresses.push(93);
	progresses.push(30);
	progresses.push(55);

	speeds.push(1);
	speeds.push(30);
	speeds.push(5);

	solution(progresses, speeds);
	
	for (int i = 0; i < solution(progresses,speeds).size(); i++)
	{
		cout << solution(progresses, speeds)[i]<<endl;
	}

	//system("pause");

	return 0;
}
