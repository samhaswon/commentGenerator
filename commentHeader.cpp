/**************************************************************************
 * Title: commentHeader.cpp                                               *
 * Author: Samuel Howard                                                  *
 * Date: 02-22-2022                                                       *
 * Purpose: Generate a comment header for C++, Java, Python and any other *
 *          language that uses the same multiline comment as any of them. *
 *************************************************************************/

#include "commentHeader.h"

int main()
{
    // Variables:
    string purposeInput, functionName, functionParameters, functionReturn, className, clipboardCache;
    char clipboardCopy, genAgain;
    int languageChoice = 0;
    bool again = true;
    // Get the date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    do
    {
        // Choose the language
        menuPrint();
        cin >> languageChoice;
        validateChoice(languageChoice, 6);

        // If exit is chosen, end the program
        if(languageChoice == 6)
        {
            cout << "\nGoodbye.\n";
            return 0;
        }

        // Get program/function/class purpose:
        cin.ignore();
        cout << "Please input the purpose: " << endl;
        getline(cin, purposeInput);

        // Note: functions output to global output string
        switch(languageChoice)
        {
            // C/C++ file header
            case 1:
                // get user input
                cout << "Please enter the title ( program.cpp ): ";
                getline(cin, functionName);

                cout << endl << "Copy this:" << endl << endl;

                // Head
                output += cHead + "\n";

                cCommentOut("Title", functionName);
                cCommentOut("Author", author);

                // Get the date and dump to the output
                sstream << " * Date: " << right << setfill('0') << setw(2) << 1 + ltm->tm_mon << '-' << setw(2) << ltm->tm_mday << '-' << 1900 + ltm->tm_year <<  setfill(' ')<< setw(59) << cEnd;
                sstream << left << setw(75) << " *";
                sstream << cEnd;
                getline(sstream, clipboardCache);
                output += clipboardCache + "\n";
                getline(sstream, clipboardCache);
                output += clipboardCache + "\n";

                // Output the purpose
                cCommentOut("Purpose", purposeInput);

                // Foot
                output += cFoot + "\n";
                
                break;

            // C / C++ function header
            case 2:
                // get user input
                cout << "Please enter the function name: ";
                getline(cin, functionName);
                cout << "Please enter function parameter(s): ";
                getline(cin, functionParameters);
                cout << "Please enter the function return(s): ";
                getline(cin, functionReturn);

                cout << endl << "Copy this:" << endl << endl;

                // top line and function name
                output += cHead + "\n";
                sstream << left << " * Function Name: " << setw(57) << functionName << " *\n";
                getline(sstream, clipboardCache);
                output += clipboardCache + "\n";

                // Function details:
                cCommentOut("Parameters", functionParameters);
                cCommentOut("Return", functionReturn);
                cCommentOut("Purpose", purposeInput);

                // Add the footer
                output += cFoot;
                break;

            // C++ Class
            case 3:
                cout << "Please enter the class name: ";
                getline(cin, className);

                cout << endl << "Copy this:" << endl << endl;

                // Head
                output += cHead + "\n";
                
                // Body
                cCommentOut("Class Name", className);
                cCommentOut("Purpose", purposeInput);

                // Footer
                output += cFoot + "\n";

                break;

            // Javadocs file header
            case 4:
                cout << endl << "Copy this:" << endl << endl;

                // Head
                output += "/**\n";

                // Sends the purpose to Java's ouput function
                javaCommentOut(purposeInput);

                // add the remaining data
                output += " *\n";
                output += " * @author " + author + "\n";
                sstream << " * @version " << 1 + ltm->tm_mon << '-' << ltm->tm_mday << '-' << 1900 + ltm->tm_year << "\n";
                getline(sstream, clipboardCache);
                output += clipboardCache + "\n */";
                break;

            // Python with a similar format as Java
            case 5:
                // get user input
                cout << "Please enter the title ( program.py ): ";
                getline(cin, functionName);

                cout << endl << "Copy this:" << endl << endl;

                // Python comment start
                output += "########################################################################\n";
                
                // Send the purpose to Python's output function
                pythonCommentOut(purposeInput);

                // add the remaining info
                output += "#\n";
                output += "# File name: " + functionName + "\n";
                output += "# Author: " + author + "\n";
                sstream << "# Version: " << 1 + ltm->tm_mon << '-' << ltm->tm_mday << '-' << 1900 + ltm->tm_year << "\n";
                getline(sstream, clipboardCache);
                output += clipboardCache;

                // Python comment end
                output += "\n########################################################################\n";
                break;
            
            default:
                // If this trips, something weird happened
                cout << "\n***error***\n";
        }

        cout << output << endl << endl;

        // ask for windows clipboard copy
        cout << "Would you like to copy to the clipboard (y/n)? ";
        cin >> clipboardCopy;
        validateInput(clipboardCopy);

        if(clipboardCopy == 'y')
        {
            // copy the comment to the clipboard
            HWND hwnd = GetDesktopWindow();
            toClipboard(hwnd, output);
        }
        cout << endl;
        
        // Ask the user if they wish to continue and verify input
        cout << "Do you wish to generate another comment (y/n)? ";
        cin >> genAgain;
        validateInput(genAgain);

        // If no, end
        if(tolower(genAgain) == 'n')
        {
            again = false;
        }
        // If yes, prepare for next comment
        else
        {
            cout << endl;
            // Clear output for next comment
            output = "";
        }

    } while(again); // end of execution

    return 0;
}