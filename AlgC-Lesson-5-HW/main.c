//
//  main.c
//  AlgC-Lesson-5-HW
//
//  Created by admin on 04.08.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc/malloc.h>
#include <string.h>

#define MAX 20

void solution1();
void solution2();
void solution3();
void solution4();
void menu();

int main(int argc, const char * argv[]) {
    menu();
    return 0;
}

void menu() {
    int solutionNumber;
    printf("Choose solution (1..4):\n");
    scanf("%d", &solutionNumber);
    switch (solutionNumber) {
        case 1:
            solution1();
            break;
        case 2:
            solution2();
            break;
        case 3:
            solution3();
            break;
        case 4:
            solution4();
            break;
        default:
            printf("Wrong solution number!");
            break;
    }
}

struct TNode {
    int value;
    struct TNode *next;
};

typedef struct TNode Node;

struct Stack {
    Node *head;
    int size;
    int maxSize;
};

struct Stack Stack;

void push(int value) {
    if (Stack.size >= Stack.maxSize) {
        printf("Stack overflow");
        return;
    }
    
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    
    tmp->value = value;
    tmp->next = Stack.head;
    
    Stack.head = tmp;
    Stack.size++;
}

int pop() {
    if (Stack.size == 0) {
        printf("Stack is empty");
        return -1;
    }
    
    Node* next = NULL;
    int value;
    value = Stack.head->value;
    
    next = Stack.head;
    Stack.head = Stack.head->next;
    
    free(next);
    
    Stack.size--;
    return value;
}

void printStack(struct Stack Stack) {
    Node *current = Stack.head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void solution1() {
    printf("Solution 1:\n");
    
    Stack.maxSize = 1000;
    Stack.head = NULL;
    
    int number;
    printf("Input number:\n");
    scanf("%d", &number);
    
    while (number > 1) {
        push(number % 2);
        number /= 2;
    }
    
    printf("Binary number = %d", number);
    printStack(Stack);
    printf("\n");

}

struct CharNode {
    int value;
    struct CharNode *next;
};

typedef struct CharNode CNode;

struct CStack {
    CNode *head;
    int size;
    int maxSize;
};

struct CStack CStack;

void pushChar(int value) {
    if (CStack.size >= CStack.maxSize) {
        printf("Stack overflow");
        return;
    }
    
    CNode *tmp;
    tmp = (CNode*) malloc(sizeof(CNode));
    
    tmp->value = value;
    tmp->next = CStack.head;
    
    CStack.head = tmp;
    CStack.size++;
}

int popChar() {
    if (CStack.size == 0) {
        printf("Stack is empty");
        return -1;
    }
    
    CNode* next = NULL;
    int value;
    value = CStack.head->value;
    
    next = CStack.head;
    CStack.head = CStack.head->next;
    
    free(next);
    
    CStack.size--;
    return value;
}

void printCStack(struct CStack CStack) {
    CNode *current = CStack.head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void solution2() {
    printf("Solution 3: \n");
    
    char bracketSequence[20] = "(1)[agd{}23]";
    printf("%s\n", bracketSequence);
    
    CStack.maxSize = 1000;
    CStack.head = NULL;
    
    int someBool = 0;
    for (int i = 0; i < strlen(bracketSequence); i++) {
        char someChar = bracketSequence[i];
        if (someChar == '(' || someChar == '{' || someChar == '[') {
            pushChar(bracketSequence[i]);
        }
        if (someChar == ')') {
            if (popChar() != '(') {
                someBool++;
                break;
            }
        }
        if (someChar == '}') {
            if (popChar() != '{') {
                someBool++;
                break;
            }
        }
        if (someChar == ']') {
            if (popChar() != '[') {
                someBool++;
                break;
            }
        }
    }
    if (CStack.size != 0 || someBool != 0) {
        printf("Incorrect bracket sequence\n");
    } else {
        printf("Correct bracket sequence\n");
    }
}

typedef struct Stack_new {
    Node *head;
    int size;
    int maxSize;
} Stack_new;

void push_new(Stack_new *stack, int value) {
    if (stack->size >= stack->maxSize) {
        printf("Stack overflow");
    }
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    
    tmp->value = value;
    tmp->next = stack->head;
    
    stack->head = tmp;
    stack->size++;
}

int pop_new(Stack_new *stack) {
    if (stack->size == 0) {
        printf("Stack is empty");
    }
    
    Node* next = NULL;
    int value;
    value = stack->head->value;
    
    next = stack->head;
    stack->head = stack->head->next;
    
    free(next);
    
    stack->size--;
    return value;
}

void printStack_new(Stack_new *stack) {
    Node *current = stack->head;
    while(current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

void copyStack(Stack_new *oldStack, Stack_new *newStack) {
    
    Stack_new SomeStack;
    SomeStack.maxSize = 1000;
    SomeStack.size = 0;
    SomeStack.head = NULL;
    
    Node *current = oldStack->head;
    while(current != NULL) {
        push_new(&SomeStack, current->value);
        current = current->next;
    }
    
    Node *current_new = SomeStack.head;
    while(current_new != NULL) {
        push_new(newStack, current_new->value);
        current_new = current_new->next;
    }
}

void solution3() {
    Stack_new OldStack;
    OldStack.maxSize = 1000;
    OldStack.size = 0;
    OldStack.head = NULL;
    push_new(&OldStack, 1);
    push_new(&OldStack, 2);
    push_new(&OldStack, 3);
    printStack_new(&OldStack);
    
    Stack_new NewStack;
    NewStack.maxSize = 1000;
    NewStack.size = 0;
    NewStack.head = NULL;
    
    copyStack(&OldStack, &NewStack);
    printStack_new(&OldStack);
    printStack_new(&NewStack);
}

struct queue {
    int items[MAX];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue *q);

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q) {
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue* q, int value) {
    if (q->rear == MAX-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        for (i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }
}

void solution4() {
    struct queue* someQ = createQueue();
    enqueue(someQ, 5);
    enqueue(someQ, 4);
    enqueue(someQ, 3);
    enqueue(someQ, 2);
    enqueue(someQ, 1);
    dequeue(someQ);
    printQueue(someQ);
}
