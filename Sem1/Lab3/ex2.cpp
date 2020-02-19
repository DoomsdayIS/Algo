#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int n;
    double a;
    double first;
    double second;
    double new_first;
    double new_second;
    ifstream ifile("garland.in");
    ifile >> n;
    ifile >> a;
    vector<vector<double>> vec1(n-1);
    vector<double> buffer(2);
    buffer[0] = 0;
    buffer[1] = a;
    vec1[0] = buffer;
    for (int i = 1; i < n-1; ++i) {
        first = vec1[i-1][0];
        second = vec1[i-1][1];
        new_first = 0.5/(1 - first/2);
        new_second = (second/2 - 1)/(1 - first/2);
        buffer[0] = new_first;
        buffer[1] = new_second;
        vec1[i] = buffer;
    }
    double min1;
    double mid;
    double integer;
    double change;
    double left = 0;
    double right = 1000000;
    while (right - left > 0.0001){

        mid = (right + left)/2;
        min1 = mid;
        change = mid;
        for (int j = n-2; j > - 1 ; --j) {
            integer = vec1[j][0]*change + vec1[j][1];
            if (integer < min1){
                min1 = integer;
            }
            change = integer;
        }
        if (min1 > 0){
            right = mid;
        } else{
            left = mid;
        }

    }
    ofstream ofile("garland.out");
    ofile << fixed << setprecision(2) << right;
    return 0;
}