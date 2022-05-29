#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct car
{
	string mark;
	string ownersSecondname;
	string ownersFirstname;
	int powerOfEngine;
	int mileage;
};

int stringCompare(string txt1, string txt2)
{
	int len1 = txt1.length();
	int len2 = txt2.length();
	if (len1 != len2)
	{
		return -1;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < len1; i++)
		{
			if (txt1[i] == txt2[i])
			{
				count++;
			}
		}
		if (count == len1)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	vector<car> base;
	vector<car> CarOverMileagebase;
	cout << "������� ���-�� �����������..." << endl;
	int n = 0;
	
	
	while (n <= 0)
	{
		cin >> n;
		if (n <= 0)
		{
			cout << "������� ������������� �����!" << endl;
		}
	}

	//��������� n �����
	for (int i = 0; i < n; i++)
	{
		string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		int randWordLength = rand() % 9 + 1;
		string mark = "";
		string ownersSecondname = "";
		string ownersFirstname = "";
		for (int j = 0; j < randWordLength; j++)
		{
			int randLetter1 = rand() % alfabet.length();
			int randLetter2 = rand() % alfabet.length();
			int randLetter3 = rand() % alfabet.length();
			
			mark.push_back(alfabet[randLetter1]);
			ownersSecondname.push_back(alfabet[randLetter2]);
			ownersFirstname.push_back(alfabet[randLetter3]);

		}
		int powerOfEngine = rand() % 100;
		int mileage = rand() % 10000;

		car NewCar = {};
		NewCar.mark = mark;
		NewCar.ownersSecondname = ownersSecondname;
		NewCar.ownersFirstname = ownersFirstname;
		NewCar.powerOfEngine = powerOfEngine;
		NewCar.mileage = mileage;

		base.push_back(NewCar);
	}

	int answer = -1;
	cout << "������� ������ �� n ����� (���� � ����������)" << endl
		<< "����������� ������� : " << endl
		<< "1. �������� ����� ������" << endl
		<< "2. ����������� ���������� � ������ � ��������� ����" << endl
		<< "3. ����� ��� ������  �������� �����, ��������� ������� �� �����" << endl
		<< "4.����� ���� ���������� � �������� ������ ������ ���������," << endl
		<< "��������� ����������� �� ��������, ��������� � ������� � ������� �� �����" << endl << endl;
	while (answer != 0)
	{

		//system("CLS");
		
		cout << "MENU" << endl
			<< "1.Print car list" << endl
			<< "2.Add new car" << endl
			<< "3.Find cars by the mark" << endl
			<< "4.Find owners by car's mileage" << endl

			<< "0.Exit " << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			cout << "mark------Owner's 2nd name--Owner's 1st name---power of engine-----mileage------------------------------" << endl;

			for (int i = 0; i < base.size(); i++)
			{
				//#include <iomanip>
				cout << left << setw(10) << base[i].mark << setw(17) << base[i].ownersSecondname << setw(20) << base[i].ownersFirstname << setw(20) << base[i].powerOfEngine << setw(10) << base[i].mileage << endl;
			}
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			break;
		}
		case 2:
		{
			car NewCar = {};
			string buff;
			int number = -1;

			cout << "Enter Mark" << endl;
			cin >> buff;
			NewCar.mark = buff;

			cout << "Enter owner's Secondname" << endl;
			cin >> buff;
			NewCar.ownersSecondname = buff;

			cout << "Enter owner's Firstname" << endl;
			cin >> buff;
			NewCar.ownersFirstname = buff;

			cout << "Enter power Of Engine" << endl;
			cin >> number;
			NewCar.powerOfEngine = number;

			cout << "Enter mileage" << endl;
			cin >> number;
			NewCar.mileage = number;

			base.push_back(NewCar);

			break;
		}
		case 3:
		{
			string buffer;
			cout << endl << "Enter the mark name" << endl << endl;
			cin >> buffer;
			int count = 0;
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			cout << "mark------Owner's 2nd name--Owner's 1st name---power of engine-----mileage------------------------------" << endl;
			for (int i = 0; i < base.size(); i++)
			{
				
				if (base[i].mark == buffer)
				{
					count++;
					cout << left << setw(10) << base[i].mark << setw(15) << base[i].ownersSecondname << setw(5) << base[i].ownersFirstname << setw(8) << base[i].powerOfEngine << setw(10) << base[i].mileage << endl;
				}
				if (count == 0)
				{
					cout << "Not found!" << endl;
				}
				
				
			}
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			break;
		}
		case 4:
		{
			int buffer;
			cout << "Enter car mileage" << endl;
			cin >> buffer;
			for (int i = 0; i < base.size(); i++)
			{
				if (base[i].mileage >= buffer)
				{
					CarOverMileagebase.push_back(base[i]);
					cout << left << setw(10) << base[i].ownersSecondname << setw(5) << base[i].ownersFirstname << setw(10) << base[i].mileage << endl;
				}

			}
			break;
		}
		case 5:
		{

			break;
		}



		system("pause");
		}
	}
}