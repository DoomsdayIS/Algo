#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>


using namespace std;

struct Element{
    string value = "";
    string key = "";
    Element* prev = nullptr;
    Element* next = nullptr;
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
    code %= 35027;
    return code;
}

class LinkedMap{
public:
    vector<Element> arr;
    LinkedMap() : arr(35027) {};
    Element* prev_el = nullptr;
    Element* create_el(string key){
        Element* new_el = new Element;
        new_el->key = key;
        return new_el;
    }
    void put(string key,string value){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (true){
            if (new_el->key == key){
                new_el->value = value;
                return;
            }
            if (new_el->key == "") {
                new_el->key = key;
                new_el->value = value;
                new_el->prev = prev_el;
                if (prev_el != nullptr) {
                    prev_el->next = new_el;
                }
                prev_el = new_el;
                return;
            }
            if (new_el->deep == nullptr){
                break;
            }else{
                new_el = new_el->deep;
            }
        }
        Element* new_element = create_el(key);
        new_element->value = value;
        new_element->deep = nullptr;
        new_element->back = new_el;
        new_el->deep = new_element;
        new_element->prev = prev_el;
        if (prev_el != nullptr){
            prev_el->next = new_element;
        }
        prev_el = new_element;
        return;
    }
    void delete_el(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (new_el != nullptr){
            if (new_el->key == key){
                if (prev_el == new_el){
                    prev_el = new_el->prev;
                }
                if (new_el == &arr[code]){
                    new_el->key  = "";
                    if (new_el->next != nullptr){
                        new_el->next->prev = new_el->prev;
                    }
                    if (new_el->prev != nullptr){
                        new_el->prev->next = new_el->next;
                    }
                    new_el->next = nullptr;
                } else{
                    if (new_el->next != nullptr){
                        new_el->next->prev = new_el->prev;
                    }
                    if (new_el->prev != nullptr){
                        new_el->prev->next = new_el->next;
                    }
                    new_el->back->deep = new_el->deep;
                    if (new_el->deep != nullptr){
                        new_el->deep->back = new_el->back;
                    }
                    delete new_el;
                }
                return;
            }
            new_el = new_el->deep;
        }
        return;

    }
    string get(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (new_el != nullptr){
            if (new_el->key == key){
                return new_el->value;
            }
            new_el = new_el->deep;
        }
        return "none";
    }
    string prev(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (new_el != nullptr){
            if (new_el->key == key){
                if (new_el->prev != nullptr){
                    return new_el->prev->value;
                }else{
                    return "none";
                }
            }
            new_el = new_el->deep;
        }
        return "none";
    }
    string next(string key){
        unsigned code = make_code(key);
        Element* new_el = &arr[code];
        while (new_el != nullptr){
            if (new_el->key == key){
                if (new_el->next != nullptr){
                    return new_el->next->value;
                }else{
                    return "none";
                }
            }
            new_el = new_el->deep;
        }
        return "none";
    }
};

int main(){
    LinkedMap linkedMap;
    ifstream cin("linkedmap.in");
    ofstream cout("linkedmap.out");
    string command;
    string key;
    string word;
    int count = 0;
    while (!cin.eof()) {
        count++;
        command = "";
        key = "";
        word = "";
        cin >> command;
        if (command == "put"){
            cin >> key;
            cin >> word;
            linkedMap.put(key,word);
        } else if (command == "delete"){
            cin >> key;
            linkedMap.delete_el(key);
        } else if (command == "get"){
            cin >> key;
            cout << linkedMap.get(key) << "\n";
        } else if (command == "prev"){
            cin >> key;
            cout << linkedMap.prev(key) <<"\n";
        } else if (command == "next"){
            cin >> key;
            cout << linkedMap.next(key) <<"\n";
        }
    }

    return 0;
}