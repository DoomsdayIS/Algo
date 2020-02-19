#include <iostream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

struct Member{
    char value;
    shared_ptr<Member> ptr;
};
shared_ptr<Member> create_el(char value){
    shared_ptr<Member> new_el(new Member);
    new_el->value = value;
    new_el->ptr = nullptr;
    return new_el;
}
class Stack{
    shared_ptr<Member> head = create_el('q');
public:
    bool push1(char new_value){
        shared_ptr<Member> new_el = create_el(new_value);
        new_el->ptr = head;
        head = new_el;
        return true;
    }
    bool push2(char new_value){
        if ( (new_value == ')' && head->value != '(') or (new_value == ']' && head->value != '[')){
            return false;
        }
        head = head->ptr;
        return true;
    }
    void pop(){
        head = head->ptr;
    }
    void clear(){
        while (head->ptr != nullptr){
            pop();
        }
    }
    bool check(){
        if (head->ptr == nullptr){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    ifstream ifile("brackets.in");
    ofstream ofile("brackets.out");
    string str;
    getline(ifile,str);
    Stack stack;
    bool no_error;
    while (str.length() > 0){
        no_error = true;
        for (int i = 0; i < str.length() ; ++i) {
            bool bl;
            if (str[i] == '[' or str[i] == '('){
                bl = stack.push1(str[i]);
            }else{
                bl = stack.push2(str[i]);
            }
            if (bl == false){
                no_error = false;
                break;
            }
        }
        if (no_error == true && stack.check() == true && str.length() > 0){
            ofile << "YES" << endl;
        }else if (str.length() > 0){
            ofile << "NO" << endl;
        }
        stack.clear();
        getline(ifile,str);
    }
    return 0;
}