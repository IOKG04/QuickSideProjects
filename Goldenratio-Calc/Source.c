#include <stdio.h>

int main(){
    printf("Amout to calculate: ");
    int a;
    scanf("%i", &a);
    printf("\n");

    double result = 1;
    for(int i = 0; i < a; ++i){
	printf("Result for %i:\t%lf\n", i, result);
	result = 1 + (1 / result);
    }

    return 0;
}
