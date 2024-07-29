#include <iostream>
#include <ctype.h>
#include <stdlib.h>

char shiftChar(char letter, int shift_value);
char shiftChar(char letter, int shift_value) {
    if(isupper(letter)) {
        int shifted;
       while (shift_value > 26 || shift_value < -26) {
        shift_value = shift_value % 26;
       }
       shifted = letter + shift_value;
       if (shifted > 90) {
        shifted = shifted - 26;
        return shifted;
       }
       else if(shifted < 65) {
        shifted = shifted + 26;
        return shifted;
       }
       else {
        return shifted;
       }
    }
    else if(islower(letter)) {
        int shifted;
        while (shift_value > 26 || shift_value < -26) {
        shift_value = shift_value % 26;
        }
        shifted = letter + shift_value;
        if (shifted > 122) {
        shifted = shifted - 26;
        return shifted;
        }
        else if(shifted < 97) {
        shifted = shifted + 26;
        return shifted;
        }
        else {
        return shifted;
        }
    }
    else {
        return letter;
    }
}