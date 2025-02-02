//BubbleSort--|
//SelectionSort--|
//QuickSort--|
//MergeSort--|
//Improved BubbleSort--|
//Improved Quicksort--|
//Radix Sort--|

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define MAX_SIZE 100000000
int *read_input(const char *file_path, int *size) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int *array = malloc(MAX_SIZE * sizeof(int));
    *size = 0;
    while (fscanf(file, "%d", &array[*size]) == 1) {
        (*size)++;
    }

    fclose(file);
    return array;
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
///////////////////////////////////////// Bubble Sort//////////////////////////////////////////////
void BubbleSort(int arr[], int n){
    int i, j;
    //clock_t start, end;
    //int counter = 0;
    //start = clock();
    bool isTwoSec = false;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            //end = clock();
            //if(end - start >= 2000.0){
            //    isTwoSec = true;
            //    break;
            //}
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
            //counter++;
            //if(isTwoSec) break;
        }
    }   
    //printf("At %f elements\n", ceil(sqrt(counter)));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Optimized Bubble Sort//////////////////////////////////////////////

// An optimized version of Bubble Sort
void optimizedBubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Selection Sort//////////////////////////////////////////////////////
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        // Assume the current position holds
        // the minimum element
        int min_idx = i;
        
        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
              
                // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }
        
        // Move minimum element to its
        // correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************Quick Sort Related**************************************************/

/////////////////////////////////////////Quick Sort///////////////////////////////////////////////////////////

int partition(int arr[], int low, int high) {
    
    // Choose the pivot
    int pivot = arr[high];
    
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Optimized Quick Sort/////////////////////////////////////////////////

void quickSortOptimized(int arr[], int low, int high,bool firstIteration) {
    if(high-low+1 <= 20 && firstIteration == true){
        selectionSort(arr,high-low+1);
    }
    else{
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSortOptimized(arr, low, pi - 1,false);
        quickSortOptimized(arr, pi + 1, high,false);
    }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/************************************************************************************************************/

/////////////////////////////////////////Merge Sort///////////////////////////////////////////////////////////

// Merge Sort
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
/*
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Radix Sort///////////////////////////////////////////////////////////
// Function to get the maximum value in the array
void counting_sort(int array[], int size, int place) {
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        int index = (array[i] / place) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int index = (array[i] / place) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

void radixSort(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int place = 1; max / place > 0; place *= 10) {
        counting_sort(array, size, place);
    }
}
/*
// A utility function to get the maximum 
// value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] 
// according to the digit represented by exp
void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array as 0

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now 
    // contains actual position of this digit
    // in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], 
    // so that arr[] now contains sorted 
    // numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to sort arr[] of size 
// n using Radix Sort
void radixSort(int arr[], int n) {
  
    // Find the maximum number to know 
    // the number of digits
    int m = getMax(arr, n); 

    // Do counting sort for every digit
    // exp is 10^i where i is the current 
    // digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    int arr34k_size = 34000;
    int *arr34k = read_input("./inputs/input34k.txt",&arr34k_size);
    //struct timeval start, end;
    //double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds

    /////////////////// Bubble Sort ////////////////////////
    printf("***** Bubble Sort *****\n");

    struct timeval start, end;
    
    gettimeofday(&start, NULL);
    BubbleSort(arr34k, arr34k_size);  // Sorting
    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    ////////////////////////////////////////////////////////

    arr34k = read_input("./inputs/input34k.txt",&arr34k_size);

    /////////////////Optimized BubbleSort///////////////////
    printf("***** Optimized Bubble Sort *****\n");
    gettimeofday(&start, NULL);    
    optimizedBubbleSort(arr34k, arr34k_size);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    ////////////////////////////////////////////////////////
    
    int arr72k_size = 72000;
    int *arr72k = read_input("./inputs/input72k.txt",&arr72k_size);

    /////////////////Selection Sort///////////////////////
    printf("***** Selection Sort *****\n");
    gettimeofday(&start, NULL);        
    selectionSort(arr72k, arr72k_size);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    //////////////////////////////////////////////////////

    int arr11m_size = 11000000;
    int *arr11m = read_input("./inputs/input11m.txt",&arr11m_size);

    /////////////////Quick Sort///////////////////////////
    printf("***** Quick Sort *****\n");
    gettimeofday(&start, NULL);
    quickSort(arr11m,0,arr11m_size-1);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    //////////////////////////////////////////////////////

    int arr10m_size = 10000000;
    int *arr10m = read_input("./inputs/input10m.txt",&arr10m_size);

    /////////////////Merge Sort///////////////////////////
    printf("***** Merge Sort *****\n");
    gettimeofday(&start, NULL);
    mergeSort(arr10m,0,arr10m_size-1);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    ///////////////////////////////////////////////////////

    int arr50m_size = 50000000;
    int *arr50m = read_input("./inputs/input50m.txt",&arr50m_size);    
    //////////////////Radix Sort///////////////////////////
    printf("***** Radix Sort *****\n");
    gettimeofday(&start, NULL);    
    radixSort(arr50m,arr50m_size);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    ///////////////////////////////////////////////////////
    
    arr11m = read_input("./inputs/input11m.txt",&arr11m_size);

    //////////////////Quick Sort Optimized/////////////////
    printf("***** Quick Sort Optimized*****\n");
    gettimeofday(&start, NULL);    
    quickSortOptimized(arr11m,0,arr11m_size-1,true);  // Sorting
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6; // Convert to seconds
    printf("Time taken: %f seconds\n", time_taken);
    ///////////////////////////////////////////////////////*/
    return 0;
}


