#i#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
vector<vector<string>> vector1(315011, vector<string>(2));

long long create_code(string key){
    long long code = 0;
    long long base = 1;
    for (int i = 0; i < key.size(); ++i) {
        code += ((int)key[i])*base;
        base = base*4;
    }
    code = code % 315011;
    return code;
}

void put(string key,string word){
    long long code = create_code(key);
    int i;
    for (i = code; i < 315011; i+=5) {
        if (vector1[i][0] == "" or vector1[i][0] == key or vector1[i][0] == "imfreenow"){
            vector1[i][0] = key;
            vector1[i][1] = word;
            break;
        }
    }
    if (i >= 315011){
        for (i = 1; i < code; i+=5) {
            if (vector1[i][0] == "" or vector1[i][0] == key or vector1[i][0] == "imfreenow"){
                vector1[i][0] = key;
                vector1[i][1] = word;
                break;
            }
        }
    }
}
void delete_key(string key){
    long long code = create_code(key);
    int i;
    for (i = code; i < 315011; i+=5) {
        if (vector1[i][0] == key){
            vector1[i][0] = "imfreenow";
            break;
        }else if (vector1[i][0] == ""){
            break;
        }
    }
    if (i >= 315011){
        for (i = 1; i < code; i+=5) {
            if (vector1[i][0] == key){
                vector1[i][0] = "imfreenow";
                break;
            }else if(vector1[i][0] == ""){
                break;
            }
        }
    }
}
string get_key(string key){
    long code = create_code(key);
    int i;
    for (i = code; i < 315011; i+=5) {
        if (vector1[i][0] == key){
            return vector1[i][1];
        }else if (vector1[i][0] == ""){
            return "none";
        }
    }
    if (i >= 315011){
        for (i = 1; i < code; i+=5) {
            if (vector1[i][0] == key){
                return vector1[i][1];
            }else if (vector1[i][0] == ""){
                return "none";
            }
        }
    }
    return "none";
}
int main(){
    ifstream cin("map.in");
    ofstream cout("map.out");
    string command;
    string key;
    string word;
    while (!cin.eof()) {
        command = "";
        key = "";
        word = "";
        cin >> command;
        if (command == "put"){
            cin >> key;
            cin >> word;
            put(key,word);
        }else if (command == "delete"){
            cin >> key;
            delete_key(key);
        }else if (command == "get"){
            cin >> key;
            cout << get_key(key) << endl;
        }
    }
    return 0;
}