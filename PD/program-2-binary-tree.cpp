// 2. Sukurti dvejetainį medį, realizuojant elemento įterpimo, pašalinimo,
// spausdinimo bei paieškos funkcijas. Perkelti to sąrašo visus elementus 
// į dvikryptį ciklinį sąrašą. Atspausdinti visus sąrašo  elementus.


#include <iostream>
using namespace std;

struct Tree {
    int data;
    Tree *right;
    Tree *left;
};
Tree *root = NULL;

struct List {
    int data;
    struct List *next, *prev;
};
List *head, *tail;

Tree *newNode(int data) {
    Tree *p;
    p = new Tree;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Tree *treeAddData(Tree *root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else if (data > root->data){
        root->right = treeAddData(root->right, data);
    } else {
        root->left = treeAddData(root->left, data);
    }
    return root;
}

Tree* findMax(Tree *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right != NULL) {
        return findMax(root->right);
    }
    return root;
}

Tree* treeRemoveData(Tree *root, int data) {
    if (root == NULL) return NULL;
    if (data > root->data) {
        root->right = treeRemoveData(root->right, data);
    } else if (data < root->data) {
        root->left = treeRemoveData(root->left, data);
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
        root->left = treeRemoveData(root->left, temp->data);
        return root;
    }
}

Tree* treeFindData(Tree *root, int data) {
    if (root == NULL || root->data == data) {
            cout << "-----------------------" << endl;
        if (root == NULL) {
            cout << "elementas nerastas" << endl;
        } else {
            cout << "elementas rastas: " << data << endl;
        }
            cout << "-----------------------" << endl;
        return root;
    } else if (data > root->data) {
        return treeFindData(root->right, data);
    } else {
        return treeFindData(root->left, data);
    }
}

void printTree(Tree *root) {
    if (root != NULL) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);    
    } else {
        cout << endl;
    }
}

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

void moveElementsFromTreeToList(Tree *root) {
    if (root != NULL) {
        moveElementsFromTreeToList(root->left);
        moveElementsFromTreeToList(root->right);
        addListElem(root->data);
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

int main() {
    int choice;
    int num;
    int elemDelete;
    int elemSearch;
    do {
        cout << "ka norite daryti toliau? (iveskite pvz.: 2)" << endl;
        cout << "1 - iterpti skaiciu i medi" << endl;
        cout << "2 - spausdinti medi" << endl;
        cout << "3 - pasalinti elementa is medzio" << endl;
        cout << "4 - rasti elementa" << endl;
        cout << "5 - perkelti elementus is medzio i dvikrypti ciklini sarsa" << endl;
        cout << "6 - spausdinti sarasa" << endl;
        cout << "7 - baigti programa" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "iveskite koki skaiciu norite iterpti" << endl;
                cin >> num;
                root = treeAddData(root, num);
                cout << "------------------------------" << endl;
                cout << "skaicius " << num << " iterptas" << endl;
                cout << "------------------------------" << endl;
                break;
            case 2:
                printTree(root);
                break;
            case 3:
                cout << "iveskite, koki elementa norite panaikinti" << endl;
                cin >> elemDelete;
                treeRemoveData(root, elemDelete);
                cout << "------------------------------" << endl;
                cout << "elementas " << elemDelete << " pasalintas" << endl;
                cout << "------------------------------" << endl;
                break;
            case 4:
                cout << "iveskite, koki elementa norite rasti" << endl;
                cin >> elemSearch;
                treeFindData(root, elemSearch);
                break;
            case 5:
                moveElementsFromTreeToList(root);
                cout << "------------------------------" << endl;
                cout << "elementai perkelti" << endl;
                cout << "------------------------------" << endl;
                break;
            case 6:
                printLinkedList();
                break;
            case 7:
                cout << "programa baigta" << endl;
                break;
            default:
                cout << "netinkamas pasirinkimas" << endl;
        }
    } while (choice != 7);

    return 0;
}
