#include <stdio.h>

void main() {

    int input1=0, input2=0, output=0;
    char opt, cont_calc;


    printf("Welcome to THE CALCULATOR!\n");
    
    do
    {
      // Take Operands as user input
    printf("Enter Number 1: ");
    scanf("%d", &input1);
    printf("Enter Number 2: ");
    scanf("%d", &input2);

    // Take operator as user input
    printf("Select the operation: \n");
    printf("1. + \n2. - \n3. * \n4. / \nEnter Your Input: ");
    scanf("%c", &opt);

    switch (opt)
    {
    case '+':
        output= input1 + input2;
        break;
    case '-':
        output= input1 - input2;
        break;
    case '*':
        output= input1 * input2;
        break;
    case '/':
        output= input1 + input2;
        break;
    
    default: printf("Invalid Operation! Exiting!");
        return;
        break;
    }

    printf("RESULT: %d \n", output);

    printf("Do another calculation? (Y/n): ");
    scanf("%c", cont_calc);
    } while (cont_calc == 'Y' | cont_calc == 'y');
    
   
}