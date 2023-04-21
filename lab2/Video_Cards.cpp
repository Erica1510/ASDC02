//
//  Video_Cards.cpp
//  lab2
//
//  Created by Erica Diaciuc on 21.04.2023.
//
#include "Video_Cards.hpp"
#include "Prototipes.h"
#include <iostream>
#include <fstream>
#include <cmath>

int i = 0, c=0, scet=0, scet2=0, scet3=0, c3=0;

void swap(Video_Cards *a, Video_Cards *b){
    Video_Cards temp = *a;
    *a = *b;
    *b = temp;
    c++;
}

void Bubble_Sort(Video_Cards* obj)
{
    int i,c=0, ok,p=0;
    Video_Cards aux;
    
    do
    {
        ok=1;
        
        for(i=0;i<49;i++){
            if(obj[i].Product_code>obj[i+1].Product_code){p++;}}
        
        for(i=0;i<49;i++){
            if(obj[i].Product_code>obj[i+1].Product_code)
            {
                aux=obj[i];
                obj[i] = obj[i+1];
                obj[i+1]=aux;
                c++;
                ok=0;
            }}}
    while(ok!=1);
    
    std::cout << "\n~~~~~~~~~~~~~~~~~Bubble_Sort~~~~~~~~~~~~~~~~~\n" << std::endl;
    for (i = 0; i < 50; i++) {
        obj[i].output();
        std::cout << std::endl;
    }
    std::cout << "\nBubble Sort O(n^2) -> 50^2 -> " << 50*50 << std::endl;
    std::cout<<"Number of comparisons = "<< p<<std::endl;
    std::cout<<"Number of swaps = "<< c;
    
    
    std::cout<<std::endl;
    
}

void Insertion_Sort(Video_Cards* obj){
    std::cout << "\n\n~~~~~~~~~~~~~~~~~Insertion_Sort~~~~~~~~~~~~~~~~~\n" << std::endl;
    int c=0,p=0,counte = 0;
    for(int i=1;i<50;i++){
        for(int j=i; j>0;j--){
            if(obj[j-1].Price >  obj[j].Price){p++;}}}
    
    for(int i=1;i<50;i++){
        for(int j=i; j>0;j--){
            if (obj[j-1].Price >  obj[j].Price){
                Video_Cards tmp= obj[j-1];
                obj[j-1]= obj[j];
                obj[j]=tmp;
                c++;
            }}
    }
    for ( int i = 0; i < 50; i++ ){
        obj[i].output();
        std::cout << std::endl;
    }
    std::cout <<"\nInsertion Sort O(n^2) -> 50^2 -> " << 50*50 << std::endl;
    std::cout<<"Number of comparisons = "<< p<<std::endl;
    std::cout<<"Number of swaps = "<<counte<<std::endl;
}


void Selection_Sort(Video_Cards* obj) {
    int p=0;
    std::cout << "\n\n~~~~~~~~~~~~~~~~~Selection_Sort~~~~~~~~~~~~~~~~~\n" << std::endl;
    for (int s = 0; s < 50; s++) {
        int j = s;
        for (int i = s + 1; i < 50; i++) {
            if (obj[i].Product_code < obj[j].Product_code) {p++;}
            if (obj[i].Product_code < obj[j].Product_code)
                j = i;
        }
        
        swap(&obj[j], &obj[s]);
    }
    for ( int i = 0; i < 50; i++ ) {
        obj[i].output();
        std::cout << std::endl;
    }
    std::cout << "\nSelection Sort O(n2) -> 50 * 2 -> " << 50 * 2 << std::endl;
    std::cout<<"Number of comparisons = "<< p<<std::endl;
    std::cout<<"Number of swaps = "<<c<<std::endl;
}

