#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    int n;
    int m;
    int k;
    ifstream ifile("radixsort.in");
    ifile >> n;
    ifile >> m;
    ifile >> k;
    char bf;
    vector<char> buffer;
    vector<vector<char>> vector1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            ifile >> bf;
            buffer.push_back(bf);

        }
        vector1.push_back(buffer);
        buffer.clear();
    }
    int counter = 0;
    for (int l = 0; l < k; ++l) {
        vector<vector<char>> vector2(n);
        vector<int> bufferxxl(26);
        for (int i = 0; i < n; ++i) {
            bufferxxl[(int)vector1[i][m - 1 - l] - 97]++;
        }
        for (int j = 0; j < 26 ; ++j) {
            counter += bufferxxl[j];
            bufferxxl[j] = counter;
        }
        for (int h = n-1; h > - 1 ; h--) {
            vector2[bufferxxl[(int)vector1[h][m - 1 - l] - 97] - 1] = vector1[h];
            bufferxxl[(int)vector1[h][m - 1 - l] - 97]--;
        }
        vector1 = vector2;
        counter = 0;
    }
    ofstream ofile("radixsort.out");
    for (int i1 = 0; i1 < n ; ++i1) {
        for (int i = 0; i < m; ++i) {
            ofile << vector1[i1][i];
        }
        ofile << endl;
    }
    return 0;
}