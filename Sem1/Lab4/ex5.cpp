#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Stonks
{
    long long m_array[1000000];
    int m_next = 0;
public:
    void push(long long value){
        m_array[m_next] = value;
        up(m_next);
        m_next++;
    }
    void up(int value){
        int buf = value;
        int buf2 = value;
        if (buf % 2 == 0){
            buf--;
        }
        while (buf > 0){
            buf = buf / 2;
            if (m_array[buf2] < m_array[buf]){
                swap(m_array[buf2],m_array[buf]);
                buf2 = buf;
            }else{
                break;
            }
            if (buf % 2 == 0){
                buf--;
            }
        }
    }
    void pop(){
        if (m_next == 0){
            cout << "*" << endl;
        } else {
            m_next--;
            swap(m_array[0], m_array[m_next]);
            daun(0);
            cout << m_array[m_next] << endl;
        }
    }
    void find_and_fix(long long value,long long new_value){
        for (int i = 0; i < m_next ; ++i) {
            if (m_array[i] == value){
                m_array[i] = new_value;
                up(i);
                break;
            }
        }
    }
    void daun(int cnt){
        while (cnt*2 + 1 < m_next){
            if (cnt*2 + 2 < m_next){
                if (m_array[cnt*2 + 1] < m_array[cnt*2 + 2]){
                    if (m_array[cnt*2 + 1] < m_array[cnt]){
                        swap(m_array[cnt*2 + 1],m_array[cnt]);
                        cnt = cnt*2 + 1;
                    }else{
                        break;
                    }
                } else{
                    if (m_array[cnt*2 + 2] < m_array[cnt]){
                        swap(m_array[cnt*2 + 2],m_array[cnt]);
                        cnt = cnt*2 + 2;
                    }else{
                        break;
                    }
                }
            } else{
                if (m_array[cnt*2 + 1] < m_array[cnt]){
                    swap(m_array[cnt*2 + 1],m_array[cnt]);
                    cnt = cnt*2 + 1;
                }else{
                    break;
                }
            }
        }
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
    ifstream cin("priorityqueue.in");
    ofstream cout("priorityqueue.out");
    Stonks stack;
    vector<long long> values;
    string str;
    string buffer;
    long long value;
    getline(cin,str);
    while (str.length() > 0) {
        buffer = "";
        if (str[0] == 'p') {
            long long znak = 1;
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] == '-'){
                    znak = -1;
                }
                if ((int) str[i] >= 48 && (int) str[i] < 58) {
                    buffer = str[i] + buffer;
                }
            }
            value = get_value(buffer);
            value = value * znak;
            values.push_back(value);
            stack.push(value);
            buffer = "";
        } else if (str[0] == 'e') {
            stack.pop();
            values.push_back(0);
        } else if (str[0] == 'd') {
            values.push_back(0);
            long long value1;
            long long value2;
            long long znak = 1;
            for (int i = 12; i < str.length(); ++i) {
                if (str[i] == '-'){
                    znak = -1;
                }
                if ((int) str[i] >= 48 && (int) str[i] < 58) {
                    buffer = str[i] + buffer;
                } else if (str[i] == ' ') {
                    if (buffer != "") {
                        value1 = get_value(buffer);
                        buffer = "";
                    }
                }
            }
            value2 = get_value(buffer);
            value2 = value2*znak;
            stack.find_and_fix(values[value1 - 1], value2);
            values[value1 - 1] = value2;
        }
        getline(cin,str);
    }
}