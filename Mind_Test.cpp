#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;
int width = 2;
int lenth = 2;
int score = 0;
int tri = 1;
int result = 0;
time_t start = 0;
time_t End = 0;
bool stand()
{
	cout << "\t\t## Welcome ##\n"
		<< "\t\t-------------\n"
		<< "\t\t## Are You Ready.... ##\n"
		<< "\t\t-----------------------\n"
		<< "[1]-Main Menu\n"
		<< "[0]-Exit\n\n";
	int choice;
	do
	{
		cout << "Enter Your Choice : ";
		cin >> choice;
		cout << endl;
	} while (choice > 1 || choice < 0);
	return (choice == 1) ? true : false;
}
// // // /////////////// // /// // ///// / / /// //////
//*****************************************************
int level()
{
	int choice;
	system("cls");
	cout << "\t\t[Choose]\n"
		<< "[1]-Easy\n"
		<< "[2]-Medium\n"
		<< "[3]-Hard\n";
	//<< "Enter Your Answer : ";
	do {
		cout << "Enter Your Choice : ";
		cin >> choice;
	} while (choice > 3 || choice < 1);
	return choice;
}
// // // /////////////// // /// // ///// / / /// //////
//*****************************************************
void shape(int level)
{
	int choice = -1;
	int t = 5;
	while (t--)
	{
		start = time(0);
		cout << "-------------------------------------------------------------------------\n";
		cout << "|\t\t|trial : " << tri++ << "/5 |" << "\t\t\t|Score : " << score << " |\t\t|\n"
			<< "-------------------------------------------------------------------------\n\n\n";
		srand(time(0));
		width = rand() % ((level * 2) + 4 - 1) + level *2;
		lenth = rand() % ((level * 2) + 4 - 1) + level *2;
		result = width * lenth;
		for (int i = 0; i < width; i++)
		{
			cout << "\t\t";
			for (int j = 0; j < lenth; j++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << "\nEnter How Many Blocks \"#\" : ";
		cin >> choice;
		End = time(0) - start;
		Sleep(500);
		//pause("5");
		system("cls");
		if (choice == result && End <= 5)
		{
			cout << "Right Answer...\n";
			score++;
		}
		else if (choice == result && End > 5)
		{
			cout << "Right Answer ..But You Are Late. \n";
		}
		else
		{
			cout << "Wrong Answer...\n";
		}
		cout << "You Took : " << End << " s.\n";
		Sleep(1000);
		system("cls");
		cout << "Please Wait ....... ";
		for (int u = 2; u >= 0; u--)
		{
			cout << u << "\b";
			Sleep(1000);
			//system("cls");
		}
		cout << endl;
		if (tri == 6)
		{
			cout << "Your Score is : " << (score / 5) * 100 << " % " << endl;
			cout << "\t\t Wish You Enjoyed <Thanks>\n";
			break;
		}
		Sleep(500);
		system("cls");
	}
}
// // // /////////////// // /// // ///// / / /// //////
//*****************************************************
int main()
{
	int complete = -1;
	do
	{
		if (stand())
		{
			tri=1;
			system("CLS");
			shape(level());
		}
		else
			cout << "\t\t## THANKS.... ##";
		cout << "\n" << "Do You Want To Try Again ([1]-Yes/[0]-N) : ";
		cin >> complete;
	} while (complete);
}
