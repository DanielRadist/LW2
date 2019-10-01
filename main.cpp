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

class Student
{

public:	
	#define N 3												//кол-во предметов у ученика

	Student()
	{
		init();
	}
	~Student()
	{

	}

	void init()												//инициал. ученика
	{
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
			points[i] = point;
		}
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

private:

	class Discipline
	{
	public:

		float discipline_weight(int hours, int complexity)	//вес предмета в рейтинге
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

	int points[N];											//баллы по предметам
	Discipline subjects[N];									//указатель на массив объектов-предмет
};

int main()
{
	Student q;
	q.display();
	//Student::subject_pattern sub;


	return 0;
}
