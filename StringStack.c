#include <stdio.h>
char A[100];
int size,i,top;
void push() {
    char item;
    if (top == size - 1) {
        printf("\nStack is FULL!\n");
    } else {
        printf("Enter a value to push: ");
        scanf("%s",&item);
        top++;
        A[top]=item;
    }
}
void  pop() {
    if (top == -1) {
        printf("\nStack is EMPTY!\n");
    } 
    else
    {
        printf("The popped elements is %c",A[top]);
        top--;
    }
}
    

void display() 
{
    if(top==-1)
        printf("Stack is EMPTY! ");
    else{
        printf("\nThe elements in stack\n");
        for(i=0;i<=top;i++){
            printf("%c",A[i]);
    }
    }
}
void reverse() {
    if (top == -1) {
        printf("Stack is EMPTY! ");
    } else {
        printf("Reverse: ");
        for (i = top; i >= 0; i--) {
            printf("%c", A[i]);
        }
    }
}



int main() {
    int choice;
    top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    do {
        printf("\n1.PUSH\t2.POP\t3.DISPLAY.\t4.Revrese\t5.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;
case 4: 
   reverse();
   break;
            
            case 5:
                printf("Exit");
                break;
        


            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    
    return 0;
}
