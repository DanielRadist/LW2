﻿/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Предмет имеет целое – число часов в неделю и целое – трудоемкость предмета (коэффициент 1-10).
 * Определить метод, вычисляющий вес предмета в рейтинге учащегося, равный число часов/8 * трудоемкость/10.
 * Основной класса – ученик с тремя полями предметов и количеством баллов по каждому предмету.
 * Реализовать метод, вычисляющий средний рейтинг ученика, равный сумме произведений балл по предмету на его вес и метод,
 * определяющий предмет с максимальным весом в рейтинге.
 *
 */

#include <iostream>

using namespace std;

class Discipline
{
public:

	float discipline_weight()							//вес предмета в рейтинге
	{
		return (float(hours * complexity) / 80);
	}

	void init(int complexity, int hours)				//инициализация передмета
	{
		this->complexity = complexity;
		this->hours = hours;
	}

	void read()											//ввод часов и коэф
	{
		do {
			cout << " ~ Enter complexity: ";
			cin >> complexity;
		} while(complexity > 10 || complexity < 1);

		do {
			cout << " ~ Enter hours: ";
			cin >> hours;
		} while(hours < 0);
	}

	void display()										//вывод информации по предмету
	{
		cout << "complexity: " << complexity << "; hours: " << hours << "; ";
	}

private:

	int complexity;										//трудоемкость предмета (коэффициент 1-10)
	int hours;											//часы в неделю
};


class Student
{

public:	
	#define N 3												//кол-во предметов у ученика

	void read()												//ввод ученика
	{
		for(int i = 0; i < N; i++)
		{
			int point;										//балл

			cout << "Subject #" << i + 1 << endl;
			do {
				cout << " ~ Enter point: ";
				cin >> point;
			} while(point < 0);
			points[i] = point;
		}
	}

	void init(int in_point0, int in_point1, int in_point2)	//инициал. ученика
	{
		points[0] = in_point0;
		points[1] = in_point1;
		points[2] = in_point2;
	}

	void display()											//вывод инф. по ученику
	{
		cout << "Number of subjects: " << N << endl;

		for(int i = 0; i < N; i++)
		{
			cout << i + 1 <<") ";
			subjects[i].display();
			cout << "point: " << points[i] << "; ";
			cout << endl;
		}
	}

	float status()											//возр. средний рейтинг ученика
	{
		float tmp = 0;
		for(int i = 0; i < N; i++)
			tmp += points[i] * subjects[i].discipline_weight();
		return tmp;
	}

	int max_discipline_weight()								//возр. индекс на предмет с макс. рейтингом
	{
		float tmp = subjects[0].discipline_weight();
		int tmp_p = 0;										//индекс указывающий на предмет с макс. весом
		for(int i = 1; i < N; i++)
		{
			if(tmp < subjects[i].discipline_weight())
			{
				tmp = subjects[i].discipline_weight();
				tmp_p = i;
			}
		}
		return tmp_p;
	}


	Discipline subjects[N];									//указатель на массив объектов-предмет

private:

	int points[N];											//баллы по предметам
};

int main()
{
	Student Oleg;
	Oleg.init(50, 67, 80);
	Oleg.subjects[0].init(4, 5);
	Oleg.subjects[1].init(7, 9);
	Oleg.subjects[2].read();
	Oleg.display();

	cout << "Student rating: " << Oleg.status() << "; the heaviest subject: " << Oleg.max_discipline_weight() + 1 << "; " << endl;


	return 0;
}
