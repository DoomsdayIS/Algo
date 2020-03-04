#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start,const vector<vector<int>>& matrix,vector<short>& used,vector<int>& ans,bool& trouble){
    for (const int &i: matrix[start]) {
        if (used[i] == 1 and ans[i] == ans[start]) {
            trouble = true;
        }
        if (used[i] == 0) {
            used[i] = 1;
            ans[i] = - ans[start];
            dfs(i, matrix, used, ans, trouble);
        }
    }
    used[start] = 2;
}

int main() {
    int n,m, start, end;
    int parent = -1;
    bool trouble = false;
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    fin >> n >> m;
    vector<vector<int>> matrix(n,(vector<int>()));
    vector<short> used(n,0);
    vector<int> ans(n,0);
    for (int i = 0; i < m; ++i) {
        fin >> start >> end;
        if (start == end){
            trouble = true;
        }
        matrix[start - 1].push_back(end - 1);
        matrix[end - 1].push_back(start - 1);
    }
    for (int j = 0; j < n; ++j) {
        used[j] = 1;
        ans[j] = 1;
        dfs(j,matrix,used,ans,trouble);
        while (j + 1 < n) {
            if (used[j + 1] == 0) {
                break;
            } else {
                j++;
            }
        }
    }
    if (!trouble){
        fout << "YES";
    }else{
        fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}