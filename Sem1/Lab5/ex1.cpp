#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void insert_value(int* arr,int value,int mod_value){
    int i;
    for (i = mod_value; i < 1002403; i+=5) {
        if (arr[i] == 0 or arr[i] == value or arr[i] == 1000000001){
            arr[i] = value;
            break;
        }
    }
    if (i >= 1002403){
        for (i = 1; i < mod_value; i+=5) {
            if (arr[i] == 0 or arr[i] == value or arr[i] == 1000000001){
                arr[i] = value;
                break;
            }
        }
    }

}

void delete_value(int *arr,int value,int mod_value){
    int i;
    for (i = mod_value; i < 1002403; i+=5) {
        if (arr[i] == value){
            arr[i] = 1000000001;
            break;
        }else if (arr[i] == 0){
            break;
        }
    }
    if (i >= 1002403){
        for (i = 1; i < mod_value; i+=5) {
            if (arr[i] == value){
                arr[i] = 1000000001;
                break;
            }else if (arr[i] == 0){
                break;
            }
        }
    }

}

bool exists_value(int *arr,int value, int mod_value){
    int i;
    for (i = mod_value; i < 1002403; i+=5) {
        if (arr[i] == value){
            return true;
        }else if (arr[i] == 0){
            return false;
        }
    }
    if (i >= 1002403){
        for (i = 1; i < mod_value; i+=5) {
            if (arr[i] == value){
                return true;
            }else if (arr[i] == 0){
                return false;
            }
        }
    }

}
int main(){
    ifstream cin("set.in");
    ofstream cout("set.out");
    string x;
    int value;
    int mod_value;
    int arr[1002403] = {};
    arr[0] = 1000000002;
    int *array = arr;
    while (!cin.eof()){
        x = "";
        cin >> x;
        cin >> value;
        if (value >= 0){
            mod_value = value % 1002403;
        }else{
            mod_value = 1002403 + (value % 1002403);
        }
        mod_value++;
        if (x == "insert"){
            if (value == 0){
                arr[0] = 0;
            }else{
                insert_value(array,value,mod_value);
            }
        }else if (x == "delete"){
            if (value == 0){
                arr[0] = 1000000002;
            }else{
                delete_value(array,value,mod_value);
            }
        }else if (x == "exists"){
            if (value == 0){
                if (arr[0] == 0){
                    cout << "true" << endl;
                }else{
                    cout << "false" << endl;
                }
            }else{
                if (exists_value(array,value,mod_value)){
                    cout << "true" << endl;
                }else{
                    cout << "false" << endl;
                }
            }
        }
    }
    return 0;
}