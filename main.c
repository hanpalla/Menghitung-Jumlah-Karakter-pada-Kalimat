#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

char kalimat[MAX], vokal[40], konsonan[40], numerik[40], tanpaSpasi[MAX];
int a = 0, b = 0, c = 0;

void separator(){
    for(int i = 0; tanpaSpasi[i] != '\0'; i++){
        if(isdigit(tanpaSpasi[i])){
            numerik[c] = tanpaSpasi[i];
            c++;
        }
        else{
            if(tanpaSpasi[i] >= 97 && tanpaSpasi[i] <= 122){
                if(tanpaSpasi[i] == 97 || tanpaSpasi[i] == 101  || tanpaSpasi[i] == 105  || tanpaSpasi[i] == 111  || tanpaSpasi[i] == 117){
                    vokal[a] = tanpaSpasi[i];
                    a++;
                }
                else{
                    konsonan[b] = tanpaSpasi[i];
                    b++;
                }
            }
        }
    }
}

void cetak(int x){
    int i = 0;
    if(x == 0){
        while(vokal[i] != '\0'){
            printf("%c ", vokal[i]);
            i++;
        }
        printf("\n");
    }
    else if(x == 1){
        while(konsonan[i] != '\0'){
            printf("%c ", konsonan[i]);
            i++;
        }
        printf("\n");
    }
    else{
        while(numerik[i] != '\0'){
            printf("%c ", numerik[i]);
            i++;
        }
        printf("\n");
    }
}

int cari(char x){
    for(int i = 0; tanpaSpasi[i] != '\0'; i++){
        if(x == tanpaSpasi[i])
            return 1;
    }
    return 0;
}

int main(){
    int i, j = 0;
    char input;

    system("cls");
    printf("PROGRAM MENCARI KARAKTER PADA KALIMAT.\n\n");
    printf("Input Kalimat\t\t\t: " );
    gets(kalimat);

    for(i = 0; kalimat[i] != '\0'; i++)
        kalimat[i] = tolower(kalimat[i]);

    i = 0;
    while(kalimat[i] != '\0'){
        if(kalimat[i] != ' '){
            tanpaSpasi[j] = kalimat[i];
            j++;                                        
        }
        i++;
    }

    separator();

    printf("\nOutput\n");
    printf("Karakter Vokal\t\t\t: %d\t= ", a);
    cetak(0);

    printf("Karakter Konsonan\t\t: %d\t= ", b);
    cetak(1);

    printf("Karakter Numerik\t\t: %d\t= ", c);
    cetak(2);

    printf("\nInput Karakter yang dicari\t: ");
    scanf("%c", &input);
    input = tolower(input);

    int flag = cari(input);
    if(flag == 1)
        printf("Karakter ditemukan.");
    else
        printf("Karakter tidak ditemukan.");

    return 0;
}
