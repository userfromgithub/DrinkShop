/*
  *This program performs the user interface of the unmanned drink shop.
  *@GROUP 17
  *@GROUP MEMBER: B094020022 B097610007 B104020001 B104020002
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Customer.h"
#include "define.h"
 //UI variable
char confirm[CFM_LEN];
char command[SIZE];  
char clerk[] = {0}; //TIM 
char order[MAX][BOUGHT_BEV_LEN] = {'\0'}; // change variable name to orders
char numOfDrinks[] = {'\0'};

// we want to simulate the operationthe mode, so it is preset without input errors (because press buttons) 
// function main begins program execution
int main(void) {

	// clerk to turn on the drinks machine by giving their names	
	printf("PLEASE ENTER YOUR NAME: ");
	scanf("%s", clerk);
	machineOn(clerk);	
	readIngredient();
	
	printf("%s", WELCOME);
	Instruction();

	// process while-loop
	while(true) {
		printf("---> ");
		scanf("%s", command);
		if (strcmp(command, CHECK_MENU) == 0) { // enter MENU
			checkAvail();
			checkMenu();
		} 
		if(strcmp(command, CHECK_SHOP) == 0){ // enter SHOPINFOR
			checkShopInformation();
		}
		if (strcmp(command, ORDER) == 0) { // enter ORDER
			printf("%s", MAKE_ORDER);
			int num = 0;
			// process inner while-loop: to make an order
			while (true) {
				scanf("%s", order[num]);
				if (strcmp(order[num], END) == 0) {
					break;
				} 
				getchar();
				scanf("\n%c", &numOfDrinks[num]);
				num++;
			} 
			printf("%s", CONFIRM_ORDER); // prompt the customer to enter YES or NO
			scanf("%s", confirm);
			if (strcmp(confirm, YES) == 0) {
				makeOrder(num, order, numOfDrinks);
				makeBeverage(num, order, numOfDrinks);
				countIngredient(num, order, numOfDrinks); 
			} 
			else if (strcmp(confirm, NO) == 0) {
				printf("%s", ORDER_AGAIN);
				continue;
			} 			
			printf("%s", GET_RECEIPT); // prompt the customer to enter YES or NO 
			scanf("%s", confirm);
			if (strcmp(confirm, YES) == 0) { // get receipt --> printinvoice --> B097610007
				printInvoice(num, order, numOfDrinks);
				printf("%s", GET_PAY); // customer pay to the machine
				scanf("%d", &pay);
				giveChange(pay); 				
				printf("%s", THANKS);
				Sleep(2000); // to act as the waiting interval for the next customer to order
			} 
			else if (strcmp(confirm, NO) == 0) { // print total --> givechange
				noInvoice(num, order, numOfDrinks);
				printf("%s", GET_PAY); //customer pay to the machine
				scanf("%d", &pay);
				giveChange(pay); 
				printf("%s", THANKS); // to act as the waiting interval for the next customer to order
				Sleep(2000);
			} 
		} 
		if (strcmp(command, CLOSED) == 0) { // enter "CLOSE"
			printf("PLEASE ENTER YOUR NAME: "); // give the name of the clerk to turn off the machine
			scanf("%s", clerk);
			machineOff(clerk);
			printf("%s %d\n", PROFIT, profit);
			checkIngredient();
			return false;
		} 
	} 

	return 0; // program successfully operated 

} // end function main()
