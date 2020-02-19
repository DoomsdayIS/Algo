#include <iostream>
#include <fstream>

using namespace std;

void qsort(int left,int right,int arr[]){
    if (left >= right)
        return;
    int middle = arr[left + (rand() % (right - left))];
    int i = left;
    int j = right;
    while (i < j) {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i > j)
            break;
        int swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
        i++;
        j--;
    }
    qsort(left,j,arr);
    qsort(i,right, arr);
}

int main(void) {
    int len;
    ifstream ifile("sort.in");
    ifile >> len;
    int left = 0;
    int right = len - 1;
    int arr[len];
    for (int i = 0; i < len; ++i) {
        ifile >> arr[i];
    }
    qsort(left,right,arr);
    ofstream ofile("sort.out");
    for (int j = 0; j < len ; ++j) {
        ofile << arr[j] << " ";
    }
    return 0;
}