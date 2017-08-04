/*********************************************************************
 ** Program name: main.cpp
 ** Author: reuben youngblom
 ** Date: 3/12/17
 ** Description: main function for Lab 9:  queues and Stacks
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;


void placeNumber (int userPlaceFront, int placeRear, queue <int>&);  //function constructor.  Takes in user ints and a queue (more in function definition)



int main() {

    srand (time (NULL));  //seeds random generator

    int selection;  //takes in user selection
    bool selectionBool = true;  //validates user input
    
    cout << "Hello!" << endl;
    
    while (selectionBool == true)  //while user input is valid, pass through this loop
    {
    
    cout << "Would you like to enter Queue or Stack?  Please select 1 for queue or 2 for stack:" << endl;  //user direction
    
    
    cin >> selection;//takes in user chouce
        
    if (selection > 0 && selection < 3)  //validation.  If valid...
        {selectionBool = false;}  //end loop
        
    else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input! Please try again:" << endl;
            cout << endl;
            selectionBool = true;  //loop again
            
        }
    }

    selectionBool = true;  //resets bool
        
    
    switch (selection)  //switch for user-driven menu
    {
        case 1:
        {
    /*************************QUEUE*******************************/
    
    int rounds, placeFront, placeRear, lengthHolder;  //int variables
    int roundNo = 1;  //holds round number
    float averageLength;  //holds average queue length
    
    while (selectionBool == true)  //validation
            {
            
    cout << "How many rounds would you like to run?" << endl;  //user info
    
    cin >> rounds; //takes in user rounds
            
            if (rounds >= 0)  //validation.  If valid...
            {selectionBool = false;}  //end loop
            
            else
            {  //but if not...
                cout << endl;
                cout << "sorry, invalid input! Please try again:" << endl;
                cout << endl;
                selectionBool = true;  //loop again
                
            }
        }
    
    selectionBool = true;  //resets bool
            
    queue <int> randQueue;  //creates queue
    
    randQueue.push (5);
    randQueue.push (85);  //seeds it with three numbers
    randQueue.push (35);
    
    for (int i = 0; i < rounds; i++)  //loops through user-specified number of times
        
    {
        lengthHolder++;  //tracks the round for average formula purposes
        
        cout << endl;
        cout << "Round " << roundNo << endl;  //tracks round for user info purposes (could have combined, but this gives more flexibility later)
        
        roundNo ++;  //adds to round number
        
    cout << endl;
    cout << "How likely should it be that we add a random number to the front of the queue? Please enter a percentage: " << endl;  //user info
    
        
        while (selectionBool == true)  //validation
        {
            
    cin >> placeFront;  //user percentage
        
        if (placeFront >= 0 && placeFront <= 100)  //validation.  If valid...
        {selectionBool = false;}  //end loop
        
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input! Please try again:" << endl;
            cout << endl;
            selectionBool = true;  //loop again
            
        }
    }
        
        selectionBool = true; //resets bool
        
    cout << "How likely should it be that we remove number from the back of the queue? Please enter a percentage: " << endl; //user direction
    
        
        while (selectionBool == true)  //validation
        {
        
    cin >> placeRear;  //takes in user selection
        
    
        if (placeRear >= 0 && placeRear <= 100)  //validation.  If valid...
        {selectionBool = false;}  //end loop
        
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input! Please try again:" << endl;
            cout << endl;
            selectionBool = true;  //loop again
            
        }
    }
    
        selectionBool = true; //resets bool
        
    cout << "Thanks!  Let's send those numbers off..." << endl;  //user info
    
    cout << endl;
        
    placeNumber(placeFront, placeRear, randQueue);  //sends these numbers to function
    
    cout << endl;
        
        
    cout << "Now there are " << randQueue.size () << " ints currently in the queue" << endl;  //user info
        
        double currentLength = randQueue.size();  //creates double to use for average calculation

        
        averageLength = ((averageLength * (lengthHolder - 1)) + currentLength )/lengthHolder;  //calculates running average
        
        cout << endl;
        
        cout << "The average size of the queue has been: " << averageLength << " integers!" << endl;  //prints average for user
        
    
    }
            
            cout << "Thanks!" << endl;  //thanks!!
            break;
        }
    /*************************STACK*******************************/
    
        case 2:
        {
            
    stack <char> palStack;  //creates stack
    
    string palindrome, resultString;  //variables
    
    cout << "Hello!  Please enter a word to turn into a palindrome: " << endl;  //user info
    
    cin >> palindrome;  //takes in word to mirror
    
    cout << "Thanks!" << endl;
    
    for(string::size_type i = 0; i < palindrome.size(); i++)  //iterates though string...
    {
        palStack.push (palindrome[i]);  //and pushes characters into stack
        resultString += palindrome[i];  //and adds to final string
    }
    
    
    
    for (int i=0; i < palindrome.size(); i++)  //then, iterates through again
    {
        resultString += palStack.top();  //and adds characters from the top of the stack to the string
        palStack.pop();  //and removes them.  They're now coming out backwards
        
    }
    
    cout << endl;
    cout << "Thanks! Your palindrome is: " << resultString << endl;  //prints out the resulting palindrome
    
        }
            break;
    }
    
    
    return 0;
}




void placeNumber (int userPlaceFront, int userPlaceRear, queue <int> & passedQueue)  //function for determining whether or not something is queued
{
    int endRandom, chanceFront, chanceRear;  //variables
    
    endRandom = rand() % 999;  //i limited the random number to less than 1,000, simply because larger numbers look unwieldy.

    chanceFront = 0 + rand() % 100;  //creates random number in "percentage" range
    
    if (chanceFront < userPlaceFront)  //if it's less than user percentage (percentage of this happening is exactly user percentage)
    {
         passedQueue.push (endRandom);  //add to queue
    }
    
    
    chanceRear = 0 + rand() % 100;  //generates random percentage in percentage range
    
    if (chanceRear < userPlaceRear) //if it's less than user percentage (percentage of this happening is exactly user percentage)
    {
        
        if (passedQueue.size() > 0)  //and if the queue has more than zero ints in it...
        
        {passedQueue.pop();}  //remove back integer
        
        else  //if there are zero ints in queue....
        {
            cout << endl;
            cout << "There is nothing to pop!  Please add numbers to the queue." << endl;
            cout << endl;  //let user know
        }
    }
    


}
