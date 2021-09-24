#include <stdio.h>
#include <string.h>

char* reverseWord(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }

    return s;
}

char* reverseWords(char *s){
    int len = strlen(s);
    int left = 0;
    int right = 0;

    while ( right < len ) {
        if ( s[right] == ' ' ) {
            s = reverseWord(s, left, right - 1);
            left = right + 1;
        }
        right++;
    }
    reverseWord(s, left, len - 1);

    return s;
}

int main() {
    char s[] = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(s));
    return 0;
}