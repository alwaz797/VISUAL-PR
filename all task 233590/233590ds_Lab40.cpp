#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head=NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode=new Node(value);
        newNode->next=head;
        if (head!=NULL) {
            head->prev=newNode;
        }
        head=newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode=new Node(value);
        if (head==NULL) {
            head=newNode;
            return;
        }

        Node* temp=head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    void insertInMiddle(int position, int value) {
        if (position<0) {
            cout<<"Position should be non-negative"<<endl;
            return;
        }

        Node* newNode=new Node(value);
        if (position==0) {
            insertAtBeginning(value);
            return;
        }

        Node* current=head;
        for (int i=0; i<position-1; i++) {
            if (current==NULL) {
                cout<<"Position out of bounds"<<endl;
                delete newNode;
                return;
            }
            current=current->next;
        }

        if (current==NULL) {
            cout<<"Position out of bounds"<<endl;
            delete newNode;
            return;
        }

        newNode->next=current->next;
        newNode->prev=current;

        if (current->next!=NULL) {
            current->next->prev=newNode;
        }
        current->next=newNode;
    }

    void deleteAtBeginning() {
        if (head==NULL) {
            cout<<"Error: The list is empty."<<endl;
            return;
        }

        Node* temp=head;
        head=head->next;
        if (head!=NULL) {
            head->prev=NULL;
        }
        delete temp;
    }

    void deleteInMiddle(int position) {
        if (head==NULL) {
            cout<<"Error: The list is empty."<<endl;
            return;
        }

        Node* current=head;

        if (position==0) {
            deleteAtBeginning();
            return;
        }

        for (int i=0; i<position; i++) {
            if (current==NULL) {
                cout<<"Position out of bounds"<<endl;
                return;
            }
            current=current->next;
        }

        if (current==NULL) {
            cout<<"Position out of bounds"<<endl;
            return;
        }

        if (current->prev!=NULL) {
            current->prev->next=current->next;
        }

        if (current->next!=NULL) {
            current->next->prev=current->prev;
        }

        delete current;
    }

    void deleteAtEnd() {
        if (head==NULL) {
            cout<<"Error: The list is empty."<<endl;
            return;
        }

        Node* current=head;
        while (current->next!=NULL) {
            current=current->next;
        }

        if (current->prev!=NULL) {
            current->prev->next=NULL;
        } else {
            head=NULL;
        }
        delete current;
    }

    void display() {
        Node* temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    ~DoublyLinkedList() {
        while (head!=NULL) {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice,value,position;

    do {
        cout<<"Menu:"<<endl;
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert in middle"<<endl;
        cout<<"4. Delete at beginning"<<endl;
        cout<<"5. Delete in middle"<<endl;
        cout<<"6. Delete at end"<<endl;
        cout<<"7. Display"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter value to insert at beginning: ";
                cin>>value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout<<"Enter value to insert at end: ";
                cin>>value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout<<"Enter position and value to insert in middle: ";
                cin>>position>>value;
                list.insertInMiddle(position,value);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                cout<<"Enter position to delete in middle: ";
                cin>>position;
                list.deleteInMiddle(position);
                break;
            case 6:
                list.deleteAtEnd();
                break;
            case 7:
                cout<<"Current list: ";
                list.display();
                break;
            case 8:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice!=8);

    return 0;
}

