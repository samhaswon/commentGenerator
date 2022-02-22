PROJECT TITLE: Comment Header
PURPOSE OF PROJECT: Make file, function, class, etc. commenting easier
DATE: 02-22-22
HOW TO START THIS PROJECT: compile using "g++ commentHeader.cpp commentFunctions.cpp comment.res -o commentHeader" 
						   or the included batch file (compile.bat) and run commentHeader
AUTHORS: Samuel Howard

USER INSTRUCTIONS: 
	Compile and run. The menu promps you for the language and will then prompt input for appropriate fields. Be sure to 
change the author string in commentHeader.h to your name and cEnd, cFoot, & cHead to your preference of style before
compiling. I'm not wanting to take credit for your projects here! For java, since javadocs are so customizable, their 
implementation is sparse as they can be used so differently. That means the user is responsible for their use outside of the 
given template. Similarly, there are many tools avalible for Python when it comes to function and class commenting. Because 
of this, there is no implementation of any of these. This project also can copy the output to your windows clipboard if you 
wish. Currently, there is no implementation of this feature for any Unix based operating system.

CHANGE:
	To add more functions, follow the comments for what the current functions do. cCommentOut() is a good example to go 
by. All functions use stringstream to be able to use iomanip for formatting before dumping to global output string "output". 
