#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "DrinkStruct.h"
#include "Clerk.h"
#include "Game.h"
#include "SetPoint.h"

// function prototypes
void Instruction();
void makeBeverage(int n, char item_name[][BOUGHT_BEV_LEN], char comb[]);
void countIngredient(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]); 
void printInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]);
void manageInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]);
void noInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]);
void giveChange(int pay);
void readIngredient(); 
void checkAvail();
bool notExist(char *item);

int countTotal();
int beforeDiscount();



int saveInd[INGR_NUM];
int noAvailnum = 0;
char noAvail[INGR_NUM][INGR_LEN];



int ingnum[INGR_NUM]; 
char ingredient[INGR_NUM][INGR_LEN]; 
char temp[MAX][BOUGHT_BEV_LEN] = {0};
char cupSize[MAX] = {0};
char ans[5];

int numOfeach[MAX] = {0};
int type = 1;
int discount = 0;
int total = 0;
int pay = 0;
int point = 0;
int profit = 0;//++

// function definition - Instruction
void Instruction() {
	
	printf("--------------------------------------------INSTRUCTION--------------------------------------------\n\n");
	printf("MENU/SHOPINFO/ORDER ---> NAME OF DRINKS ---> END ---> (CONFIRM ORDER?)YES/NO ---> (RECEIPT?)YES/NO\n\n");
		
}

// function definition - makeBeverage
void makeBeverage(int n, char item_name[][BOUGHT_BEV_LEN], char comb[]) {
	
	// just assume that the input of beverage name always is correct
	FILE *fp;
	char name[20];
	char recipe[50];

	size_t i = 0;
   
	while (i < n) {
		fp = fopen("RECIPE.txt","r");
		assert(fp != NULL);	
		while(fscanf(fp, "%s %[^\n]%*c", name, recipe) != EOF) {
			if(strcmp(name, item_name[i]) == 0) {
				printf("Making! Please wait");
				waitMachine();
				printf("%-10s ---> %s %c\n", recipe, name, comb[i]);
				printf("Done!\n\n");
			} 
		} 
		i++;
	}
	
}

// function definition - readIngredient
void readIngredient() {
	
	FILE *fp;
	fp = fopen("PURCHASE.txt","r");
	assert(fp != NULL);
	size_t i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %d", Initingt.ingname, &Initingt.ingnum);
		strcpy(ingredient[i], Initingt.ingname);
		ingnum[i] = Initingt.ingnum;
		i++;
	}
	fclose(fp);
	
}

// function definition - countIngredient
void countIngredient(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]) {
	
	FILE *fp;
	
	size_t i = 0;
	while (i < n) {
		fp = fopen("INGREDIENTS.txt","r");
		assert(fp != NULL);
		while(!feof(fp)) {
			fscanf(fp, "%s %s %s %s %s", Ingt.name, Ingt.ing1, Ingt.ing2, Ingt.ing3, Ingt.ing4);
			if(strcmp(Ingt.name, item_name[i]) == 0 && cup[i] == 'M') {
				size_t j;
				for (j = 0; j < INGR_NUM; j++) {
					if (strcmp(ingredient[j], Ingt.ing1) == 0) {
						ingnum[j]--;
					}
					else if (strcmp(ingredient[j], Ingt.ing2) == 0) {
						ingnum[j]--;
					}
					else if (strcmp(ingredient[j], Ingt.ing3) == 0) {
						ingnum[j]--;
					}
					else if (strcmp(ingredient[j], Ingt.ing4) == 0) {
						ingnum[j]--;
					}
				}
				break;
			} 
			else if(strcmp(Ingt.name, item_name[i]) == 0 && cup[i] == 'L') {
				size_t j;
				for (j = 0; j < INGR_NUM; j++) {
					if (strcmp(ingredient[j], Ingt.ing1) == 0) {
						ingnum[j] -= 2;
					}
					else if (strcmp(ingredient[j], Ingt.ing2) == 0) {
						ingnum[j] -= 2;
					}
					else if (strcmp(ingredient[j], Ingt.ing3) == 0) {
						ingnum[j] -= 2;
					}
					else if (strcmp(ingredient[j], Ingt.ing4) == 0) {
						ingnum[j] -= 2;
					}
				}
				break;
			}
		} 
		i++;
	}	
	fclose(fp);
	
} 

