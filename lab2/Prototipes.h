//
//  Prototipes.h
//  lab2
//
//  Created by Erica Diaciuc on 21.04.2023.
//

#ifndef Prototipes_h
#define Prototipes_h
void swap(Video_Cards *a, Video_Cards *b);
void Bubble_Sort(Video_Cards* obj);
void Insertion_Sort(Video_Cards* obj);
void Selection_Sort(Video_Cards* obj);
int partition(Video_Cards obj[], int s1, int s2);
void Quick_Sort(Video_Cards obj[], int s1, int s2);
void Shell_Sort(Video_Cards obj[], int N);
void heapify(Video_Cards obj[], int n, int root);
void Heap_Sort(Video_Cards obj[], int n);
void merge(Video_Cards *obj, int low, int high, int mid);
void Merge_Sort(Video_Cards *obj, int low, int high);

#endif /* Prototipes_h */
