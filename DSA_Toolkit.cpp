#include <iostream>
#include<conio.h>
#include<string>
#include <queue>
#include <stack>
using namespace std;
class LinkedList {
	struct Node {
	    int data;
	    Node* next;
	};
    private:
        Node* head;
    public:
        LinkedList() {
            head = NULL;
        }

        // Function to insert a new node at the beginning of the linked list
        void insertNode(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            cout << "Node with value " << value << " inserted at the beginning." << endl;
            getch();
        }

        // Function to delete a node with the given value from the linked list
        void deleteNode(int value) {
            if (head == NULL) {
                cout << "The linked list is empty. Unable to delete." << endl;
                return;
            }

            if (head->data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                cout << "Node with value " << value << " deleted." << endl;
                return;
            }

            Node* currentNode = head;
            while (currentNode->next != NULL) {
                if (currentNode->next->data == value) {
                    Node* temp = currentNode->next;
                    currentNode->next = temp->next;
                    delete temp;
                    cout << "Node with value " << value << " deleted." << endl;
                    return;
                }
                currentNode = currentNode->next;
            }

            cout << "Node with value " << value << " not found in the linked list." << endl;
        }

        // Function to sort the linked list in ascending order
        void sortList() {
            if (head == NULL) {
                cout << "The linked list is empty. Unable to perform sort." << endl;
                return;
            }

            Node* currentNode = head;
            while (currentNode != NULL) {
                Node* temp = currentNode->next;
                while (temp != NULL) {
                    if (currentNode->data > temp->data) {
                        int swap = currentNode->data;
                        currentNode->data = temp->data;
                        temp->data = swap;
                    }
                    temp = temp->next;
                }
                currentNode = currentNode->next;
            }

            cout << "Linked list sorted in ascending order." << endl;
        }

        // Function to search for a value in the linked list
        void searchValue(int value) {
            if (head == NULL) {
                cout << "The linked list is empty. Unable to perform search." << endl;
                return;
            }

            Node* currentNode = head;
            int count = 0;
            while (currentNode != NULL) {
                if (currentNode->data == value) {
                    cout << "Value " << value << " found at index " << count << "." << endl;
                    return;
                }
                currentNode = currentNode->next;
                count++;
            }

            cout << "Value " << value << " not found in the linked list." << endl;
        }

        // Function to print the linked list
        void printList() {
            if (head == NULL) {
                cout << "The linked list is empty." << endl;
                return;
            }

            Node* currentNode = head;
            cout << "Linked List: ";
            while (currentNode != NULL) {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
            getch();
        }
public:
void singlylinkedlist() {
    LinkedList list;
    int choice, value;

    do {
    	system("cls");
        cout << "\n---- Singly Linked List Operations ----" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Sort List" << endl;
        cout << "4. Search Value" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertNode(value);
                
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.sortList();
                break;

            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                list.searchValue(value);
                break;

            case 5:
                list.printList();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option (1-6)." << endl;
                break;
        }
    } while(choice != 6);

}

};

// Doubly Linked List Node


// Class for Doubly Linked List operations
class DoublyLinkedList {
	
    struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
	};
	
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
        cout << "Node inserted successfully at the beginning." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            cout << "Node inserted successfully at the end." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Node inserted successfully at the end." << endl;
    }

    // Function to delete a node from the list
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is already empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {
                if (temp->prev == NULL) {
                    head = temp->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                }

                delete temp;
                cout << "Node deleted successfully." << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Node not found." << endl;
    }

    // Function to search for a node in the list
    void searchNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Node found in the list." << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Node not found in the list." << endl;
    }

    // Function to display all elements of the list
    void displayList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

public:
	void doubles() {
	    DoublyLinkedList list;
	    int choice, value;
	
	    do {
	    	system("cls");
	        cout << "----- Doubly Linked List Program -----" << endl;
	        cout << "1. Insert Node at the Beginning" << endl;
	        cout << "2. Insert Node at the End" << endl;
	        cout << "3. Delete Node" << endl;
	        cout << "4. Search Node" << endl;
	        cout << "5. Display List" << endl;
	        cout << "6. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        switch(choice) {
	            case 1:
	                cout << "Enter value to be inserted at the beginning: ";
	                cin >> value;
	                list.insertAtBeginning(value);
	                break;
	            case 2:
	                cout << "Enter value to be inserted at the end: ";
	                cin >> value;
	                list.insertAtEnd(value);
	                break;
	            case 3:
	                cout << "Enter value to be deleted: ";
	                cin >> value;
	                list.deleteNode(value);
	                break;
	            case 4:
	                cout << "Enter value to be searched: ";
	                cin >> value;
	                list.searchNode(value);
	                break;
	            case 5:
	                list.displayList();
	                break;
	            case 6:
	                cout << "Exiting the program." << endl;
	                break;
	            default:
	                cout << "Invalid choice. Please enter a valid option." << endl;
	        }
	    } while(choice != 6);
	}
};

