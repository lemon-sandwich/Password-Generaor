#include <iostream>
#include <string>
#include <ctime>
using namespace std;
string passwordGenerator(int length, string upper, string lower, string special, string number);
int include(int ascii[92], int starting, int ending);
int* randomNumber(int length, int ascii[92], int lengthUsed);
int main()
{
	int length;
	string upper, lower, special, number;
	cout << "Length of your password: ";
	cin >> length;
	if (length > 0)
	{

		cout << "Choose with Y or N\n";
		cout << "Include UpperCase? ";
		cin >> upper;
		cout << "Include LowerCase? ";
		cin >> lower;
		cout << "Include Special Characters? ";
		cin >> special;
		cout << "Include Numbers? ";
		cin >> number;
			cout << "Generated Password: " + passwordGenerator(length, upper, lower, special, number) << endl;
	}
	else cout << "Don't be silly\n";
}

string passwordGenerator(int length, string upper, string lower, string special, string number)
{
	int ascii[92];
	for (int i = 0; i < 92; i++)
		ascii[i] = 0;
	if (upper == "Y" || upper == "y") *ascii = include(ascii, 65, 90);
	if (lower == "Y" || lower == "y") *ascii = include(ascii, 97, 122);
	if (number == "Y" || number =="y")*ascii = include(ascii, 48, 57);
	if (special == "Y" || special == "y")
	{
		*ascii = include(ascii, 33, 47);
		*ascii = include(ascii, 58, 64);
		*ascii = include(ascii, 91, 96);
		*ascii = include(ascii, 123, 126);

	}
	//Total indexes used
	int lengthUsed = 0;
	bool unfilled = false;
	for (int i = 0; i < 92; i++)
		if (ascii[i] == 0)
		{
			lengthUsed = i;
			unfilled = true;
			break;
		}
	if (!unfilled) lengthUsed = 92;
	if (lengthUsed != 0)
	{
		int* random = randomNumber(length, ascii, lengthUsed);

		string pass;
		for (int i = 0; i < length; i++)
			pass += *(random + i);
		return pass;
	}
	return "N/A";

}

int include(int ascii[92], int starting, int ending)
{
	int j = 0;
	for (; j < 92; j++)
		if (ascii[j] == 0)
			break;
	for (int i = starting; j < 92 && i <= ending; j++, i++)
		ascii[j] = i;
	return *ascii;
}

int* randomNumber(int length, int ascii[92], int lengthUsed)
{
	int* random = new int(length);
	int i = 0;
	srand((unsigned)time(0));
	do
	{
		int num = (rand() % lengthUsed) + 1;
		*(random + i) = ascii[num];
		i++;
	} while (i < length);
	return random;
}