#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer;
	int i = 0;

	while(i >= 0){
		for (int j = 0; j < priorities.size() - 1; j++) {
			if (priorities[i] < priorities[j]) {
				priorities.push_back(priorities.front());
				priorities.erase(priorities.begin());

				if (i == location) {
					location = priorities.size();
					cout << "[" << location << "]";
					break;
				} else {
					location--;
					cout << "[" << location << "]";
					break;
				}
			}
			else
			{
				cout << "<" << priorities[j] << ">";
			}
			
			cout << priorities[j] << ",";
			
		}
		i++;

		cout << endl;
		
	}

	answer = location+1;

	for (int i = 0; i < priorities.size(); i++)
	{
		cout << priorities[i]<<",";
	}

	cout << endl << answer;


    return answer;
}

void main() {
	vector<int> priorities = { 1,2,3,2 };
	int location =1;

	solution(priorities, location);

	system("pause");
}