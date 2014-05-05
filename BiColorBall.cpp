//
//  BiColorBall.cpp
//
//  Created by Muxuezi Tao on 5/5/14.
//  Copyright (c) 2013 Muxuezi Tao. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

//Function Protoypes
void setSeed();                         //This will set the seed for the random numbers
int randomRedNumber();                //This will get a random number 1-33
int randomBlueNumber();                  //This will get a random number 1-16
bool checkArray(int [], int, int);      //This will check to see if a random number has already been found
int displayMenu();                      //This will display the intro menu and let the user buy tickets
int won(int, bool);                     //This function determines how much money a ticket won
//global constants
const int SIZE = 7;                     //This is the number of balls per ticket
const int MAX_Red = 33;               //This is the range of the Red balls
const int MAX_Blue = 16;                 //This is the range of the Blue balls
const int waysToWin = 10;

int main(int argc, const char * argv[])
{
    int tickets = displayMenu();        //Welcome screen lets you buy tickets
    int spending = tickets * 2;         //Charges you for the tickets
    int randomTickets[tickets][SIZE];   //Ticket number holders
    int randomPowerNumber[SIZE];        //Power ball numbers
    int arrayHolder[SIZE];              //Temporary ticket holder
    int ballCounter = 0;                //Keeps track of winning balls in a ticket
    bool BlueBall;                       //Keeps track if the Blue ball matches
    int cashWon = 0;                    //Cash won Accumalator
    int lost = 0;
    int winningTickets[waysToWin];
    setSeed();                          //Sets random seed

    /*
     The next set of instructions will randomly generates the first 6 Red balls and the last ball is the Blue ball
                                Red balls are 1-33 and the Blue ball are 1-16
     */

    cout<<"Powerballs: ";
    for(int i = 0; i<SIZE; i++)
    {
        randomPowerNumber[i] = randomRedNumber();                   //Randomly generates a number 1-33
        while(checkArray(randomPowerNumber, i, randomPowerNumber[i])) //If random number is in use generate another random number
        {
            randomPowerNumber[i] = randomRedNumber();               //Randomly generates a number 1-33
        }
        if(i == (SIZE - 1))                                           //If the increment is the last one it is the Blue ball
        {
            randomPowerNumber[i] = randomBlueNumber();                 //So it generates a number 1-16
        }
        cout<<"["<<randomPowerNumber[i]<<"] ";                        //This displays the number at current increment
    }
    cout<<endl;

    cout<<"Your tickets\n";


    /*
     The following code is a nested loop the first loop indicates the ticket we are at
     the second loop indicates the number we are at in the current ticket.
     The number of tickets is user defined. The main purpose of the code is to generate random numbers
     for a ticket to simulate quick picks.
     */
    for(int i = 0; i < tickets; i++)
    {
        ballCounter = 0;                //This counter keeps track of all the numbers that match the Red power balls
        BlueBall = false;                //This boolean variable keeps track if you have a Blueball match
        for(int j = 0; j < SIZE; j++)
        {
            arrayHolder[j] = randomRedNumber();               //This will generates a random number 1-33 at current location
            while(checkArray(arrayHolder, j, arrayHolder[j]))   //If number generated is in use enter while loop
            {
                arrayHolder[j] = randomRedNumber();           //Generate a random number for current location
            }
            if(j == (SIZE - 1))                                 //If current location is the Blue ball generate a number 1-16
            {
                arrayHolder[j] = randomBlueNumber();
            }else{
                if(checkArray(randomPowerNumber, (SIZE-1), arrayHolder[j]))       //If current number generated is a Red ball
                    ballCounter++;                                         //Check to see if the number is a powerball number if
            }                                                              //it matches increment ball counter
            randomTickets[i][j] = arrayHolder[j];                          //Stores number in ticket
            cout<<"["<<randomTickets[i][j]<<"] ";                          //Display number to screen
        }

        cout<<"\nRedballs match : "<<ballCounter<<" ";     //This displays the number of Red balls that match the powerballs
                                                             //Red balls

        //This checks to see if the tickets Blueball matches the powerballs Blueball
        if(arrayHolder[SIZE - 1] == randomPowerNumber[SIZE-1])
        {
            cout<<"The Blue ball matches too!";
            BlueBall = true;
        }

        cashWon += won(ballCounter, BlueBall);       //This adds the cash won from the ticket to your cash fund


        //The following else if statements just keeps track of how many tickets of each level actually won
        if(ballCounter == 6 && BlueBall)
            winningTickets[0]++;
        else if(ballCounter == 6)
            winningTickets[1]++;
        else if(ballCounter == 5 && BlueBall)
            winningTickets[2]++;
        else if(ballCounter == 5)
            winningTickets[3]++;
        else if(ballCounter == 4 && BlueBall)
            winningTickets[4]++;
        else if(ballCounter == 4)
            winningTickets[5]++;
        else if(ballCounter == 3 && BlueBall)
            winningTickets[6]++;
        else if(ballCounter == 2 && BlueBall)
            winningTickets[7]++;
        else if(ballCounter == 1 && BlueBall)
            winningTickets[8]++;
        else if(BlueBall)
            winningTickets[9]++;
        else
            lost++;
        cout<<endl;
    }
    //The folling code outputs to the user the number of tickets that won and display the number of losing tickets
    cout<<"You have "<<winningTickets[0]<<" tickets that is a grand prize winner"<<endl;
    cout<<"You have "<<winningTickets[1]<<" tickets winning percent 25% of grand prize"<<endl;
    cout<<"You have "<<winningTickets[2]<<" tickets winning RMB 3,000"<<endl;
    cout<<"You have "<<winningTickets[3] + winningTickets[4]<<" tickets winning RMB 200"<<endl;
    cout<<"You have "<<winningTickets[5] + winningTickets[6]<<" tickets winning RMB 10"<<endl;
    cout<<"You have "<<winningTickets[7] + winningTickets[8] + winningTickets[9]<<" tickets winning RMB 5"<<endl;
    cout<<"You have "<<lost<<" losing tickets"<<endl;

    //The following code outputs how much money you spent and how much money you won
    cout<<"You spent RMB "<<spending<<endl;
    cout<<"You won RMB "<<cashWon<<endl;
}

