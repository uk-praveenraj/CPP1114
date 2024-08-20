// C++ Program to how to sort an array
#include <algorithm>
#include <iostream>
using namespace std;

void bubble(int arr[10])
{
  for(int i=0; i<10; i++){
    for(int j=i+1; j<10; j++){
      if(arr[j] < arr[i]){
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

void selectionSort(int arr[])
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < 10; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    // Initializing an array
    int arr[10] = { 5, 6, 12, 18, 1, 2, 3, 9, 7, 4 };

    // Print the array before sorting the elements
    cout << "Array Before Sorting: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // bubble(arr);
    selectionSort(arr);

    // Print the array after sorting the elements
    cout << "Array After Sorting: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}