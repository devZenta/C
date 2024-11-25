#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void drawLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("*  ");
    }
}

void drawSquare(int n) {
    for (int i = 0; i < n; i++) {
        drawLine(n);
        printf("\n");
    }
}

void drawRectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*  ");
        }
        printf("\n");
    }
}

void drawTriangle(int length) {
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*  ");
        }
        printf("\n");
    }
}

void drawTriangleIsocele(int length) {
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= length - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int createRandomNumber(int min, int max) {
    int random_number = min + rand() % (max - min + 1);
    return random_number;
}

void initArray(int tabLength, int min, int max, int *tab) {
    for (int i = 0; i < tabLength; i++) {
        tab[i] = createRandomNumber(min, max);
    }
}

void displayArray(int tabLength, int *tab) {
    printf("Contenu du tableau : ");
    for (int i = 0; i < tabLength; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void trierEtAfficher(int *tab, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < taille; j++) {
            if (tab[j] < tab[minIndex]) {
                minIndex = j;
            }
        }
        int temp = tab[minIndex];
        tab[minIndex] = tab[i];
        tab[i] = temp;
    }

    printf("Tableau trie : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}


bool isPalindrome(char *str) {
    int debut = 0;
    int fin = strlen(str) - 1;

    while (debut < fin) {
        if (str[debut] != str[fin]) {
            return false;
        }
        debut++;
        fin--;
    }
    return true;
}


bool isAnagramme(char* word1, char* word2) {
    int size = strlen(word1);
    if(size != strlen(word2)) {
        return false;
    }
    bool charFound;
    for(int i = 0; i < size; i++) {
        charFound = false;
        for(int j = 0; j < size; j++) {
            if(word1[i] == word2[j]) {
                charFound = true;
                word2[j] = " ";
                break;
            }
        }
        if(!charFound) {
            return false;
        }
    }
    return true;
}

int main(void) {
    srand(time(NULL));

    /*
    printf("Hello, World!");
    printf("\n");
    printf("\n");

    printf("Ligne de tirets");
    printf("\n");
    drawLine(5);

    printf("\n");
    printf("\n");
    printf("Carre de 5 de largeur");
    printf("\n");
    drawSquare(5);

    printf("\n");
    printf("Rectangle de 3 de longueur et 5 de largeur");
    printf("\n");
    drawRectangle(5, 3);

    printf("\n");
    printf("Triangle de 5 de hauteur");
    printf("\n");
    drawTriangle(5);

    printf("\n");
    printf("Triangle isocele de 5 de hauteur");
    printf("\n");
    drawTriangleIsocele(5);

    printf("\n");
    int userInput = 0;
    printf("Merci de choisir un nombre entre 0 et 66 : \n");
    scanf("%d", &userInput);
    printf("Vous avez entre %d comme nombre", userInput);
    printf("\n");
    drawTriangleIsocele(userInput);
    */

    /*printf("\n");

    int minInput = 0;
    printf("Merci de choisir un nombre minimum : \n");
    scanf("%d", &minInput);

    int maxInput = 0;
    printf("Merci de choisir un nombre maximum : \n");
    scanf("%d", &maxInput);

    int tabLengthInput = 0;
    printf("Merci de choisir la taille du tableau : \n");
    scanf("%d", &tabLengthInput);

    srand(time(NULL));

    int tab[tabLengthInput];

    initArray(tabLengthInput, minInput, maxInput, tab);
    displayArray(tabLengthInput, tab);
    trierEtAfficher(tab, tabLengthInput);
    */

    const char *word = "KAYAK";
    printf("\"%s\" est un palindrome ? %s\n", word, isPalindrome(word) ? "Oui" : "Non");

    char *word1 = "acteur";
    char *word2 = "crueat";
    if (isAnagramme(word1, word2)) {
        printf("Les mots sont des anagrammes.\n");
    } else {
        printf("Les mots ne sont pas des anagrammes.\n");
    }

    return 0;

    }