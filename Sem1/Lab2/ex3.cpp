#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
vector<long long> Vec;
long long cnt;

void Merge(int left, int right){
    if (left + 1 >= right)
        return;
    int mid = (left + right) / 2;
    Merge(left, mid);
    Merge(mid, right);
    int i = 0;
    int j = 0;
    vector<int> vec2;
    while (left + i < mid or mid + j < right){
        if (left + i < mid && mid + j < right) {
            if (Vec[left + i] <= Vec[mid + j]){
                vec2.push_back(Vec[left + i]);
                i++;
            } else {
                vec2.push_back(Vec[mid + j]);
                j++;
                cnt += mid - (left + i);
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
    long long buffer;
    ifstream ifile("inversions.in");
    ifile >> n;
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        ifile >> buffer;
        Vec.push_back(buffer);
    }
    int left = 0;
    int right = n;
    Merge(left, right);
    ofstream ofile("inversions.out");
    ofile << cnt;
    return 0;
}