// Class for circular linked list

class CircularLinkedList {
private:
    struct Node {
        int data;
        struct Node* next;
    };
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;

        if (head != NULL) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        } else {
            newNode->next = newNode; // Point to itself for the first node
        }

        head = newNode;
        cout << "Node inserted successfully at the beginning." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;

        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Point to itself for the first node
            cout << "Node inserted successfully at the end." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        cout << "Node inserted successfully at the end." << endl;
    }

    // Function to delete a node from the list
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        do {
            if (current->data == value) {
                if (prev == NULL) {
                    if (current->next == head) {
                        head = NULL;
                    } else {
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = current->next;
                        head = current->next;
                    }
                } else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Node deleted successfully." << endl;
                return;
            }

            prev = current;
            current = current->next;

        } while (current != head);

        cout << "Node not found." << endl;
    }

    // Function to search for a node in the list
    void searchNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == value) {
                cout << "Node found in the list." << endl;
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Node not found in the list." << endl;
    }

    // Function to display all elements of the list
    void displayList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

public:
    void circulars() {
        CircularLinkedList list;
        int choice, value;

        do {
        	system("cls");
            cout << "----- Circular Linked List Program -----" << endl;
            cout << "1. Insert Node at the Beginning" << endl;
            cout << "2. Insert Node at the End" << endl;
            cout << "3. Delete Node" << endl;
            cout << "4. Search Node" << endl;
            cout << "5. Display List" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to be inserted at the beginning: ";
                    cin >> value;
                    list.insertAtBeginning(value);
                    break;
                case 2:
                    cout << "Enter value to be inserted at the end: ";
                    cin >> value;
                    list.insertAtEnd(value);
                    break;
                case 3:
                    cout << "Enter value to be deleted: ";
                    cin >> value;
                    list.deleteNode(value);
                    break;
                case 4:
                    cout << "Enter value to be searched: ";
                    cin >> value;
                    list.searchNode(value);
                    break;
                case 5:
                    list.displayList();
                    break;
                case 6:
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option." << endl;
            }
        } while (choice != 6);
    }
};

//Queue Class

class Queue{
	
	void enqueue(queue<int>& q) {
	    int value;
	    cout << "Enter a value to enqueue: ";
	    cin >> value;
	    q.push(value);
	    cout << value << " has been enqueued." << endl;
	    getch();
	}
	
	void dequeue(queue<int>& q) {
	    if (!q.empty()) {
	        int value = q.front();
	        q.pop();
	        cout << value << " has been dequeued." << endl;
	    } else {
	        cout << "Queue is empty. Cannot dequeue." << endl;
	    }
	    getch();
	}
	
	void display(queue<int> q) {
	    if (!q.empty()) {
	        cout << "Elements in the queue: ";
	        while (!q.empty()) {
	            cout << q.front() << " ";
	            q.pop();
	        }
	        cout << endl;
	    } else {
	        cout << "Queue is empty." << endl;
	    }
	    getch();
	}
	
public:
	void queues() {
	    queue<int> q;
	
	    int choice;
	    do {
	    	system("cls");
	        cout << "\n---- Queue Operations ----" << endl;
	        cout << "1. Enqueue" << endl;
	        cout << "2. Dequeue" << endl;
	        cout << "3. Display" << endl;
	        cout << "4. Exit" << endl;
	        cout << "\nEnter your choice (1-4): ";
	        cin >> choice;
	
	        switch (choice) {
	            case 1:
	                enqueue(q);
	                break;
	            case 2:
	                dequeue(q);
	                break;
	            case 3:
	                display(q);
	                break;
	            case 4:
	                system("cls");
	                break;
	            default:
	                cout << "Invalid choice. Please enter a valid choice." << endl;
	                getch();
	        }
	    } while (choice != 4);
	
	}
};

//Stack Class

