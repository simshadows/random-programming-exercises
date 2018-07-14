/*
 * Filename: halfpyramid.c
 * Author:   https://github.com/simshadows
 *
 * This program takes an arbitrary integer value from user input and prints a bunch of
 * "pyramids" using various different algorithms.
 *
 * Example pyramid with a height of 4:
 * 
 *    #
 *   ##
 *  ###
 * ####
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_MALLOC_MSG "WARNING: malloc() returned NULL."

void print_pyramid_1(int height);
void print_pyramid_1_alt(int height);
void print_pyramid_2(int height);
void print_pyramid_2_alt(int height);
void print_pyramid_3(int height);
void print_pyramid_4(int height);
void print_pyramid_5(int height);

int main() {
    int height = 0;
    
    do {
        printf("Please input the height: ");
        scanf("%d", &height);
    } while (height < 1 || height > 100);
    // Arbitrary limit of 100. Just change that as needed.
    
    printf("\nprint_pyramid_1()\n");
    print_pyramid_1(height);

    printf("\nprint_pyramid_1_alt()\n");
    print_pyramid_1_alt(height);
    
    printf("\nprint_pyramid_2()\n");
    print_pyramid_2(height);

    printf("\nprint_pyramid_2_alt()\n");
    print_pyramid_2_alt(height);
    
    printf("\nprint_pyramid_3()\n");
    print_pyramid_3(height);
    
    printf("\nprint_pyramid_4()\n");
    print_pyramid_4(height);
    
    printf("\nprint_pyramid_5()\n");
    print_pyramid_5(height);
}

/*
 * This is probably the most basic implementation that runs two loops, and calls printf()
 * once for each character.
 */
void print_pyramid_1(int height) {
    for (int row = 1; row <= height; ++row) {
        int limit;
        
        limit = height - row;
        for (int i = 0; i < limit; ++i) {
            printf(" ");
        }
        
        limit = row;
        for (int i = 0; i < limit; ++i) {
            printf("#");
        }
        
        printf("\n");
    }
}

/*
 * This is similar to print_pyramid_1(), except the code is organized more succinctly.
 *
 * print_pyramid_1() is intentionally verbose in order to illustrate the logic in a
 * clearer way.
 */
void print_pyramid_1_alt(int height) {
    for (int row = 1; row <= height; ++row) {
        for (int i = 0; i < height - row; ++i) printf(" ");
        for (int i = 0; i < row; ++i) printf("#");
        printf("\n");
    }
}

/*
 * A different solution that uses a loop and an if-statement instead of two loops.
 *
 * The advantage with this solution is that the mathematical expression for determining
 * the shape of the output is a single, clear expression:
 *      row + col > height
 */
void print_pyramid_2(int height) {
    for (int row = 1; row <= height; ++row) {
        for (int col = 1; col <= height; ++col) {
            if (row + col > height) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*
 * This is similar to print_pyramid_2(), except we instead use a ternary operator to
 * more succinctly determine the character printed.
 */
void print_pyramid_2_alt(int height) {
    for (int row = 1; row <= height; ++row) {
        for (int col = 1; col <= height; ++col) {
            printf(row + col > height ? "#" : " ");
        }
        printf("\n");
    }
}

/*
 * This solution involves modifying a buffer on each iteration of the loop.
 */
void print_pyramid_3(int height) {
    char *str = malloc(height + 1);
    if (!str) printf(NULL_MALLOC_MSG);
    
    memset(str, ' ', height);
    str[height] = '\0';

    for (int i = height - 1; i >= 0; --i) {
        str[i] = '#';
        printf("%s\n", str);
    }

    free(str); // Keep our planet clean. #FreeTheMalloc
}

/*
 * This one's a more novel solution that prepares a single buffer, then simply prints a
 * fixed-width section of it at a time.
 */
void print_pyramid_4(int height) {
    char *str = malloc(height * 2);
    if (!str) printf(NULL_MALLOC_MSG);
    
    memset(str, ' ', height);
    memset(str + height, '#', height);

    for (int i = 1; i <= height; ++i) {
        printf("%.*s\n", height, str + i);
    }

    free(str);
}

/*
 * This one's another novel solution that makes use of the same mechanism with the '#'
 * characters, but the spaces are done using by specifying a fixed width in the format
 * string.
 */
void print_pyramid_5(int height) {
    char *str = malloc(height + 1);
    if (!str) printf(NULL_MALLOC_MSG);

    memset(str, '#', height);
    str[height] = '\0';

    for (int i = height - 1; i >= 0; --i) {
        printf("%*s\n", height, str + i);
    }

    free(str);
}

/*
 * Unfortunately, there is no mechanism in printf to print the same arbitrary character
 * multiple times as far as I know.
 */
