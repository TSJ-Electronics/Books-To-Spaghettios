/*
Spaghettios To Books Converter
By: TSJ_Electronics
October 2, 2022
TSJelectronics.com
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>


using namespace std;
int main()
{
    
    /* ######### Program Setup ######### */
    
    // element 0 = a, element 25 = z
    int alphabetCharacterCount[26] = { 0 };

    //Starting ascii code for 'a' = 97
    int ascii_A = 97; 

    //Name of book, this is used for printing to console
    string bookName = "Bible";

    //initialize array, element 0 = number of letter 'a' in can of alphabet spaghettios, element 25 = z
    //int charactersPerCanOfSpaghettios[26] = { 25,25,26,40,23,25,24,38,39,35,43,29,33,30,387,26,34,34,43,41,41,17,15,24,38,41 };// actual count of 1 can DONT DELETE
    int charactersPerCanOfSpaghettios[26] = { 27,28,29,26,32,31,28,26,28,30,39,32,27,25,441,35,26,37,30,31,28,25,31,28,26,36 };// average of 5 cans

    char ch;

    //Holds percent occurence of a single character in a book.
    double percentOccurence = 0.00;

    int totalLettersInBook = 0;

    int totalLettersInCan = 0;

    int cansNeededForBook = 1; //you need at least 1 can to do anything.

    /* ######### Can Of Spaghettios Info ######### */

    int caloriesInCan = 280;

    int canWeightInGrams = 448;

    double heightInInches = 4.25;

    double widthInInches = 3.125;

    /* ######### Read Chars In Book ######### */

    //Path to file to read
    ifstream fin("C:\\Users\\Tyler\\Desktop\\Bible.txt");

    while (fin >> noskipws >> ch) {
        //Check if current character equals any letter in the alphabet
        for (int x = 0; x < 26; x++) {
            // make sure all upper cases are converted to lower and check character
            if (tolower(ch) == (ascii_A + x)) {
                ++alphabetCharacterCount[x];
                 ++totalLettersInBook;
            }
        }
        
    }


    for (int x = 0; x < 26; x++) {
        totalLettersInCan += charactersPerCanOfSpaghettios[x];
    }


    /* ######### Output Can Letter Stats ######### */
    cout.imbue(locale(""));
    cout << "\n  Average can of ABC SpaghettiO's\n\n";
    cout << "Letter     % total       Times Occurred\n";
    for (int x = 0; x < 26; x++) {

        percentOccurence = (double(charactersPerCanOfSpaghettios[x]) / double(totalLettersInCan)) * 100;

        cout << char(ascii_A + x) << "          " << setprecision(3) << percentOccurence;
        cout << "             " << charactersPerCanOfSpaghettios[x] << "              " << endl;

    }
    cout << "\n\nTotal letters: " << totalLettersInCan;
    cout << "\n\n\n\n";


    //Pause system, press key to continue.
    system("pause");
    system("CLS");


    /* ######### Output Book Letter Stats ######### */
    cout << "\n  Letters in " << bookName << "\n\n";
    cout << "Letter     % total       Times Occurred\n";
    for (int x = 0; x < 26; x++) {

        percentOccurence = (double(alphabetCharacterCount[x]) / double(totalLettersInBook)) * 100;

        cout << char(ascii_A + x) << "          " << setprecision(3) << percentOccurence;
        cout << "             " << alphabetCharacterCount[x] << "              " << endl;
        
    }

    cout << "\n\nTotal letters: " << totalLettersInBook;
    cout << "\n\n\n\n";

    //Pause system, press key to continue.
    system("pause");
    system("CLS");

    /* ######### Output Spaghettios To Books ######### */

    for (int x = 0; x < 3; x++) {
        cout << "\nCalculating Spaghettio's to Books.";
        Sleep(300);
        cout << ".";
        Sleep(300);
        cout << ".";
        Sleep(300);
        system("CLS");
    }
    

    for (int x = 0; x < 26; x++) {
        if ((alphabetCharacterCount[x] / charactersPerCanOfSpaghettios[x]) >= cansNeededForBook)
            cansNeededForBook = (alphabetCharacterCount[x] / charactersPerCanOfSpaghettios[x]) + 1; // +1 because you cant have fractional cans, so you need to round up.
    }


    double baseCanCost = 1.39;
    double totalCostOfCans = baseCanCost * (double)cansNeededForBook;

    cout << "\nTotal Cans Needed: " << cansNeededForBook << "\n\n";
    cout << "SpaghettiO's Left Over: " << (totalLettersInCan * cansNeededForBook) - totalLettersInBook << "\n\n";
    cout << "Total Cost: $" << setprecision(10) << totalCostOfCans << "\n\n";
    cout << "Total Calories: " << (caloriesInCan * cansNeededForBook) << "\n\n";
    cout << "Total Height of Stacked Cans: " << setprecision(5) << ((cansNeededForBook * heightInInches) / 12) / 5280 << " miles\n\n";

   

    system("pause");
}