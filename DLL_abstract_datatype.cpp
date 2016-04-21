//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 9
//  2/10/2016
//  giftlist class
//  double linked list of abstract datatype with iterator

#include <iostream>
#include "DLL_abstract_datatype.h"
using namespace std;

template <typename T>
ddlist<T>::ddlist(){
    Node *list = new Node();
    list->number = -1;
    list->next = list;
    list->prev = list;

    counter = 0;
    head = list;
}

template <typename T>
ddlist<T>::~ddlist(){
    /*Node *temp = head;
    Node *next;

    do { //free each Node by running through  list
        next = temp->next;
        delete temp;
        temp = next;
    } while (temp != head);*/
    while (numItems()>0) {
        removeLast();
    }
}
template <typename T>
typename ddlist<T>::ddlist_iterator ddlist<T>::begin(){
    return ddlist_iterator(head->next);
}
template <typename T>
typename ddlist<T>::ddlist_iterator ddlist<T>::end(){
    return ddlist_iterator(head);
}

template <typename T>
int ddlist<T>::numItems(){
    return counter; // return the kept number of counter in
}

template <typename T>
void ddlist<T>::addFirst(T x){
    Node *ddlist = new Node();
    ddlist->number = x; // allocate the number
    ddlist->next = head->next;// next four line set ddlist in to the beginning of list
    ddlist->prev = head;
    head->next->prev = ddlist;
    head->next = ddlist;
    counter++;//increment counter

}

template <typename T>
void ddlist<T>::addLast(T x){
    Node *ddlistlast = new Node();
    ddlistlast->number = x;//give number to that Node
    ddlistlast->next = head;//next four line set Node at the end of list and connect all links
    ddlistlast->prev = head->prev;
    head->prev->next = ddlistlast;
    head->prev = ddlistlast;
    counter++; // increment counter
}

template <typename T>
T ddlist<T>::removeFirst(){
    Node *ddlistrf = head->next;//temp Node

    head->next = ddlistrf->next; // link temp Node to keep all the linked list
    ddlistrf->next->prev = head;

    int temp = ddlistrf->number; // temp holder to delete the Node
    delete ddlistrf; // free the first one
    counter--; //decrement counter
    return temp; // return the value of the temp Node which you deleted
}

template <typename T>
T ddlist<T>::removeLast(){
    Node *ddlistrl = head->prev; //temp Node

    head->prev = ddlistrl->prev; // connect temp Node to make sure link doesnt dissapear
    ddlistrl->prev->next = head;

    int temp = ddlistrl->number; //temp Node to delete
    delete ddlistrl;//delete that Node
    counter--;//decrement counter
    return temp;//return the value of deleted Node
}

template <typename T>
T ddlist<T>::getFirst(){
    return head->next->number;//return the first Node number
}

template <typename T>
T ddlist<T>::getLast(){
    return head->prev->number; // return the value of last Node by going prov from head
}

template <typename T>
ostream& operator<<(ostream& out, ddlist<T>& l){
    cout << "List: ";
    /*typename ddlist<T>::Node *temp;
    temp = l.head->next;
    while (temp != l.head){
        cout << temp->number << ", ";
        temp = temp->next;
    }*/
    for (typename ddlist<T>::ddlist_iterator it=l.begin(); it!=l.end(); it++) {
        cout << (*it)->number << ",";
    }
    return out;
}

int main(){
    ddlist<int> s;
    ddlist<double> s2;
    s.addFirst(10);
    s.addFirst(20);
    s.addFirst(30);
    s.addLast(40);
    s.addLast(25);
    s.removeFirst();

    cout << s << endl;

    return 0;
}
