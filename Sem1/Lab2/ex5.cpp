#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int k;
int ans;

void qsort(int left,int right,int arr[]) {
    if (left + 1 >= right) {
        if (left == right) {
        }else if(arr[left] > arr[right]) {
            swap(arr[left],arr[right]);
        }
    } else {
        int middle = arr[left + rand()%(right - left - 1)];
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
        if (k <= j) {
            qsort(left, j, arr);
        } else {
            qsort(i, right, arr);

        }
    }
}
int main() {
    int n;
    ifstream ifile("kth.in");
    ifile >> n;
    ifile >> k;
    k--;
    int arr[n];
    int a,b,c;
    ifile >> a;
    ifile >> b;
    ifile >> c;
    int first,second;
    ifile >> first;
    arr[0] = first;
    ifile >> second;
    arr[1] = second;
    for (int i = 2; i < n; ++i) {
        int buffer = a*arr[i-2] + b*arr[i-1] + c;
        arr[i] = buffer;

    }
    int left = 0;
    int right = n - 1;
    ofstream ofile("kth.out");
    qsort(left,right,arr);
    ans = arr[k];
    ofile << ans;
    return 0;
}