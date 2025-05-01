//Author: Colin Ames
//Purpose: Project 10
//Date: 4-28-25

#include <stdio.h>
#define wordlength 6
#define guessesallowed 6

int openword(char word[]);
void convertLowercase(char guess[]);
int check(char guess[]);
void convertGuess(char guess[], char word[]);
void showResults(char guess[], char word[], char uparrow[]);
void showUparrow(char uparrow[]);

int main(){
	char word[wordlength];
	char guess[wordlength];
	char uparrow[wordlength];
	int guesses = 0;
	int correct = 0;
	
	openword(word);
	
	while(guesses < guessesallowed && correct == 0){
		printf("GUESS %d! Enter your guess: ", guesses+1);
		scanf("%s", guess);
		convertLowercase(guess);
		
		if(check(guess) == 1){
	
			convertGuess(guess, word);
			showResults(guess, word, uparrow);
			showUparrow(uparrow);
			
			correct = 1;
			for(int index = 0; index < wordlength - 1; index++){
				if(guess[index] < 'A' || guess[index] > 'Z'){
					correct = 0;
				}
			}
			guesses++;
		}
	}
	
	if(correct == 1){
		printf("You won in %d guesses!\nNice!\n", guesses);
	}
	else{
	printf("You lost, better luck next time!\n");
	}
	
	return 0;
}

int openword(char word[]){
	FILE *wordfile = fopen("mystery.txt", "r");
	if(wordfile == NULL){
		return 0;
	}
	fscanf(wordfile, "%s", word);
	fclose(wordfile);
	return 0;
}

void convertLowercase(char guess[]){
	int index = 0;
	while(guess[index] != '\0'){
		if(guess[index] >= 'A' && guess[index] <= 'Z'){
		guess[index] = guess[index] + ('a'-'A');
		}
	index++;
}
}

int check(char guess[]){
	int index = 0;
	
	while(guess[index] != '\0'){
		if(!((guess[index] >= 'a' && guess[index] <= 'z') || (guess[index] >= 'A' && guess[index] <= 'Z'))){
			printf("Invalid characters used. Please try again: ");
			return 0;
		}
	index++;
	}
	
	if(index != (wordlength - 1)){
		printf("Your guess must be 5 letters long. Please try again: ");
		return 0;
	}
	
	return 1;
}

void convertGuess(char guess[], char word[]){
	int index;
	for(index = 0; index < wordlength-1; index++){
		if(guess[index] == word[index]){
			guess[index] = guess[index] - ('a' - 'A');
		}
	}
}

void showResults(char guess[], char word[], char uparrow[]){
	int index, index2;
	for(index = 0; index < wordlength - 1; index++){
		printf("%c", guess[index]);
	}
	printf("\n");
	
	for(index = 0; index < wordlength -1; index++){
		if(guess[index] == word[index]){
		uparrow[index] = ' ';
		}
		else{
		uparrow[index] = ' ';
		for(index2 = 0; index2 < wordlength - 1; index2++){
			if(guess[index] == word[index2]){
				uparrow[index] = '^';
				break;
			}
		}
		}
	}
}
	
void showUparrow(char uparrow[]){
	for(int index = 0; index < wordlength -1; index++){
	printf("%c", uparrow[index]);
	}
	printf("\n");
}


	
