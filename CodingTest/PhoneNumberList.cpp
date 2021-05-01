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
	//���� ���� ������ ��� ���ؼ� origin ���� ����
	vector<string> origin = phone_book;
	vector<int> checker = {};
	int check = 0;
	int max = 0;

	//���� ū ������ ������ ���ϱ�
	for (int i = 0; i < phone_book.size(); i++)
		max = max > phone_book[i].size() ? max : phone_book[i].size();

	// ���� ū ������ ������� �ؽ�
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