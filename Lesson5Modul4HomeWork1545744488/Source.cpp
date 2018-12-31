#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Lesson5Modul4HomeWork1545744488

void Task1()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask1\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int sp, ts, rating, sum=0;

	for (sp = 1; sp <= 2; sp++)
	{
		for (ts = 1; ts <= 5; ts++)
		{
			rating = 1 + rand() % 4;
			printf("%3d вид спорта, балл: %d \n", ts, rating);
			sum = sum + rating;
		}

		printf("\n\t %d спортсмен, сумма баллов : %d \n\n", sp, sum);
	}

}


void Task2()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask2\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int klass, student, rating, sum = 0;
	float average;

	for (klass = 1; klass <= 2; klass++)
	{
		printf("\n\%3 Оценки учеников %d класса по физике: \n\n", klass);

		for (student = 1; student <= 15; student++)
		{
			rating = 3 + rand() % 3;
			sum = sum + rating;
			printf("%3d - ученик - оценка - %d \n", student, rating);
		}

		average = sum;
		sum = 0;
		average = average / (student-1);
		printf("\n\t Средняя оценка по классу - %.1f \n\n", average);
		
	}

}


void Task3()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask3\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	float p=0, s=0, density, sum=0;
	int district;

	printf("Район \%5 Население (т.чел.) \%5 Площадь (кв.км.) \%5 Плотность (т.чел./кв.км.) \n\n");
	

	for (district = 1; district <= 12; district++)
	{
		p = float (7 + rand() % 5) / (5 + rand() % 3);
		s = float (25 + rand() % 5) / (2 + rand() % 3);
		density = p / s;
		sum = sum + density;

		
		printf("%3d \t\t %5.2f  \t %7.2f  \t\t %5.2f \n", district, p, s, density);

	}

	printf("\n\n Средняя плотность населения по области %.2f (т.чел./кв.км.) \n\n", (sum / (district-1)));
}


void Task4() 
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask4\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int size, sum = 0, i, max, min;
	
	printf("%3 Введите кол-во человек посетивших сегодня спортзал => ");
	scanf_s("%d", &size);

	int* array = new int[size];

	printf("\n%3 Введите возраст каждого посетителя: \n\n");
	
	for (i = 0; i < size; i++)
	{
		printf("\t %d - посетитель => ", i+1 );
		scanf_s("%d", &array[i]);
	}

	max = array[0];
	min = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max) max = array[i];
		if (array[i] < min) min = array[i];
		sum = sum + array[i];
	}
	
	printf("\n%3 Возраст самого старшего посетителя: %d", max);
	printf("\n%3 Возраст самого младшего посетителя: %d", min);
	printf("\n%3 Средний возраст посетителей: %d", sum/size);

}


void Task5()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask5\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int store = 15, n=0, i=0;

	do 
	{
		i++;
		printf("\n%3 %d - машина, укажите кол-во ящиков с яблоками на погрузку => ", i);
		scanf_s("%d", &n);

		if (n <= store)
		{
			store = store - n;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("\n%3 Вы ввели больше ящиков чем у Вас имеется на складе!\n Остаток на складе %d ящиков, повторите ввод заново...\n", store);
			SetConsoleTextAttribute(hConsole, 7);
			i--;
		}
		if (store == 0)
		{
			SetConsoleTextAttribute(hConsole, 11);
			printf("\n%3 Вы отгрузили со склада все ящики с яблоками!");
			SetConsoleTextAttribute(hConsole, 7);
			break;
		}

	} while (store >= 0);
		




}



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));



	int number, flag;

	do
	{
		printf("Enter number of Task (1) to (5) => ");
		scanf_s("%d", &number);

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;
		case 4: {Task4(); } break;
		case 5: {Task5(); } break;
		
		default: printf("\nEntered number of Task does not exist...\n\n");

		}

		SetConsoleTextAttribute(hConsole, 10);
		printf("\n--------------------------------------------------------------------------\n\n"); ("\n");
		SetConsoleTextAttribute(hConsole, 7);

		printf("Do you want to continue? 1/0 => ");
		scanf_s("%d", &flag);

	} while (flag == 1);



	if (flag == 1)
		system("pause");


}