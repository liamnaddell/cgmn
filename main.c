#include <stdio.h>
#include <stdlib.h>
#define BADINT_MINUS1 "\nSORRY, that was not detected as a valid integer"
#define PROMPT "\nPlease enter a number, friend:"
#define PROMPT_GAMEMASTER "\nEnter the number to be guessed:"
#define GUESS_GREATERTHAN "\nYour guess was too high :'("
#define GUESS_LESSTHAN "\nYour guess was too low :'("
#define INT_TOOBIG "\nNumber must be less than or equal to 2000\n"
#define INT_TOOSMALL "\nNumber must be above -1 or bad integer\n"
static long getInt();


int main() {
	printf(PROMPT_GAMEMASTER);
	long p1Input = getInt();
	long *p2Input = malloc(sizeof(long));
	if (p1Input == -1) {
		printf(BADINT_MINUS1);
		return 1;
	}
	if (p1Input < 0) {
		printf(INT_TOOSMALL);
		return 1;
	} else if (p1Input > 2000) {
		printf(INT_TOOBIG);
		return 1;
	}
	printf("\033c");
	short i;
	for ( i = 0; p1Input != *p2Input; i++) {
		printf(PROMPT);
		*p2Input = getInt();
		if (*p2Input == -1) {
			printf(BADINT_MINUS1); 
			return 1;
		}
		if (*p2Input < p1Input) {
			printf(GUESS_LESSTHAN); 
		}
		if (*p2Input > p1Input) {
			printf(GUESS_GREATERTHAN);
		}

	}
	free(p2Input);
	printf("It only took you %hi attempt(s)\n", i);
	return 0;
}

long getInt() {
	long myInt;
	long result = scanf("%li", &myInt);
	if(result < 1) {
		return -1;
	}
	return myInt;
}
