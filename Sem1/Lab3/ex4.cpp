#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    int n;
    ifstream ifile("sort.in");
    ifile >> n;
    vector<long long> vector1;
    long long buffer;
    for (int i = 0; i < n; ++i) {
        ifile >> buffer;
        vector1.push_back(buffer);
    }
    int counter;
    int buffer2;
    for (int j = n/2 - 1; j > -1; --j) {
        buffer2 = j;
        counter = 0;
        while (2*buffer2 + 1 < n && counter == 0) {
            if (2 * buffer2 + 2 >= n) {
                if (vector1[2 * buffer2 + 1] > vector1[buffer2]) {
                    swap(vector1[buffer2], vector1[2 * buffer2 + 1]);
                    buffer2 = buffer2*2 + 1;
                }else{
                    counter = 1;
                }
            }else {
                if (vector1[2 * buffer2 + 1] > vector1[2 * buffer2 + 2]) {
                    if (vector1[2 * buffer2 + 1] > vector1[buffer2]) {
                        swap(vector1[buffer2], vector1[2 * buffer2 + 1]);
                        buffer2 = buffer2*2 + 1;
                    }else{
                        counter = 1;
                    }
                }else {
                    if (vector1[2 * buffer2 + 2] > vector1[buffer2]) {
                        swap(vector1[buffer2], vector1[2 * buffer2 + 2]);
                        buffer2 = buffer2*2 + 2;
                    } else{
                        counter = 1;
                    }
                }
            }
        }
    }
//    for (int k = 0; k < n ; ++k) {
//        cout << vector1[k] << " ";
    //   }
    for (int l = 0; l <  n; ++l) {
        swap(vector1[0],vector1[n - 1 - l]);
        buffer2 = 0;
        counter = 0;
        while (2*buffer2 + 1 < n - l - 1 && counter == 0) {
            if (2 * buffer2 + 2 >= n - l - 1) {
                if (vector1[2 * buffer2 + 1] > vector1[buffer2]) {
                    swap(vector1[buffer2], vector1[2 * buffer2 + 1]);
                    buffer2 = buffer2*2 + 1;
                }else{
                    counter = 1;
                }
            }else {
                if (vector1[2 * buffer2 + 1] > vector1[2 * buffer2 + 2]) {
                    if (vector1[2 * buffer2 + 1] > vector1[buffer2]) {
                        swap(vector1[buffer2], vector1[2 * buffer2 + 1]);
                        buffer2 = buffer2*2 + 1;
                    }else{
                        counter = 1;
                    }
                }else {
                    if (vector1[2 * buffer2 + 2] > vector1[buffer2]) {
                        swap(vector1[buffer2], vector1[2 * buffer2 + 2]);
                        buffer2 = buffer2*2 + 2;
                    } else{
                        counter = 1;
                    }
                }
            }
        }
    }
    ofstream ofile("sort.out");
    for (int m = 0; m < n; ++m) {
        ofile << vector1[m] << " ";
    }
    return 0;
}