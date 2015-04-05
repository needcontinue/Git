/*
 * exercise_1.cpp
 *
 *  Created on: 2015Äê4ÔÂ5ÈÕ
 *      Author: YI
 */

#include <iostream>
#include "exercise_1.h"
#include <string.h>

using namespace std;

Cd::Cd(char *s1, char *s2, int n ,double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & rc)
{
    strcpy(performers, rc.performers);
    strcpy(label, rc.label);
    selections = rc.selections;
    playtime = rc.playtime;   
}

Cd::Cd()
{
    strcpy(performers, "none");
    strcpy(label, "none");
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
	}

void Cd::Report() const
{
    cout << "Performer is : " << performers << endl;
    cout << "label of this CD is : " << label << endl;
    cout << "this CD contain " << selections << " selections" <<
            " and will play " << playtime << " minutes.\n";
}

Cd & Cd::operator=(const Cd & rc)
{
	if(this==&rc)
		return *this;
	strcpy(performers,rc.performers);
	strcpy(label,rc.label);
	selections = rc.selections;
	playtime = rc.playtime;
	return *this;
}


// devriated calss
Classic::Classic(char * s0, char * s1, char * s2, int n ,double x)
 : Cd(s1,s2,n,x)
{

   strcpy(primaryWork, s0);
}

Classic::Classic()
{

}

Classic::Classic(const Cd & rc, char * s0)
 : Cd(rc)
{
    strcpy(primaryWork, s0);
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Then primary work of this disk is: " << primaryWork << endl;
}

Classic & Classic::operator =(const Classic & rc)
{
	if(this==&rc)
		return *this;
	Cd::operator=(rc);
	strcpy(primaryWork,rc.primaryWork);
	return *this;
}

