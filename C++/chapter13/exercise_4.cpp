#include <iostream>
#include <cstring>
#include "exercise_4.h"

using namespace std;

Port::Port(const char * br, const char * st, int b)
{
    int len;
    
    len = strlen(br);
    brand = new char [len+1];
    strcpy(brand, br);

    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    int len; 
    
    len = strlen(p.brand);
    brand = new char [len+1];
    strcpy(brand,p.brand);

    strcpy(style,p.style);
    bottles = p.bottles;
}



Port & Port::operator=(const Port & p)
{
    if(this==&p)
        return *this;
    delete [] brand;
    int len = strlen(p.brand);
    brand = new char [len+1];
    strcpy(brand,p.brand);

    strcpy(style,p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-(int b)
{
    if(bottles<b)
    {
        cout << "Bottles is less than " << b << endl;
        return *this;
    }

    bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

// friend of base class -- Port
ostream & operator<<(ostream & os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

/* derived class */
VintagePort::VintagePort()
{
    nickname = NULL;
    year = 0;
}

VintagePort::VintagePort(const char *br, const char * st, int b, const char *nn, int y)
 : Port(br, st, b)
{
    int len = strlen(nn);
    nickname = new char [len+1];
    strcpy(nickname,nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
    : Port(vp)
{
    int len = strlen(vp.nickname);
    nickname = new char [len+1];
    strcpy(nickname,vp.nickname);
    year = vp.year;   
}


VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this==&vp)
        return *this;
    Port::operator=(vp);    // base class
    int len = strlen(vp.nickname);
    nickname = new char [len+1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nick Name: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os ,const VintagePort &vp)
{
	os << (Port &) vp;
	os << ", " << vp.nickname << ", " << vp.year << "years.\n";
}
