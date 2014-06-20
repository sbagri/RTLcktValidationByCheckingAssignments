This is the final project for course ECE 5534 Electronic Design Automation.
The theoritical details of the project is in file "Report_sbagri.pdf"
This file lists the details of how to run this code.


DEPENDENCIES
--------------------------
1) Python 2.7
2) Eclipse (Suggested but not necessary)
3) PyDev plugin of Eclipse
4) z3-4.3.0 for python (Supplied with the project)
5) PyCParser (Supplied with the project)
	This has custom changes made for this project so
	need to use only this folder of PyCparser
6) Verilator generator *.cpp and *.h file of circuit to be tested.
	It needs to be aligned and all "coverage" line should be moved
	just below the condition code.
	All the files on which the program worked are supplied with the
	project
7) Program file named as Check3.py
8) Verilator (optional) - Needed to covert VHDL files to C++ files.
	For this project C++ files which are tested are supplied.
	However, it may be needed to test some new circuits.
	
HOW TO USE:
---------------------------
Install Eclipse.
Install PyDev on Eclipse
Update PYTHONPATH with 
1) Python 2.7 interpreter path
2) z3 Library path
3) PyCParser folder path

In the program file i.e Check3.py, just inside main at around line no. 18
three variables need to be updated
1) cppfile - with the name of cpp file to be tested. It should be placed in the
	same folder as the program file
2) hfile - with the name of h file to be tested. It should be placed in the
	same folder as the program file
3) CoveragesToTest - the number inside 'range' function should be updated to 
	maximum number of coverage point to be tested.
	Program will test coverages from 0 to that maximum number.

Run the program.
Full analysis for each coverage number would be printed at the command line

Output for circuit b01, b06, b07 and b12 are supplied with the project for reference.

