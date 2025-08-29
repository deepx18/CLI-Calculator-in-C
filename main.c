#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

int numNumber(char*, char*);
void addChar(char*, char);
int strcompare(char*, char);
int getlength(char*);
int charToIntNumber(char*);

int main() {
    char *ops = "+-*/";
    char *input;
    int num1;
    int num2;
    char op;
    int result;

    char *charnum1 = malloc(sizeof(char) * 10);
    charnum1[0] = '\0';
    char *charnum2 = malloc(sizeof(char) * 10);
    charnum2[0] = '\0';

    // fgets(input, 64, stdin);
    // input[sizeof(input) - 1] = '\0';
    
    scanf("%s", input);

    


    


    int i = 0;
    while (input[i] != '\0'){
        if (strcompare(ops, input[i])){
            op = input[i];
            i++;
            continue;
        }
        

        if (strcompare(ops, op)){
            addChar(charnum2, input[i]);
        }
        else{
            addChar(charnum1, input[i]);
        }
        i++;
    }

    num1 = charToIntNumber(charnum1);
    num2 = charToIntNumber(charnum2);

    switch (op){
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / (float)num2;
        break;
    
    default:
        break;
    }
    printf("%d\n", result);

    


    


    return 0;
}

void addChar(char *target, char chr){

    int i = 0;
    while (target[i] != '\0'){
        i++;
    }

    *(target+i) = chr;
    *(target+i+1) = '\0';

    return;
}

int strcompare(char *target, char chr){
    int i = 0;
    while (target[i] != '\0')
    {
        if (target[i] == chr)
        {
            return true;
        }
        i++;
    }
    return false;
}

int getlength(char *target){
    int i = 0;
    while (target[i] != '\0')
    {
        i++;
    }
    return(i);
}

int charToIntNumber(char *charNum){
    int num = 0;
    int length = getlength(charNum);

    int j = length-1;
    for (int i = 0; i < length; i++)
    {
        num += ((int)charNum[i] - 48) * pow(10, j);
        j--;
    }
    
    return num;
}

int numNumber(char *target, char *ops) {
    int j = 1;
    int i = 0;
    while (target[i] != '\0'){
        if (strcompare(ops, target[i])){
            j++;
        }
        i++;
    }
    return(j);
}