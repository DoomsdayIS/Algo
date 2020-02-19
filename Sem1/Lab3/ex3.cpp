#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    int n;
    ifstream ifile("isheap.in");
    ifile >> n;
    int ans = 1;
    long long a;
    ifile >> a;
    vector<long long> vector1;
    vector1.push_back(a);
    for (int i = 2; i < n+1; ++i) {
        ifile >> a;
        if (a < vector1[i/2 - 1]) {
            ans = 0;
        }
        vector1.push_back(a);
    }
    ofstream ofile("isheap.out");
    if (ans == 0){
        ofile << "NO";
    }else{
        ofile << "YES";
    }
    return 0;
}