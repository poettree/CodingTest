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

		for (int k = 0; k < phone_book.size(); k++)
		{
			check = 0;

			if (k >= phone_book.size() - 1)
				count = 0;

			//TODO: 접두어 순차 확인하기
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