// function definition - printInvoice
void printInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]) {
	
	srand(time(NULL));
	// ask customer if they want get discount
	printf("%s", GET_DISCOUNT);
	scanf("%s", ans);
	if(strcmp(ans, "YES") == 0) {
		discount = game();
	}
	else if(strcmp(ans, "NO") == 0 ){
		printf("You lose your chance. >_< !!\n");
	}

	manageInvoice(n, item_name, cup);
	printf("%s", PRINT_INVOICE);
	printf("\n%25s", "E-INVOICE\n");
	printf("%16c%c-",(rand() % (90 - 65 + 1) + 65),(rand() % (90 - 65 + 1) + 65));
	printf("%d\n", rand() % (999999 - 100000 + 1) + 100000);
	
	struct tm *local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	//MON[0-11]
	//YEAR is current year-1900
	printf("%d-%d-%d %d:%d:%d\n", local->tm_year + 1900 , local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
	printf("-----------------------------------------\n");
	printf("ITEMS %33s\n\n", "AMOUNT");

	countTotal();
	
	printf("-----------------------------------------\n");
 
 	local->tm_min += n;
	if(local->tm_min > 60) {
		local->tm_hour += 1;
		local->tm_min -= 60;
	}
	printf("FINISHING_TIME: %d:%d:%d\n", local->tm_hour, local->tm_min, local->tm_sec);	
	printf("-----------------------------------------\n");
	printf("NUMBER%31d\n", n);
	printf("ORIGINAL PRICE%23d\n", total);

	if(discount != 0) {
		discount  = total - ((total * discount) / 10);
		printf("DISCONT%30d\n", -(discount));
		total -= discount;
	}
	else {
		printf("DISCONT%30s\n", "0");
	}

	point = setPoint(total);
	profit += total;//++
	printf("POINT%32d\n",point);
	printf("-----------------------------------------\n");		
	printf("%-30s NT$ %d\n", "TOTAL", total, n);
	printf("-----------------------------------------\n");
	//print loyalt card
	printf("\n\n");
	loyaltCard(point);
	printf("\n");
	
	// to empty the arrays
	memset(temp, 0, sizeof(temp));
	memset(cupSize, 0, sizeof(cupSize));
	memset(numOfeach, 0, sizeof(numOfeach));	
	//reset discount
	discount = 0; 
	
}

// function definition - manageInvoice
void manageInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]) {
	
	size_t i = 1;
    size_t j = 0;

    strcpy(temp[0], item_name[0]);
    cupSize[0] = cup[0];
    numOfeach[0] = 1;

    int count = 0;
    int check = 0;
	int exist = 0;
	
	// process while-loop
    while (i < n) {
        j = 0;
  	    count = 0;
  	    exist = 0;
  	    // process hwile-loop: to check whether the ordered beverage with the cup size already exists in the array
        while (j < type) {
            if (strcmp(temp[j], item_name[i]) != 0) { // if not
                count += 1; // count the times this condition occurs
            } 
            else if (strcmp(temp[j], item_name[i]) == 0) { // otherwise
                if (cupSize[j] == cup[i]) { // the beverage with its cup size exists
     				numOfeach[j] += 1;
     				exist = 1;
     				break;
    			} 
				else {
     				check += 1;
    			} 
   			} 
   			j++;
  		} 
  		// process if-statement
  		if (check == 1 && exist != 1) {
   			strcpy(temp[type], item_name[i]);
   			cupSize[type] = cup[i]; 
   			numOfeach[j] += 1;
   			type += 1;
   			check = 0;
   			exist = 0;
  		} 
  		if (count == type) {
   			cupSize[type] = cup[i];
      		strcpy(temp[type], item_name[i]);
      		numOfeach[j] += 1;
   			type += 1;
  		} 
  		i++;
 	} 
 	
}

// function definition - counTotal
int countTotal() {
	//counttotal and print invoice
	size_t i = 0;
	FILE *fp;
	while (i < type) {
		fp = fopen("MENU.txt","r");
		assert(fp != NULL);
		while (!feof(fp)) {
			fscanf(fp, "%s %d %d %s %d %d", Drink1.name, &Drink1.Mprice, &Drink1.Lprice, Drink2.name, &Drink2.Mprice, &Drink2.Lprice);
			if (strcmp(Drink1.name, temp[i]) == 0 && (cupSize[i] == 'M')) {
				total += Drink1.Mprice * numOfeach[i];
				printf("%-26s (%c) NT$ %d X%d\n", Drink1.name, cupSize[i], Drink1.Mprice, numOfeach[i]);
				break;
			}
			else if (strcmp(Drink1.name, temp[i]) == 0 && (cupSize[i] == 'L')) {
				total += Drink1.Lprice * numOfeach[i];
				printf("%-26s (%c) NT$ %d X%d\n", Drink1.name, cupSize[i], Drink1.Lprice, numOfeach[i]);
				break;
			} 
			else if (strcmp(Drink2.name, temp[i]) == 0 && (cupSize[i] == 'M')) {
				total += Drink2.Mprice * numOfeach[i];
				printf("%-26s (%c) NT$ %d X%d\n", Drink2.name, cupSize[i], Drink2.Mprice, numOfeach[i]);
				break;
			}
			else if (strcmp(Drink2.name, temp[i]) == 0 && (cupSize[i] == 'L')) {
				total += Drink2.Lprice * numOfeach[i];
				printf("%-26s (%c) NT$ %d X%d\n", Drink2.name, cupSize[i], Drink2.Lprice, numOfeach[i]);
				break;
			}
		}
		i++;
	}	
	fclose(fp);
	return total;
	
}

