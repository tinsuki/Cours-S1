#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
    T value;
    Node<T>* next = nullptr;
public:
    Node(T value){
        this->value = value;
    }

    T getValue(){
        return this->value;
    }

    Node<T>* getNext(){
        return this->next;
    }

    void setNext(Node<T>* newNext){
        this->next = newNext;
    }
};

template <typename T>
class LinkedList {
    private:
        int listSize = 0;
        Node<T>* first = nullptr;
    public:
        void displayList(){
            Node<T>* first = this->first;
            while(first != nullptr){
                std::cout << first->getValue() << " ";
                first = first->getNext();
            }
            if(listSize != 0) std::cout << "(" << listSize << ")" << std::endl;
        }

        void push(Node<T>* value){
            value->setNext(this->first);
            this->first = value;
            this->listSize++;
        }

        Node<T>* top(){
            return this->first;
        }

        void pop(){
            Node<T>* topValue = this->first;
            Node<T>* newTop = topValue->getNext();
            this->first = newTop;
            this->listSize--;
            delete topValue;
        }

        void clear(){
            Node<T>* current = this->first;
            Node<T>* toDel = current;
            while(first != nullptr){
                toDel = current;
                current = current->getNext();
                delete toDel;
            }
            if(listSize != 0) std::cout << "(" << listSize << ")" << std::endl;
        }
};


int main()
{
    LinkedList<double> *list = new LinkedList<double>;
    list->push(new Node<double>(0.1));
    list->push(new Node<double>(0.2));
    list->displayList();
    std::cout << list->top()->getValue() << std::endl;
    list->pop();
    list->displayList();
    list->clear();
    list->displayList();
    delete list;

    return 0;
}
