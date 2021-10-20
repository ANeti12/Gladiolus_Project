/* ---------------------------------------------
    Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
        above each other.

    Course: CS 141, Fall 2021. Tuesday 3 PM Lab
    System: Mac using CLion
    Author: Abhi Neti

    ASCII Graphic (UIC Flames):
    ------------------------------------------
             /   \
            / / \ \ / \
      / \ / /     \ __   \  __ / \
      \    /            \        /
       \   \              \     /
        \   \ __ __ __ __ __   /
          \ __ __ __ __ __ __ /
    ------------------------------------------
*/
#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.
#include <math.h>     // for fabs, the absolute value function
using namespace std;  // so that we don't need to preface every cin and cout with std::
// Entire program is given inside of main(), which is acceptable since this is the first program.
int main()
{
    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Gladiolus            \n"
    << "Choose from among the following options:  \n"
    << "   1. Display original graphic  \n"
    << "   2. Display Gladiolus         \n"
    << "   3. Exit the program          \n"
    << "Your choice -> ";
    cin >> menuOption;

    // Handle menu option of 3 to exit
    if( menuOption == 3)
    {
        exit( 0);
    }
    // Handle menu option of 1 to display custom ASCII graphics
    else if( menuOption == 1)
    {
        //Display flames
        for (int i = 0; i < 42; i++) //Displays dashes above ASCII art
            {
            cout << "-";
            } //End of for loop
            cout << endl;
        //ASCII art to display UIC flames logo
        cout << setw(8) << " " << " /   \\  \n"
        << "        / / \\ \\ / \\ \n"
        << "  / \\ / /     \\ __   \\  __ / \\ \n"
        << "  \\    /            \\        / \n"
        << "   \\   \\              \\     / \n"
        << "    \\   \\ __ __ __ __ __   / \n"
        << "      \\ __ __ __ __ __ __ /"
        << endl;
        for (int i = 0; i < 42; i++) //Displays dashes below ASCII art
            {
            cout << "-";
            } //End of for loop
            cout << endl;
    }
    else if( menuOption == 2)
    {
        // Prompt for and get the number of flower sections.
        int numberOfSections = 0;
        cout << "Number of sections -> ";
        cin >> numberOfSections;
        // Gladiolus code
        for (int i = 0; i < numberOfSections; i++) //Main for loop that executes for the value of numberOfSections
        {
            cout << setw(numberOfSections + 3) << "---" << endl; //Uses a formula to set the right number of spaces for top dash
            for (int iteration = i; iteration > -i - 1; iteration--)
            {
                cout << setw(numberOfSections - (i - fabs(iteration))) << "(";
                if (iteration == 0)//Special case for the center, prints the '@' symbol
                {
                    cout << setw(2 + i) << "@" << setw(2 + i) << ")";
                }
                else //Clause to print the right parentheses
                {
                    cout << setw(4 + 2 * (-fabs(iteration) + i)) << ")";
                }
                cout << endl;
            }//End of for loop to print rest of flower
        }//End of main for loop
        cout << setw(numberOfSections + 3) << "---" << endl; //Flower portion finished
        for (int i = 1; i < 2 * (numberOfSections) + 1; i++)//For loop for stem, number of dashes is twice the number of sections
        {
            if (i % 2 == 0)//Prints regular stem for all even numbers, special cases below
            {
                cout << setw(numberOfSections + 2) << "|" << endl;
            }
            else
            {
                if (i % 4 == 1)//"/" pattern occurs in pattern 1, 5, 9, etc, this clause prints it for that pattern
                {
                    cout << setw(numberOfSections + 3) << "|/" << endl;
                }
                if (i % 4 == 3)//"\" pattern occurs in pattern 3, 7, 11, etc, this clause prints it for that pattern
                {
                    cout << setw(numberOfSections + 2) << "\\|" << endl;
                }
            }
        }//End of for loop
    }//End of menu option
}//End of program