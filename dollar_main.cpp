/*
 * main file for DollarAmount
 * Name:Rumana Khan
 * Date Last Modified: 2/9/2020
 * Known Bug: N/A
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "dollar.h"
using namespace std;

const int INIT_SIZE = 10;

int main ()
{
    cout << "Please use 0.0 to end the program." << endl;
           
    DollarAmount * arr = new DollarAmount[INIT_SIZE];
    DollarAmount * ptr=NULL;
    int arr_size =INIT_SIZE;
    int arr_len = 0;

    bool lastInput = false;

    do 
    {
        if (arr_len == arr_size)
        {
            ptr = new DollarAmount[arr_size*2];

            //cope each element in arr into the new array that ptr points to 
            for (int i = 0; i < arr_size*2; ++i)
            {
                ptr[i] = arr[i];
            }

            //now delete the current arr
            delete [] arr;
            arr = ptr;
            arr_size = arr_size*2;
        }

        cout << "Enter the dollar amount: $";
        cin >> arr[arr_len];//read in a dollar amount from cin

        //if its 0.0
        if (arr[arr_len].get_dollar()==0 && arr[arr_len].get_cents()==0)
            lastInput = true;
        else
            arr_len++;
    }while (!lastInput);
    
    DollarAmount total(0,0);

    // A loop to add all the DollarAmount up, and display the total
    for (int i = 0; i < arr_size; i++)
    {
        total = total + arr[i];    
    }

    //Bubble Sorts the array of DollarAmount
    int n_size = arr_size - 1;
    int j;
    for (int pass = 0; pass < arr_size; pass++)
    {
        for (j = 0; j < n_size; j++)
        {
            if (arr[j] > arr[j+1])
            {
                //temp
                DollarAmount tmp;
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
        n_size -= 1;
     }
    //Outputs the sorted list
    cout << "Sorted List:" << endl;

    int count = 0;
    for (int k = 0; k < arr_size; k++)
    {
        if(arr[k].get_dollar()==0 && arr[k].get_cents()==0)
            cout << "";
        else 
        {
            cout << arr[k] << endl;
            count++;
        }
    }

    if (total.check(total.get_dollar()) && (total.chk(total.get_cents()))) 
    {
        cout << "The total is $" << total << endl;
        cout << total.convert(total.get_dollar());
        cout << "and " << total.get_cents() << "/100" << endl;
    }
    
    //Code needed to find the median
    int remain = 10 - count;
    DollarAmount median;
    if (count%2 == 0)
    {
        median = (arr[remain + (count -1)/2] + arr[remain + count/2])/2;
    }
    else 
    {
        median = arr[remain + (count/2)];
    }
    cout << "The median is $" << median << endl;
   
    cout << "Bye!" << endl;

    return 0;
}
