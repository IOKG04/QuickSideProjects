#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	//Create variables
	char** countries = malloc(sizeof(char*) * 48);
	char** capitals = malloc(sizeof(char*) * 48);
	for(int i = 0; i < 48; i++){
		countries[i] = malloc(sizeof(char) * 29);
		capitals[i] = malloc(sizeof(char) * 20);
	}
	int correct, wrong1, wrong2, wrong3, picked, correct_placement, repeats, wrongs;
	unsigned int seed;

	//Initialize variables
	seed = time(NULL);
	wrongs = 0;

	//Countries
	strcpy(countries[0], "Afghanistan\x00");
	strcpy(countries[1], "Armenien\x00");
	strcpy(countries[2], "Aserbaidschan\x00");
	strcpy(countries[3], "Bahrein\x00");
	strcpy(countries[4], "Bangladesch\x00");
	strcpy(countries[5], "Bhutan\x00");
	strcpy(countries[6], "Brunei\x00");
	strcpy(countries[7], "China\x00");
	strcpy(countries[8], "Georgien\x00");
	strcpy(countries[9], "Indien\x00");
	strcpy(countries[10], "Indonesien\x00");
	strcpy(countries[11], "Irak\x00");
	strcpy(countries[12], "Iran\x00");
	strcpy(countries[13], "Isreal\x00");
	strcpy(countries[14], "Japan\x00");
	strcpy(countries[15], "Jemen\x00");
	strcpy(countries[16], "Jordanien\x00");
	strcpy(countries[17], "Kambodscha\x00");
	strcpy(countries[18], "Kasachstan\x00");
	strcpy(countries[19], "Katar\x00");
	strcpy(countries[20], "Kirgisistan\x00");
	strcpy(countries[21], "Kuwait\x00");
	strcpy(countries[22], "Laos\x00");
	strcpy(countries[23], "Libanon\x00");
	strcpy(countries[24], "Malaysia\x00");
	strcpy(countries[25], "Malediven\x00");
	strcpy(countries[26], "Mongolei\x00");
	strcpy(countries[27], "Myanmar\x00");
	strcpy(countries[28], "Nepal\x00");
	strcpy(countries[29], "Nordkorea\x00");
	strcpy(countries[30], "Oman\x00");
	strcpy(countries[31], "Ostimor\x00");
	strcpy(countries[32], "Pakistan\x00");
	strcpy(countries[33], "Philippinen\x00");
	strcpy(countries[34], "Russland\x00");
	strcpy(countries[35], "Saudi-Arabien\x00");
	strcpy(countries[36], "Singapur\x00");
	strcpy(countries[37], "Sri Lanka\x00");
	strcpy(countries[38], "Suedkorea\x00");
	strcpy(countries[39], "Syrien\x00");
	strcpy(countries[40], "Tadschikistan\x00");
	strcpy(countries[41], "Taiwan\x00");
	strcpy(countries[42], "Thailand\x00");
	strcpy(countries[43], "Tuerkei\x00");
	strcpy(countries[44], "Turkmenistan\x00");
	strcpy(countries[45], "Usbekistan\x00");
	strcpy(countries[46], "Vereinigte Arabische Emirate\x00");
	strcpy(countries[47], "Vietnam\x00");
	//Capitals
	strcpy(capitals[0], "Kabul\x00");
	strcpy(capitals[1], "Jerewan\x00");
	strcpy(capitals[2], "Baku\x00");
	strcpy(capitals[3], "Manama\x00");
	strcpy(capitals[4], "Dhaka\x00");
	strcpy(capitals[5], "Thimphu\x00");
	strcpy(capitals[6], "Bandar Seri Begawan\x00");
	strcpy(capitals[7], "Peking\x00");
	strcpy(capitals[8], "Tifilis\x00");
	strcpy(capitals[9], "Neu-Delhi\x00");
	strcpy(capitals[10], "Jakarta\x00");
	strcpy(capitals[11], "Bagdad\x00");
	strcpy(capitals[12], "Teheran\x00");
	strcpy(capitals[13], "Jerusalem\x00");
	strcpy(capitals[14], "Tokio\x00");
	strcpy(capitals[15], "Sana\x00");
	strcpy(capitals[16], "Amman\x00");
	strcpy(capitals[17], "Phnom Penh\x00");
	strcpy(capitals[18], "Nur Sultan\x00");
	strcpy(capitals[19], "Doha\x00");
	strcpy(capitals[20], "Bischkek\x00");
	strcpy(capitals[21], "Kuwait\x00");
	strcpy(capitals[22], "Vientiane\x00");
	strcpy(capitals[23], "Beirut\x00");
	strcpy(capitals[24], "Kuala Lumpur\x00");
	strcpy(capitals[25], "Male\x00");
	strcpy(capitals[26], "Ulan Bator\x00");
	strcpy(capitals[27], "Naypyidaw\x00");
	strcpy(capitals[28], "Katmandu\x00");
	strcpy(capitals[29], "Pjoengjang\x00");
	strcpy(capitals[30], "Maskat\x00");
	strcpy(capitals[31], "Dili\x00");
	strcpy(capitals[32], "Islamabad\x00");
	strcpy(capitals[33], "Manila\x00");
	strcpy(capitals[34], "Moskau\x00");
	strcpy(capitals[35], "Riad\x00");
	strcpy(capitals[36], "Singapur\x00");
	strcpy(capitals[37], "Colombo\x00");
	strcpy(capitals[38], "Seoul\x00");
	strcpy(capitals[39], "Damaskus\x00");
	strcpy(capitals[40], "Dushanbe\x00");
	strcpy(capitals[41], "Taipeh\x00");
	strcpy(capitals[42], "Bangkok\x00");
	strcpy(capitals[43], "Ankara\x00");
	strcpy(capitals[44], "Ashgabat\x00");
	strcpy(capitals[45], "Taschkent\x00");
	strcpy(capitals[46], "Abu Dhabi\x00");
	strcpy(capitals[47], "Hanoi\x00");
	
	//Loop
	printf("How often do you want to train? ");
	scanf("%i", &repeats);
	printf("\n\n");
	for(int i = 0; i < repeats; i++){
		//Get random answers
		correct = rand_r(&seed) % 48;
		++seed;
		correct_placement = rand_r(&seed) % 4;
		++seed;
		do {
			wrong1 = rand_r(&seed) % 48;
			++seed;
			wrong2 = rand_r(&seed) % 48;
			++seed;
			wrong3 = rand_r(&seed) % 48;
			++seed;
		}while (correct == wrong1 || correct == wrong2 || correct == wrong3 || wrong1 == wrong2 || wrong1 == wrong3 || wrong2 == wrong3);

		if(i % 2 == 0){
			//Given capital find country
			printf("%s\n\n", capitals[correct]);
			if(correct_placement == 0){
				printf("0: %s\n", countries[correct]);
				printf("1: %s\n", countries[wrong1]);
				printf("2: %s\n", countries[wrong2]);
				printf("3: %s\n", countries[wrong3]);
			}
			if(correct_placement == 1){
				printf("0: %s\n", countries[wrong1]);
				printf("1: %s\n", countries[correct]);
				printf("2: %s\n", countries[wrong2]);
				printf("3: %s\n", countries[wrong3]);
			}
			if(correct_placement == 2){
				printf("0: %s\n", countries[wrong1]);
				printf("1: %s\n", countries[wrong2]);
				printf("2: %s\n", countries[correct]);
				printf("3: %s\n", countries[wrong3]);
			}
			if(correct_placement == 3){
				printf("0: %s\n", countries[wrong1]);
				printf("1: %s\n", countries[wrong2]);
				printf("2: %s\n", countries[wrong3]);
				printf("3: %s\n", countries[correct]);
			}
			printf("\nWhich answer is correct? ");
			scanf("%i", &picked);
			if(picked == correct_placement){
				printf("\nCorrect!\n");
			}
			else{
				printf("\nWrong. The right answer would have been: %s\n", countries[correct]);
				++wrongs;
			}
		}
		else{
			//Given country find capital
			printf("%s\n\n", countries[correct]);
			if(correct_placement == 0){
				printf("0: %s\n", capitals[correct]);
				printf("1: %s\n", capitals[wrong1]);
				printf("2: %s\n", capitals[wrong2]);
				printf("3: %s\n", capitals[wrong3]);
			}
			if(correct_placement == 1){
				printf("0: %s\n", capitals[wrong1]);
				printf("1: %s\n", capitals[correct]);
				printf("2: %s\n", capitals[wrong2]);
				printf("3: %s\n", capitals[wrong3]);
			}
			if(correct_placement == 2){
				printf("0: %s\n", capitals[wrong1]);
				printf("1: %s\n", capitals[wrong2]);
				printf("2: %s\n", capitals[correct]);
				printf("3: %s\n", capitals[wrong3]);
			}
			if(correct_placement == 3){
				printf("0: %s\n", capitals[wrong1]);
				printf("1: %s\n", capitals[wrong2]);
				printf("2: %s\n", capitals[wrong3]);
				printf("3: %s\n", capitals[correct]);
			}
			printf("\nWhich answer is correct? ");
			scanf("%i", &picked);
			if(picked == correct_placement){
				printf("\nCorrect!\n");
			}
			else{
				printf("\nWrong. The right answer would have been: %s\n", capitals[correct]);
				++wrongs;
			}
		}
		printf("\n\n");
	}

	printf("Wrong answers: %i\n", wrongs);
	printf("You got ~%i%% wrong.\n",  (100 * wrongs) / repeats);

	//Free memory
	for(int i = 0; i < 48; i++){
		free(countries[i]);
		free(capitals[i]);
	}
	free(countries);
	free(capitals);
	return 0;
}
