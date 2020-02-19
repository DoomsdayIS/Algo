#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
vector<vector<string>> Vec;
void Merge(int left, int right){
    if (left + 1 >= right)
        return;
    int mid = (left + right) / 2;
    Merge(left, mid);
    Merge(mid, right);
    int i = 0;
    int j = 0;
    vector<vector<string>> vec2;
    while (left + i < mid or mid + j < right){
        if (left + i < mid && mid + j < right) {
            if (Vec[left + i][0] <= Vec[mid + j][0]){
                vec2.push_back(Vec[left + i]);
                i++;
            } else {
                vec2.push_back(Vec[mid + j]);
                j++;
            }
        } else {
            if (left + i < mid){
                vec2.push_back(Vec[left + i]);
                i++;
            } else {
                vec2.push_back(Vec[mid + j]);
                j++;
            }
        }
    }
    for (int k = 0; k < i + j; ++k) {
        Vec[left + k] = vec2[k];

    }
    return;


}

int main() {
    int n;
    ifstream ifile("race.in");
    ifile >> n;
    for (int i = 0; i < n; ++i) {
        vector<string> Dynamic;
        string buffer;
        for (int j = 0; j < 2 ; ++j) {
            ifile >> buffer;
            Dynamic.push_back(buffer);
        }
        Vec.push_back(Dynamic);
    }
    int left = 0;
    int right = n;
    Merge(left, right);
    string buffer = "";
    ofstream ofile("race.out");
    for (int j = 0; j < n ; ++j) {
        if (Vec[j][0] != buffer){
            buffer = Vec[j][0];
            ofile << "=== " << Vec[j][0] << " ===" << "\n";
            ofile << Vec[j][1] << "\n";
        } else {
            ofile << Vec[j][1] << "\n";

        }
    }
    return 0;
}