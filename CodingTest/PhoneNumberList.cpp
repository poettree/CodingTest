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

		for (int k = 0; k < phone_book.size(); k++)
		{
			check = 0;

			if (k >= phone_book.size() - 1)
				count = 0;

			//TODO: ���ξ� ���� Ȯ���ϱ�
			if (k != count)
			{
				for (int j = 0; j < origin[k].size(); j++)
				{
					if (phone_book[k][j] == phone_book[count][j])
						check++;

				if (check == origin[k].size()) { answer = false; break; }
				cout << "Check: " << check << endl;
				}


			}
				count++;
		}

		cout << endl;
	}


	for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it)
	cout << ' ' << *it;

	cout << endl;
	cout << "Answer: " << answer;
	cout << endl;
	cout << endl;

	return answer;
}

int main()
{
	string numbers[] = { "119", "97674223", "1195524421" };
	vector<string>phone_book;
	for (int i = 0; i < size(numbers); i++)
	{
		phone_book.push_back(numbers[i]);
	}

	solution(phone_book);

	system("pause");
	
	return 0;
}