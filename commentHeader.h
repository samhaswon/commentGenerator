#ifndef COMMENTHEADER_H
#define COMMENTHEADER_H


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
// for clipboard implementation on windows:
#include <Windows.h>
#include <winuser.h>

using namespace std;


// Global stuff:
/* 
 * For open c comments, comment out the upper declaration
 * and un-comment the lower declaration
 */
const string cEnd = " *\n", cHead = "/****************************************************************************", cFoot = " ***************************************************************************/";
// const string cEnd = " \n", cHead = "/*", cFoot = " */";
const string author = "Samuel Howard, Computer Science Major"; // Name, major
inline stringstream sstream;
inline string output = ""; // Holds whole output for clipboard (in windows for now) and finished output


// Functions:
void cCommentOut(string type, string comment);
int findLastSpace(string toCheck, int checkLength);
void javaCommentOut(string purposeInput);
void menuPrint();
void pythonCommentOut(string purposeInput);
void toClipboard(HWND hwnd, const std::string &s);
void validateChoice(int& choice, int max = 4);
void validateInput(char& validChar);

#endif