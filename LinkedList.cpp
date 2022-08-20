/*
    LinkedList Header File : Made by Kanwar Adnan
    List of Methods :
        1)  isEmpty()
        2)  isIndex()
        3)  isValid()
        4)  insertAtBeginning(int value)
        5)  insertAtLast(int value)
        6)  removeFirst()
        7)  removeLast()
        8)  insertAtId(int id, int value)
        9)  removeAtId(int id)
        10) getLength()
        11) getFirst()
        12) getLast()
        13) getElementById(int id)
        14) getElementByValue(int value)
        15) getElementIdByValue(int value)
        16) deleteElementById(int id)
        17) deleteElementByValue(int value)
        18) doesExist(int value)
        19) doesExistRet(int value , int * index)
        20) reverse()
        21) print()
        22) printWithIndex()
        23) printRev(Node * current)
        24) getFirstElement()
        25) getLastElement()
        26) getNodeById(int id)
*/
#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node * next;
public:
    Node() : data(0), next(NULL) {}

    Node(int data, Node * next = NULL){
        setData(data);
        setNext(next);
    }
    Node * getNext()            { return next; }
    int getData()               { return data; }
    void setNext(Node * next)   { this->next = next; }
    void setData(int data)      { this->data = data; }
};

class LinkedList{
private:
    Node * head;
    int length;
public:
    LinkedList() : length(0) , head(NULL) {}
    bool isEmpty()              { return (head == NULL); }
    bool isIndex(int index)     { return ( (index <= length) && (index > 0) ); }
    bool isValid(int index)     { return ( (!isEmpty()) && (isIndex(index)) ); }
    Node* getFirst()            { return head; }
    Node * getLast()            { return getNodeById(length); }
    int getFirstElement()       { return getFirst()->getData(); }
    int getLastElement()        { return getLast()->getData(); }
    int getLength()             { return length; }

    void insertAtBeginning(int value){
        Node * temp = new Node(value);
        temp->setNext(head);
        head = temp;
        length++;
    }

    void insertAtLast(int value){
        Node * temp = new Node(value);
        if (isEmpty())
            head = temp;
        else {
            Node * temp2 = getNodeById(length);
            temp2->setNext(temp);
        }
        length++;
    }

