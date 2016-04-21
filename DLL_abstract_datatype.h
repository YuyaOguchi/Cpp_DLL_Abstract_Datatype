//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 9
//  2/10/2016
//  giftlist class
//  double linked list of abstract datatype with iterator

#pragma once
template <typename T>
class ddlist{
private:
    typedef struct node{
        T number;
        struct node *next;
        struct node *prev;
    } Node;

    int counter;
    Node *head;

    class ddlist_iterator : std::iterator<std::forward_iterator_tag, Node> {
        public://private:
            Node *current;
        public:
            ddlist_iterator(Node* node) {
                current = node;
            }
            Node* operator*() const {
                return current;
            }
            ddlist_iterator& operator++() {
                current = current->next;
                return *this;
            }
            ddlist_iterator operator++(int) {
                Node *temp = current;
                current = current->next;
                return temp;
            }
            ddlist_iterator& operator--() {
                current = current->prev;
                return *this;
            }
            ddlist_iterator operator--(int) {
                Node *temp = current;
                current = current->prev;
                return temp;
            }
            bool operator==(const ddlist_iterator other) const{
                return current == other.current;
            }
            bool operator!=(const ddlist_iterator other) const{
                return current != other.current;
            }
    };
public:
    ddlist();
    ~ddlist();

    int numItems();
    void addFirst(T x);
    void addLast(T x);
    T removeFirst();
    T removeLast();
    T getFirst();
    T getLast();
    ddlist_iterator begin();
    ddlist_iterator end();

    template <typename I>
    friend std::ostream& operator<<(std::ostream&, ddlist<I>&);
};
