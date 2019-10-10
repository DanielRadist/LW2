/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
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

	void display()										//вывод информации по предмету
	{
		cout << "complexity: " << complexity << "; hours: " << hours << "; ";
	}

private:

	int complexity;										//трудоемкость предмета (коэффициент 1-10)
	int hours;											//часы в неделю
};

class Point
{

public:

	int get()											//получить балл по индексу
	{
		return point;
	}

	void read(int val)									//записать балл по индексу
	{
		point = val;
	}

private:
	int point;
};


class Student
{

public:	
	#define M 50

	Student(int NumberSubjects = 3)
	{
		this->N = NumberSubjects;
		points = new Point[N];
		subjects = new Discipline[N];
	}
	~Student()
	{
		delete [] points;
		delete [] subjects;
	}

	void init(char s[])
	{
		for(int i = 0; i < M; i++)
		{
			name[i] = s[i];
			if(name[i] == '\0') break;
		}
	}

	void read()												//инициал. ученика
	{
		cout << "Enter name student: ";
		cin.getline(name, M);

		for(int i = 0; i < N; i++)
		{
			int hours;										//часы в неделю
			int complexity;									//трудоемкость предмета (коэффициент 1-10)
			int point;										//балл

			cout << "Subject #" << i + 1 << endl;
			do {
				cout << " ~ Enter complexity: ";
				cin >> complexity;
			} while(complexity > 10 || complexity < 1);

			do {
				cout << " ~ Enter hours: ";
				cin >> hours;
			} while(hours < 0);

			subjects[i].init(complexity, hours);

			do {
				cout << " ~ Enter point: ";
				cin >> point;
			} while(point < 0);

			while(cin.get() != '\n');

			points[i].read(point);
		}

	}

	void display()											//вывод инф. по ученику
	{
		cout << "Student: " << name << endl;
		cout << "Number of subjects: " << N << endl;

		for(int i = 0; i < N; i++)
		{
			cout << i + 1 <<") ";
			subjects[i].display();
			cout << "point: " << points[i].get() << "; ";
			cout << endl;
		}
	}

	float status()											//возр. средний рейтинг ученика
	{
		float tmp = 0;
		for(int i = 0; i < N; i++)
			tmp += points[i].get() * subjects[i].discipline_weight();
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

	Point *points;
	Discipline *subjects;									//указатель на массив объектов-предмет

private:

	char name[M];
	int N;
};

int main()
{
	Student Oleg(2);
	Oleg.init("123");
	Oleg.points[0].read(75);
	Oleg.points[1].read(55);

	Oleg.display();

	Oleg.subjects[0].init(5, 17);
	Oleg.subjects[1].init(4, 15);

	Oleg.display();

	cout << "Student rating: " << Oleg.status() << "; the heaviest subject: " << Oleg.max_discipline_weight() + 1 << "; " << endl;


	return 0;
}
