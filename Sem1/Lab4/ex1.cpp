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
    long long pop(){
        shared_ptr<Member> deleted = head;
        head = head->ptr;
        return deleted->value;
    }
};

int main(){
    Stack stack;
    int n;
    ifstream ifile("stack.in");
    ofstream ofile("stack.out");
    ifile >> n;
    for (int i = 0; i < n; ++i) {
        char pls_min;
        ifile >> pls_min;
        if (pls_min == '+') {
            long long cnt;
            ifile >> cnt;
            stack.push(cnt);
        }else{
            long long bb = stack.pop();
            ofile << bb << endl;
        }
    }
}