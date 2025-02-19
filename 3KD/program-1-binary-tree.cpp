//Sukurti dvejetainį medį, kurio elementai būtų asmenų pavardes (simboliu eilutes). Realizuoti 
//įterpimo, paieškos, spausdinimo ir  šalinimo operacijas bei atlikti šiuos veiksmus:

//a. Visas pavardes, kurių ilgis didesnis nei 5  įrašyti į  eilę, realizuotą kaip sąrašas.

//b. Pašalinti iš medžio visas  pavardes, kurių ilgis didesnis už 5, bet mažesnis už 10, 
//įrašant jas į deko, realizuoto kaip sąrašas, pradžią.

//c. Pašalinti iš medžio visas  pavardes, kurių ilgis didesnis už 10, įrašant jas į deko, 
//realizuoto kaip sąrašas, pabaigą.

//d. Spausdinti deką ir eilę.

/*******REQUIREMENTS IN ENGLISH*******/
// Create a binary tree where the elements are last names (strings).  
// Implement insertion, search, printing, and deletion operations,  
// and perform the following tasks:  

// a. Store all last names longer than 5 characters in a queue implemented as a list.  

// b. Remove from the tree all last names longer than 5 but shorter than 10 characters,  
// inserting them at the front of a deque implemented as a list.  

// c. Remove from the tree all last names longer than 10 characters,  
// inserting them at the end of a deque implemented as a list.  

// d. Print the deque and the queue. 

#include <iostream>
#include <string>
using namespace std;

struct Tree {
    string data;
    Tree *right;
    Tree *left;
};
Tree *root = NULL;

struct elem {
    string data;
    elem *next;
};

struct Queue {
  int size;
  elem *start;
  elem *tail;
};

struct Deque {
    string data;
    Deque *prev;
    Deque *next;
};
Deque *start = NULL;
Deque *tail = NULL;

Queue* initializeQueue() {
    Queue *q = new Queue;
    q->size = 0;
    q->start = NULL;
    q->tail = NULL;
    return q;
}

Tree* newNode(string lastName) {
    Tree *p;
    p = new Tree;
    p->data = lastName;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Tree* treeAddLastName(Tree *root, string lastName) {
    if (root == NULL) {
        return newNode(lastName);
    } else if (lastName > root->data){
        root->right = treeAddLastName(root->right, lastName);
    } else {
        root->left = treeAddLastName(root->left, lastName);
    }
    return root;
}

Tree* treeFindLastName(Tree *root, string lastName) {
    if (root == NULL || root->data == lastName) {
            cout << "-----------------------" << endl;
        if (root == NULL) {
            cout << "pavarde nerasta" << endl;
        } else {
            cout << "pavarde rasta: " << lastName << endl;
        }
            cout << "-----------------------" << endl;
        return root;
    } else if (lastName > root->data) {
        return treeFindLastName(root->right, lastName);
    } else {
        return treeFindLastName(root->left, lastName);
    }
}

Tree* findMax(Tree *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right != NULL) {
        return findMax(root->right);
    }
    return root;
}

Tree* treeRemoveLastName(Tree *root, string lastName) {
    if (root == NULL) return NULL;
    if (lastName > root->data) {
        root->right = treeRemoveLastName(root->right, lastName);
    } else if (lastName < root->data) {
        root->left = treeRemoveLastName(root->left, lastName);
    } else if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    } else if (root->left == NULL || root->right == NULL) {
        Tree *temp;
        if (root->left == NULL) {
            temp = root->right;
        } else {
            temp = root->left;
        }
        delete root;
        return temp;
    } else {
        Tree *temp = findMax(root->left);
        root->data = temp->data;
        root->left = treeRemoveLastName(root->left, temp->data);
        return root;
    }
}

void printTree(Tree *root) {
    if (root != NULL) {
        printTree(root->left);
        cout << root->data << "  ";
        printTree(root->right);    
    } else {
        cout << "" << endl;
    }
}

