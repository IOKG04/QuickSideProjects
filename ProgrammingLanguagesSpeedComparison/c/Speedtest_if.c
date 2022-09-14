#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	//Number of times to repeat the tests
	const int repeats = 5;
	int *times = malloc(sizeof(int) * repeats);
	int time_average = 0;

	//Printing test
	const long long timesToRepeat = 10000000000;	//Ten Billion
	for(int c = 0; c < repeats; ++c){
		int result = 0;
		times[c] = time(NULL);
		for(long long i = 0; i < timesToRepeat; ++i){
			if(i % 2 == 0){
				++result;
			}
			if(i % 3 == 0){
				--result;
			}
			/*if(i % (timesToRepeat % i) == 0){
				result = !result;
			}*/
		}
		times[c] = time(NULL) - times[c];
	}
	for(int c = 0; c < repeats; c++){
		time_average += times[c];
	}
	printf("\nAverage time for if test: %i\n", (time_average / 5));
}
