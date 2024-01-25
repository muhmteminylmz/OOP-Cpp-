#include <iostream>
#include <cctype>


using namespace std;

class list{
public:
    list *head;
    list *tail;
    list *next;
    int num;

    list(){ head = tail = next = NULL; };
    virtual void store(int i) = 0;
    virtual int retrieve() = 0;
};

class queue : public list{
public:
    void store(int i);
    int retrieve();
};

void queue ::store(int i) {
    list *item;

    item = new queue;
    if(!item){
        cout << "Allocation error.\n";
        exit(1);
    }

    item-> num =i;

    if(tail) tail->next = item;
    tail = item;
    item -> next = NULL;
    if(!head) head = tail;
}

int queue ::retrieve() {
    int i;
    list *p;

    if(!head){
        cout << "List is empty. \n";
        return 0;
    }

    i=head->num;
    p= head;
    head = head->next;
    delete p;

    return i;
}

class stack : public list{
public:
    void store(int i);
    int retrieve();
};

void stack ::store(int i) {
    list *item;
    item = new stack;

    if(!item){
        cout << "Allocation error.\n";
        exit(1);
    }

    /*
    item-> num =i;

    if(tail) tail->next = item;
    tail = item;
    item -> next = NULL;
     */

    item-> num =i;

    if(head) item->next = head;
    head = item;
    if(!tail) tail = head;
}

int stack :: retrieve() {
    int i;
    list *p;

    if(!head){
        cout << "List is empty.\n";
        return 0;
    }

    /*
    i=head->num;
    p= head;
    head = head->next;
     */

    i = head->num;
    p= head;
    head = head->next;
    delete p;

    return i;
}

int main(){
    list *p;

    queue q_ob;
    stack s_ob;

    char ch;
    int i;
    for(i=0;i<10;i++){
        cout << "Stack or Queue?: ";
        cin >> ch;
        ch = tolower(ch);
        if(ch=='q') p= &q_ob;
        else p = &s_ob;
        p->store(i);
    }

    cout << "Enter T to terminate\n";
    for(;;){
        cout << "Remove from Stack or Queue?: ";
        cin >> ch;
        ch = tolower(ch);
        if(ch=='t') break;
        if(ch=='q') p= &q_ob;
        else p=&s_ob;
        cout << p->retrieve() << "\n";
    }
    cout << endl;
    /*p->store(1);
    p->store(2);
    p->store(3);

    cout << "Queue: ";
    cout << p->retrieve();
    cout << p->retrieve();
    cout << p->retrieve();

    cout << endl;

    stack s_ob;
    p= &s_ob;

    p->store(1);
    p->store(2);
    p->store(3);

    cout << "Stack: ";
    cout << p->retrieve();
    cout << p->retrieve();
    cout << p->retrieve();
*/
    return 0;
}