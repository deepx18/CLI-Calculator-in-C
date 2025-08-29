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
char* intToCharNumber(int);

int main() {
    char *ops = "+-*/";
    char *chars = "1234567890+-*/";
    char *input;
    int result = 0;
    

    scanf("%s", input);

    int numsLength = numNumber(input, ops);

    int *nums = calloc(numsLength, sizeof(int));
    int opArr[numsLength];
    char *numchars[numsLength];

    for (int i = 0; i < numsLength; i++){
        numchars[i] = malloc(sizeof(char) * 10);
        numchars[i][0] = '\0';
    }
    

    int i = 0;
    int j = 0;
    while (input[i] != '\0'){
        if (strcompare(ops, input[i])){
            opArr[j] = input[i];
            i++;
            j++;
            continue;
        }

        if (!strcompare(chars, input[i])){
            printf("Invalid Mathematical symbol(s) !\n");
            return(0);
        }
        
        
        addChar(numchars[j], input[i]);

        i++;
    }

    for (int i = 0; i < numsLength; i++)
    {
        nums[i] = charToIntNumber(numchars[i]);
    }

    
    
    for (int i = 0; i < numsLength-1; i++)
    {
         switch (opArr[i]){
            case '+':
            {
                if ( i == 0 ) {
                    result = nums[i] + nums[i+1]; 
                    break;
                }
                result += nums[i+1];

                break;
            }    
            case '-':
            {
                if ( i == 0 ) {
                    result = nums[i] - nums[i+1]; 
                    break;
                }
                result -= nums[i+1];

                break;
            }    
            case '*':
            {
                if ( i == 0 ) {
                    result = nums[i] * nums[i+1]; 
                    break;
                }
                switch (opArr[i-1])
                {
                case '+':
                    result -= nums[i];
                    result += nums[i] * nums[i+1];
                    continue;
                    break;
                case '-':
                    result += nums[i];
                    result -= nums[i] * nums[i+1];
                    continue;
                    break;

                }
                result *= nums[i+1];

                break;
            }    
            case '/':
            {
                if ( i == 0 ) {
                    result = nums[i] / nums[i+1]; 
                    continue;;
                }

                switch (opArr[i-1])
                {
                case '+':
                    result -= nums[i];
                    result += nums[i] / nums[i+1];
                    continue;
                    break;
                case '-':
                    result += nums[i];
                    result -= nums[i] / nums[i+1];
                    continue;
                    break;

                }

                result /= nums[i+1];

                break;
            }    
            }
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

char* intToCharNumber(int num){
    char *charNum = malloc(sizeof(char) * 10);

    int i = 0;
    while (num != 0)
    {
        charNum[i] = (char)(num % 10 + 48);
        num /= 10;
        i++;
    }
    charNum[i] = '\0';
    return charNum;
}
