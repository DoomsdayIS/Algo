#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

struct Member{
    long long value;
    shared_ptr<Member> ptr;
};
shared_ptr<Member> create_el(long long value){
    shared_ptr<Member> new_el(new Member);
    new_el->value = value;
    new_el->ptr = nullptr;
    return new_el;
}
class Stack{
    shared_ptr<Member> head = create_el(0);
public:
    void push(long long new_value){
        shared_ptr<Member> new_el = create_el(new_value);
        new_el->ptr = head;
        head = new_el;
    }
    void pop(char znak){
        if (znak == '+'){
            head->ptr->value += head->value;
            head = head->ptr;
        }else if ( znak == '*'){
            head->ptr->value *= head->value;
            head = head->ptr;
        }else{
            head->ptr->value = head->ptr->value - head->value;
            head = head->ptr;
        }
    }
    long long check(){
        return head->value;
    }
};
long long get_value(string buf){
    long long ans = 0;
    int cntr = 1;
    for (int i = 0; i < buf.length(); ++i) {
        ans += ((int)buf[i] - 48)*cntr;
        cntr *= 10;
    }
    return ans;
}
int main(){
    ifstream cin("postfix.in");
    ofstream cout("postfix.out");
    Stack stack;
    string str;
    long long value;
    string buffer = "";
    getline(cin,str);
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '-' or str[i] == '+' or str[i] == '*'){
            stack.pop(str[i]);
        }else if ((int)str[i] >=48 && (int)str[i]<58){
            buffer = str[i] + buffer;
        } else if (str[i] == ' '){
            if (buffer != ""){
                value = get_value(buffer);
                stack.push(value);
                buffer = "";
            }
        }
    }
    cout << stack.check();
    return 0;
}