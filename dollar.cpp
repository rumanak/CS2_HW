/*
 * DollarAmount Class CPP File 
 * Author: Rumana Khan 
 * Last Modified: 2/1/2020
 * Known Bug: N/A
 */

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include "dollar.h"

using namespace std;

//default constructor
DollarAmount::DollarAmount()
{
    dollar = 0;
    cents = 0;
}
//constructor
DollarAmount::DollarAmount(int d, int c)
{
    dollar = d;
    cents = c;
}
//getter function 
//outputs the private dollar variable
int DollarAmount::get_dollar()
{
    return dollar;
}
//getter function
//outputs the private cents variable
int DollarAmount::get_cents()
{
    return cents;
}
//Bool function
//Checks if the input is valid or not
bool DollarAmount::check(int d)
{
    if (d > 9999)
    {
        cout << "Too big of a input!" << endl;
        return 0;
    }
    else if (d < 0)
    {
        cout << "CAN NOT BE NEGATIVE!!!" << endl;
        return 0;
    }
    else if (cin.fail())
    {
        cout << "Wrong input types." << endl;
        cin.clear();
        cin.ignore(2048, '\n');
        return 0;
    }
    else
        return 1;
}
//Bool Function
//Checks if input for cents makes sense
bool DollarAmount::chk(int c)
{
    if (c < 0) 
    {   
        cout << "Too many digits for cents!!!" << endl;
        return 0;
    }
    else if (c >= 100)
    {
        cout << "Too many digits for cents!!!" << endl;
        return 0;
    } 
    else
        return 1;
}
//String Function 
//Converts dollar amounts 0 through 19
string DollarAmount::num_word(int n, string s)
{
    string one[] = { "", "one ", "two ", "three ", "four ", "five ", "six ",
                     "seven ", "eight ", "nine ", "ten ", "eleven ", 
                     "twelve ", "thirteen ", "fourteen ", "fifteen ", 
                     "sixteen ", "seventeen ", "eighteen ", "nineteen "
                   };

    string ten[] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", 
                    "sixty ", "seventy ", "eighty ", "ninety "
                   };
    string str = "";
    if (n > 19)
        str += ten[n/10] + one[n%10];
    else 
        str += one[n];
    return str;

}
//String Function
//Converts dollar amounts from 19 to 9999
string DollarAmount::convert(int n)
{
    string output;

    output += num_word(((n/1000) % 100), "");
    if (n > 999)
        output += "thousand ";

    output += num_word(((n/100) % 10), "");
    if ((n/100) % 10)
        output += "hundred ";

    if (n > 100 && n % 100)
        output += "and ";

    output += num_word((n%100), "");

    return output;
}
//get-from operator (extraction)
istream& operator >>(istream &ins, DollarAmount & d)
{
    char dot;
    ins >> d.dollar;
    ins >> dot;
    ins >> d.cents;
    return ins;
}
//put-to operator (insertion)
ostream& operator <<(ostream &ous, const DollarAmount & d)
{
    ous << d.dollar << "." << d.cents;
    return ous;
}
//overloads operator +
DollarAmount operator + (const DollarAmount &a, const DollarAmount &b)
{
    int new_d = a.dollar + b.dollar;
    int new_c = a.cents + b.cents;
        if (new_c >= 100)
        {
            new_c =- 100;
            new_d =+ 1;
        }
    DollarAmount new_type(new_d, new_c);
    return new_type;
}
//overloads operator /
DollarAmount operator / (const DollarAmount &a, const int &b)
{
    int new_d = a.dollar/b;
    int new_c = a.cents/b;
    DollarAmount new_type(new_d, new_c);
    return new_type;
}
//relational operator 
//overloads operator > (greater-than)
bool operator > (const DollarAmount &a, const DollarAmount &b)
{
    if (a.dollar > b.dollar)
        return 1;
    else if ((a.dollar == b.dollar) && (a.cents > b.cents))
        return 1;
    else 
        return 0;
}

