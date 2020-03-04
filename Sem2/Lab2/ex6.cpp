#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

short dfs(int start,const vector<vector<int>>& matrix,vector<short>& used,short player){
    short buffer = player;
    for(const int& i: matrix[start]){
        if (used[i] == 0){
            used[i] = 2;
            if (player == 1) {
                buffer = min(dfs(i, matrix, used, -1), buffer);
            }else{
                buffer = max(dfs(i, matrix, used, 1), buffer);
            }
        }
        else {
            if (used[i] == 1 and player == 1) {
                buffer = -1;
            }
            if (used[i] == -1 and player == -1) {
                buffer = 1;
            }
        }
    }
    used[start] = buffer;
    return buffer;
}

int main() {
    int n,m,s, start, end;
    short player = 1;
    ifstream fin("game.in");
    ofstream fout("game.out");
    fin >> n >> m >> s;
    s--;
    vector<vector<int>> matrix(n,(vector<int>()));
    vector<short> used(n,0);
    for (int i = 0; i < m; ++i) {
        fin >> start >> end;
        matrix[start - 1].push_back(end - 1);
    }
    short ans =  dfs(s,matrix,used,player);
    if (ans == 1){
        fout << "Second player wins";
    }else{
        fout << "First player wins";
    }
    fin.close();
    fout.close();
    return 0;
}