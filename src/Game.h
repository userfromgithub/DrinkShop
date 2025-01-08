#include <stdio.h>
#include <time.h>
// play game and get discount
int game() {
	// game rule
	printf("\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("* Let's get discount!!                                                    *\n");
	printf("* RULE:If your number is bigger or samlller than coumputer than you win!! *\n");
	printf("* Discount:WIN 1 ROUND  --> 10 %%OFF                                       *\n");
	printf("*          WIN 2 ROUNDS --> 20 %%OFF                                       *\n");
	printf("*          WIN 3 ROUNDS --> 30 %%OFF                                       *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	
	srand(time(NULL));	
	int flag = 0;
	int count = 0;
	int cost_number = 0;
	int rand_number = 0;
	int model;

	int i ;
	for(i = 0; i < 3 && flag != 1; i++) {
		printf("Enter your number (1 - 6):");
		scanf("%d", &cost_number);
		
		rand_number = rand() % 6 + 1;
		model = rand() % 2 + 1;

		if(model == 1) { // big model
			printf("MODEL:BIG!!\n");
			if(rand_number > cost_number) { // condition 1 - lose
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--YOU LOSE!!--\n\n");
				flag = 1;
			}
			else if(rand_number == cost_number) { // condition 2 - tie
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--EQUAL!!TRY AGAIN!--\n\n");		
			}
			else {	 // condition 3 - win
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--YOU WIN!!--\n\n");
				count++;			
		}		
		}
		else {		// small model
			printf("MODEL:SMALL!!\n");
			if(rand_number < cost_number) { // condition 1 - lose
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--YOU LOSE!!--\n\n");
				flag = 1;
			}
			else if(rand_number == cost_number) { //condition 2 - tie	
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--EQUAL!!TRY AGAIN!--\n\n");		
			}
			else {    // condition 3 - win
				printf("YOUR NUMBER    :%d\n", cost_number);
				printf("COMPUTER NUMBER:%d\n", rand_number);
				printf("--YOU WIN!!--\n\n");
				count++;			
			}		
		} 

	}
	switch(count) { //return discount
		case 0:
			printf("<YOU DIDN'T GET ANY DISCOUNT!>\n");
			return 0;
			break;
		case 1:
			printf("<YOU GOT 10 %%0FF!>\n");
			return 9;
			break;
		case 2:
			printf("<YOU GOT 20 %%0FF!>\n");
			return 8;
			break;
		case 3:
			printf("<YOU GOT 30 %%0FF!>\n");
			return 7;
			break;
		default :
			break;			
	}
}
