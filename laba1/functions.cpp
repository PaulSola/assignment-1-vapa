#include "iostream"
#include "fstream"
#include "string"
using namespace std;
void Poisk(struct Devider num1)
{
	num1[1].line = 0;
	num1[1].Devidedby = 0;
	for (int i = 0; i < 22; i++)        // i < 22
	{
		char *p = strtok(num1[i].line, ",");  //    num[i] 
		int q = 0;
		while (p != NULL)
		{
			strcpy(num1[q].Devidedby, p);
			++q;
			p = strtok(NULL, ",");
		}
	}
}
void Schet(struct Devider num1, struct Team mass1)
{
	int schet = 0;
	for (int i = 1; i < 11; i++)
	{
		if (num1[i].Devidedby[0] > num1[i].Devidedby[2])
		{
			schet = schet + 3;
		}
		else if (num1[i].Devidedby[0] < num1[i].Devidedby[2])
		{
			schet = schet + 0;
		}
		else if (num1[i].Devidedby[0] = num1[i].Devidedby[2])
		{
			schet = schet + 1;
		}

		mass1[i].name = num1[0].Devidedby;
		mass1[i].point = schet;
		schet = 0;
	}
}
void Max(struct Team mass1)
{
	ofstream file1("results.csv");
	int Max = mass1[1].point;         //Max Element
	int u = 0;
	for (int i = 2; i < 21; i++)
	{
		if (mass1[i].point > Max)
		{
			Max = mass1[i].point;
			u = i;
		}
	}
	for (int i = 1; i < 21; i++)
	{
		cout << mass1[i].name << " has " << mass1[i].point << " points " << endl;
		file1 << mass1[i].name << " has " << mass1[i].point << "\n";
	
	}
	file1.close();
}
