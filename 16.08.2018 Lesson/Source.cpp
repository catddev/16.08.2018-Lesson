#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include<math.h>
#include<string>
#include<ctime>

using namespace std;

//int areaR(int h, int w=1){ // здесь можно присваивать значения аргумента по умолчанию
//	// после аргумента, назначенного по умолчанию все последующие тоже должны быть по умолчанию!!!
//	return h * w;
//}
//int areaR(int x, double b=0.5) { // mistake
//	return x*2;
//}

//int arrMax(int arr[], int size) {
//	int max = INT_MIN;
//	for (int i = 0; i < size; i++)
//		if (arr[i] > max)
//			max = arr[i];
//	return max;
//}
//int arrMax(double arr[], int size) {
//	double max = arr[0];
//	for (int i = 0; i < size; i++)
//		if (arr[i] > max)
//			max = arr[i];
//	return max;
//}

// 35.	**Напишите шаблон функции, которая осуществляет поиск максимального элемента в массиве.
// Функция возвращает позицию элемента и его значение.
// Рекомендации: Воспользуйтесь передачей параметров по ссылке.
// case 5
template<typename type> // шаблон, теперь предыдущие две функции для перегрузок можно объединить сюда
 //template<class type>
	type arrMax(type arr[], int size, int &pos) {
		type max = arr[0];
		int max_pos;
		for (int i = 0; i < size; i++)
			if (arr[i] > max)
			{
				max = arr[i];
				max_pos = i;
			}
		pos = max_pos;
		return max;
	}
// 36.	**Напишите шаблон функции, которая принимает массив, и выводит на экран позиции нулевых элементов массива.
	// case 6
template<typename type> 
void arrZero(type arr[], int size) {
	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
			cout << i <<" ";
	cout << endl;
}

//37.	**Напишите шаблон функции, которая принимает x и y и вычисляет x в степени y. Y – целое число.
// case 8
template<typename type>
type power1(type x, int y) {
	x = pow(x, y);
	return x;
}


	// 41.	**Напишите функцию, которая принимает дату(день, месяц, год)
	// и возвращает номер дня недели, которому соответствует эта дата.
	// 1 – понедельник, 2 – вторник, 3 – среда, 4 – четверг, 5 – пятница, 6 – суббота, 7 – воскресенье.
	//int weekday(int d, int m, int y) {
	//	int wd = 0;
	//	wd = (d + m * 30 + y * 12 * 30)%7;

	//	return wd;
	//}

