#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void Encrypt(char *Plain, int len, int K, char *Cipher) 
{
    for(int i = 0 ; i < len ; i++) {
        if(Plain[i] >= 'a' && Plain[i] <= 'z')
            Cipher[i] = ((Plain[i]-'a'+K)%25)+'a';
        else if ((Plain[i] >= 'A') && (Plain[i] <= 'Z'))
            Cipher[i] = ((Plain[i]-'A'+K)%25) + 'A';
        else 
            Cipher[i] = Plain[i];
    }
    Cipher[len] = '\0';
}

void Decrypt(char *Cipher, int len, int K, char *Plain)
{
    for(int i = 0; i < len ; i ++) {
        if(Cipher[i] >= 'a' && Cipher[i] <= 'z')
            Plain[i] = ((Cipher[i] - 'a' - K) < 0) ? ((Cipher[i] - 'a' - K) + 25 + 'a') : ((Cipher[i] - 'a' - K)%25) + 'a';
        else if ((Cipher[i] >= 'A') && (Cipher[i] <= 'Z'))
            Plain[i] = ((Cipher[i] - 'A' - K) < 0) ? ((Cipher[i] - 'A' - K) + 25 + 'A') : ((Cipher[i] - 'A' - K)%25) + 'A';
        else
            Plain[i] = Cipher[i];
    }
    Plain[len] = '\0';
}

void main()
{
    char Plain[N];
    char newPlain[N];
    printf("Enter Text to encrypt: ");
    scanf(" %s", Plain);
    int len = strlen(Plain);
    char *Cipher = malloc(sizeof(char) * N);
    Encrypt(Plain, len, 1, Cipher);
    printf("Cipher is %s \n", Cipher);
    Decrypt(Cipher, strlen(Cipher), 1, newPlain);
    printf("Decrypted string is %s \n", newPlain);
}