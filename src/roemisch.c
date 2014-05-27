#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roemisch.h"

char* concat(char* head, char* tail) {
    char* s = malloc(strlen(head)+strlen(tail)+1);
    sprintf(s, "%s%s", head, tail);
    return s;
}

struct literal {
    int arabisch;
    char* roemisch;
};

struct literal literale[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};
int anzahlLiterale = sizeof(literale) / sizeof(literale[0]);

char* roemischFuer(int arabisch) {
    for (int i=0; i<anzahlLiterale; i++) {
        if (arabisch >= literale[i].arabisch) {
            return concat(literale[i].roemisch, 
                    roemischFuer(arabisch-literale[i].arabisch));
        }
    }
    return "";
}
