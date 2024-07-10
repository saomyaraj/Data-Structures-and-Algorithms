#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
// node structure for a linked list
struct node
{
    int data;
    struct node *link;
};
//---DISPLAY FUNCTION
void printnumber(struct node *head)
{
    // Create a current node to traverse the linked list
    struct node *temp = head;
    // Traverse the linked list and print each node's data
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->link;
    }
}
//---INSERT FUNCTION
struct node *insertatfirst(struct node *head, int data)
{
    // Allocate memory for a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    // Set the data and link of the new node
    new_node->data = data;
    new_node->link = head;
    // Return the new node as the new head of the linked list
    return new_node;
}
//---REVERSE FUNCTION
struct node *numreverse(struct node *head)
{
    // Initialize three pointers for reversing the linked list
    struct node *temp = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    // Reverse the links of each node in the linked list
    while (temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
//---ADDITION FUNCTION
struct node *add(struct node *number1, struct node *number2)
{
    int add = 0;   // Used to store the sum of data
    int carry = 0; // Used to track the carry if produced
    struct node *num1 = number1;
    struct node *num2 = number2;
    struct node *result = NULL;
    // Traverse both linked lists until both are not null
    while ((num1 != NULL) && (num2 != NULL))
    {
        // Calculate the sum (0 to 9 values only) and update 'add'
        add = (num1->data + num2->data + carry) % 10;
        // Insert the sum into the result linked list
        result = insertatfirst(result, add);
        // Update the carry for the next iteration
        carry = (num1->data + num2->data + carry) / 10;
        // Move to the next nodes in both linked lists
        num1 = num1->link;
        num2 = num2->link;
    }
    // If there are nodes still left in num2
    if (num1 == NULL)
    {
        while (num2 != NULL)
        {
            // Calculate the sum and update 'add' and insertatfirst in result
            add = (num2->data + carry) % 10;
            result = insertatfirst(result, add);
            carry = (num2->data + carry) / 10;
            num2 = num2->link;
        }
    }
    // If there are nodes still left in num1
    if (num2 == NULL)
    {
        while (num1 != NULL)
        {
            // Calculate the sum and update 'add' and insertatfirst in result
            add = (num1->data + carry) % 10;
            result = insertatfirst(result, add);
            carry = (num1->data + carry) / 10;
            num1 = num1->link;
        }
    }
    // If there exists a carry after adding the last digit, resolve it here
    if ((num1 == NULL) && (num2 == NULL) && (carry != 0))
    {
        result = insertatfirst(result, carry);
    }
    return result;
}
struct node *Subtract(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *prev = NULL;
    int borrow = 0;
    // Traverse both lists
    while (temp1 != NULL || temp2 != NULL)
    {
        // Get the current digits to subtract
        int data1 = (temp1 != NULL) ? temp1->data : 0;
        int data2 = (temp2 != NULL) ? temp2->data : 0;
        // Perform subtraction with borrow
        int diff = data1 - data2 - borrow;
        // If result is negative, borrow from next digit
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        // Add the result to the front of the list
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = diff;
        newNode->link = result;
        result = newNode;
        // Move to the next digits
        if (temp1 != NULL)
        {
            temp1 = temp1->link;
        }
        if (
            temp2 != NULL)
        {
            temp2 = temp2->link;
        }
    }
    // If there's a borrow left, add it to the last digit
    if (borrow == 1)
    {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = borrow;
        newNode->link = result;
        result = newNode;
    }
    return result;
}
//---MULTIPLICATION FUNCTION
struct node *multiplicate(struct node *number1, struct node *number2)
{
    int mul_carry = 0; // Used to track the carry during multiplication
    int count = 0;     // Used to track the digit position of number2
    struct node *num1 = number1;
    struct node *num2 = number2;
    struct node *result = NULL;
    // Using the standard multiplication algorithm
    while (num2 != NULL)
    {
        struct node *num3 = NULL;
        // Add zeros according to the digit position of number2
        if (count > 0)
        {
            int temp = count;
            while (temp != 0)
            {
                num3 = insertatfirst(num3, 0);
                temp--;
            }
        }
        // Declare temp_num to avoid losing num1 while multiplying
        struct node *temp_num = num1;
        while (temp_num != NULL)
        {
            int mul = ((temp_num->data) * (num2->data) + mul_carry) % 10;
            mul_carry = ((temp_num->data) * (num2->data) + mul_carry) / 10;
            num3 = insertatfirst(num3, mul);
            temp_num = temp_num->link;
        }
        // If there is a carry left after multiplying
        if (mul_carry > 0)
        {
            num3 = insertatfirst(num3, mul_carry);
            mul_carry = 0;
        }
        // Add the current result to the overall result
        num3 = numreverse(num3);
        result = add(result, num3);
        result = numreverse(result);
        num2 = num2->link;
        count++;
    }
    // Reverse the final result before returning
    result = numreverse(result);
    return result;
}
void main()
{
    struct node *number1 = NULL, *number2 = NULL, *addition = NULL, *subtraction = NULL, *multiplication = NULL;
    int len1, len2, temp;
    // Get digits for number1 from the user, allowing for an unlimited number of digits
    printf("Enter length of number 1: ");
    scanf("%d", &len1);
    printf("Enter digits one by one!!!\n");
    for (int i = 0; i < len1; i++)
    {
        scanf("%d", &temp);
        number1 = insertatfirst(number1, temp);
    }
    // Get digits for number2 from the user, allowing for an unlimited number of digits
    printf("Enter length of number 2: ");
    scanf("%d", &len2);
    printf("Enter digits one by one!!!\n");
    for (int i = 0; i < len2; i++)
    {
        scanf("%d", &temp);
        number2 = insertatfirst(number2, temp);
    }
    addition = add(number1, number2);
    subtraction = Subtract(number1, number2);
    multiplication = multiplicate(number1, number2);
    // Reverse number1 and number2 to printnumber as entered by the user
    printf("Number 1 is : ");
    number1 = numreverse(number1);
    printnumber(number1);
    printf("\nNumber 2 is : ");
    number2 = numreverse(number2);
    printnumber(number2);
    // Print the results of arithmetic operations
    printf("\nAddition of number 1 and number 2 is : ");
    printnumber(addition);
    printf("\nSubtraction of number 1 from number 2 is : ");
    printnumber(subtraction);
    printf("\nMultiplication of number 1 and number 2 is : ");
    printnumber(multiplication);
}