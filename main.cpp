#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Services.h"
using namespace std;



/*
 * В этой программе пользователь может вводить любое значение из величин(метры, сантиметры, футы и дюймы)
 * и получать отконвертированные значения. Чтобы выйти из программы нужно ввести символ '|'.
 * В конце программы пользователю выводятся все введенные им значения в метрах, а так же максимальное и минимальное
 * значения
 *
 * c - сантиметры
 * m - метры
 * f - футы
 * i - дюймы
 *
 *
 */

    int main() {

        Services services;


        vector<double> values;

        vector<char> allow = {'c', 'm', 'f', 'i'};


        char unit = ' ';
        int cnt = 0;
        double var1 = 0, max = 0, min = 0;
        cout << "Введите любую из приведенных ниже величин в формате значение - величина(100 m, 11 f)\n";
        cout << "c - сантиметры\n";
        cout << "m - метры\n";
        cout << "f - футы\n";
        cout << "i - дюймы\n";
        cout << "Для выхода из программы введите '|'\n";

        cout << "Вводите значения: \n";
        while (cin >> var1 >> unit) {


            if (var1 == '|') break;

            //Здесь программа выводит значения данной величины в других представленных величинах
            services.convertion(var1, unit);

            //Если пользователь ввел недопустимую величину - ему представляется возможность переввести значние и величину
            if(!(find(allow.begin(), allow.end(), unit) != allow.end())) continue;

            //Перевод значения в метры и дальнейшее сравнение его с предыдущими введенными значениями
            var1 = services.toMeters(var1, unit);
        
            //если программа запущена впервые - мин и макс принимают значения первого введенного числа
            if (cnt == 0)
            {
                max = var1, min = var1;
            }
            ++cnt;
            if (var1 > max) {
                max = var1;
                cout << var1 << "m - наибольшее среди выделенных!\n";
            }
            if (var1 < min) {
                min = var1;
                cout << var1 << "m - наименьшее среди выделенных\n";
            }

            //Добавление значения в вектор
            values.push_back(var1);


        }
        //сортировка вектора
        sort(values.begin(), values.end());

        for(double x : values)
        {
            cout << x << "m ";
        }

        cout << "\n" << max << "m - наибольшее число!";
        cout << "\n" << min << "m - наименьшее число!";
    }
