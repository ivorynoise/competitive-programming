// Stack is represented using linked list
struct stack {
    int data;
    struct stack* next;
};

int isEmpty(struct stack* s)
{
    if (s == NULL)
        return 1;
    return 0;
}

 
// Recursive function to insert an item x in sorted way
//can be done simply using a while loop too
void sortedInsert(struct stack** s, int x)
{
    // Base case
    if (isEmpty(*s) or x > top(*s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}
 
void sortStack(struct stack** s)
{
    if (!isEmpty(*s)) {
        int x = pop(s);
         sortStack(s);
         sortedInsert(s, x);
    }
}
