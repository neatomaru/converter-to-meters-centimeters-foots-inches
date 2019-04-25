//
// Created by admin on 2019-04-25.
//

#ifndef HELLO_WORLD_SERVICES_H
#define HELLO_WORLD_SERVICES_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Services {
private:
    const double m_to_cm = 100;
    const double in_to_cm = 2.54;
    const double ft_to_in = 12;


    /*
     * Перевод значений в сантиметры
     */
    double toCentimeters(double value, char unit) {
        double buffer = 0;

        switch (unit) {
            case 'm':
                return value * m_to_cm;


            case 'c':
                return value;

            case 'i':
                return value * in_to_cm;


            case 'f':
                return value * ft_to_in * in_to_cm;


        }
    }


    /*
     *
     * Перевод значений в дюймы
     */
    double toInches(double value, char unit)
    {
        double buffer = 0;

        switch (unit) {
            case 'm':
                return value * m_to_cm / in_to_cm;


            case 'c':
                return value / in_to_cm;

            case 'i':
                return value;


            case 'f':
                return value * ft_to_in;


        }
    }


    /*
     *
     * Перевод значений в футы
     */
    double toFoot(double value, char unit)
    {

        switch (unit) {
            case 'm':
                return value * m_to_cm / in_to_cm / ft_to_in;


            case 'c':
                return value / in_to_cm / ft_to_in;

            case 'i':
                return value / ft_to_in;


            case 'f':
                return value;


        }
    }



public:
/*
 * Перевод значений в метры
 */
    double toMeters(double value, char unit) {

        switch (unit) {
            case 'm':
                return value;


            case 'c':
                return value / m_to_cm;

            case 'i':
                return value * in_to_cm / m_to_cm;


            case 'f':
                return (value * ft_to_in * in_to_cm / m_to_cm);


        }

    }


    /*
     *
     * Функция в текстовом виде выводит конвертированные значения
     */
    void convertion(double value, char unit) {

        bool flag = true;
        double buffer = 0;
        switch (unit) {
            case 'm': {

                cout << value << "m == " << toCentimeters(value, unit) << "cm\n";

                cout << value << "m == " << toInches(value, unit) << "in\n";

                cout << value << "m == " << toFoot(value, unit) << "ft\n";
                break;
            }

            case 'c': {
                cout << value << "cm == " << toMeters(value, unit) << "m\n";

                cout << value << "cm == " << toInches(value, unit) << "in\n";

                cout << value << "cm == " << toFoot(value, unit) << "ft\n";
                break;
            }
            case 'i': {
                cout << value << "in == " << toCentimeters(value, unit) << "cm\n";

                cout << value << "in == " << toMeters(value, unit) << "m\n";

                cout << value << "in == " << toFoot(value, unit) << "ft\n";
                break;
            }

            case 'f': {

                cout << value << "ft == " << toInches(value, unit) << "in\n";

                cout << value << "ft == " << toCentimeters(value, unit) << "cm\n";

                cout << value << "ft == " << toMeters(value, unit) << "m\n";
                break;
            }

            default:
                cout << "Неизвестная величина!\n";
                break;

        }


    }

};


#endif //HELLO_WORLD_SERVICES_H