// Function to push an element into the stack
class Stack{
void pushElement(stack<int>& stackObj) {
    int value;
    cout << "Enter a value to push: ";
    cin >> value;
    stackObj.push(value);
    cout << "Element successfully pushed into the stack." << endl;
    getch();
}

// Function to pop an element from the stack
void popElement(stack<int>& stackObj) {
    if (stackObj.empty()) {
        cout << "Stack is empty. Cannot perform pop operation." << endl;
        return;
    }
    cout << "Popped element: " << stackObj.top() << endl;
    stackObj.pop();
    getch();
}

// Function to display the top element of the stack
void peekElement(stack<int>& stackObj) {
    if (stackObj.empty()) {
        cout << "Stack is empty. Cannot peek." << endl;
        getch();
        return;
    }
    cout << "Top element: " << stackObj.top() << endl;
    getch();
}

// Function to display the entire contents of the stack
void displayStack(stack<int>& stackObj) {
    if (stackObj.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack contents: ";
    stack<int> tempStack = stackObj;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
    getch();
}
public:
	void stacks() {
	    stack<int> stackObj;
	    int choice;
	
	    do {
	    	system("cls");
	        cout << "\nStack Operations Menu:" << endl;
	        cout << "------------------------" << endl;
	        cout << "1. Push element into stack" << endl;
	        cout << "2. Pop element from stack" << endl;
	        cout << "3. Peek top element in stack" << endl;
	        cout << "4. Display stack contents" << endl;
	        cout << "5. Exit" << endl;
	        cout << "Enter your choice (1-5): ";
	        cin >> choice;
	
	        switch (choice) {
	            case 1:
	                pushElement(stackObj);
	                break;
	            case 2:
	                popElement(stackObj);
	                break;
	            case 3:
	                peekElement(stackObj);
	                break;
	            case 4:
	                displayStack(stackObj);
	                break;
	            case 5:
	                system("cls");
	                break;
	            default:
	                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
	                getch();
	        }
	    } while (choice != 5);
	}
};


    class Array{
	void displayArray(int arr[], int size) {
	    cout << "Array elements: ";
	    for (int i = 0; i < size; i++) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    getch();
	}
	
	void findMax(int arr[], int size) {
	    int max = arr[0];
	    for (int i = 1; i < size; i++) {
	        if (arr[i] > max) {
	            max = arr[i];
	        }
	    }
	    cout << "Max element: " << max << endl;
	    getch();
	}
	
	void findMin(int arr[], int size) {
	    int min = arr[0];
	    for (int i = 1; i < size; i++) {
	        if (arr[i] < min) {
	            min = arr[i];
	        }
	    }
	    cout << "Min element: " << min << endl;
	    getch();
	}
	
	float calculateAverage(int arr[], int size) {
	    int sum = 0;
	    for (int i = 0; i < size; i++) {
	        sum += arr[i];
	    }
	    return static_cast<float>(sum) / size;
	}
	public:
	void arrays() {
	    int arr[100];
	    int size, choice;
	
	    cout << "Enter the size of the array: ";
	    cin >> size;
	
	    cout << "Enter the elements of the array: ";
	    for (int i = 0; i < size; i++) {
	        cin >> arr[i];
	    }
		
		do{
			
		    cout << "\nAvailable Functions:\n";
		    cout << "1. Display Array";
		    cout << "\n2. Find Maximum Element";
		    cout << "\n3. Find Minimum Element";
		    cout << "\n4. Calculate Average";
		    cout << "\n5. Exit";
		
		    cout << "\nEnter your choice (1-4): ";
		    cin >> choice;
		
		    switch (choice) {
		        case 1:
		            displayArray(arr, size);
		            system("cls");
		            break;
		        case 2:
		            findMax(arr, size);
		            system("cls");
		            break;
		        case 3:
		            findMin(arr, size);
		            system("cls");
		            break;
		        case 4:
		            cout << "Average: " << calculateAverage(arr, size) << endl;
		            getch();
		            system("cls");
		            break;
		        case 5:
		        	system("cls");
		        	break;
		        default:
		            cout << "Invalid choice!" << endl;
		    }
		}while(choice!=5);
	}
};


class Pointer{
	
	void swap(int* a, int* b) {
	    int temp = *a;
	    *a = *b;
	    *b = temp;
	}
	
	void increment(int* num) {
	    (*num)++;
	}
	
	bool isPositive(int* num) {
	    if (*num >= 0)
	        return true;
	    return false;
	}
	
