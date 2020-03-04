#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Element{
    int value;
    Element* left;
    Element* right;
};

class Tree{
public:
    Element* head = nullptr;
    Element* create_el(int value) {
        Element* new_el = new Element;
        new_el->value = value;
        new_el->right = nullptr;
        new_el->left = nullptr;
        return new_el;
    }
    void insert(int value){
        if (head == nullptr){
            Element* new_element = create_el(value);
            head = new_element;
        }else{
            Element* new_element = create_el(value);
            Element* buffer = head;
            while (true){
                if (new_element->value > buffer->value){
                    if (buffer->right == nullptr){
                        buffer->right = new_element;
                        break;
                    }
                    buffer = buffer->right;
                } else{
                    if (buffer->left == nullptr){
                        buffer->left = new_element;
                        break;
                    }
                    buffer = buffer->left;
                }
            }
        }
    }
    void delete_el(int value){
        if (head == nullptr){
            return;
        }
        else{
            if (head->value == value){
                if (head->left == nullptr and head->right == nullptr){
                    delete head;
                    head = nullptr;
                    return;
                } else if (head->right == nullptr){
                    Element* buffer = head;
                    head = head->left;
                    delete buffer;
                    return;
                } else if (head->left == nullptr){
                    Element* buffer = head;
                    head = head->right;
                    delete buffer;
                    return;
                } else{
                    Element* buffer = head;
                    while (true){
                        int code = 0;
                        int new_v = next(value);
                        if (new_v == 1000000001){
                            break;
                        }
                        buffer->value = new_v;
                        value = new_v;
                        Element* buffer2 = buffer;
                        while (true){
                            if (buffer2->right != nullptr){
                                if (buffer2->right->value == value){
                                    if (buffer2->right->right != nullptr and buffer2->right->left != nullptr){
                                        buffer = buffer2->right;
                                        break;
                                    } else if (buffer2->right->right != nullptr){
                                        Element* buffer3 = buffer2->right;
                                        buffer2->right = buffer2->right->right;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    } else if (buffer2->right->left != nullptr){
                                        Element* buffer3 = buffer2->right;
                                        buffer2->right = buffer2->right->left;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    } else{
                                        Element* buffer3 = buffer2->right;
                                        buffer2->right = nullptr;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    }
                                }
                            }
                            if (buffer2->left != nullptr){
                                if (buffer2->left->value == value){
                                    if (buffer2->left->right != nullptr and buffer2->left->left != nullptr){
                                        buffer = buffer2->left;
                                        break;
                                    } else if (buffer2->left->right != nullptr){
                                        Element* buffer3 = buffer2->left;
                                        buffer2->left = buffer2->left->right;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    } else if (buffer2->left->left != nullptr){
                                        Element* buffer3 = buffer2->left;
                                        buffer2->left = buffer2->left->left;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    } else{
                                        Element* buffer3 = buffer2->left;
                                        buffer2->left = nullptr;
                                        delete buffer3;
                                        code = 1;
                                        break;
                                    }
                                }
                            }
                            if (value >= buffer2->value){
                                buffer2 = buffer2->right;
                            }else{
                                buffer2 = buffer2->left;
                            }
                        }
                        if (code == 1){
                            break;
                        }
                    }
                }
            } else{
                Element* buffer = find_el(value);
                if (buffer == nullptr){
                    return;
                }
                buffer = head;
                while (true){
                    int code = 0;
                    Element *buffer2 = buffer;
                    if (buffer != head) {
                        int new_v = next(value);
                        if (new_v == 1000000001) {
                            break;
                        }
                        buffer->value = new_v;
                        value = new_v;
                    }
                    while (true){
                        if (buffer2->right != nullptr){
                            if (buffer2->right->value == value){
                                if (buffer2->right->right != nullptr and buffer2->right->left != nullptr){
                                    buffer = buffer2->right;
                                    break;
                                } else if (buffer2->right->right != nullptr){
                                    Element* buffer3 = buffer2->right;
                                    buffer2->right = buffer2->right->right;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                } else if (buffer2->right->left != nullptr){
                                    Element* buffer3 = buffer2->right;
                                    buffer2->right = buffer2->right->left;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                } else{
                                    Element* buffer3 = buffer2->right;
                                    buffer2->right = nullptr;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                }
                            }
                        }
                        if (buffer2->left != nullptr){
                            if (buffer2->left->value == value){
                                if (buffer2->left->right != nullptr and buffer2->left->left != nullptr){
                                    buffer = buffer2->left;
                                    break;
                                } else if (buffer2->left->right != nullptr){
                                    Element* buffer3 = buffer2->left;
                                    buffer2->left = buffer2->left->right;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                } else if (buffer2->left->left != nullptr){
                                    Element* buffer3 = buffer2->left;
                                    buffer2->left = buffer2->left->left;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                } else{
                                    Element* buffer3 = buffer2->left;
                                    buffer2->left = nullptr;
                                    delete buffer3;
                                    code = 1;
                                    break;
                                }
                            }
                        }
                        if (value >= buffer2->value){
                            buffer2 = buffer2->right;
                        }else{
                            buffer2 = buffer2->left;
                        }
                    }
                    if (code == 1){
                        break;
                    }
                }
            }
        }
    }
    Element* find_el(int value){
        if (head == nullptr){
            return nullptr;
        }else{
            Element* buffer = head;
            while (buffer != nullptr){
                if (buffer->value == value){
                    return buffer;
                }
                if (value > buffer->value){
                    buffer = buffer->right;
                } else{
                    buffer = buffer->left;
                }
            }
            return nullptr;
        }
    }
    int next(int value){
        int next_v = 1000000001;
        if (head != nullptr){
            Element* buffer = head;
            while (buffer != nullptr){
                if (buffer->value > value and buffer->value < next_v){
                    next_v = buffer->value;
                }
                if (value >= buffer->value){
                    buffer = buffer->right;
                } else{
                    buffer = buffer->left;
                }
            }
        }
        return next_v;
    }
    int prev(int value){
        int prev_v = -1000000001;
        if (head != nullptr){
            Element* buffer = head;
            while (buffer != nullptr){
                if (buffer->value < value and buffer->value > prev_v){
                    prev_v = buffer->value;
                }
                if (value > buffer->value){
                    buffer = buffer->right;
                } else{
                    buffer = buffer->left;
                }
            }
        }
        return prev_v;
    }
};

int main(){
    Tree bin;
    ifstream cin("bstsimple.in");
    ofstream cout("bstsimple.out");
    string command;
    int value;
    while (!cin.eof()) {
        command = "";
        cin >> command;
        cin >> value;
        if (command == "insert"){
            if (bin.find_el(value) == nullptr) {
                bin.insert(value);
            }
        } else if (command == "delete"){
            bin.delete_el(value);
        } else if (command == "exists"){
            if (bin.find_el(value) != nullptr){
                cout << "true" << "\n";
            } else{
                cout << "false" << "\n";
            }
        } else if (command == "prev"){
            if (bin.prev(value) != -1000000001){
                cout << bin.prev(value) << "\n";
            } else{
                cout << "none" << "\n";
            }
        } else if (command == "next"){
            if (bin.next(value) != 1000000001){
                cout << bin.next(value) << "\n";
            } else{
                cout << "none" << "\n";
            }
        }
    }

    return 0;
}
