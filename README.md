# C-Very-Large-Number-Addition
This program manipulates strings to perform integer addition without the native limits characterized by ints. 

This program uses arguments given in the command line, however it can be easily modified to use user input instead. The two numbers are taken from the command line, and each put in a char array. Another char array to hold the final sum  is then created based on the lengths of the other two char arrays.

The program then manipulates ASCII values to give each index within the sum array a value of 0. Again manipulating ASCII values the program performs the addition, it does so manually, by starting at the end of the two numbers by adding the two corresponding digits at each index, carrying the remainder and repeating the process. In the case that one number is bigger than the other, it will only perform the addition with that number and the remainder. After each index is calculated its value is stored within the sum array, and after all the calculations are completed any zeroes at the beginning of the number are terminated.
