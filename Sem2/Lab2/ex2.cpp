#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start,const vector<vector<int>>& matrix,vector<short>& used,vector<int>& ans,bool& cycle,int& stop){
    if (!cycle) {
        for (const int &i: matrix[start]) {
            if (used[i] == 1) {
                cycle = true;
                stop = i;
                break;
            }
            if (used[i] == 0) {
                used[i] = 1;
                dfs(i, matrix, used, ans, cycle,stop);
                if (cycle){
                    break;
                }
            }
        }
        used[start] = 2;
        if (cycle and stop != -228) {
            if (stop == start){
                stop = -228;
            }
            ans.push_back(start);
        }
    }
}

int main() {
    int n,m, start, end;
    int stop = -1;
    bool cycle = false;
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
    fin >> n >> m;
    vector<vector<int>> matrix(n,(vector<int>()));
    vector<short> used(n,0);
    vector<int> ans(0);
    for (int i = 0; i < m; ++i) {
        fin >> start >> end;
        matrix[start - 1].push_back(end - 1);
    }
    for (int j = 0; j < n; ++j) {
        used[j] = 1;
        dfs(j,matrix,used,ans,cycle,stop);
        while (j + 1 < n) {
            if (used[j + 1] == 0) {
                break;
            } else {
                j++;
            }
        }
    }
    if (cycle){
        reverse(ans.begin(),ans.end());
        fout << "YES" << "\n";
        for (const int& i:ans) {
            fout << i + 1 << " ";
        }
    }else{
        fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}

