// hash example
#include <iostream>
#include <functional>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	int count = 1;
	//기존 벡터 사이즈 계산 위해서 origin 벡터 생성
	vector<string> origin = phone_book;
	vector<int> checker = {};
	int check = 0;
	int max = 0;

	//가장 큰 벡터의 사이즈 구하기
	for (int i = 0; i < phone_book.size(); i++)
		max = max > phone_book[i].size() ? max : phone_book[i].size();

	// 가장 큰 벡터의 사이즈로 해싱
	for (int i = 0; i < phone_book.size(); i++)
		phone_book[i].resize(max,'#');

	for (int i = 0; i < phone_book.size(); i++)
	{
		checker.clear();
		check = 0;

		if (i >= phone_book.size()-1)
			count = 0;

		for (int k = 0; k < origin.size(); k++)
		{
			if (k != count)
				for (int j = 0; j < origin[i].size(); j++)
				{
					if (origin[k][j] == phone_book[count][j])
						checker.push_back(1);
				}
			else continue;
		}

		for (int j = 0; j < checker.size(); j++)
		{
			check += checker[j];
			if (check == origin[i].size())
			{
				answer = false;
				break;
			}
		}

		count++;

		cout << endl;
	}


	for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it)
	cout << ' ' << *it;

	cout << endl;
	cout << answer;
	cout << endl;
	cout << max;
	cout << endl;

	return answer;
}

int main()
{
	string numbers[] = { "43466", "431", "432" , "431121"};
	vector<string>phone_book;
	for (int i = 0; i < size(numbers); i++)
	{
		phone_book.push_back(numbers[i]);
	}

	solution(phone_book);

	system("pause");
	
	return 0;
}