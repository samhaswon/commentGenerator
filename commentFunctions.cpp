/****************************************************************************
 * Title: commentFunctions.cpp                                              *
 * Author: Samuel Howard, Computer Science Major                            *
 * Date: 12-06-2021                                                         *
 *                                                                          *
 * Purpose: Functions of commentHeader.cpp                                  *
 ***************************************************************************/

#include "commentHeader.h"

// Get the date for all functions
time_t now = time(0);
tm *ltm = localtime(&now);

// The Menu
void menuPrint()
{
    cout << "Please choose a language for the comment:\n" <<
            "1. C / C++ file\n" <<
            "2. C / C++ function\n" <<
            "3. C / C++ class\n" <<
            "4. Java file\n" << 
            "5. Python file\n";
    return;
}

// Validates integer choice as 1-4
void validateChoice(int& choice, int max)
{
    if (choice >= 1 && choice <= max)
    {
        return;
    }
    if(cin.fail())
    {
        // in case the user enters something other than an integer like I, the programmer, did
        cin.clear();
        cin.ignore(10000, '\n');
    }
    else
    {
        cout << "Choice is invalid, please enter a number 1-" << max << ": ";

        cin >> choice;
        cout << endl;
        // recursive call to check again
        validateChoice(choice, max);
    }
    
}

/*
 * Function Name: validateInput()
 * Parameters: Character (Pointer) to validate
 * Retruns: A character
 * Purpose: Makes sure user enters y or n 
 */
void validateInput(char& validChar)
{
    // y or n
    bool yOrN = tolower(validChar) == 'y' || tolower(validChar) == 'n';

    // cin.fail() used to detect unexpected input, in this case something other than a character
    if(cin.fail() || !yOrN)
    {
        // In case the user enters something other than an integer, clear flags and buffer
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Your input was not y or n as expected. Please enter either y or n.\n";
        cin >> validChar;
    }
    else
    {
        return;
    }
    // check again after completion of the if statement and return valid number
    validateInput(validChar);
}

// Finds last space before checkLength characters
int findLastSpace(string toCheck, int checkLength)
{
    int first, last;
    toCheck = toCheck.substr(0, checkLength - 1);

    first = toCheck.find(" ");
    last = toCheck.find_last_of(" ");

    if ( first == last || toCheck.size() < checkLength - 1)
    {
        return toCheck.size() - 1;
    }

    return last;
}

// Function to send out c comments
void cCommentOut(string type, string comment)
{
    string clipboardCache;
    bool purposeLeft = true;
    int index = 0;

    sstream << left << " * " << type << ": ";

    // Specific output code different from while loop (includes type)
    index = findLastSpace(comment, 70 - type.size());
    sstream << setw(70 - type.size()) << comment.substr(0, index + 1) << cEnd;
    getline(sstream, clipboardCache);
    output += clipboardCache + "\n";

    comment = comment.substr(index + 1);

    // just end if there is no more comment
    if (comment.size() < 1)
    {
        purposeLeft = false;
    }

    // format the comment after initial part
    while(purposeLeft)
    {
        // find where to stop the current line and add to output
        index = findLastSpace(comment, 70 - type.size());
        sstream << setw(type.size() + 5) << " * " << setw(70 - type.size()) << comment.substr(0, index + 1);
        sstream << cEnd;
        getline(sstream, clipboardCache);
        output += clipboardCache + "\n";

        // remove what was just added from the input
        comment = comment.substr(index + 1);

        // end when the comment is exhausted
        if (comment.size() < 1)
        {
            purposeLeft = false;
        }
    }
}

// Java's output function
void javaCommentOut(string purposeInput)
{
    // Variable(s)
    string clipboardCache = "";
    int index = 0;
    bool purposeLeft = true;

    // format the purpose
    while(purposeLeft)
    {
        // find where to stop the current line and add to output
        index = findLastSpace(purposeInput, 76);
        sstream << " * " << purposeInput.substr(0, index + 1) << "\n";
        getline(sstream, clipboardCache);
        output += clipboardCache + "\n";

        purposeInput = purposeInput.substr(index + 1);

        if (purposeInput.size() < 1)
        {
            purposeLeft = false;
        }
    }
}

// Python's output function
void pythonCommentOut(string purposeInput)
{
    // Variable(s)
    string clipboardCache = "";
    int index = 0;
    bool purposeLeft = true;

    // format the purpose
    while(purposeLeft)
    {
        index = findLastSpace(purposeInput, 76);
        sstream << "# " << purposeInput.substr(0, index + 1) << "\n";
        getline(sstream, clipboardCache);
        output += clipboardCache + "\n";

        purposeInput = purposeInput.substr(index + 1);

        if (purposeInput.size() < 1)
        {
            purposeLeft = false;
        }
    }
}

// Windows clipboard copy:
void toClipboard(HWND hwnd, const string &s)
{
	OpenClipboard(hwnd);
	EmptyClipboard();	
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
        cout << "\n***error copying to clipboard***\n";
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}