int date(int day, int month, int year) {
	int begin_shift = 6;// номер дня недели точки сдвига 1 янв 2000
	bool leap_year = true; //проверка на високосный
	int bday = 1;
	int bmonth = 1;
	int byear = 2000;
	int days=day;
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) { // високосный год
		months[1] = 29;
		leap_year = true;
	}
	else
	{
		leap_year = false;
	}
	for (int i = 0; i < month-1; i++)
	{
		days += months[i];
	}

	cout << days << endl;
	int week_day = days % 7;
	return week_day;
	// если учитывать сдвиг 1 января, а в високосный год сдвиг на два дня, то можно прогу сделать универсальной для разных годов
	// чтобы прошлые годы надо точку сдвига пораньше выбрать, например 2000 год
}



	// 42.	 Напишите  функцию, которая принимает дату(день, месяц, год) и возвращает :
	// А) количество месяцев, соответствующее этой дате.
	// Б) количество дней, соответствующее этой дате.
	void daymonth(int d, int m, int y) {
		int day = 0;
		int month = 0;
		day = d + m * 30 + y * 12 * 30;
		month = y / 12 + month + d / 30;
		cout << day << endl;
		cout << month << endl;
	}

	// 43.	**Напишите функцию, которая принимает целое число
	// и выводит на экран эквивалент этого числа в двоичной системе исчисления.
	void sys2(int n) {
		int a[20];
		int i = 0;
		
		int k = 0;

		while (n / 2 > 0)
		{
			if (n >= 2)
			{
				a[i] = n % 2;
				n = n / 2;
				i++;
				k++;
			}
			if (n < 2)
			{
				a[i] = n;
				k++;
			}
		}

		for (i = 0; i < k / 2; i++)
		{
			swap(a[i], a[k - 1 - i]);
		}

		for (int i = 0; i < k; i++)
		{
			cout << a[i];
		}
		cout << endl << endl;

	}
	// 44.	**Напишите функцию, которая принимает целое число
	// и выводит на экран эквивалент этого числа в восьмеричной системе исчисления.
	void sys8(int n) {
		int a[20];
		int i = 0;

		int k = 0;

		while (n / 8 > 0)
		{
			if (n >= 8)
			{
				a[i] = n % 8;
				n = n / 8;
				i++;
				k++;
			}
			if (n < 8)
			{
				a[i] = n;
				k++;
			}
		}

		for (i = 0; i < k / 2; i++)
		{
			swap(a[i], a[k - 1 - i]);
		}

		for (int i = 0; i < k; i++)
		{
			cout << a[i];
		}
		cout << endl << endl;

	}
	// 45.	***Напишите функцию, которая принимает целое число
	// и выводит на экран эквивалент этого числа в шестнадцатеричной системе исчисления.
	void sys16(int n) {
		int a[20];
		int i = 0;

		int k = 0;

		while (n / 16 > 0)
		{
			if (n >= 16)
			{
				a[i] = n % 16;
				n = n / 16;
				i++;
				k++;
			}
			if (n < 16)
			{
				if (n <= 9)
					a[i] = n;
				k++;
			}
		}

		for (i = 0; i < k / 2; i++)
		{
			swap(a[i], a[k - 1 - i]);
		}

		for (int i = 0; i < k; i++)
		{
			if(i<k-1) cout << a[i];

			if (i==k-1 && a[k-1] > 9)
			{
				if (a[k - 1] == 10) cout << "A";
				else if (a[k - 1] == 11) cout << "B";
				else if (a[k - 1] == 12) cout << "C";
				else if (a[k - 1] == 13) cout << "D";
				else if (a[k - 1] == 14) cout << "E";
				else if (a[k - 1] == 15) cout << "F";
			}
			else if (i==k-1 && a[k-1]<=9) cout << a[i];
		}
		cout << endl << endl;

	}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 3:
		{
			char str[10]; //10 элементов = 9 видимых символов,
						  // т.к. последняя ячейка уходит на спец разделитель, означающий конец строки
			cin >> str; // в случае со строками компилятор понимает ввод массива символов как одно целое, можно без цикла

			cout << str << endl;
			cout << str[0] << endl;

			cout << strlen(str) << endl;
		}
		break;
		case 4:
		{
			int x, y;
			cin >> x >> y;
			//	cout << areaR(x) << endl;
		}
		break;
		case 35:
		{
			int a[] = { 2, 5, 0, 8, 3 };
			double b[] = { 1.2, 0, 2.8, 0 , 3.6 };
			int position=0;
			cout << arrMax(a, 5, position) << " " << position << endl;
			cout << arrMax(b, 5, position) << " " << position << endl;
		}
		break;
		case 36:
		{
			int a[] = { 2, 5, 0, 8, 3 };
			double b[] = { 1.2, 0, 2.8, 0 , 3.6 };
			
			arrZero(a, 5);
			arrZero(b, 5);

		}
		break;
		case 41:
		{
		/*	int d, m, y;
			cin >> d >> m >> y;
			
			cout << weekday(d, m, y) << endl;*/
			cout << date(15, 5, 2018) << endl;
		}
		break;
		case 42:
		{
			daymonth(16, 8, 2018);
		}
		break;
		case 37:
		{
			double x = 2.5;
			int y = 3;

			cout << power1(x, y) << endl;
		}
		break;
		case 43:
		{
			int n;
			cout << "enter a number: ";
			cin >> n;
			
			sys2(n);
		}
		break;
		case 44:
		{
			int n;
			cout << "enter a number: ";
			cin >> n;

			sys8(n);
		}
		break;
		case 45:
		{
			int n;
			cout << "enter a number: ";
			cin >> n;

			sys16(n);
		}
		break;
		case 12:
		{

		}
		break;
		case 13:
		{

		}
		break;
		case 14:
		{

		}
		break;
		case 15:
		{

		}
		break;
		
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}