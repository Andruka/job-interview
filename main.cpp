#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Geometrical_Figure.h"
#include <cmath>
#include <algorithm>
#include <typeinfo>
#include <cstring>

using namespace std;

//перегруженная функция генерации и добавления кривой в контейнер

void add(int type,bool flags[],vector<shared_ptr<Geometrical_Figure>> &first_container) {
    int rad, rad_x, rad_y, st;
	if (type == 0) {
		flags[0] = false;
		rad = 1 + rand() % 10;
		first_container.push_back(make_shared<Circle>(rad));
	}
	else if (type == 1) {
		flags[1] = false;
		rad_x = 1 + rand() % 10;
		rad_y = 1 + rand() % 10;
		first_container.push_back(make_shared<Ellipse>(rad_x,rad_y));
	}
	else if (type == 2) {
		flags[2] = false;
		rad = 1 + rand() % 10;
		st = 1 + rand() % 5;
		first_container.push_back(make_shared<Spiral>(rad,st));
	}
}

int main()
{
    int type;
    bool flags[3] = {true,true,true};
    int sum = 0;
    vector <shared_ptr<Geometrical_Figure>> first_container;
    vector <shared_ptr<Geometrical_Figure>> second_container;

    //генерация кривых различных типов и заполнение первого контейнера

    srand(time(NULL));
    for (int i = 0; i < 25; ++i) {
        type = rand() % 3;
		add(type, flags, first_container);
    }

    //проверка на наличие в первом контейнере кривых всех типов

    for (int i = 0; i < 3; ++i) {
        if(flags[i]) {
			add(type, flags, first_container);
        }
    }

    //вывод в консоль координат точки и первой производной для каждой кривой из первого контейнера

    for (unsigned int i = 0; i < first_container.size(); ++i) {
		cout << i + 1 << ") " << typeid(*first_container[i]).name() << endl;
		first_container[i]->print(PI_4);
    }

    //добавление всех кругов из первого контейнера во второй контейнер

    for (unsigned int i = 0; i < first_container.size(); ++i) {
        if(!strcmp(typeid(*first_container[i]).name(), "class Circle")) second_container.push_back(first_container[i]);
    }

	//сортировка второго контейнера по радиусам

    sort(second_container.begin(),second_container.end(),comp);

    //подсчёт суммы радиусов всех кривых из второго контейнера

    for (unsigned int i = 0; i < second_container.size(); ++i) {
        sum += second_container[i]->get_radius();
    }
    return 0;
}
