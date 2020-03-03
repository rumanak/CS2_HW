/*
 * H FILE for DollarAmount
 * Name: Rumana Khan 
 * Date Last Modified: 2/9/2020
 * Known Bug: N/A
 */

#ifndef _DOLLAR_
#define _DOLLAR_

using namespace std;

class DollarAmount
{
public:

    //default constructor
    DollarAmount();
    //constructor
    DollarAmount (int d, int c);

    //getter functions
    int get_dollar();
    int get_cents();

    //functions needed to output dollar amount in words
    //All needed to output the total DollarAmount
    bool check (int d);
    bool chk (int c);
    string num_word(int n, string s);
    string convert(int n);

    //overloaded operations

    //extraction (or get-from) operator
    //Overloads the >> operator so it can input values of DollarAmount
    //Precondition: If ins is a file input stream, then ins is connected.
    friend istream& operator>>(istream &ins, DollarAmount & d);

    //insertion (or put-to) operator
    //Overloads the << operator so it can be output values of type DollarAmount
    //Precondition: If ous is a file output stream, then ous is connected.
    friend ostream& operator<<(ostream &ous, const DollarAmount & d);

    //overloaded operator + (addition)
    friend DollarAmount operator + 
    (const DollarAmount &a, const DollarAmount &b);

    //overloaded operator / (division)
    friend DollarAmount operator /
    (const DollarAmount &a, const int &b);

    //relational operator > (greater-than)
    friend bool operator > 
    (const DollarAmount &a, const DollarAmount &b);

private:
    int dollar;
    int cents;

};

#endif //_DOLLAR_H_
