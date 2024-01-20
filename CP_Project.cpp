/*
Computer Programming Project by:
Muhammad Hunain
Roshan Sheikh
Ali Ahmed Farooqui
*/

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};
Node* createNode(int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void display(Node* head) {
  Node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}
void insert_begin(Node*& head, int data) {
  Node* newNode = createNode(data);
  newNode->next = head;
  head = newNode;
}

void insert_end(Node*& head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void insert_at(Node*& head, int data, int position) {
  if (position <= 0) {
    insert_begin(head, data);
  } else {
    Node* newNode = createNode(data);
    Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) {
      current = current->next;
      currentPosition++;
    }
    if (current != NULL) {
      newNode->next = current->next;
      current->next = newNode;
    } else {
      cout << "Invalid position." << endl;
    }
  }
}

void delete_begin(Node*& head) {
  if (head == NULL) {
    cout << "Linked list is empty." << endl;
  } else {
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted first element." << endl;
  }
}

void delete_end(Node*& head) {
  if (head == NULL) {
    cout << "Linked list is empty." << endl;
  } else if (head->next == NULL) {
    delete head;
    head = NULL;
    cout << "Deleted the only element." << endl;
  } else {
    Node* current = head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    delete current->next;
    current->next = NULL;
    cout << "Deleted last element." << endl;
  }
}

void delete_at(Node*& head, int position) {
  if (head == NULL) {
    cout << "Linked list is empty." << endl;
  } else if (position <= 0) {
    delete_begin(head);
  } else {
    Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) {
      current = current->next;
      currentPosition++;
    }
    if (current != NULL && current->next != NULL) {
      Node* temp = current->next;
      current->next = temp->next;
      delete temp;
      cout << "Deleted element at position " << position << "." << endl;
    } else {
      cout << "Invalid position. Deletion failed." << endl;
    }
  }
}

void delete_data(Node*& head, int data) {
  if (head == NULL) {
    cout << "Linked list is empty." << endl;
  } else if (head->data == data) {
    delete_begin(head);
  } else {
    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
      current = current->next;
    }
    if (current->next != NULL) {
      Node* temp = current->next;
      current->next = temp->next;
      delete temp;
      cout << "Deleted element with data " << data << "." << endl;
    } else {
      cout << "Data not found. Deletion failed." << endl;
    }
  }
}

Node* search(Node* head, int data) {
  Node* current = head;
  while (current != NULL && current->data != data) {
    current = current->next;
  }
  return current;
}

int main() {
  Node* head = NULL;
  int choice;
  while (true) {
    cout << "Linked List Operations:" << endl;
    cout << "1. Display" << endl;
    cout << "2. Insert at the beginning" << endl;
    cout << "3. Insert at the end" << endl;
    cout << "4. Insert at position" << endl;
    cout << "5. Delete at the beginning" << endl;
    cout << "6. Delete at the end" << endl;
    cout << "7. Delete at position" << endl;
    cout << "8. Delete specific data" << endl;
    cout << "9. Search" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 0:
        cout << "Exiting..." << endl;
        return 0;
      case 1:
        cout << "Linked List: ";
        display(head);
        break;
      case 2: {
        int data;
        cout << "Enter data to insert at the beginning: ";
        cin >> data;
        insert_begin(head, data);
        cout << "Data inserted...." << endl;
        break;
      }
      case 3: {
        int data;
        cout << "Enter data to insert at the end: ";
        cin >> data;
        insert_end(head, data);
        cout << "Data inserted At end...." << endl;
        break;
      }
      case 4: {
        int data, position;
        cout << "Enter data to insert: ";
        cin >> data;
        cout << "Enter position to insert at: ";
        cin >> position;
        insert_at(head, data, position);
        cout << "Data inserted At Position :" << position << endl;
        break;
      }
      case 5:
        delete_begin(head);
        cout << "Data Deleted From Begining..." << endl;
        break;
      case 6:
        delete_end(head);
        cout << "Data Deleted From End..." << endl;
        break;
      case 7: {
        int position;
        cout << "Enter position to delete: ";
        cin >> position;
        delete_at(head, position);
        cout << "Data Deleted At Position :" << position << endl;
        break;
      }
      case 8: {
        int data;
        cout << "Enter data to delete: ";
        cin >> data;
        delete_data(head, data);
        cout << "Data Deleted Successfully!" << endl;
        break;
      }
      case 9: {
        int data;
        cout << "Enter data to search: ";
        cin >> data;
        Node* result = search(head, data);
        if (result != 0) {
          cout << "Data found at address " << result << endl;
        } else {
          cout << "Data not found." << endl;
        }
        break;
      }
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }
}