/****************************************************************************
 *                          displayMenu()                                   *
 *    The displayMenu function outputs intro menu to screen and it allows   *
 *    The user to buy 1 to 20000 tickets                                   *
 ***************************************************************************/
int displayMenu()
{
    int tickets;
    cout<<"Powerball Simulator\n";
    cout<<"6 Red Balls will be random generated and the last ball is Blue\n";
    cout<<"Each ticket cost RMB 2\nEnter how many ticket will you like to buy: ";
    cin>>tickets;

    while((tickets <= 0 || tickets > 20000))
    {
        cout<<"Please enter a number between 1-20000: ";
        cin>>tickets;
    }
    return tickets;
}

/****************************************************************************
 *                          setSeed()                                       *
 *    The set Seed function sets the seed for the rand function             *
 ***************************************************************************/

void setSeed()
{
    long seed;
    seed = time(0);
    unsigned int sseed = static_cast<unsigned int>(seed);
    srand(sseed);
}

/****************************************************************************
 *                          randomRedNumber()                             *
 *    The function will generate a number 1-33 and return the number        *
 ***************************************************************************/

int randomRedNumber()
{
    int randomVar = (rand() % MAX_Red)+1;
    return randomVar;
}

/****************************************************************************
 *                          randomBlueNumber()                               *
 *    The function will generate a number 1-16 and return the number        *
 ***************************************************************************/
int randomBlueNumber()
{
    int randomVar = (rand() % MAX_Blue)+1;
    return randomVar;
}

/****************************************************************************
 *                              checkArray()                                *
 *    This function will search through array[] for a number if  the number *
 *    is found then return true if it is not found return false             *
 ***************************************************************************/
bool checkArray(int array[], int size, int number)
{
    bool has = false;
    for(int i = 0; i< size; i++)
    {
        if(array[i] == number)
        {
            has = true;
        }
    }
    return has;
}
/****************************************************************************
 *                              won()                                       *
 *    This functions compare the number of balls that match in a ticket     *
 *    and returns the amount of cash the ticket is worth                    *
 ***************************************************************************/
int won(int ballCount, bool BlueBall)
{
    int cash = 0;
    switch(ballCount)
    {
        case 6:
            if(BlueBall)
                cash = 10000000;
            else
                cash = 2500000;
            break;
        case 5:
            if(BlueBall)
                cash = 3000;
            else
                cash = 200;
            break;
        case 4:
            if(BlueBall)
                cash = 200;
            else
                cash = 10;
            break;
        case 3:
            if(BlueBall)
                cash = 10;
            else
                cash = 0;
            break;
        case 2:
            if(BlueBall)
                cash = 5;
            else
                cash = 0;
            break;
        case 1:
            if(BlueBall)
                cash = 5;
            else
                cash = 0;
            break;
        default:
            if(BlueBall)
                cash = 5;
            else
                cash =0;
            break;
    }
    return cash;
}