// function definition - giveChage 
void giveChange(int pay) {

	if (pay > total) {
		printf("%-14s:%3d\n", "CHANGE", (pay - total));
	}
	else if (pay == total) {
		printf("%-14s:%3d\n", "CHANGE", 0);
	}
	total = 0;
}

// function definition - no_invoice
void noInvoice(int n, char item_name[][BOUGHT_BEV_LEN], char cup[]) {
	//print tatal
	manageInvoice(n, item_name, cup);
	printf("\nTOTAL:%3d\n", beforeDiscount());
	//print point
	point = setPoint(total);
	profit += total;//++
	printf("POINT:%3d\n",point);
	//print loyalt card
	loyaltCard(point);
	printf("\n");		

	memset(temp, 0, sizeof(temp));
	memset(cupSize, 0, sizeof(cupSize));
	memset(numOfeach, 0, sizeof(numOfeach));
	
}

// function definition - before_discount
int beforeDiscount() {
	//count total without discount and print invoice
	size_t i = 0;
	total = 0;
	FILE *fp;
	while (i < type) {
		fp = fopen("MENU.txt","r");
		assert(fp != NULL);
		while (!feof(fp)) {
			fscanf(fp, "%s %d %d %s %d %d", Drink1.name, &Drink1.Mprice, &Drink1.Lprice, Drink2.name, &Drink2.Mprice, &Drink2.Lprice);
			if (strcmp(Drink1.name, temp[i]) == 0 && (cupSize[i] == 'M')) {
				total += Drink1.Mprice * numOfeach[i];
				break;
			}
			else if (strcmp(Drink1.name, temp[i]) == 0 && (cupSize[i] == 'L')) {
				total += Drink1.Lprice * numOfeach[i];
				break;
			} 
			else if (strcmp(Drink2.name, temp[i]) == 0 && (cupSize[i] == 'M')) {
				total += Drink2.Mprice * numOfeach[i];
				break;
			}
			else if (strcmp(Drink2.name, temp[i]) == 0 && (cupSize[i] == 'L')) {
				total += Drink2.Lprice * numOfeach[i];
				break;
			}
		}
		i++;
	}	
	fclose(fp);
	return total;
	
}
void checkIngredient() {
 
	printf("    %s\n", INVENTORY);
	size_t i;
	for (i = 0; i < INGR_NUM; i++) {
		printf("%-25s: %4d serving\n", ingredient[i], ingnum[i]);
	}

}

void checkAvail() {
	
	int ind = 0;
	size_t j = 0;
	for (j = 0; j < INGR_NUM; j++) {
		if (ingnum[j] == 0) {
			saveInd[ind] = j;
			ind++;
		}
	}
	
	FILE *fp2;

	size_t i = 0;
	while (i < ind) {
		fp2 = fopen("INGREDIENTS.txt","r");
		while(!feof(fp2)) {
			fscanf(fp2, "%s %s %s %s %s", Ingt.name, Ingt.ing1, Ingt.ing2, Ingt.ing3, Ingt.ing4);
			if(strcmp(ingredient[saveInd[i]], Ingt.ing1) == 0) {
				if (notExist(Ingt.name) == true) {
					strcpy(noAvail[noAvailnum], Ingt.name);
					noAvailnum++;
				}
				else {
					break;
				}
			} else if (strcmp(ingredient[saveInd[i]], Ingt.ing2) == 0) {
				if (notExist(Ingt.name) == true) {
					strcpy(noAvail[noAvailnum], Ingt.name);
					noAvailnum++;
				}
				else {
					break;
				}
			} else if (strcmp(ingredient[saveInd[i]], Ingt.ing3) == 0) {
				if (notExist(Ingt.name) == true) {
					strcpy(noAvail[noAvailnum], Ingt.name);
					noAvailnum++;
				}
				else {
					break;
				}
			} else if (strcmp(ingredient[saveInd[i]], Ingt.ing4) == 0) {
				if (notExist(Ingt.name) == true) {
					strcpy(noAvail[noAvailnum], Ingt.name);
					noAvailnum++;
				}
				else {
					break;
				}
			}
		}
		fclose(fp2);
		i++;
	}
	
	size_t m = 0;
	for (m = 0; m < noAvailnum; m++) {
		if(m == 0) {
			printf("\n---- %s ----\n", NOAVAIL);	
			printf("      %2d. %s\n", m + 1, noAvail[m]);
			if(m + 1 == noAvailnum) {
				printf("---- %13s%15s", "END", "----");
			}
		}
		else if( m == noAvailnum - 1) {
			printf("      %2d. %s\n", m + 1, noAvail[m]);			
			printf("---- %13s%15s", "END", "----");
		}
		else {
			printf("      %2d. %s\n", m + 1, noAvail[m]);		
		}
	}
	printf("\n-------------------------------------------------------------------------------\n");
	
}

bool notExist(char *item) {
	
	int count = 0;
	size_t i = 0;
	for (i = 0; i < noAvailnum; i++) {
		count = 0;
		if (strcmp(item, noAvail[i]) == 0) {
			return false;
		} else {
			count++;
		}
    }
    
    if (count == noAvailnum) {
    	return true;
	}
}
