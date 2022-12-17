#include <stdio.h>                                    //header file declaration
int binary_search(int a[], int n, int start, int end) // funtion declaration
{
  int mid;

  if (start <= end) // loop condition
  {
    mid = (start + end) / 2; // finding mid
    if (a[mid] == n)
    {
      return mid; // return mid
    }
    if (a[mid] > n) // comdition checking for mid >n
    {
      return binary_search(a, n, start, mid - 1);
    }
    if (a[mid] < n) ////comdition checking for mid <n
    {
      return binary_search(a, n, mid + 1, end);
    }
  }

  return -1;
}
void main() // main function
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int len=sizeof(a)/sizeof(a[0]);
  int x = 4;
  int result = binary_search(a, x, 0, 10);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result); // print element index
}
