/*Comsc 210 | Lab 18 | Lawrence Bryant
IDE used: Visual Studio Code*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Struct for the linked list node
struct Node {
    float value;
    string review;
    Node *next;
};

class Movie
{

    private:
    Node *head;
    string title;

};

//Function prototypes
void addToHead(Node *&, float, string);
void addToTail(Node *&, float, string);
    
//Main function
int main() 
{
    //Variables
    Movie movie[4];
    int hot;
    double rating;
    string comment;
    Node *head = nullptr;

    ifstream fin("Test.txt");
    if(fin.good())
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