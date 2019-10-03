/* @autor Rakhmanin Danila aka Radist AltSTU PI-82
 *
 * Блюдо(dish) представляет собой несколько отдельный продуктов(food).
 * реалзовать характеристики продуктов: вкус, внешний вид, сытность, соленость
 * создать зависимоть характеристик блюда от продуктов
 * сделать соленость условно "константой", которую можно изменить только через функцию "посолить"
 *
 */

#include <iostream>

using namespace std;


class Food											//класс вкус
{
	#define N 50
public:

	void read()										//иниц. еды
	{
		cin.clear();
		cout << " ~ Enter name food: ";
		cin.getline(name, N);

		do {
			cout << " ~  ~ Enter taste: ";
			cin >> taste;
		} while(taste < 1 || taste > 10);

		do {
			cout << " ~  ~ Enter appearance: ";
			cin >> appearance;
		} while(appearance < 1 || appearance > 10);

		do {
			cout << " ~  ~ Enter satiety: ";
			cin >> satiety;
		} while(satiety < 1 || satiety > 10);

		while(cin.get() != '\n');

		salt = 1;
	}

	void init(char s[], int in_taste, int in_appearance, int in_satiety)
	{
		for(int i = 0; s[i] != '\0'; i++)
			name[i] = s[i];

			taste = in_taste;
			appearance = in_appearance;
			satiety = in_satiety;
	}

	void display()									//вывод еды
	{
		cout << " ~ Food: " << name << endl;
		cout << " ~  ~ taste: " << taste << endl;
		cout << " ~  ~ appearance: " << appearance << endl;
		cout << " ~  ~ satiety: " << satiety << endl;
		cout << " ~  ~ salt: " << salt << endl;
	}

	void toSalt()									//"сложная" технология соления
	{
		salt++;
		if(salt > 10)
		{
			salt = 10;
		} else if(salt > 4)
		{
			taste = taste / 2;
		}
	}

	int getTaste()
	{
		return taste;
	}

	int getAppearance()
	{
		return appearance;
	}

	int getSatiety()
	{
		return satiety;
	}

	int getSalt()
	{
		return salt;
	}
private:

	char name[N];									//имя еды
	int taste;										//вкус
	int appearance;									//внешний вид
	int satiety;									//сытность
	int salt;										//солёность

};

class Dish
{
public:
#define N 50

	Dish(int size = 2)
	{
		if(size < 2)
			size = 2;

		foods = new Food[size];
		size_dish = size;
	}
	~Dish()
	{
		delete [] foods;
	}

	void init(char s[])
	{
		for(int i = 0; s[i] != '\0'; i++)
			name[i] = s[i];
	}

	void read()											//иниц. блюда
	{
		cin.clear();
		cout << "Enter name dish: ";
		cin.getline(name, N);
	}

	void display()										//вывод имени блюда и вызов дисплея еды
	{
		cout << "Dish: " << name << endl;
		for(int i = 0; i < size_dish; i++)
			foods[i].display();
	}

	void toSalt()										//посолить еду
	{
		for(int i = 0; i < size_dish; i++)
			foods[i].toSalt();
	}

	void assessmentDish()								//оценка блюда
	{
		int taste = 0;									//вкус
		int appearance = 0;								//внешний вид
		int satiety = 0;								//сытность
		int salt = 0;									//солёность

		for(int i = 0; i < size_dish; i++)
			taste += foods->getTaste();
		taste /= size_dish;

		for(int i = 0; i < size_dish; i++)
			appearance += foods->getAppearance();
		appearance /= size_dish;

		for(int i = 0; i < size_dish; i++)
			satiety += foods->getSatiety();

		for(int i = 0; i < size_dish; i++)
			salt += foods->getSalt();
		salt /= size_dish;

		cout << "Dish: " << name << endl;
		cout << " ~ taste dish: " << taste << endl;
		cout << " ~ appearance dish: " << appearance << endl;
		cout << " ~ satiety dish: " << satiety << endl;
		cout << " ~ salt dish: " << salt << endl;

	}

private:

	char name[N];										//имя блюда
	Food *foods;
	int size_dish;										//кол-во объектов класса Food в Dish
};

int main()
{

	Dish q;
	q.display();
	cout << endl;
	q.assessmentDish();

	return 0;
}