    void print(){
        Node * temp = head;
        while (temp != NULL){
            cout << temp->getData() << "->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }

    void printWithIndex(){
        Node * temp = head;
        int index = 1;
        while (temp != NULL){
            cout << index << " : " << temp->getData() << '\n';
            index++;
            temp = temp->getNext();
        }
        cout << '\n';
    }
    
    void removeFirst(){
        if (isEmpty())
            return;
        else if (head->getNext() == NULL) {
            delete head;
            head = NULL;
        }
        else {
            Node * temp = head->getNext();
            delete head;
            head = temp;
        }
        length--;
    }

    void removeLast(){
        if (isEmpty())
            return;
        else if(head->getNext() == NULL){
            delete head;
            head = NULL;
        }
        else {
            Node * temp = getNodeById( length - 1 );
            Node * temp2 = temp->getNext();
            delete temp2;
            temp->setNext(NULL);
        }
        length--;
    }

    int getElementById(int id){
        Node * temp = getNodeById(id);
        if (temp != NULL)
            return temp->getData();
        return -9999;
    }

    Node * getNodeById(int id){
        if ((!isEmpty()) && (isIndex(id))){
            Node * temp = head;
            int count = 1;
            while (count != id){
                temp = temp->getNext();
                count++;
            }
            return temp;
        }
        return NULL;
    }


    Node * getNodeByValue(int value){
        if (!isEmpty()){
            Node * temp = head;
            while (temp != NULL){
                if (value == temp->getData())
                    return temp;
                temp = temp->getNext();
            }
        }
        return NULL;
    }

    int getElementIdByValue(int value){
        if (!isEmpty()){
            Node * temp = head;
            int count = 1;
            while (temp != NULL){
                if (value == temp->getData())
                    return count;
                count++;
                temp = temp->getNext();
            }
        }
        return -9999;
    }
//**
    void deleteElementById(int id){
        if ( (!isEmpty()) && (isIndex(id)) ){
            if ( (id == 1) && (length <= 2) )
                removeFirst();
            else {
                Node * temp = getNodeById( id - 1 );
                Node * temp2 = temp->getNext();
                Node * next = temp2->getNext();
                temp->setNext(next);
                delete temp2;
                length--;
            }
        }
    }

    void deleteElementByValue(int value){
        if (!isEmpty()){
            if ( (head->getData() == value) && (length <= 2) )
                removeFirst();
            else {
                Node * temp = head;
                Node * temp2 = head->getNext();
                while (temp2->getNext() != NULL){
                    if (temp2->getData() == value){
                        Node * next = temp2->getNext();
                        temp->setNext(next);
                        delete temp2;
                        length--;
                        return;
                    }
                    temp2 = temp2->getNext();
                    temp = temp->getNext();
                }
                // If the last member is to delete
                if (temp2->getData() == value){
                    removeLast();
                }
            }
        }
    }

    bool doesExist(int value){
        Node * temp = head;
        while (temp != NULL){
            if (value == temp->getData())
                return true;
            temp = temp->getNext();
        }
        return false;
    }

    // This method returns the index of the element if it exists
    Node * doesExistRet(int value, int* index){
        Node * temp = head;
        int count = 1;
        while (temp != NULL){
            if (value == temp->getData()){
                *index = count;
                return temp;
            }
            temp = temp->getNext();
            count++;
        }
        *index = -1; // -1 incase element not found
        return NULL;
    }


    void reverse(){
        if (!isEmpty()){
            if (length == 1){
                return;
            }
            Node * previous = NULL;
            Node * current = head;
            Node * next = NULL;
            while(current != NULL){
                next = current->getNext();
                current->setNext(previous);
                previous = current;
                current = next;
            }
            head = previous;
        }
    }

    void insertAtId(int id,int value){
        if (!isEmpty() && isIndex(id) ){
            if (id == 1)
                insertAtBeginning(value);
            else {
                Node * temp = new Node(value);
                Node * prevId = getNodeById(id-1);
                Node * currentId = prevId->getNext();
                prevId->setNext(temp);
                temp->setNext(currentId);
                length++;
            }
        }
        // Comment it if does not need this
        else if (!isEmpty() && (id > length) ){
            insertAtLast(value);
        }
     }

    // It's also same as deleteElementById
    void removeAtId(int id){
        if (!isEmpty() && isIndex(id)){
            if (id == 1){
                removeFirst();
            }
            else if (id == length){
                removeLast();
            }
            else {
                Node * prevId = getNodeById(id-1);
                Node * currentId = prevId->getNext();
                Node * nextId = currentId->getNext();
                prevId->setNext(nextId);
                delete currentId;
                length--;
            }
        }
    }

    // Incomplete
    void swap(int id1, int id2){
        if (isIndex(id1) && isIndex(id2)){
            if (id1 == id2)
                return;
            else {
                Node * prevId1 = getNodeById( id1 - 1 );
                Node * prevId2 = getNodeById( id2 - 1 );
                Node * currId1 = prevId1->getNext();
                Node * currId2 = prevId2->getNext();
                Node * nextId1 = currId1->getNext();
                Node * nextId2 = currId2->getNext();
                prevId1->setNext(currId2);
                currId2->setNext(nextId1);
                prevId2->setNext(currId1);
                currId1->setNext(nextId2);
            }
        }
    }

    void printRev(Node * current){
        if (current == NULL)
            return;
        printRev(current->getNext());
        cout << "<-" << current->getData();
    }
    
    void remDup(){
        LinkedList l1;
        l1.insertAtLast(head->getData());
        Node * toDelete = head;
        head = head->getNext();
        delete toDelete;
        
        while (head != NULL){
            if (!l1.doesExist(head->getData())){
                l1.insertAtLast(head->getData());
            }
            toDelete = head;
            head = head->getNext();
            delete toDelete;
        }
        delete head;
        head = l1.getFirst();
        length = l1.getLength();
    }

};


int main(){
    LinkedList l1;
    l1.insertAtLast(1);
    l1.insertAtLast(1);
    l1.insertAtLast(1);
    l1.insertAtLast(1);
    l1.insertAtLast(2);
    l1.insertAtLast(2);
    l1.insertAtLast(2);
    l1.insertAtLast(2);
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtLast(5);
    l1.insertAtLast(5);
    l1.insertAtLast(5);
    l1.print();
    l1.remDup();
    l1.print();
    // cout << "NULL";
    // l1.printRev(l1.getFirst());
}
/*
Output: 
    1->1->1->1->2->2->2->2->3->4->3->4->3->4->5->5->5->NULL
    1->2->3->4->5->NULL
*/