///---------------------------------------------------
int partition(Video_Cards obj[], int s1, int s2)
{
    int pivot = obj[s1].Price;
    int c = 0;
    
    for (int i = s1 + 1; i <= s2; i++) {
        if (obj[i].Price <= pivot)
            c++;
    }
    int pivotIndex = s1 + c;
    swap(&obj[pivotIndex], &obj[s1]);
    
    int i = s1, j = s2;
    while (i < pivotIndex && j > pivotIndex) {
        while (obj[i].Price <= pivot) {
            i++;
        }
        while (obj[j].Price > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(&obj[i++], &obj[j--]);
            scet++;
        }
    }
    return pivotIndex;
}
int n=0;

void Quick_Sort(Video_Cards obj[], int s1, int s2)
{
    
    if (s1 >= s2) return ;
    int p = partition(obj, s1, s2);
    Quick_Sort(obj, s1, p - 1);
    Quick_Sort(obj, p + 1, s2);
    
    
}


void Shell_Sort(Video_Cards obj[], int N)
{
    int j, p=0, c=0;
    std::cout << "\n\n~~~~~~~~~~~~~~~~~Shell_Sort~~~~~~~~~~~~~~~~~\n" << std::endl;
    
    for (int gap = N/2; gap > 0; gap /= 2){
        
        for (int i = gap; i < N; i += 1){
            Video_Cards temp = obj[i];
            for (j = i; j >= gap && obj[j - gap].Product_code > temp.Product_code; j -= gap)
                p++; }
        
        for (int i = gap; i < N; i += 1){
            Video_Cards temp = obj[i];
            for (j = i; j >= gap && obj[j - gap].Product_code > temp.Product_code; j -= gap)
                obj[j] = obj[j - gap];
            obj[j] = temp;  c++;
        }}
    for ( int i = 0; i < 50; i++ ){
        obj[i].output();
        std::cout << std::endl;
    }
    std::cout << "\nShell Sort at the best case O(n) -> " << 50 << ", \n at the worst case O(n^2) - 50^2 -> "<< 50*50 << std::endl;
    std::cout<<"Number of comparisons = "<< p<<std::endl;
    std::cout<<"Number of swaps = "<<c<<std::endl;
}


void heapify(Video_Cards obj[], int n, int root)
{
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;
    if (l < n && obj[l].Price > obj[largest].Price)
        largest = l;
    if (r < n && obj[r].Price > obj[largest].Price)
        largest = r;
    if (largest != root){scet2++;}
    
    if (largest != root){
        swap(&obj[root], &obj[largest]);
        heapify(obj, n, largest);
    }
}

void Heap_Sort(Video_Cards obj[], int n)
{
    int c1=0;
    std::cout << "\n\n~~~~~~~~~~~~~~~~~Heap_Sort~~~~~~~~~~~~~~~~~\n" << std::endl;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(obj, n, i);
    
    for (int i=n-1; i>=0; i--){
        swap(&obj[0], &obj[i]); c1++;
        heapify(obj, i, 0);
    }
    for ( int i = 0; i < 50; i++ ){
        obj[i].output();
        std::cout << std::endl;
    }
    std::cout << "\nHeap Sort O(n*log(n)) -> 50 * log(50) -> " << (50 * log(10)) << std::endl;
    std::cout<<"Number of comparisons = "<< scet2<<std::endl;
    std::cout<<"Number of swaps = "<<c1<<std::endl;
}


void merge(Video_Cards *obj, int low, int high, int mid)
{
    int i, j, k;
    Video_Cards c[100];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (obj[i].Product_code < obj[j].Product_code){scet3++;}
        if (obj[i].Product_code < obj[j].Product_code){
            c[k] = obj[i];  k++;  i++;
        }
        else {
            c[k] = obj[j]; k++; j++;
        }
    }
    while (i <= mid){
        c[k] = obj[i]; k++; i++;
    }
    while (j <= high) {
        c[k] = obj[j]; k++; j++;
    }
    for (i = low; i < k; i++)  {
        obj[i] = c[i];  c3++;
    }
}

void Merge_Sort(Video_Cards *obj, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        Merge_Sort(obj,low,mid);
        Merge_Sort(obj,mid+1,high);
        merge(obj,low,high,mid);
    }
}

