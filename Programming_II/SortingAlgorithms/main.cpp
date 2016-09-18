/*
 * File Name: main.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 09
 * Description: Program will receive from the command line (via argv[]) the size of an array to be generated 
 * and sorted, the initial order of data, and the algorithm to be used to perform the sort.
 * The program will then generate an array based on this input and sort based on input.
 * The output will output the size of the data set, sort used, initial order, and time the sort takes. 
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "selectionSort.cpp"
#include "quicksort.cpp"


int main(int argc, char* argv[]) 
{
  //program assumes proper input
    //lab9 <data_size> <random|ascending|descending> <selection|insertion|bubble|merge|quick>
    
    //sets variables based on proper input
      //dataSize
      //ascending/descending/random order
      //sort to be used
    int dataSize = atoi(argv[1]);
    std::string order = argv[2];
    std::string sort = argv[3];
    
    clock_t t;//used to retrieve time

    //create array
    double userArray[dataSize];

    //fill array based on order selected
    if(order == "ascending") 
    {
      for(int i = 0; i < dataSize; i++) 
      {
        userArray[i] = 0.001*static_cast<double>(i);
      }
    } 
    if(order == "descending") 
    {
      for(int i = 0; i < dataSize; i++) 
      {
        userArray[i] = 0.001*static_cast<double>(dataSize-i-1);
      }
    }
    if(order == "random") 
    {
      srand48(525);
      for(int i = 0; i < dataSize; i++) 
      {
        userArray[i] = (drand48() * 100000.0);
      }
    } 

    //run based on chosen sort
    if(sort == "selection") 
    {
      t = clock();
      selectionSort<double>(userArray, dataSize);
      t = clock()-t;
    } 
    if(sort == "insertion") 
    {
      t = clock();
      insertionSort<double>(userArray, dataSize);
      t = clock()-t;
    } 
    if(sort == "bubble") 
    {
      t = clock();
      bubbleSort<double>(userArray, dataSize);
      t = clock()-t;
    } 
        if(sort == "merge") 
    {
      t = clock();
      mergeSort<double>(userArray, dataSize);
      t = clock()-t;
    } 
    if(sort == "quick") 
    {
      t = clock();
      quickSort<double>(userArray, 0, dataSize);
      t = clock()-t;
    }
    
    //print array size, sort used, order of the data set, and time taken
    std::cout << "Size: " << dataSize << '\n';
    std::cout << "Sort: " << sort << '\n';
    std::cout << "Order: " << order << '\n';
    std::cout << "Time (sec): " << (double)t/(double)CLOCKS_PER_SEC << '\n';
    
     return 0;
  }

 
