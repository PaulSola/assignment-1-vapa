#include "iostream"
#include "fstream"
#include "string"
using namespace std;
struct Devider
{
	char line[100] = {};
	char Devidedby[11] = {};
} num[22];

struct Team {
	string name;
	int point;
} mass[22];

int main()
{
	setlocale(LC_ALL, "Russian");

	
	ifstream file("premier_league.csv");
	if (file.fail()) {
		cout << "\n Ошибка открытия файла ";
		system("pause");
		exit(1);
	}
	int k = 0;
	while (file)
	{

		file.getline(num[k].line, 100);
		k++;
	}
	
	for (int i = 0; i < 22; i++)        // i < 22
	{
		char *p = strtok(num[i].line, ",");  //    num[i] 
		int q = 0;
		while (p != NULL)
		{
			strcpy(num[q].Devidedby, p);
			++q;
			p = strtok(NULL, ",");
		}

			int schet = 0;
		for (int i = 1; i < 11; i++)
		{
			if (num[i].Devidedby[0] > num[i].Devidedby[2])
			{
				schet = schet + 3;
			}
			else if (num[i].Devidedby[0] < num[i].Devidedby[2])
			{
				schet = schet + 0;
			}
			else if (num[i].Devidedby[0] = num[i].Devidedby[2])
			{
				schet = schet + 1;
			}
		}
		mass[i].name = num[0].Devidedby;
		mass[i].point = schet;
		schet = 0;

	}
	//mass[1] = { num[0].Devidedby,schet };
	//cout << num[0].Devidedby << " has " << schet << " points! " << endl;
//	cout << mass[3].name << " has " << mass[3].point << " points " << endl;
	ofstream file1("results.csv");

	int Max = mass[1].point;         //Max Element
	int u = 0;
	for (int i = 2; i < 21; i++)
	{
		if (mass[i].point > Max)
		{
			Max = mass[i].point;
			u = i;
		}
	}
	for (int i = 1; i < 21; i++)
	{
		cout << mass[i].name << " has " << mass[i].point << " points " << endl;
		file1 << mass[i].name << " has " << mass[i].point << "\n";

	}
	file1 << "\t\t\t\t\t" << "##############################################" << "\n";
	file1 << "\t\t\t\t\t\t" << mass[u].name << " is a Winner! " << mass[u].point << " points!\n";
	file1 << "\t\t\t\t\t" << "##############################################" << "\n";


	file.close();
	file1.close();
	cout << "\n" << mass[u].name << " is a Winner! " << mass[u].point << " points!" << endl;
	system("pause");

}