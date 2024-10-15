#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data=val;
        next=NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head=NULL;
    }

    void insertAtHead(int value) {
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode=new Node(value);
        if(head==NULL) {
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
	
	
	void insertAtThirdIndex(int value) {
        Node* newNode=new Node(value);
        if(head==NULL||head->next==NULL||head->next->next==NULL) {
            insertAtEnd(value);
        } else {
            Node* temp=head;
            for(int i=0;i<1;++i) {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
     void deleteThirdNode() {
        if(head==NULL||head->next==NULL||head->next->next==NULL) {
            cout<<"Error: Less than 3 nodes in the list."<<endl;
            return;
        }
        Node* temp=head;
        for(int i=0;i<1;++i) {
            temp=temp->next;
        }
        Node* nodeToDelete=temp->next;
        temp->next=nodeToDelete->next;
        delete nodeToDelete;
    }
	
	
void deleteLastNode() {
        if(head==NULL) {
            cout<<"Error: The list is empty."<<endl;
            return;
        }
        if(head->next==NULL) {
            delete head;
            head=NULL;
        } else {
            Node* temp=head;
            while(temp->next->next!=NULL) {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
        }
    }
    
    void display() {
        Node* temp=head;
        while(temp!=NULL) {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    cout<<"Initial list: ";
    list.display();

    list.insertAtEnd(40);
    cout<<"After inserting 40 at end: ";
    list.display();


    list.deleteLastNode();
    cout<<"After deleting last node: ";
    list.display();

    return 0;
}
