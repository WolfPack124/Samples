#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int alpha[26];

int CheckStr(char str1[N], int ln1, char str2[N], int ln2)
{
    for(int i = 0; i < ln1; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z')
            alpha[str1[i] - 'a']++; 
        else if (str1[i] >= 'A' && str1[i] <= 'Z')
            alpha[str1[i] - 'A']++; 
    }
    for(int i = 0; i < ln2; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z')
            alpha[str2[i] - 'a']--; 
        else if (str2[i] >= 'A' && str2[i] <= 'Z')
            alpha[str2[i] - 'A']--; 
    }
    for(int i = 0; i < 26; i++) {
        if(alpha[i] != 0) {
            return -1;
        }
    }
    return 1;
}

int main()
{
    char str1[N];
    char str2[N];
    int sl1, sl2;
    int result = 0;
    for(int i = 0; i < 26; i++)
        alpha[i] = 0;
    printf("Enter string 1 : ");
    scanf(" %s", str1);
    printf("Enter string 2 : ");
    scanf(" %s", str2);
    sl1 = strlen(str1);
    sl2 = strlen(str2);
    result = CheckStr(str1, sl1, str2, sl2);
    if(result == 1) {
        printf("String is Anagram\n");
    } else {
        printf("String is not anagram\n");
        printf("Characters to be deleted to make it anagram are : ");
        for (int i = 0; i < 26; i++) {
            if(alpha[i] != 0) {
                printf(" %d-%c, ", alpha[i] > 0 ? alpha[i] : -alpha[i], i + 'a');
            }
        }
        printf("\n");
    }
}