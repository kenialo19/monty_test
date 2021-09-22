#include "monty.h"
int number;
/**
 * open_and_read -
 * @argv: arguments
 * Return: void
 **/

void op_re_file(char **argv)
{
    FILE *fd = NULL;
    char *buf = NULL, *token = NULL;
    size_t len = 0;
    int line = 1;

    fd = fopen(argv[1], "r");
    if (fd == NULL)
        open_error(argv);

    for (line = 1; getline(&buf, &len, fd) != -1; line++)
    {
        get_op_code(buf, line);
        /** token = strtok(buf, "\n\t\r "); **/
    }
    (void)token;
}

void push(stack_t **head, unsigned int line_number)
{
    stack_t *new_node;

    (void)line_number;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        malloc_error();

    new_node->n = number;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node;
    }
}

void pall(stack_t **head, unsigned int line_number)
{
    int i = 0;

    if ((*head) == NULL)
        printf("ESTOY EN NULL\n");

    for (i = 0; *head != NULL; i++)
    {
        if ((*head)->n)
            printf("%d\n", (*head)->n);
        else
            printf("%d\n", 0);
        *head = (*head)->prev;
    }

    (void)line_number;
}

void pop(stack_t **head, unsigned int line_number)
{
    printf("Use POP\n");
    (void)head;
    (void)line_number;
}

void swap(stack_t **head, unsigned int line_number)
{
    printf("Use SWAP\n");
    (void)head;
    (void)line_number;
}

void add(stack_t **head, unsigned int line_number)
{
    printf("Use ADD\n");
    (void)head;
    (void)line_number;
}

void nop(stack_t **head, unsigned int line_number)
{
    printf("Use NOP\n");
    (void)head;
    (void)line_number;
}