#include <stdio.h>
#include <string.h>

#define SIZE 180

int main() {
    char str[SIZE], result[SIZE] = {};
    scanf("%s", str);
    str[strlen(str) - 1] = ',';
    int index = 0;
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == ',') {
            int count = 0;
            char slice[6] = {};
            for(int j = index, k = 0; j < i; j++, k++)
                slice[k] = str[j];
            index = i + 1;
            if(strstr(result, slice) == NULL) {
                strcat(result, slice);
                char* ptr = str;
                while((ptr = strstr(ptr, slice)) != NULL) {
                    count++;
                    ptr += strlen(slice);
                }
                char a[4];
                sprintf(a, "-%i\n", count);
                strcat(result, a);
            }
        }
    printf("%s", result);
}