	bool isNegative(int* num) {
	    if (*num < 0)
	        return true;
	    return false;
	}
	
public:
	void point() {
	    int option, num1, num2, num;
	
	    do{
	    	system("cls");
	        cout << "Choose an option: " << endl;
	        cout << "1. Swap numbers" << endl;
	        cout << "2. Increment a number" << endl;
	        cout << "3. Check if a number is positive" << endl;
	        cout << "4. Check if a number is negative" << endl;
	        cout << "5. Exit" << endl;
	        cin >> option;
	
	        switch (option) {
	            case 1:
	                cout << "Enter the first number: ";
	                cin >> num1;
	                cout << "Enter the second number: ";
	                cin >> num2;
	                swap(&num1, &num2);
	                cout << "After swapping, num1 = " << num1 << " and num2 = " << num2 << endl;
	                getch();
	                break;
	
	            case 2:
	                cout << "Enter a number: ";
	                cin >> num;
	                increment(&num);
	                cout << "After incrementing, num = " << num << endl;
	                getch();
	                break;
	
	            case 3:
	                cout << "Enter a number: ";
	                cin >> num;
	                if (isPositive(&num))
	                    cout << "The number is positive" << endl;
	                else
	                    cout << "The number is not positive" << endl;
	                getch();
	                break;
	
	            case 4:
	                cout << "Enter a number: ";
	                cin >> num;
	                if (isNegative(&num))
	                    cout << "The number is negative" << endl;
	                else
	                    cout << "The number is not negative" << endl;
	                getch();
	                break;
	
	            case 5:
	                system("cls");
	                break;
	
	            default:
	                cout << "Invalid option! Please try again." << endl;
	        }
	        cout << endl;
	    }while(option!=5);
	
	}
};


class Structure{
	
	struct Student {
	    string name;
	    int rollNumber;
	    float gpa;
	};

	void addStudent(Student students[], int& numStudents) {
		system("cls");
	    if (numStudents == 10) {
	        cout << "Max limit reached. Cannot add more students.\n";
	        return;
	    }
	
	    cout << "\nEnter student details:\n";
	    cout << "Name: ";
	    cin >> students[numStudents].name;
	    cout << "Roll Number: ";
	    cin >> students[numStudents].rollNumber;
	    cout << "GPA: ";
	    cin >> students[numStudents].gpa;
	
	    numStudents++;
	    cout << "Student added successfully.\n";
	    getch();
	}
	
	void displayStudents(Student students[], int numStudents) {
		system("cls");
	    if (numStudents == 0) {
	        cout << "No students found.\n";
	        getch();
	        return;
	    }
	
	    cout << "\nStudent Database:\n";
	    for (int i = 0; i < numStudents; i++) {
	        cout << "Name: " << students[i].name << endl;
	        cout << "Roll Number: " << students[i].rollNumber << endl;
	        cout << "GPA: " << students[i].gpa << endl;
	        cout << "------------------------\n";
	    }
	    getch();
	}
	
	void searchStudent(Student students[], int numStudents, int rollNumber) {
		system("cls");
	    bool found = false;
	    for (int i = 0; i < numStudents; i++) {
	        if (students[i].rollNumber == rollNumber) {
	            cout << "\nStudent found:\n";
	            cout << "Name: " << students[i].name << endl;
	            cout << "Roll Number: " << students[i].rollNumber << endl;
	            cout << "GPA: " << students[i].gpa << endl;
	            found = true;
	            break;
	        }
	    }
	
	    if (!found) {
	        cout << "\nStudent not found.\n";
	    }
	    getch();
	}
	
public:
	void structures() {
	    Student students[10];
	    int numStudents = 0;
	
	    int choice;
	    int searchRollNumber;
	
	    do {
	    	system("cls");
	        cout << "\n----- Student Database Menu -----\n";
	        cout << "1. Add Student\n";
	        cout << "2. Display Students\n";
	        cout << "3. Search Student\n";
	        cout << "4. Exit\n";
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        switch(choice) {
	            case 1:
	                addStudent(students, numStudents);
	                break;
	            case 2:
	                displayStudents(students, numStudents);
	                break;
	            case 3:
	                cout << "\nEnter roll number to search: ";
	                cin >> searchRollNumber;
	                searchStudent(students, numStudents, searchRollNumber);
	                break;
	            case 4:
	                system("cls");
	                break;
	            default:
	                cout << "\nInvalid choice. Please try again.\n";
	                break;
	        }
	    } while (choice != 4);
	}
};
class ListSelection{
    public:
    void fulllink(LinkedList a,DoublyLinkedList b,CircularLinkedList cir){
    	int var;
    	bool value = 1;
    	system("cls");
    	do{
			cout<<"\nSelect type of linked list:\n"<<endl;
			cout<<"1-Single linked list"<<endl;
			cout<<"2-Double linked list"<<endl;
			cout<<"3-Circular linked list"<<endl;
			cout<<"4-Exit"<<endl;
			cout<<"\nChoose one of them: "<<endl;
			cin>>var;
			switch(var){
			case 1:
				a.singlylinkedlist();
				system("cls");
			    break;
			case 2:
				b.doubles();
				system("cls");
			    break;
			case 3:
				cir.circulars();
				system("cls");
				break;
			case 4:
				system("cls");
				return;
				break;	
			default:
			    cout << "\nInvalid choice. Please try again.\n";
			    getch();
			    system("cls");
			    break;
			}
		}while(var!=1||var!=2||var!=3);
		system("cls");
	}
};

class Sorting{
	
