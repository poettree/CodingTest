
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
#pragma region Various
	vector<int> answer;
	bool finish = false;
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
			progresses[i] += speeds[i];

			if (progresses[i] >= 100)
			{
				answer.push_back(i+1);
				progresses.pop_back();
			}
		}

		
	}

	return answer;
}

int main() {
	vector<int> progresses;
	vector<int> speeds;

	const queue

	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);

	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);


	solution(progresses, speeds);

	system("pause");
	

	return 0;
}
