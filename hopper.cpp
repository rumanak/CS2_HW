// Rumana Khan 

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>
#include "hopper.h"

using namespace std;

Hopper::Hopper()
{
    //empty
}
void Hopper::openfile(ifstream &infile, string &fname)
{
    using namespace std;
    cout << "Hello, please choose a flight to book seats on from the following:"
         << "fa9911.fdf (it is a hopper flight)"; 

    cin >> fname;

    infile.open(fname);
    if (infile.fail( ))
    {
        cout << fname << ": file open failed for input file.\n";
        exit(1);
    }
}
void Hopper::save_flight_data(const vector<string> &rows,const string &fname)
{
    using namespace std;
    ofstream outfile(fname);
    if (outfile.fail())
    {
        cout << fname << ": file open for writing failed.\n";
        exit(1);
    }
    for (string r : rows)
        outfile << r << endl;
    outfile.close();
    return;
}
unsigned int Hopper::get_flight_data(ifstream &fdin, vector<string> &vec)
{
    using namespace std;
    string row;
    while (getline(fdin, row))
        vec.push_back(row);
    return vec.size();
}
void Hopper::read_flight_data(ifstream &fltdata,string &fname, 
        vector<string> &rows,unsigned int &rowct)
{
    openfile(fltdata, fname);
    rowct = get_flight_data(fltdata, rows);
    fltdata.close();
    if (rowct == 0)
    {
        std::cerr << "Nothing in flight data file.  Exiting." << std::endl;
        exit(1);
    }
    return;
}
void Hopper::displayrow(const string &rw)
{
    int count = 1;
    for (unsigned int i = 0U; i < rw.length(); ++i)
    {
        if (rw.at(i) == 'O')
        {
            cout << count << " ";
            count++;
        }
        else if (rw.at(i) == 'X')
        {
            cout << "X" << " ";
            count++;
        }
        else if ((rw.at(i) == 'F') || (rw.at(i) == 'E'))
        {
            //empty
        }
        else 
            cout << rw.at(i) << " ";
    }
    cout << endl;
    return;
}
void Hopper::special_seats(const string &rw)
{
    int count = 0;
    for (unsigned int i = 0U; i < rw.length(); ++i)
    {
        if (rw.at(i)  == 'W')
        {
            cout << "W" << " ";
        }
        else if (rw.at(i) == 'A')
        {
            cout << "A" << " ";
        }
        else 
        {
            count++;
            if (((count == 1) || (count == 3)) && (rw.at(i) == 'O'))
                cout << count << " ";
            else if ((count == 2) && (rw.at(i) == 'O'))
                cout << count << " ";
            else 
                cout << " " << " ";  
        }

    }
    cout << endl;
    return;
}
void Hopper::show_special_seats(vector<string> &seats)
{
    for (unsigned int i = 0U; i < seats.size(); ++i)
    {
        cout << "[" << setw(2) << i+1 << "]";
        special_seats(seats.at(i));
    }
    return;
}
void Hopper::showseating(const vector<string> &seats)
{
    using namespace std;
    for (unsigned int i = 0U; i < seats.size(); ++i)
    {
        cout << "[" << setw(2) << i+1 << "] ";
        displayrow(seats.at(i));
    }
    return;
}
bool Hopper::book_seat(vector<string> &rows, int rnum, char seat)
{
    int seatcount;
    if (seat == 1)
    {
        seatcount = seat;
    }
    else if ((seat == 2) || (seat == 3))
    {
        seatcount = seat + 1;
    }
   

        if (rows[rnum - 1][seatcount] == 'O') 
        {
            rows[rnum - 1][seatcount] = 'X';
            return true;
        }
        else 
            return false;
}
bool Hopper::remove_seat(vector<string> &rows, int &rnum, int &seat)
{
    int seatcount;
    if (seat == 1)
        seatcount = seat;
    else if ((seat == 2) || (seat == 3))
    {
        seatcount = seat + 1;
    }
    

        if (rows[rnum - 1][seatcount] == 'X') 
        {
            rows[rnum - 1][seatcount] = 'O';
            return true;
        }
        else 
            return false;
}
unsigned int Hopper::
get_seatcount(const vector<string> &seats)
{
    unsigned int count = 0U;

    for (unsigned int i = 0U; i < seats.size(); ++i)
    {
        for (char seat : seats[i])
        if ((isalpha(seat)) && (seat != 'W') &&
           (seat != 'A') && (seat != 'F') && (seat != 'E'))
        {
            count++;
        }
    }
    return count;
}
unsigned int Hopper::
get_occupied_ct(const vector<string> &seats)
{
    unsigned int count = 0U;

    for (unsigned int i = 0U; i < seats.size(); ++i)
    {
        for (char seat : seats[i])
            if (isalpha(seat) && seat == 'X')
                count++;
    }
    return count;
}
void Hopper::book_flight(vector<string> &rows)
{
    using namespace std;
    unsigned int numseats = get_seatcount(rows);
    unsigned int numoccupied = get_occupied_ct(rows);
    cout << "This plane has " << rows.size() << " rows.\n";

    int rownum;
    int seatnum;
    char ans;
    char y_or_n;
    bool repeat = true;
    do
    {
        cout << endl;
        cout << "Total seats: " << numseats << endl;
        cout << "Number open: " << numseats - numoccupied << endl;
        cout << "Show seating [s]\nBook a seat  [b]\nRemove a seat [r]\nQuit [q]\n";
        cin >> ans;
        switch(ans)
        {
            case 'b':
            case 'B':
                cout << "Would you like to see avaiable window and aisle seats?";
                cin >> y_or_n;
                if ((y_or_n  == 'n') || (y_or_n == 'N'))
                {
                    cout << "Enter the row number followed by the seat letter: ";
                    cin >> rownum >> seatnum;
                    cout << endl;
                    cout << "Seat " << rownum << " " << seatnum << " ";
                    if ( book_seat(rows, rownum, seatnum) )
                        cout << "has been booked." << endl;
                    else
                        cout << "is taken." << endl;
                    numoccupied = get_occupied_ct(rows);
                }
                else if ((y_or_n == 'y') || (y_or_n == 'Y'))
                {
                    show_special_seats(rows);
                    cout << "Enter the row number followed by the seat letter: ";
                    cin >> rownum >> seatnum;
                    cout << endl;
                    cout << "Seat " << rownum << " " << seatnum << " ";
                    if ( book_seat(rows, rownum, seatnum) )
                        cout << "has been booked." << endl;
                    else
                        cout << "is taken." << endl;
                    numoccupied = get_occupied_ct(rows);
                }
                break;
            case 's':
            case 'S':
                showseating(rows);
                break;
            case 'q':
            case 'Q':
                repeat = false;
                break; 
            case 'r':
            case 'R':
                cout << "Enter the row number followed by the seat letter:";
                cin >> rownum >> seatnum;
                cout << endl;
                cout << "Seat " << rownum << " " << seatnum << " ";
                if ( remove_seat(rows, rownum, seatnum) )
                    cout << "is now free." << endl;
                else 
                    cout << "was always empty." << endl;
                break;
            default:
                cout << "Unknown option." << endl;
        }
    } while (repeat);
    return;
}

     


























































































































































































































































