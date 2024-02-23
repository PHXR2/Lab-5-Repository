//Palmer Henry 
//LAB ASSIGNMENT #4
//COP-3502C

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    // Start a counter variable
    int count = 0;
    // Loop through the linked list until the end
    while (head != NULL)
    {
        // Increment the counter for each node
        count++;
        // Move to the next node
        head = head->next;
    }
    // Return the counter value
    return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    // Get the length of the linked list
    int len = length(head);
    // Allocate memory for the string
    char* str = malloc(len + 1); // +1 for the null termination
    // Check if memory allocation was successful
    if (str == NULL)
    {
        // Return NULL if not
        return NULL;
    }
    // Begin an index variable
    int i = 0;
    // Loop through the linked list until the end
    while (head != NULL)
    {
        // Copy the letter from the node to the string
        str[i] = head->letter;
        // Increment the index
        i++;
        // Move to the next node
        head = head->next;
    }
    // Add the null terminator to the end of the string
    str[i] = '\0';
    // Return the string
    return str;

}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    // Create a new node with the given character
    node* newNode = malloc(sizeof(node));
    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        // Return if not
        return;
    }
    // Set the letter and next fields of the new node
    newNode->letter = c;
    newNode->next = NULL;
    // Check if the linked list is empty
    if (*pHead == NULL)
    {
        // Set the new node as the head of the list
        *pHead = newNode;
    }
    else
    {
        // Find the last node of the list
        node* last = *pHead;
        while (last->next != NULL)
        {
            // Move to the next node
            last = last->next;
        }
        // Set the new node as the next of the last node
        last->next = newNode;
    }
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    // Set a temporary pointer
    node* temp = NULL;
    // Loop through the linked list until the end
    while (*pHead != NULL)
    {
        // Save the current node in the temporary pointer
        temp = *pHead;
        // Move the head pointer to the next node
        *pHead = (*pHead)->next;
        // Free the memory of the temporary node
        free(temp);
    }

}
int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}