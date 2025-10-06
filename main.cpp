/*Comsc 210 | Lab 18 | Lawrence Bryant
IDE used: Visual Studio Code*/

#include <iostream>
using namespace std;

//Struct for the linked list node
struct Node {
    float value;
    string review;
    Node *next;
};

//Function prototypes
void addToHead(Node *&, float, string);
void addToTail(Node *&, float, string);
    
//Main function
int main() 
{
    //Variables
    int hot;
    double rating;
    string comment;
    Node *head = nullptr;

    //User input
    cout << "Which linked list method should we use?\n";
    cout << "[1] New nodes are added to the head of each linked list\n";
    cout << "[2] New nodes are added to the tail of each linked list\n";
    cin >> hot;

    //Checks to see if Head or Tail was selected
    while(hot != 1 && hot != 2)
    {
        cout << "Invalid input. Please enter 1 or 2.\n";
        cin >> hot;
    }

    //For nodes being added to the head of the list
    if (hot == 1)
    {
        char adder = 'y';
        while(adder == 'y')
        {
            cout << "Enter review rating 0-5: \n";
            cin >> rating;
            
            //Input validation for rating
            while(rating < 0 || rating > 5)
            {
                cout << "Please enter a rating between 0 and 5.\n";
                cin >> rating;
            }

            cout << "Enter review comment: \n";
            cin >> comment;
            addToHead(head, rating, comment);
            cout << "Enter another review? Y/N: \n";
            cin >> adder;
            adder = tolower(adder);
        }


    }

    //For nodes being added to the tail of the list
    if (hot == 2)
    {
        char adder = 'y';
        while(adder == 'y')
        {
            cout << "Enter review rating 0-5: \n";
            cin >> rating;

            //Input validation for rating
            while(rating < 0 || rating > 5)
            {
                cout << "Please enter a rating between 0 and 5.\n";
                cin >> rating;
            }
            cout << "Enter review comment: \n";
            cin >> comment;
            addToTail(head, rating, comment);
            cout << "Enter another review? Y/N: \n";
            cin >> adder;
            adder = tolower(adder);
        }
        
    }

    //Prints out the linked list
    cout << "Outputting all reviews:\n";
    int i = 1;
    double average;
    for(Node *temp = head; temp != nullptr; temp = temp->next)
    {
        cout << "   > Review #" << i << ": " <<  temp->value << ": " << temp->review << "\n";
        average += temp->value;
        i++;
    }
    average = average / (i - 1);
    cout << "   >Average: " << average << "\n";

    return 0;
}

//Function that adds a new node to the head.
//Takes head pointer by reference for reasons I cannot yet fully grasp
//And a float + string.
void addToHead(Node *&hd, float val, string com) 
{
    Node *newNode = new Node;
    newNode->value = val;
    newNode->review = com;
    newNode->next = hd;
    hd = newNode;
}

//Function that adds a new node to the tail.
void addToTail(Node *&hd, float val, string com)
{
    Node *newNode = new Node;
    newNode->value = val;
    newNode->review = com;
    newNode->next = nullptr;

    if(hd == nullptr)
    {
        hd = newNode;
    }
    else
    {
        Node *temp = hd;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}