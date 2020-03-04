#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bfs(vector<int>& ans, vector<vector<int>>& matrix, int start){
    vector<int> dynamic(1,start);
    int left = 0;
    while (left < dynamic.size()){
        for (int i = 0; i < matrix[dynamic[left]].size(); ++i) {
            if (ans[matrix[dynamic[left]][i]] == 0 and matrix[dynamic[left]][i] != 0){
                dynamic.push_back(matrix[dynamic[left]][i]);
                ans[matrix[dynamic[left]][i]] = ans[dynamic[left]] + 1;
            }
        }
        left++;
    }
}

int main() {
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    int n,m;
    int start,end;
    fin >> n >> m;
    vector<int> ans(n,0);
    vector<vector<int>> matrix(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        fin >> start >> end;
        if (start != end){
            matrix[start - 1].push_back(end - 1);
            matrix[end - 1].push_back(start - 1);
        }
    }
    bfs(ans,matrix,0);
    for (int k = 0; k < n; ++k) {
        fout << ans[k] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
