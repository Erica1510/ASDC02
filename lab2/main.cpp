#include <iostream>
#include <fstream>
#include<ctime>
#include <stdio.h>
#include<chrono>
#include<math.h>
#include "Video_Cards.hpp"
#include "Prototipes.h"
#include "Video_Cards.cpp"

using namespace std;



int main()
{
    time_t start, end;
    
    Video_Cards obj[50];
    std::ifstream file("/Users/ericadiaciuc/Desktop/алгоритмы и стр/L2/Table.txt");
    
    
    cin.clear();
    while (i != 51) {
        file >> obj[i].Product_code >>  obj[i].Name >> obj[i].Producer >> obj[i].TechnicalProcess >> obj[i].EnergyConsum >> obj[i].Price;
        i++;
    }
    ///-----------------------------------------------
    cout<<"---Search Methods in Tables---"<<endl;
    
    unsigned int start_time =  clock();
    
    Bubble_Sort(&obj[0]);
    
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    double sec =search_time;
    cout<<"Time = "<< sec/1000;
    
    ///----------------------------------------------
    unsigned int start_time2 =  clock();
    
    Insertion_Sort(&obj[0]);
    
    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;
    double sec2 =search_time2;
    cout<<"Time = "<< sec2/1000;
    
    ///----------------------------------------------
    unsigned long start_time3 =  clock();
    
    Selection_Sort(&obj[0]);
    
    unsigned int end_time3 = clock();
    unsigned int search_time3 = end_time3 - start_time3;
    double sec3 =search_time3;
    cout<<"Time = "<< sec3/1000;
    
    ///------------------------------------------------
    
    cout << "\n\n~~~~~~~~~~~~~~~~~Quick_Sort~~~~~~~~~~~~~~~~~\n" << endl;
    int p, n;
    unsigned int start_time4 =  clock();
    Quick_Sort(obj, 0, 49);
    
    for ( int i = 0; i < 50; i++ ) {
        obj[i].output();
        cout << endl;
    }
    cout << "\nQuick Sort at the best case - O(n*2*log2n) -> " << (50 * 2 * log(2*50)) \
    << ",\n at worst case - O(n^2) -> " << pow(50,2) << ", average - O(n*log*2*n) -> " \
    << (50 * log(2*50))  << endl;
    cout<<"Number of comparisons = "<< scet <<endl;
    cout<<"Number of swaps = "<<c<<endl;
    
    unsigned int end_time4 = clock();
    unsigned int search_time4 = end_time4 - start_time4;
    double sec4 =search_time4;
    cout<<"Time = "<< sec4/1000;
    
    ///------------------------------------------------
    
    unsigned int start_time5 =  clock();
    Shell_Sort(&obj[0],50);
    
    unsigned int end_time5 = clock();
    unsigned int search_time5 = end_time5 - start_time5;
    double sec5 =search_time5;
    cout<<"Time = "<< sec5/1000;
    
    ///------------------------------------------------
    
    unsigned int start_time6 =  clock();
    Heap_Sort(&obj[0],50);
    
    unsigned int end_time6 = clock();
    unsigned int search_time6 = end_time6 - start_time6;
    double sec6 =search_time6;
    cout<<"Time = "<< sec6/1000;
    
    ///------------------------------------------------
    cout << "\n\n~~~~~~~~~~~~~~~~~Merge_Sort~~~~~~~~~~~~~~~~~\n" << endl;
    unsigned int start_time7 =  clock();
    Merge_Sort(&obj[0], 0, 49);
    
    for ( int i = 0; i < 50; i++ ) {
        obj[i].output();
        cout << endl;
    }
    
    cout << "\nMerge Sort O(n*log(n)) -> 50 * log(50) -> " << (50 * log(50)) << endl;
    cout<<"Number of comparisons = "<< scet3 <<endl;
    cout<<"Number of swaps = "<<c3<<endl;
    
    unsigned int end_time7 = clock();
    unsigned int search_time7 = end_time7 - start_time7;
    double sec7 =search_time7;
    cout<<"Time = "<< sec7/1000;
    return 0;
}



