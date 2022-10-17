#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(const int argc, const char* argv[])
{
    char rem = 0; // variable representing remainder
    int n=strlen(argv[1])+1; // variable representing the length of the sum array
    const int num1len = strlen(argv[1]); // variable representing the length of the num1 array
    const int num2len = strlen(argv[2]); // variable representing the length of the num2 array

    char num1[num1len]; // array representing the first number inputted in the command line
    char num2[num2len]; // array representing the second number inputted in the command line

    if(strlen(argv[2]) > strlen(argv[1])) // defines the length of the sum array as the length of the biggest inputted number + 1
    {
        n=strlen(argv[2])+1;
    }
    
    char sum[n]; // the sum array
    


    for (int i=strlen(argv[1])-1; i>=0; i--) // inputs the first number from the command line into num1
    {
        num1[i]=argv[1][i]; 
        
    }

    for (int i=strlen(argv[2])-1; i>=0; i--) // inputs the second number from the command line into num2
    {
        num2[i]=argv[2][i];
    }



    for (int i=n-1; i>=0; i--) // makes all the values in the sum array = 0 (char value of 48)
    {
        sum[i]=48;
        
    }    


    int i=1; // variable used for iterating through the arrays within the upcoming while loops
    while (i <= num1len && i <= num2len) // while both arrays contain digits
    {
        sum[n-i] = (((num1[num1len - i]-48) + (num2[num2len - i] - 48) + rem)%10 + '0'); // performs the addition
        if(((num1[num1len - i]-48) + (num2[num2len - i] - 48)  + rem) > 9) //checks remainder
        {
            rem = 1;
        }
        else{
            rem = 0;
        }
        i++;
            
    }
    while (i <= num2len) //while only num2 contains digits
    {
        sum[n-i] = ((num2[num2len - i] - 48) + rem)%10 + '0'; // performs addition without num1
        if (((num2[num2len - i] - 48) + rem) > 9 ) // checks remainder
        { 
            rem = 1; 
        }
        else 
        {
            rem = 0;
        }
        i++;
    }
    while (i <= num1len) //while only num1 has digits
    {
        sum[n-i] = ((num1[num1len - i] - 48) + rem)%10 + '0'; // performs addition without num2
        if (((num1[num1len - i] - 48) + rem) > 9 ) // checks remainder
        {
            rem = 1; 
        }
        else 
        {
            rem = 0;
        }
        i++;
    }

    while (i <= n) // while there is an empty index in the sum array
    {
        sum[0] = rem + 48; // the first index is replaced with the rem + 48 (will end up being 0 or 1 because of ASCII values)
       i++;
    }


    bool zeroFirstDigit = false; // variable checking if 0 is the first digit in the sum array
    if (sum[0]==48) // checks if 0 is the first digit in the sum array
        zeroFirstDigit = true; 

    cout << "Sum: "; // output

    for (int i = zeroFirstDigit? 1 : 0; i<n; i++) // if the first digit in the sum array is 0, start at index 1, otherwise if the first digit is 1, start at index 0 
    {
      cout << sum[i]; // print out sum array
    }
   

    return 0;
}