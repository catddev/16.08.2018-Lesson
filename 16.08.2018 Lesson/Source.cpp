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
	int weekday(int d, int m, int y) {
		int wd = 0;
		wd = (d + m * 30 + y * 12 * 30)%7;

		return wd;
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

	// 44.	**Напишите функцию, которая принимает целое число
	// и выводит на экран эквивалент этого числа в восьмеричной системе исчисления.

	// 45.	***Напишите функцию, которая принимает целое число
	// и выводит на экран эквивалент этого числа в шестнадцатеричной системе исчисления.



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
		case 5:
		{
			int a[] = { 2, 5, 0, 8, 3 };
			double b[] = { 1.2, 0, 2.8, 0 , 3.6 };
			int position=0;
			cout << arrMax(a, 5, position) << " " << position << endl;
			cout << arrMax(b, 5, position) << " " << position << endl;
		}
		break;
		case 6:
		{
			int a[] = { 2, 5, 0, 8, 3 };
			double b[] = { 1.2, 0, 2.8, 0 , 3.6 };
			
			arrZero(a, 5);
			arrZero(b, 5);

		}
		break;
		case 7:
		{
			int d, m, y;
			cin >> d >> m >> y;
			
			cout << weekday(d, m, y) << endl;
		}
		break;
		case 8:
		{
			double x = 2.5;
			int y = 3;

			cout << power1(x, y) << endl;
		}
		break;
		case 9:
		{

		}
		break;
		case 10:
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