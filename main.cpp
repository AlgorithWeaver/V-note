#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<time.h>
#include<sstream>
#pragma warning( disable : 4996 )
using namespace std;
ifstream input;
ofstream output;
time_t timer;
struct tm* ltm;
void disp()
{
	system("title V-note 1.0.5");
	cout << "Now Running V-note Recording Program." << endl;
	cout << "If You Want To Stop Taking Note,Type '/TZJL'" << endl;
	cout << "If You Want To Export Your Note,Type '/Export' After '/TZJL'." << endl;
	cout << "Or Type Anyting Else Except '/Export' After '/TZJL' If You Do Not Want To Export Your Note."<<endl;
	cout << "Export Date Format Is YYYY MM DD HH:MM:SS." << endl;
	cout << "For More,You Can Read 'README.md'." << endl;
	cout <<"\t\t\t\t\t\t\t\t" << "By-Victor Qi" << endl;
	return;
}
void exout()
{
	ifstream input;
	ofstream output;
	input.open("rjdata.rjrec");
	output.open("C:\\Users\\Desktop\\Note.txt");
	//	char c;
	string c;
	cout << "Keep The Last Exported Notes,And It WILL BE CLEARD.Exported Note On The Desktop " << endl;
	system("pause");
	while (getline(input, c))
	{
		output << c << endl;
	}
	cout << "Export Sucsessed." << endl;
	//	input.close;
	//	output.close;
//	system("pause");
	return;
}
int main()
{
	time_t timer;
	struct tm* ltm;
	time(&timer);
	ltm = localtime(&timer);
	int y = 1900 + ltm->tm_year;
	int m = 1 + ltm->tm_mon;
	int d = ltm->tm_mday;
	input.open("rjdata.rjrec");
	output.open("rjdata.rjrec", ios::app);
	output << endl << y << " " << m << " " << d << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " reg:" << endl;
	string plus;
	disp();
	while (1)
	{
		
		getline(cin, plus);
		if (plus == "/TZJL")
		{
			break;
		}
		output << plus << endl;
	}
	output << "-------------------------------------" << endl;
	input.close();
	output.close();
	string ex;
	cin >> ex;
	if (ex == "/Export")
	{
		exout();
	}
	cout << "Thanks For Using!" << endl;
	system("pause");
	return 0;
}