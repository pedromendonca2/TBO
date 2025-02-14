
// Stack with a very, very simple implementation.

#ifdef TYPE
#ifdef TPREFIX

// Opaque struture.
typedef struct TPREFIX(stack) TPREFIX(Stack);

// Creates a new stack.
TPREFIX(Stack*) TPREFIX(stack_create)();

// Frees the space allocated to the given stack.
void TPREFIX(stack_destroy)(TPREFIX(Stack*));

// Pushes the given value to the top.
void TPREFIX(stack_push)(TPREFIX(Stack*), TYPE);

// Pops and returns the top.
TYPE TPREFIX(stack_pop)(TPREFIX(Stack*));

// Returns the stack size.
int TPREFIX(stack_size)(TPREFIX(Stack*));

#endif
#endif
