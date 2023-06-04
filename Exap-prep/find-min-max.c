#include<stdio.h>

void find_min_max(int* arr, int n, int* max, int* min){
    *max = arr[0];
    *min = arr[0];

    for(int i = 1; i<n; i++){
        if(*max < arr[i]){
            *max = arr[i];
        }

        if(*min > arr[i]){
            *min = arr[i];
        }
    }

} 

void main(){
    int arr[] = {2, 6, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max;
    int min;


    find_min_max(arr, n, &max, &min);

    printf("Max: %d", max);
    printf("Min: %d", min);
}