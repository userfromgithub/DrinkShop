#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "DrinkShop.h"

 // function prototypes
void checkMenu();
void checkShopInformation();
void makeOrder(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]);

char search[20];
const char MENU[] = "CHECKMENU";
const char SEASONAL[] = "SEASONAL";
const char MILK_TEA[] = "MILK TEA";
const char TEA_LATTE[] = "TEA LATTE";
const char FRUIT_TEA[] = "FRUIT TEA";
const char SHOP_INFORMATION[] = "SHOP_INFORMATION"; 

// function definition - checkShopinformation
void checkMenu() { 

	FILE *fp;
	printf("HERE'S THE MENU!\n");
	fp = fopen("menu.txt","r");	
	assert(fp != NULL);	
		
	int count = 0;
	printf("\t\t\t\t\t< MENU >\t\t\t\t\n\n");
	while(!feof(fp) && count < 10){		
		if (count < 5) {
			if (count == 0) {
				printf("%15s %13s %8s %14s %15s %10s", "MILK TEA", "NT$(M)", "NT$(L)", "FRUIT", "NT$(M)", "NT$(L)\n\n");
			}		
			fscanf(fp, "%s %d %d %s %d %d", milk_tea.name, &milk_tea.Mprice, &milk_tea.Lprice, fruit_tea.name, &fruit_tea.Mprice, &fruit_tea.Lprice);
			printf("%-25s %d %6d\t%-25s %2d %6d\n", milk_tea.name, milk_tea.Mprice, milk_tea.Lprice, fruit_tea.name, fruit_tea.Mprice, fruit_tea.Lprice);
			} else if (count >= 5) {
				if (count == 5) {
					printf("\n");
				    printf("%15s %13s %8s %16s %13s %10s", "SEASONAL", "NT$(M)", "NT$(L)", "TEA LATTE", "NT$(M)", "NT$(L)\n\n");
				}
			fscanf(fp, "%s %d %d %s %d %d", seasonal_tea.name, &seasonal_tea.Mprice, &seasonal_tea.Lprice, tea_latte.name, &tea_latte.Mprice, &tea_latte.Lprice);
			printf("%-25s %d %6d\t%-25s %2d %6d\n", seasonal_tea.name, seasonal_tea.Mprice, seasonal_tea.Lprice, tea_latte.name, tea_latte.Mprice, tea_latte.Lprice);
			}
			count += 1;
		}

		fclose(fp);	
		printf("\n");
}

// function definition - checkShopInformation
void checkShopInformation() {

	FILE *fp;
	char string[1000];	
	printf("\t\t\t<HERE IS THE SHOPINFORMATION>\n");
	fp = fopen("SHOPINFO.txt","r");
	assert(fp != NULL);	
		
	while(fgets(string, 1000, fp) != NULL){
		fputs(string, stdout);
	}
	fclose(fp);
	printf("\n\n");
}

// function definition - makeOrder
void makeOrder(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]) {
	
	printf("\nTHANK YOU!\nNOW PROCESSING YOUR ORDER\n");
	waitMachine();
	printf("So your order goes:\n");
	int temp = 0;
	while (temp < n) {
		printf("%s %c\n", item_name[temp], cup[temp]);
		temp++;
	}
	printf("\n");
}

