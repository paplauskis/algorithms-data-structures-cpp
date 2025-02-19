// Sukurti steką, realizuotą kaip vienkryptis sąrašas. Sukurti funkcijas, kurios vykdo duomenų
// įvedimą, bei pašalinimą. Realizuoti funkcijas, kurios:

// a. Visus pašalintus elementus įrašys į vienkryptį ciklinį sąrašą;

// b. Vienkrypčiame cikliniame sąraše visus nelyginius elementus padvigubins bei parodys
// juos ekrane;

// c. Pašalins iš vienkrypčio ciklinio sąrašo visus elementus po paskutinio teigiamo bei
// parodys juos ekrane.

#include <iostream>
using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

Stack *start = NULL;

struct List {
    int data;
    struct List *next;
};
List *head = NULL;
List *tail = NULL;

void addListData(int stackData) {
    List *newNode = new List;
    newNode->data = stackData;
    newNode->next = head;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    tail->next = head;
}

void printLinkedList() {
    if (head == NULL) {
        cout <<"---------------------------" << endl;
        cout << "sarasas yra tuscias" << endl;
        cout <<"---------------------------" << endl;
    } else {
        List *current = head;
        cout <<"---------------------------" << endl;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "head" << endl;
        cout <<"---------------------------" << endl;
    }
}

void doubleOdd() {
    List *current = head;
    cout <<"---------------------------" << endl;
    do {
        if (current->data % 2 == 1 || current->data % 2 == -1) {
            cout << "elementas " << current->data << " padvigubintas i ";
            current->data = current->data * 2;
            cout << current->data << endl;
        }
        current = current->next;
    } while (current != head);
    cout <<"---------------------------" << endl;
}

int findLastPositive() {
    List *current = head;
    int positiveElem = 0;
    do {
        if (current->data > 0) {
            positiveElem = current->data;
        }
        current = current->next;
    } while (current != head);
    return positiveElem;
}

void removeElem(int lastPositive) {
    List *current = head;
    List *prev = nullptr;
    
    while (current->next != head) {
        if (current->data == lastPositive) {
            break;
        }
        prev = current;
        current = current->next;
    }
    List *temp = current->next;
    current->next = head;
    while (temp != head) {
        List *nextNode = temp->next;
        cout <<"---------------------------" << endl;
        cout << "panakintas elementas: " << temp->data << endl;
        cout <<"---------------------------" << endl;
        delete temp;
        temp = nextNode;
    }
}

void removeAfterLastPositive() {
    int lastPositive = findLastPositive();
    removeElem(lastPositive);
}

void addData(int x) {
    Stack *temp = new Stack;
    temp->data = x;
    temp->next = start;
    start = temp;
}

int isEmpty() {
    if (start == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void removeData() {
    if (isEmpty() == 1) {
        cout <<"---------------------------" << endl;
        cout << "stekas yra tuscias, negalima salinti elemento" << endl;
        cout <<"---------------------------" << endl;
    } else {
        Stack *temp = start;
        start = start->next;
        addListData(temp->data);
        cout <<"---------------------------" << endl;
        cout << "elementas " << temp->data << " pasalintas" << endl;
        cout <<"---------------------------" << endl;
        delete temp;
    }
}

void deleteStack() {
    while (!isEmpty()) {
        removeData();
    }
}

int main() {
    int choice, x;
    do {
        cout << "pasirinkite, koki veiksma norite vykdyti, pvz.: 3" << endl;
        cout << "1 - iterpti elementa i steka" << endl;
        cout << "2 - pasalinti elementa is steko ir prideti ji i sarasa" << endl;
        cout << "3 - patikrinti ar stekas tuscias" << endl;
        cout << "4 - istrinti visa steka atspausdinant jo elementus" << endl;
        cout << "5 - spausdinti sarasa" << endl;
        cout << "6 - padvigubinti nelyginius elementus sarase" << endl;
        cout << "7 - pasalinti visus elementus po paskutinio teigiamo sarase" << endl;
        cout << "8 - baigti programa" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1: 
                cout << "iveskite, koki elementa norite prideti, pvz.: 73" << endl;
                cin >> x;
                addData(x);
                cout <<"---------------------------" << endl;
                cout << "elementas pridetas: " << x << endl;
                cout <<"---------------------------" << endl;
                break;
            case 2:
                removeData();
                break;
            case 3:
                if (isEmpty() == 0) {
                    cout <<"---------------------------" << endl;
                    cout << "stekas nera tuscias" << endl;
                    cout <<"---------------------------" << endl;
                } else {
                    cout <<"---------------------------" << endl;
                    cout << "stekas yra tuscias" << endl;
                    cout <<"---------------------------" << endl;
                }
                break;
            case 4:
                deleteStack();
                break;
            case 5:
                printLinkedList();
                break;
            case 6:
                doubleOdd();
                break;    
            case 7:
                removeAfterLastPositive();
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