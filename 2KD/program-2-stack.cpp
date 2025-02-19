// 2. Sukurti steką. Sukurti funkcijas, kurios vykdo duomenų įvedimą, bei pašalinimą. Realizuoti funkcijas, kurios

// a. Visus pašalintus elementus įrašys į dvikryptį ciklinį sąrašą;

// b. Dvikrypčiame cikliniame sąraše visus neigiamus elementus pakeis atitinkamais
// teigiamais bei parodys juos ekrane;

// c. Pašalins iš dvikrypčio ciklinio sąrašo elementus iki pirmojo 0 bei parodys juos ekrane.

/*******REQUIREMENTS IN ENGLISH*******/
// 2. Create a stack. Implement functions for data insertion and removal.  
// Implement the following functions:  

// a. Store all removed elements in a doubly circular linked list.  

// b. In the doubly circular linked list, replace all negative elements with their  
// corresponding positive values and display them on the screen.  

// c. Remove all elements from the doubly circular linked list up to the first 0  
// and display them on the screen.  

#include <iostream>
using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

Stack *start = NULL;

struct List {
    int data;
    struct List *next, *prev;
};
List *head, *tail;

void addListElem(int stackElem) {
    List *newNode = new List;
    newNode->data = stackElem;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        newNode->prev = tail;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void printLinkedList() {
    if (head == NULL) {
        cout <<"---------------------------" << endl;
        cout << "sarasas yra tuscias" << endl;
        cout <<"---------------------------" << endl;
    } else {
        List *current = head;
        cout << "---------------------------" << endl;
        cout << "tail -> ";
        do {
            cout << current->data << " <--> ";
            current = current->next;
        } while (current != head);
        cout << "head" << endl;
        cout <<"---------------------------" << endl;
    }
}

void listNegativeToPositive() {
    List *current = head;
    if (head == NULL) {
        cout << "---------------------------" << endl;
        cout << "sarasas yra tuscias" << endl;
        cout << "---------------------------" << endl;
    } else {
        do {
            if (current->data < 0) {
                cout << "elementas " << current->data << " pakeistas i ";
                current->data = current->data * (-1);
                cout << current->data << endl;
            }
            current = current->next;
        } while (current != head);
        cout << "---------------------------" << endl;
    }
}

bool findZeroInList() {
    if (head == NULL) {
        return false;
    }
    List *current = head;
    do {
        if (current->data == 0) {
            return true;
        }
        current = current->next;
    } while (current != head);
    return false;
}

void deleteElemBeforeZero() {
    List *current = head;
    List *prev = tail;
    bool zeroExists = findZeroInList();
    if (zeroExists == false) {
        cout << "sarase 0 nerastas" << endl;
    } else {
        while (zeroExists) {
            if (current->data == 0) {
                break;
            } else {
                
                }
            }
            prev = current;
            current = current->next;
    }
}

void addElem(int num) {
    Stack *temp = new Stack;
    temp->data = num;
    temp->next = start;
    start = temp;
}

void removeElem() {
    if (start == NULL) {
        cout <<"---------------------------" << endl;
        cout << "stekas yra tuscias, negalima salinti elemento" << endl;
        cout <<"---------------------------" << endl;
    } else {
        Stack *temp = start;
        start = start->next;
        addListElem(temp->data);
        cout <<"---------------------------" << endl;
        cout << "elementas " << temp->data << " pasalintas" << endl;
        cout <<"---------------------------" << endl;
        delete temp;
    }
}

int main() {
    int choice, num;
    do {
        cout << "pasirinkite, koki veiksma norite vykdyti, pvz.: 3" << endl;
        cout << "1 - iterpti elementa i steka" << endl;
        cout << "2 - pasalinti elementa is steko ir prideti ji i sarasa" << endl;
        cout << "3 - spausdinti sarasa" << endl;
        cout << "4 - pakeisti neigiamus elementus i teigiamus sarase" << endl;
        cout << "5 - pasalinti elementus iki pirmojo 0 sarase" << endl;
        cout << "8 - baigti programa" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1: 
                cout << "iveskite, koki elementa norite prideti, pvz.: 44" << endl;
                cin >> num;
                addElem(num);
                cout <<"---------------------------" << endl;
                cout << "elementas pridetas: " << num << endl;
                cout <<"---------------------------" << endl;
                break;
            case 2:
                removeElem();
                break;
            case 3:
                printLinkedList();
                break;
            case 4:
                listNegativeToPositive();
                break;
            case 5:
                deleteElemBeforeZero();
                break;
            case 8: 
                cout << "programa baigta" << endl;
                break;
            default:
                cout <<"---------------------------" << endl;
                cout << "negalimas pasirinkimas" << endl;
                cout <<"---------------------------" << endl;
        }
    } while (choice != 8);

    return 0;
}