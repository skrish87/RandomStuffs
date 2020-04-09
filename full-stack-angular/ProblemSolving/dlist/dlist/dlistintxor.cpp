//
//  dlistintxor.cpp
//  dlist
//
//  Created by Zulfikar Ali Sahool Hameed on 11/3/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
    
} *head;

class Node {
    
public:
    Node() {
        head = NULL;
    }
    
    void createList(int value) {
        struct node *s, *temp;
        temp = new(struct node);
        temp->info = value;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
        }
        else
        {
            s = head;
            while (head->next != NULL)
                head = head->next;
            head->next = temp;
            temp->prev = s;
        }
    }
    
    void push_front(int value) {
        if (head == NULL)
        {
            cout << "Please create the list ... " << endl;
            return;
        }
        struct node *temp = new (struct node);
        temp->prev = NULL;
        temp->info = value;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    void push_back(int value) {
        if (head == NULL) {
            cout << "Please create the list ... " << endl;
            return;
        }
        struct node *temp = new(struct node), *q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        temp->info = value;
        temp->next = NULL;
        temp->prev = q;
        q->next = temp;
    }
    
    void pop_front() {
        struct node *tmp;
        tmp = head;
        head = head->next;
        head->prev = NULL;
        free(tmp);
    }
    
    void pop_back() {
        struct node *tmp = head, *q;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        q = tmp->prev;
        q->next = NULL;
        free(tmp);
    }

    void reverse()
    {
        struct node *p1, *p2;
        p1 = head;
        p2 = p1->next;
        p1->next = NULL;
        p1->prev = p2;
        while (p2 != NULL)
        {
            p2->prev = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2->prev;
        }
        head = p1;
    }
    
    void find(int value) {
        struct node *p = head;
        int pos = 0;
        while (p->next != NULL) {
            if (p->info == value) {
                cout << "Node with value " << value << " is found at " << pos << endl;
                return;
            }
            p = p->next;
            pos++;
        }
        cout << "Node with value " << value << " is not found " << endl;
    }
    
    int size()
    {
        struct node *q = head;
        int cnt = 0;
        while (q != NULL)
        {
            q = q->next;
            cnt++;
        }
        cout << "The size of the list is " << cnt << endl;
        return cnt;
    }
    
    void printList() {
        struct node *q;
        if (head == NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        q = head;
        cout << "The Doubly Link List is :"  << endl;
        while (q != NULL)
        {
            cout << q->info << " <-> ";
            q = q->next;
        }
        cout << "NULL" << endl;
    }
    
};

int main() {
    Node n;
    n.createList(5000);
    n.push_front(4000);
    n.push_front(3000);
    n.push_front(2000);
    n.push_front(1000);
    n.push_front(500);
    n.find(3000);
    n.find(200);
    n.printList();
    n.reverse();
    n.printList();
    n.size();
    n.pop_front();
    n.printList();
    n.pop_back();
    n.printList();
    n.push_back(9000);
    n.push_back(10000);
    n.push_back(11000);
    n.push_back(12000);
    n.printList();
    return 0;
}