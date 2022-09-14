#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	//Number of times to repeat the tests
	const int repeats = 5;
	int *times = malloc(sizeof(int) * repeats);
	int time_average = 0;

	//Printing test
	long long timesToPrint = 1000000000;	//One Billion
	for(int c = 0; c < repeats; ++c){
		times[c] = time(NULL);
		for(int i = 0; i < timesToPrint; ++i){
			printf("-");
		}
		times[c] = time(NULL) - times[c];
	}
	for(int c = 0; c < repeats; c++){
		time_average += times[c];
	}
	printf("\nAverage time for counting test: %i\n", (time_average / 5));
}
