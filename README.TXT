PROJECT TITLE: Comment Header
PURPOSE OF PROJECT: Make file, function, class, etc. commenting easier
VERSION or DATE: 12-6-21
HOW TO START THIS PROJECT: compile using "g++ commentHeader.cpp commentFunctions.cpp -o commentHeader" and run commentHeader
AUTHORS: Samuel Howard

USER INSTRUCTIONS: 
	Compile and run. The menu promps you for the language and will then prompt input for appropriate fields. Be sure to 
change the author string in commentHeader.h to your name and cEnd, cFoot, & cHead to your preference of style before
compiling. I'm not wanting to take credit for your projects here! For java, since javadocs are so customizable, their 
implementation is sparse as they can be used so differently. That means the user is responsible for their use outside of the 
given template. This project also can copy the output to the clipboard if you wish.

CHANGE:
	To add more functions, follow the comments for what the current functions do. cCommentOut() is a good example to go 
by. All functions use stringstream to be able to use iomanip for formatting before dumping to global output string "output". 