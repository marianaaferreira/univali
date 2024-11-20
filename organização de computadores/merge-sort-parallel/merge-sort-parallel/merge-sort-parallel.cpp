#include <iostream>
#include <iostream>
#include <time.h>
#include <thread>
#define TMAX 50000
using namespace std;

void merge(int A[], int left, int right, int mid) {
    int i, j, k, t[TMAX];
    i = left; k = left; j = mid + 1;
    while (i <= mid && j <= right) {
        if (A[i] < A[j]) {
            t[k] = A[i];
            i++;
        }
        else {
            t[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        t[k] = A[i];
        k++;
        i++;
    }
    while (j <= right) {
        t[k] = A[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++) {
        A[i] = t[i];
    }
}

void merge_sort_parallel(int A[], int left, int right, int depth=0) {

    if (left < right) {
        int mid = (left + right) / 2;

        if (depth <= 1) {
            cout << "rodando thread t1 na profundidade " << depth << endl;
            thread t1(merge_sort_parallel, A, left, mid, depth + 1);
            cout << "rodando thread t2 na profundidade " << depth << endl;
            thread t2(merge_sort_parallel, A, mid + 1, right, depth + 1);

            t1.join();
            t2.join();
        }
        else {
            merge_sort_parallel(A, left, mid, 2);
            merge_sort_parallel(A, mid + 1, right, 2);
        }


        merge(A, left, right, mid);

    }
}

void merge_sort_non_parallel(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort_non_parallel(A, left, mid);
        merge_sort_non_parallel(A, mid + 1, right);

        merge(A, left, right, mid);
    }
}

int main() {
    srand(time(NULL));
    int A[TMAX], B[TMAX], n = 50000;
    double time_parallel, time_non_parallel;

    for (int i = 0; i < n; i++) { 
        A[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    cout << "COM PARALELISMO" << endl;
    double start_time = (double)clock() / CLOCKS_PER_SEC;
    merge_sort_parallel(A, 0, n - 1);
    double end_time = (double)clock() / CLOCKS_PER_SEC;
    time_parallel = end_time - start_time;
    cout << "TIME: " << time_parallel << " segundos" << endl;

    cout << "SEM PARALELISMO" << endl;
    start_time = (double)clock() / CLOCKS_PER_SEC;
    merge_sort_non_parallel(B, 0, n - 1);
    end_time = (double)clock() / CLOCKS_PER_SEC;
    time_non_parallel = end_time - start_time;
    cout << "TIME: " << time_non_parallel << " segundos" << endl;

    cout << "Aceleracao: " <<  time_non_parallel/ time_parallel;

    return 0;
}
