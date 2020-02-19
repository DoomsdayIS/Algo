#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

struct Member{
    long long value;
    shared_ptr<Member> ptr_top;
    shared_ptr<Member> ptr_back;
};

shared_ptr<Member> create_el(long long value){
    shared_ptr<Member> new_el(new Member);
    new_el->value = value;
    new_el->ptr_top = nullptr;
    new_el->ptr_back = nullptr;
    return new_el;
}
class Queue{
    shared_ptr<Member> head = create_el(0);
public:
    void push(long long new_value){
        shared_ptr<Member> new_el = create_el(new_value);
        head->ptr_top = new_el;
        if (head->ptr_back == nullptr){
            new_el->ptr_back = head;
        }else{
            new_el->ptr_back = head->ptr_back;
        }
        head = new_el;
    }
    long long pop(){
        shared_ptr<Member> deleted = head->ptr_back;
        head->ptr_back = deleted->ptr_top;
        return deleted->ptr_top->value;
    }
};


int main(){
    Queue que;
    int n;
    ifstream ifile("queue.in");
    ofstream ofile("queue.out");
    ifile >> n;
    for (int i = 0; i < n; ++i) {
        char pls_min;
        ifile >> pls_min;
        if (pls_min == '+') {
            long long cnt;
            ifile >> cnt;
            que.push(cnt);
        }else{
            long long bb = que.pop();
            ofile << bb << endl;
        }
    }
}