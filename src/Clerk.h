#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
#include "Command.h"
#include "Define.h"

 // function prototypes
void punchIOTim(const char *name);
void machineOn(char *clerk);
void machineOff(char *clerk);
void waitMachine();

int Timwork = 1;

/* to punch in or punch out during the work;
input the name of the clerk and output aotomatically the current time
of the clerk either punching in or punching out; output it in the puching card form */

// function definition - punchIOTim
void punchIOTim(const char *name) {
	
	time_t t;
	time(&t);
	FILE *fp1;

		
	if (strcmp(name, "TIM") == 0) {
		fp1 = fopen("Tim.txt", "a");
		assert(fp1 != NULL);
		if ((Timwork % 2) == 1) {
			fprintf(fp1, "%-10s: %s", "PUNCH IN", ctime(&t));
			Timwork += 1;
		}
		else {
			fprintf(fp1, "%-10s: %s", "PUNCH OUT", ctime(&t));
			Timwork += 1;
		}
	}

	fclose(fp1);

}

// function definition - machineOn
// we view the clerk punch in as the opening time of the machine
void machineOn(char *clerk) {

	if (strcmp(clerk, TIM) == 0) {
		printf("%s", TURN_ON);
		waitMachine();
		printf("%s", MACHINE_ON); 
		punchIOTim(TIM);  
	}
}

// function definition - machineOff
// we view the clerk punch out as the opening time of the machine	
void machineOff(char *clerk) {

	if (strcmp(clerk, TIM) == 0) {
		printf("%s", TURN_OFF);
		waitMachine();
		printf("%s", MACHINE_OFF);
		punchIOTim(TIM);  
	}
}

// function definition - waitMachine
void waitMachine() {
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(".\n");
	Sleep(500);
}