	// Function to print the array
	void printArray(int arr[], int size) {
	    for (int i = 0; i < size; i++) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	
	// Function to swap two elements in an array
	void swap1(int* a, int* b) {
	    int temp = *a;
	    *a = *b;
	    *b = temp;
	}
	
	// Bubble Sort
	void bubbleSort(int arr[], int size) {
	    for (int i = 0; i < size - 1; i++) {
	        for (int j = 0; j < size - i - 1; j++) {
	            if (arr[j] > arr[j + 1]) {
	                swap1(&arr[j], &arr[j + 1]);
	            }
	        }
	    }
	}
	
	void merge(int arr[], int left, int middle, int right) {
	    int n1 = middle - left + 1;
	    int n2 = right - middle;
	
	    int L[n1], R[n2];
	
	    for (int i = 0; i < n1; i++) {
	        L[i] = arr[left + i];
	    }
	
	    for (int j = 0; j < n2; j++) {
	        R[j] = arr[middle + 1 + j];
	    }
	
	    int i = 0;
	    int j = 0;
	    int k = left;
	
	    while (i < n1 && j < n2) {
	        if (L[i] <= R[j]) {
	            arr[k] = L[i];
	            i++;
	        }
	        else {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	
	    while (i < n1) {
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2) {
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	
	void mergeSort(int arr[], int left, int right) {
	    if (left < right) {
	        int middle = left + (right - left) / 2;
	
	        mergeSort(arr, left, middle);
	        mergeSort(arr, middle + 1, right);
	
	        merge(arr, left, middle, right);
	    }
	}
	void selectionSort(int arr[], int size) {
	    for (int i = 0; i < size - 1; i++) {
	        int minIndex = i;
	        for (int j = i + 1; j < size; j++) {
	            if (arr[j] < arr[minIndex]) {
	                minIndex = j;
	            }
	        }
	        swap1(&arr[minIndex], &arr[i]);
	    }
	}
	
	void insertionSort(int arr[], int n) {
	    for (int i = 1; i < n; ++i) {
	        int key = arr[i];
	        int j = i - 1;
	
	        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
	        while (j >= 0 && arr[j] > key) {
	            arr[j + 1] = arr[j];
	            j = j - 1;
	        }
	        arr[j + 1] = key;
	    }
	}
	
	// Function to partition the array into two halves and return the pivot index
	int partition(int arr[], int low, int high) {
	    int pivot = arr[high];  // Choose the rightmost element as the pivot
	    int i = low - 1;        // Index of the smaller element
	
	    for (int j = low; j <= high - 1; j++) {
	        // If the current element is smaller than or equal to the pivot
	        if (arr[j] <= pivot) {
	            i++;
	            std::swap(arr[i], arr[j]);
	        }
	    }
	
	    // Swap the pivot element with the element at (i + 1), placing the pivot in its correct position
	    swap(arr[i + 1], arr[high]);
	
	    return i + 1;
	}
	
	// Function to perform Quick Sort recursively
	void quickSort(int arr[], int low, int high) {
	    if (low < high) {
	        // Partition the array and get the pivot index
	        int pivotIndex = partition(arr, low, high);
	
	        // Recursively sort the subarrays on both sides of the pivot
	        quickSort(arr, low, pivotIndex - 1);
	        quickSort(arr, pivotIndex + 1, high);
	    }
	}

public:
	void sorting() {
	    int size;
	    cout << "Enter the size of the array: ";
	    cin >> size;
	
	    int arr[size];
	    cout << "Enter the array elements: ";
	    for (int i = 0; i < size; i++) {
	        cin >> arr[i];
	    }
	
	    int choice;
	
		do{
			system("cls");
		    cout << "\nSelect a sorting technique:" << endl;
		    cout << "1. Bubble Sort" << endl;
		    cout << "2. Merge Sort" << endl;
		    cout << "3. Selection Sort" << endl;
		    cout << "4. Insertion Sort" << endl;
		    cout << "5. Quick Sort" << endl;
		    cout << "6. EXIT "<<endl;
		    cout << "Enter your choice: ";
		    cin >> choice;
		
		
		    switch (choice) {
		        case 1:
		            cout << "\nArray before Bubble Sort: ";
		            printArray(arr, size);
		            bubbleSort(arr, size);
		            cout << "\nArray after Bubble Sort: ";
		            printArray(arr, size);
		            getch();
		            break;
		
		        case 2:
		            cout << "\nArray before Merge Sort: ";
		            printArray(arr, size);
		            mergeSort(arr, 0, size - 1);
		            cout << "\nArray after Merge Sort: ";
		            printArray(arr, size);
					getch();
		            break;
		
		        case 3:
		        	cout << "\nArray before Selection Sort: ";
		            printArray(arr, size);
		            selectionSort(arr, size);
		            cout << "\nArray after Selection Sort: ";
		            printArray(arr, size);
					getch();
		            break;
				
				case 4:
					cout << "\nArray before Insertion Sort: ";
		            printArray(arr, size);
		            insertionSort(arr,size);
		            cout << "\nArray after Insertion Sort: ";
		            printArray(arr, size);
		            getch();
					break;
				
				case 5:
					cout << "\nArray before Quick Sort: ";
		            printArray(arr, size);
					quickSort(arr, 0, size - 1);
					cout << "\nArray after Quick Sort: ";
		            printArray(arr, size);
		            getch();
					break;
				
				case 6:
					system("cls");
					break;
				
		        default:
		            cout << "Invalid choice!";
		            getch();
		            break;
		    }
		} while (choice != 6);
	}
};

int main(){

     LinkedList a;
     DoublyLinkedList b;
     CircularLinkedList cir;
     Queue c;
     Stack d;
     Array e;
     Pointer f;
     Structure g;
     ListSelection l;
     Sorting j;


int choice;

    do {
    	system("cls");
    	cout<<"\n\t\t\t\t\t*********************************"<<endl;
        cout<<"\n\t\t\t\t\t\tSUBMITTED BY :\n"<<endl;
        cout<<"\t\t\t\t\tM Saif Ali Shah"<<"\t"<<endl;
        cout<<"\n\t\t\t\t\tCourse:"<<"\t"<<"DATA STRUCTURES AND ALGORITHMS"<<endl;
        cout<<"\n\t\t\t\t\tProject Title:"<<"\t"<<"DSA TOOLKIT"<<endl;
        cout<<"\n\t\t\t\t\tSubmitted to : MAM ANUM HAFEEZ"<<endl;
        cout<<"\n\t\t\t\t\t*********************************"<<endl;

        cout<<"\n\t\t\t\t\t1. Linked List";
        cout<<"\n\t\t\t\t\t2. Queue";
        cout<<"\n\t\t\t\t\t3. Stack";
        cout<<"\n\t\t\t\t\t4. Array";
        cout<<"\n\t\t\t\t\t5. Pointers";
        cout<<"\n\t\t\t\t\t6. Structures";
        cout<<"\n\t\t\t\t\t7. Sorting";
        cout<<"\n\t\t\t\t\t8. Exit";

        cout<<"\n\t\t\t\t\tEnter your choice: ";
        cin>>choice;
		system("cls");

        switch(choice) {
            case 1:
                l.fulllink(a, b, cir);
                break;
            case 2:
                c.queues();
                break;
            case 3:
                d.stacks();
                break;
            case 4:
                e.arrays();
                break;
            case 5:
                f.point();
                break;
            case 6:
                g.structures();
                break;
            case 7:
        		j.sorting();
        		break;
        	case 8:
        		system("cls");
        		cout<<"\n\t\t\t\tExiting the system...\n";
        		break;
        	default:
        		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Invalid choice! Retry";
        		getch();
        }
        
    }while(choice != 8);

    return 0;
}