void addElemToQueue(Queue *q, string lastName) {
    elem *temp;
    temp = new elem;
    temp->data = lastName;
    temp->next = NULL;
    if (q->size == 0) {
        q->start = temp;
        q->tail = temp;
    } else {
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size++;
}

void printQueue(elem *start) {
    if (start == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << start->data << " -> ";
        printQueue(start->next);
    }
}

Deque* dequeCreateElem(string data) {
    Deque *newElem = new Deque;
    newElem->data = data;
    newElem->prev = NULL;
    newElem->next = NULL;
    return newElem;
}

void dequeAddElemStart(string data) {
    struct Deque *newElem, *temp;
    newElem = dequeCreateElem(data);
    if (start == NULL) {
        start = newElem;
        tail = newElem;
        start->next = NULL;
        tail->prev = NULL;
    } else {
        temp = start;
        start->next = newElem;
        newElem->prev = start;
        newElem->next = temp;
        temp->prev = newElem;
    }
}

void dequeAddElemTail(string data) {
    struct Deque *newElem, *temp;
    newElem = dequeCreateElem(data);
    if (start == NULL) {
        start = newElem;
        tail = newElem;
        start->next = NULL;
        tail->prev = NULL;
    } else {
        tail->next = newElem;
        newElem->prev = tail;
        tail = newElem;
        tail->next = NULL;
    }
}

void printDeque() {
    if (start == NULL) {
        cout << "dekas tuscias" << endl;
    }
    struct Deque *temp = start;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail);
    cout << "NULL" << endl;
}

void goThroughTree(Tree *root, Queue *q, int x) {
    if (root != NULL) {
        goThroughTree(root->left, q, x);
        if (root->data.length() > 5 && x == 1) {
            addElemToQueue(q, root->data);
        }
        if (root->data.length() > 5 && root->data.length() < 10 && x == 2) {
            dequeAddElemStart(root->data);
            treeRemoveLastName(root, root->data);
        }
        if (root->data.length() > 10 && x == 3) {
            dequeAddElemTail(root->data);
            treeRemoveLastName(root, root->data);
        }
        goThroughTree(root->right, q, x);    
    }
}

int main() {
    int choice;
    int x;
    string lastName;
    Queue *q = initializeQueue();
    do {
        cout << "Pasirinkite ka norite daryti" << endl;
        cout << "1 - iterpti pavarde" << endl;
        cout << "2 - rasti pavarde" << endl;
        cout << "3 - spausdinti medi" << endl;
        cout << "4 - salinti pavarde" << endl;
        cout << "5 - irasyti pavardes kurios ilgesnes nei 5 i eile" << endl;
        cout << "6 - irasyti pavardes kurios ilgesnes nei 5 ir trumpesnes nei 10 i deko pradzia" << endl;
        cout << "7 - irasyti pavardes kurios ilgesnes nei 10 i deko gala" << endl;
        cout << "8 - spausdinti deka" << endl;
        cout << "9 - spausdinti eile" << endl;
        cout << "0 - baigti programa" << endl;
        cin >> choice;
    
        switch (choice) {
            case 1:
                cout << "iveskite pavarde, kuria norite iterpti" << endl;
                cin >> lastName;
                root = treeAddLastName(root, lastName);
                break;
            case 2:
                cout << "iveskite pavarde, kuria norite rasti" << endl;
                cin >> lastName;
                treeFindLastName(root, lastName);
                break;
            case 3:
                printTree(root);
                break;
            case 4:
                cout << "iveskite pavarde, kuria norite naikinti" << endl;
                cin >> lastName;
                treeRemoveLastName(root, lastName);
                cout << "-----------------------" << endl;
                cout << "pavarde panaikinta" << endl;
                cout << "-----------------------" << endl;
                break;
            case 5:
                goThroughTree(root, q, 1);
                break;
            case 6:
                goThroughTree(root, q, 2);
                break;
            case 7:
                goThroughTree(root, q, 3);
                break;
            case 8:
                printDeque();
                break;
            case 9:
                printQueue(q->start);
                break;
            case 0:
                cout << "programa baigta" << endl;
                break;
            default:
                cout << "-----------------------" << endl;
                cout << "negalimas pasirinkimas" << endl;
                cout << "-----------------------" << endl;
        }    
    } while (choice != 0);
    
    return 0;
}