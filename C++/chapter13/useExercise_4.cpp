/*
 * useExercise_4.cpp
 *
 *  Created on: 2015Äê4ÔÂ5ÈÕ
 *      Author: Z.Y Wang
 */

#include <iostream>
#include "exercise_4.h"

using namespace std;
int main()
{
    Port v1;
    Port v2("Gallo", "tawny", 20);
    VintagePort v3("Maotai", "ruby", 30, "The Noble", 50);

    Port *pv;

    cout << "Using object directly";
    v2.Show();
    v3.Show();

    cout << endl << "Using type Port * pointer to object";
    pv = &v2;
    pv->Show();
    pv = &v3;
    pv->Show();

    cout << endl << "Output object directly\n" << v2 << v3;

    cout << endl << "Tensting assignmeng\n";
    v1 = v2;
    cout << v1 << endl;
    v1 = v3;
    cout << v1 << endl;

    return 0;

}

