#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start,const vector<vector<int>>& matrix,vector<short>& used,vector<vector<int>>& tout_list,int& tout){
    tout++;
    for(const int& i: matrix[start]){
        if (used[i] == 0){
            used[i] = 1;
            dfs(i,matrix,used,tout_list,tout);
        }
    }
    used[start] = 2;
    tout++;
    tout_list[start] = {tout,start};
}

void bfs(vector<int>& ans, vector<vector<int>>& matrix, int start){
    vector<int> dynamic(1,start);
    int left = 0;
    while (left < dynamic.size()){
        for (int i = 0; i < matrix[dynamic[left]].size(); ++i) {
            if (ans[matrix[dynamic[left]][i]] == 0){
                dynamic.push_back(matrix[dynamic[left]][i]);
                ans[matrix[dynamic[left]][i]] = ans[start];
            }
        }
        left++;
    }
}

int main() {
    int n,m, start, end;
    int tout = 0;
    ifstream fin("cond.in");
    ofstream fout("cond.out");
    fin >> n >> m;
    vector<vector<int>> matrix(n,(vector<int>()));
    vector<short> used(n,0);
    vector<vector<int>> tout_list(n,vector<int>(2));
    for (int i = 0; i < m; ++i) {
        fin >> start >> end;
        matrix[start - 1].push_back(end - 1);
    }
    for (int j = 0; j < n; ++j) {
        used[j] = 1;
        dfs(j,matrix,used,tout_list,tout);
        while (j + 1 < n) {
            if (used[j + 1] == 0) {
                break;
            } else {
                j++;
            }
        }
    }
    sort(tout_list.begin(),tout_list.end());
    reverse(tout_list.begin(),tout_list.end());
    vector<vector<int>> new_matrix(n,(vector<int>()));
    vector<int> ans(n,0);
    for (int l = 0; l < n; ++l) {
        for (const int& i: matrix[l]){
            new_matrix[i].push_back(l);
        }
    }
    int num = 1;
    for (int k = 0; k < n; ++k) {
        ans[tout_list[k][1]] = num;
        bfs(ans,new_matrix,tout_list[k][1]);
        num++;
        while (k + 1 < n){
            if (ans[tout_list[k + 1][1]] == 0){
                break;
            } else{
                k++;
            }
        }
    }
    fout << num - 1 << "\n";
    for (int k = 0; k < n; ++k) {
        fout << ans[k] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}