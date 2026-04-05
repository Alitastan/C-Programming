#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* To set up a linked list, the first thing we will need is a 
structure that represents a single node in the list.*/
struct node
{
    int value; /* data stored in the node*/
    struct node *next; /* pointer to the next node in the list*/
};


struct node *add_to_list (struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node)); /* Step 1: allocate memory for the node. */
    if (new_node == NULL)
    {
        printf("Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n; /* Step 2: store data in the node. */
    new_node->next = list; /* Step 3: insert the node into the list. */

    return new_node;
}

struct node *search_list (struct node *list, int n)
{
    while (list != NULL && list->value != n)
        list = list->next;
    return list;
}

struct node *delete_from_list (struct node *list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next)
    ;

    if (cur == NULL) 
        return list; /* n was not found*/

    if (prev == NULL) 
        list = cur->next; /* n is in the first node*/
    else
        prev->next = cur->next; /* n is in a node other than the first*/

    free(cur);
    return list;
}


int main (void)
{
    /* Now we'll need a way to keep track of where the list begins. */
    struct node *first = NULL; /* points to the first node in the list */

    /* We'll want to create nodes one by one, adding each to the list
    Creating a node requires three steps:
    1. Allocate memory for the node.
    2. Store data in the node.
    3. Insert the node into the list.
    */

    /* When we create a node, we'll need a variable that can point
    to the node temporarily, until it's been inserted into the list */
    struct node *new_node;

    new_node = malloc(sizeof(struct node)); /* Step 1: allocate memory for the node. */

    if (new_node == NULL)
    {
        printf("Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    /* Next we'll store data in the value member of the new node.*/
    new_node->value = 10; /* Step 2: store data in the node. */
    new_node->next = first; /* Step 3: insert the node into the list. */

    first = new_node;

    new_node = malloc(sizeof(struct node)); /* Step 1: allocate memory for the node. */
    new_node->value = 20; /* Step 2: store data in the node. */
    new_node->next = first; /* Step 3: insert the node into the list. */
    first = new_node;

    /* Same demonstration using the add_to_list function */
    first = add_to_list(first, 30);
    first = add_to_list(first, 40);
}