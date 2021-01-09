#include <iostream>
#include <stdlib.h>

#ifndef FUNCTIONS_H
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n)
{
  int i, j;
  bool swapped;
  for (i = 0; i < n-1; i++)
  {
    swapped = false;
    for (j = 0; j < n-i-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
}

int getMaximum(int a[], int n){
  int max_index = 0;
  for(int i = 1; i < n; i++){
    if(a[i] > a[max_index]){
      max_index = i;
    }
  }
  return max_index;
}

int getMinimum(int a[], int n){
  int min_index = 0;
  for(int i = 1; i < n; i++){
    if(a[i] < a[min_index]){
      min_index = i;
    }

  }
  return min_index;
}


int countDistinct(int arr[], int len
){
  int uniques[len] = {};
  int difcount = 0;
  int j = 0;

  for(int i = 0; i < len; ++i) {
    j = 0;

    while(j < difcount && uniques[j] != arr[i]) {
      j++;
    }

    if (j == difcount) {
      uniques[difcount] = arr[i];
      difcount++;
    }

  }
  return difcount;
}

void getDistincts(int arr[], int len, int uniques[]) {

  int difcount = 0;
  int j = 0;

  for(int i = 0; i < len; ++i) {
    j = 0;

    while(j < difcount && uniques[j] != arr[i]) {
      j++;
    }

    if (j == difcount) {
      uniques[difcount] = arr[i];
      difcount++;
    }
  }
}
#define FUNCTIONS_H

#endif //FUNCTIONS_H
