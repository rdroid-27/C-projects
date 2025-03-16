#include <stdio.h>

void main() {

    float input1=0, input2=0, output=0;
    char opt, cont_calc;


    printf("Welcome to THE CALCULATOR!\n");
    
    do
    {
        // Take Operands as user input
        printf("Enter Number 1: ");
        scanf("%f", &input1);
        printf("Enter Number 2: ");
        scanf("%f", &input2);

        // Take operator as user input
        printf("Select the operation: \n");
        printf("1. + \n2. - \n3. * \n4. / \nEnter Your Input: ");
        scanf("\n%c", &opt);

        // Perform Calculations based on user input
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
            if(input2 == 0){
                printf("Invalid Operation! Divide By 0!\n");
                goto another_calc;
            }
            output= input1 / input2;
            break;
        
        default: printf("Invalid Operation! Please select a valid Operator!\n");
                goto another_calc;
            break;
        }

        // Print the result
        printf("RESULT: %f %c %f = %f\n", input1, opt, input2, output);

        // Perform another calculation
        another_calc:
        printf("Do another calculation? (Y/n): ");
        scanf("\n%c", &cont_calc);

    } while (cont_calc == 'Y' | cont_calc == 'y');
   
    printf("Thank you for using THE CALCULATOR! Goodbye!\n");
    return;
    
   
}