/* Rumana Khan 
 * hw 3 
 * 9/9/19 
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;
//opens ifstream by asking user for the name of the string to use
 void open_file(std::ifstream &inf, std::string &fname)
{
    cout << "What file do you want to use?";
    cin >> fname;
    inf.open(fname);

    if (inf.fail())
    {
        cout<< "Input file open failed." << endl;
        exit(1);
    }
}

int main ()
{
    ifstream inStream;
    string filename;
    string firstname;
    string lastname;
    double sum;
    double grade;
    double counter = 0;
    double average;
 
    open_file(inStream, filename);

    inStream >> lastname >> firstname;
    cout << firstname << " " << lastname << " ";

    // accounts for the sum
    while (inStream >> grade)
    {
        counter ++;
        if (counter == 1)
            sum = grade;
        else 
            sum += grade;
    }

     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     cout.precision(4);

     average = sum/counter;
     if (grade  == 0)
         cout << "N/A" << endl;
     else 
        cout << average << endl;

    // CLOSES IFSTREAM
    inStream.close();

    return 0;
}
