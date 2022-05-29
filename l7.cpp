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
struct fio
{
	string firstName;
	string secondName;
	string fatherName;
};
struct lastServiceDate
{
	int day;
	string month;
	int year;
};
struct car
{
	string mark;
	fio initials;
	int powerOfEngine;
	int mileage;
	lastServiceDate TO;
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
int textMonthToInt(string curMonth)
{
	string months[12] = { "Janary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (int i = 0; i < 12; i++)
	{
		if (stringCompare(curMonth, months[i]) == 0)
		{
			return (i + 1);
		}
	}
	return -1;
}
string fromIntToString(int num)
{
	string answer;
	int n = num;
	while (n > 0)
	{
		int d = n % 10;
		d = d + 48;
		answer.push_back((char)d);
		n = n / 10;
	}
	return answer;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	FILE* file;
	vector<car> base;
	vector<car> CarOverMileagebase;
	int CarsInFileCount = 0; 
	
	file = fopen("carBase.txt", "r+");
	if ((file == NULL))
	{
		
		printf("Error! File does not exist!\n");
		printf("Creating a new file...\n");
		
	}
	else
	{
		int wordCounter = 0;
		while (!feof(file))
		{
			car newCar; 
			for (int i = 0; i < 9; i++)
			{
				char buf[256];
				fscanf(file, "%s", buf);
				
				switch (i)
				{

				case 0:
				{
					newCar.mark = buf;
					break;
				}
				case 1:
				{
					newCar.initials.secondName = buf;
					break;
				}
				case 2:
				{
					newCar.initials.firstName = buf;
					break;
				}
				case 3:
				{
					newCar.initials.fatherName = buf;
					break;
				}
				case 4:
				{
					newCar.powerOfEngine = stoi(buf);
					break;
				}
				case 5:
				{
					newCar.mileage = stoi(buf);
					break;
				}
				case 6:
				{
					newCar.TO.day = stoi(buf);
					break;
				}
				case 7:
				{
					newCar.TO.month = buf;
					break;
				}
				case 8:
				{
					newCar.TO.year = stoi(buf);
					break;
				}
				case 9:
				{
					break;
				}
				default:
					cout << "Error!!!" << endl;
					break;
				}

			}
			base.push_back(newCar);
			CarsInFileCount++;
		}
		fclose(file);
	}
	file = fopen("carBase.txt", "w");

	cout << "Введите кол-во автомобилей..." << endl;
	int n = 0;
	string months[12] = { "Janary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (n <= 0)
	{
		cin >> n;
		if (n <= 0)
		{
			cout << "Введите положительное число!" << endl;
		}
	}

	//генерация n машин
	for (int i = 0; i < n; i++)
	{
		
		
		int randWordLength = rand() % 9 + 1;
		string mark = "";
		string ownersSecondname = "";
		string ownersFirstname = "";
		string ownersFathername = "";
		for (int j = 0; j < randWordLength; j++)
		{
			int randLetter1 = rand() % alfabet.length();
			int randLetter2 = rand() % alfabet.length();
			int randLetter3 = rand() % alfabet.length();
			int randLetter4 = rand() % alfabet.length();

			mark.push_back(alfabet[randLetter1]);
			ownersSecondname.push_back(alfabet[randLetter2]);
			ownersFirstname.push_back(alfabet[randLetter3]);
			ownersFathername.push_back(alfabet[randLetter4]);
		}
		int powerOfEngine = rand() % 100;
		int mileage = rand() % 10000;
		int year = rand() % (2022 - 1985 + 1) + 1985;
		int month = rand() % 12;
		int day = rand() % 31 + 1;

		car NewCar = {};
		NewCar.mark = mark;
		NewCar.initials.secondName = ownersSecondname;
		NewCar.initials.firstName = ownersFirstname;
		NewCar.initials.fatherName = ownersFathername;
		NewCar.powerOfEngine = powerOfEngine;
		NewCar.mileage = mileage;
		NewCar.TO.year = year;
		NewCar.TO.month = months[month];
		NewCar.TO.day = day;

		base.push_back(NewCar);
		
	}
	
	int answer = -1;
	cout << "Создать массив из n машин (ввод с клавиатуры)" << endl
		<< "Реализовать функции : " << endl
		<< "1. Добавить новую машину" << endl
		<< "2. Распечатать информацию о машине в табличном виде" << endl
		<< "3. Найти все машины  заданной марки, результат вывести на экран" << endl
		<< "4.Найти всех владельцев с пробегом машины больше заданного," << endl
		<< "результат сортировать по алфавиту, запомнить в массиве и вывести на экран" << endl << endl;
	while (answer != 0)
	{

		//system("CLS");

		cout << "MENU" << endl
			<< "1.Print car list" << endl
			<< "2.Add new car" << endl
			<< "3.Find cars by the mark" << endl
			<< "4.Find owners by car's mileage" << endl
			<< "5.Find vehicles that have been more than 18 months old since the last service" << endl
			<< "0.Exit " << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			cout << "mark------FIO-------------------------------------------------------power of engine-----mileage----last service date-----" << endl;

			for (int i = 0; i < base.size(); i++)
			{
				//#include <iomanip>
				cout << left << setw(10) << base[i].mark << setw(17) << base[i].initials.secondName << setw(20) << base[i].initials.firstName << setw(20)<<base[i].initials.fatherName << setw(20) << base[i].powerOfEngine << setw(10) << base[i].mileage << " " <<base[i].TO.day << " " << base[i].TO.month<<" "<< base[i].TO.year << endl;
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
			NewCar.initials.secondName = buff;

			cout << "Enter owner's Firstname" << endl;
			cin >> buff;
			NewCar.initials.firstName = buff;
			
			cout << "Enter owner's Firstname" << endl;
			cin >> buff;
			NewCar.initials.fatherName = buff;

			cout << "Enter power Of Engine" << endl;
			cin >> number;
			NewCar.powerOfEngine = number;

			cout << "Enter mileage" << endl;
			cin >> number;
			NewCar.mileage = number;

			cout << "Enter the year of the last service date" << endl;
			cin >> number;
			NewCar.TO.year = number;
			cout << "Enter the number of month of the last service date" << endl;
			cin >> number;
			NewCar.TO.month = months[number-1];
			cout << "Enter the day of the last service date" << endl;
			cin >> number;
			NewCar.TO.day = number;

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
			cout << "mark------FIO-------------------------------------------------------power of engine-----mileage----last service date-----" << endl;
			for (int i = 0; i < base.size(); i++)
			{
				if (base[i].mark == buffer)
				{
					count++;
					cout << left << setw(10) << base[i].mark << setw(17) << base[i].initials.secondName << setw(20) << base[i].initials.firstName << setw(20) << base[i].initials.fatherName << setw(20) << base[i].powerOfEngine << setw(10) << base[i].mileage << " " << base[i].TO.day << " " << base[i].TO.month << " " << base[i].TO.year << endl;
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
					cout << left << setw(10) << setw(17) << base[i].initials.secondName << " " << base[i].initials.firstName << " " << base[i].initials.fatherName <<  setw(10) << base[i].mileage << endl;
				}
			}
			break;
		}
		case 5:
		{
			time_t seconds = time(NULL);
			long double minutes = seconds / 60;
			long double hours = minutes / 60;
			long double days = hours / 24 + 1970*365;
			int personal_day;
			int personal_month;
			int personal_year;
			//cout << days << endl;
			long double day_count = days;
			int month_count = 0;
			int year_count = 0;
			while (day_count >= 30.4166666667)
			{
				month_count++;
				day_count -= 30.4166666667;
			}
			//int currentMonths = month_count;
			while(month_count >= 12)
			{
				year_count++;
				month_count -= 12;
			}

			cout << "Current date: " << (int)day_count + 20 << "." << months[month_count-1] << "." << year_count << endl;
			cout << "Enter the date of the last service (DD MM YYYY)" << endl;
			
			cin >> personal_day;
			cin >> personal_month;
			cin >> personal_year;
			if (personal_day < 1 || personal_day > 31)
			{
				while (personal_day < 1 || personal_day > 31) 
				{
					cout <<" Wrong DAY value! Enter again!" << endl;
					cin >> personal_day;
				}
			}
			if (personal_month < 1 || personal_month> 12)
			{
				while (personal_month < 1 || personal_month > 12)
				{
					cout << " Wrong MONTH value! Enter again!" << endl;
					cin >> personal_month;
				}
			}
			if (personal_year > year_count)
			{
				while (personal_year > year_count)
				{
					cout << " Wrong YEAR value! Enter again!" << endl;
					cin >> personal_year;
				}
			}
			int allPersMonths = personal_month + personal_year * 12;
			cout << "Vehicles that have been more than 18 months old since the last service:" << endl;
			for (int i = 0; i < base.size(); i++)
			{
				int month_number = textMonthToInt(base[i].TO.month);
				long double valueOfDays = ((month_number) + base[i].TO.year * 12) * 30.4166666667;
				if (((long double)allPersMonths * 30.4166666667 - valueOfDays) > 547.501)
				{
					cout << left << setw(10) << base[i].mark << setw(17) << base[i].initials.secondName << setw(20) << base[i].initials.firstName << setw(20) << base[i].initials.fatherName << setw(20) << base[i].powerOfEngine << setw(10) << base[i].mileage << " " << base[i].TO.day << " " << base[i].TO.month << " " << base[i].TO.year << endl;
				}
			}
			break;
		}
		default:
		{
			cout <<endl<< "Wrong number!" << endl<<endl;
			break;
		}
		system("pause");
		}
	}
	if (base.size() > CarsInFileCount)
	{
		fseek(file, 0, SEEK_END);
		for (int i = CarsInFileCount; i < base.size(); i++)
		{
			int spaceCount = 0;
			string readyToWrite = " " + base[i].mark + " " + base[i].initials.secondName + " " + base[i].initials.firstName + " " + base[i].initials.fatherName + " " + fromIntToString(base[i].powerOfEngine) + " " + fromIntToString(base[i].mileage) + " " + fromIntToString(base[i].TO.day) + " " + (base[i].TO.month) + " " + fromIntToString(base[i].TO.year) + " ";
			for (int i = 0; i < readyToWrite.size(); i++)
			{
				
				fputc(readyToWrite[i], file);
				if (readyToWrite[i] == ' ')
				{
					spaceCount++;
				}
				if (spaceCount == 10)
				{
					fputc('\n', file);
					spaceCount = 0;
				}
			}
			//fprintf(file,"\n%s", readyToWrite);
			//fprintf(file, "\n%s %s %s %s %d %d %d %s %d", base[i].mark, base[i].initials.secondName, base[i].initials.firstName, base[i].initials.fatherName, (base[i].powerOfEngine), (base[i].mileage), (base[i].mileage), (base[i].TO.day), (base[i].TO.month), (base[i].TO.year));
		}
		
	}
	cout << "CarsInFileCount" << CarsInFileCount << endl;
	cout << "CarsInBaseCount" << base.size() << endl;
	fclose(file);
	
	return 0;
}
