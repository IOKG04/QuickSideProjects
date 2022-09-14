#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	//Number of times to repeat the tests
	const int repeats = 5;
	int *times = malloc(sizeof(int) * repeats);
	int time_average = 0;
	int so_there_is_an_effect = 0;

	//Counting test
	const long long countTo = 10000000000;	//Ten billion
	for(int c = 0; c < repeats; ++c){
		times[c] = time(NULL);
		for(long long i = 0; i < countTo; ++i){
			so_there_is_an_effect += i;
		}
		times[c] = time(NULL) - times[c];
	}
	for(int c = 0; c < repeats; c++){
		time_average += times[c];
	}
	printf("\nAverage time for counting test: %i\n", (time_average / 5));
	time_average = 0;



	printf("\n%i\n", so_there_is_an_effect);
}
