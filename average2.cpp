/* Rumana Khan 
 * hw 3 
 * 9/9/19 
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;;

//opens instream file
void open_file(std::ifstream &inf, std::string &fname)
{
    cout << "What file do you want to use?";
    cin >> fname;
    inf.open(fname);

    if (inf.fail())
    {
        cout << "Input file open failed." << endl;
        exit(1);
    }
}
//opens outstreams file
void open_file(std::ofstream &onf, std::string &fname1)
{   
    cout << "What is the name of the file you would like to outfile to?";
    cin >> fname1;
    onf.open(fname1);

    if (onf.fail())
    {
        cout << "Output file open failed." << endl;
        exit(1);
    }
}
//checks to see if number is valid
bool valid_number(double grade, double min_num, double max_num)
{
    min_num = 0;
    max_num = 100;
    if ((min_num <= grade) && (grade <= max_num))
    {
        return true;
    }
    else 
    {
        return false;
     }
}

int main()
{
    ifstream inStream;
    ofstream outStream;
    string filename;
    string outfile;
    string firstname;
    string lastname;
    double sum;
    double grade;
    double counter = 0;
    double average;
    double min_num = 0;
    double max_num = 100;
    double least;
    double leastsum;
    double leastcount;
    double leastavg;
 
    open_file(inStream, filename);
    open_file(outStream, outfile);

    inStream >> lastname >> firstname;
    outStream << firstname << " " << lastname << " ";

    while (inStream >> grade)
    {
        if (valid_number(grade, min_num, max_num))
        {
            outStream << grade << " ";
            counter ++;
            if (counter == 1)
            {
                sum = grade;
                least = grade;
            }
            else 
            {  
                sum += grade;
                if (least > grade)
                {
                    least = grade;
                }
            }
        }
    }

     outStream.setf(ios::fixed);
     outStream.setf(ios::showpoint);
     outStream.precision(4);

     average = sum/counter;
     if (grade  == 0)
        outStream << "N/A" << endl;
     else 
        outStream << average << " ";

     leastsum = sum - least;
     leastcount = counter - 1;
     leastavg = leastsum/leastcount;

     outStream << leastavg << endl;


    inStream.close();
    outStream.close();

    return 0;
}
