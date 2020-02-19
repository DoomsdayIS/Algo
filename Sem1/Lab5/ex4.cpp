#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Element{
    string key = "";
    Element* deep = nullptr;
    Element* back = nullptr;
};

unsigned int make_code(string key){
    unsigned base = 1;
    unsigned code = 0;
    for (int i = 0; i < key.size() ; ++i) {
        code += (int)key[i]*base;
        base *= 23;
    }
    code %= 227;
    return code;
}
unsigned int make_code_mm(string key){
    unsigned base = 1;
    unsigned code = 0;
    for (int i = 0; i < key.size() ; ++i) {
        code += (int)key[i]*base;
        base *= 23;
    }
    code %= 4703;
    return code;
}

class MiniMap{
public:
    string key_mm = "";
    MiniMap* deep_mm = nullptr;
    MiniMap* back_mm = nullptr;
    vector<Element> arr;
    MiniMap() : arr(227) {};
    Element* create_el(string key){
        Element* new_el = new Element;
        new_el->key = key;
        return new_el;
    }
    void put(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (true){
            if (new_el->key == key){
                return;
            }
            if (new_el->deep == nullptr){
                break;
            }else {
                new_el = new_el->deep;
            }
        }
        if (arr[code].key == ""){
            arr[code].key = key;
        }
        else {
            Element *new_element = create_el(key);
            new_element->deep = nullptr;
            new_element->back = new_el;
            new_el->deep = new_element;
        }
        return;
    }
    void delete_el(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (true){
            if (new_el->key == key){
                if (new_el == &arr[code]){
                    new_el->key = "";
                }else{
                    new_el->back->deep = new_el->deep;
                    if (new_el->deep != nullptr){
                        new_el->deep->back = new_el->back;
                    }
                    delete new_el;
                }
                return;
            }
            if (new_el->deep == nullptr){
                break;
            }else {
                new_el = new_el->deep;
            }
        }
        return;
    }
    vector<string> get(){
        vector<string> values(0);
        for (int i = 0; i < 227; ++i) {
            Element* new_el = &arr[i];
            while(new_el != nullptr){
                if (new_el->key != ""){
                    values.push_back(new_el->key);
                }
                new_el = new_el->deep;
            }
        }
        return values;
    }
};

class BigMap{
public:
    vector<MiniMap> arr;
    BigMap() : arr(4703){};
    MiniMap* create_mm(string key){
        MiniMap* new_mm = new MiniMap;
        new_mm->key_mm = key;
        return new_mm;
    }
    void put(string key,string value){
        unsigned code = make_code_mm(key);
        MiniMap* new_el = &arr[code];
        while (true){
            if (new_el->key_mm == key){
                new_el->put(value);
                return;
            }
            if (new_el->deep_mm == nullptr){
                break;
            }else {
                new_el = new_el->deep_mm;
            }
        }
        if (arr[code].key_mm == ""){
            arr[code].key_mm = key;
            arr[code].put(value);
        }
        else {
            MiniMap* new_element = create_mm(key);
            new_element->deep_mm = nullptr;
            new_element->back_mm = new_el;
            new_el->deep_mm = new_element;
            new_element->put(value);
        }
        return;
    }
    void delete_el(string key,string value){
        unsigned code = make_code_mm(key);
        MiniMap* new_el = &arr[code];
        while (true){
            if (new_el->key_mm == key){
                new_el->delete_el(value);
                return;
            }
            if (new_el->deep_mm == nullptr){
                break;
            }else {
                new_el = new_el->deep_mm;
            }
        }
        return;
    }

    void delete_all(string key){
        unsigned code = make_code_mm(key);
        MiniMap* new_el = &arr[code];
        while (true){
            if (new_el->key_mm == key){
                if (new_el == &arr[code]) {
                    MiniMap *new_element = create_mm("");
                    *new_el = *new_element;
                    delete new_element;
                    return;
                }else{
                    new_el->back_mm->deep_mm = new_el->deep_mm;
                    if (new_el->deep_mm != nullptr)
                        new_el->deep_mm->back_mm = new_el->back_mm;
                    delete new_el;
                }
            }
            if (new_el->deep_mm == nullptr){
                break;
            }else {
                new_el = new_el->deep_mm;
            }
        }
        return;
    }
    vector<string> get(string key){
        unsigned code = make_code_mm(key);
        MiniMap* new_el = &arr[code];
        while(true){
            if (new_el->key_mm == key){
                return new_el->get();
            }
            if (new_el->deep_mm == nullptr){
                break;
            }else {
                new_el = new_el->deep_mm;
            }
        }
        vector<string> arr(0);
        return arr;
    }
};

int main(){
    BigMap multimap;
    ifstream cin("multimap.in");
    ofstream cout("multimap.out");
    string command;
    string key;
    string value;
    int count = 0;
    while (!cin.eof()) {
        command = "";
        key = "";
        value = "";
        cin >> command;
        if (command == "put"){
            cin >> key;
            cin >> value;
            multimap.put(key,value);
        }else if (command == "delete"){
            cin >> key;
            cin >> value;
            multimap.delete_el(key,value);
        }else if (command == "deleteall"){
            cin >> key;
            multimap.delete_all(key);
        }else if (command == "get"){
            cin >> key;
            vector<string> arr = multimap.get(key);
            cout << arr.size() << " ";
            for (int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}