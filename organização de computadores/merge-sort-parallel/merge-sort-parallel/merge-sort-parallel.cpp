#include <iostream>
#include <time.h>
#define TMAX 50
using namespace std;

void merge(int A[], int left, int right, int mid){
    int i, j, k, c[TMAX];
    i = left; k = left; j = mid + 1;
    while (i <= mid && j <= right){
        if (A[i] < A[j]){
            c[k] = A[i];  
            i++;
        }
        else{
            c[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid){
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= right){
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++){
        A[i] = c[i];
    }
}

void merge_sort(int v[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);

        merge(v, left, right, mid);
    }
}

int main(){
	srand(time(NULL));
    int A[TMAX], n=10;

	for (int i = 0; i < n; i++) {
		 A[i] = rand()%100 + 1;
	}

    cout << "Antes da ordenação com merge sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    merge_sort(A, 0, n-1);

    cout << "Depois da ordenação com merge sort: " << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
    cout << endl;
}
