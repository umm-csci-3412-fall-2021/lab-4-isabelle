#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#define chunk 1

/*
 * Checks is a character is a vowel, returns true
 * if the character is a vowel and false otherwise.
 */
bool is_vowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
	c=='A' || c=='E' || c=='I' || c =='O' || c=='U') {return true;}
	return false;
}

/*
 * Takes all non-vowels from in_buf and copies them
 * over to out_buf, and returns the number of non-vowels.
 */ 
int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int nonVowel = 0;
	for(int i=0; i < num_chars; i++){
		if(!is_vowel(in_buf[i])){
			out_buf[nonVowel] = in_buf[i];
			nonVowel++;
		}
	}
	return nonVowel;
}

/*
 * Copies all of the non-vowels from the input file to
 * the output file.
 */
void disemvowel(FILE* inputFile, FILE* outputFile){
	char* inBuffer = (char*) calloc(BUF_SIZE, sizeof(char));
	char* outBuffer = (char*) calloc(BUF_SIZE, sizeof(char));
	while(chunk!=0){
		chunk == fread(inBuffer,sizeof(char),BUF_SIZE,inputFile);
		int nonVowels = copy_non_vowels(chunk, inBuffer, outBuffer);
		fwrite(outBuffer, sizeof(char), nonVowels, outputFile);
	}
	free(inBuffer);
	free(outBuffer);
}

int main(int argc, char *argv[]){
	FILE *inputFile = stdin;
	FILE *outputFile = stdout;

	disemvowel(inputFile, outputFile);
	return 0;
}
