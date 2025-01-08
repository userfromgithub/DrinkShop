#include <stdio.h>
#include <string.h>
//count point
int setPoint(int total) {
	int point = 0;
	
	// 100 dollar 1 point	
	if(total > 1000) {
		total /= 100;
		point = total;
		return point;
	}
	else if(total < 100) {
		return 0; 
	}
	else {
		point = total / 100;
		return point ;
	}

} 
//print loyalt card
void loyaltCard(int point) {
	
	while(point > 10) {
		point -= 10;
		loyaltCard(10);
		printf("\n");
	}
	
	printf("* * * * * * * * * * * * * * * * * * * * * \n");
	printf("*              Loyalt Card              *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * \n");
	switch(point) {
		case 0:
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");
			break;
		case  1: 
			printf("* drink |       |       |       |       *\n");
			printf("* point |       |       |       |       *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");
			break;
		case  2: 
			printf("* drink | drink |       |       |       *\n");
			printf("* point | point |       |       |       *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");
			break;
		case  3: 
			printf("* drink | drink | drink |       |       *\n");
			printf("* point | point | point |       |       *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");
			break;
		case 4:
			printf("* drink | drink | drink | drink |       *\n");
			printf("* point | point | point | point |       *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");	
			break;
		case  5: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");
			printf("*       |       |       |       |       *\n");
			printf("*       |       |       |       |       *\n");	
			break;
		case  6: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");
			printf("* drink |       |       |       |       *\n");
			printf("* point |       |       |       |       *\n");		
			break;
		case  7: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");
			printf("* drink | drink |       |       |       *\n");
			printf("* point | point |       |       |       *\n");	
			break;
		case  8: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");	
			printf("* drink | drink | drink |       |       *\n");
			printf("* point | point | point |       |       *\n");
			break;
		case  9: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");
			printf("* drink | drink | drink | drink |       *\n");
			printf("* point | point | point | point |       *\n");
			break;	
		case  10: 
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			printf("* ------------------------------------- *\n");
			printf("* drink | drink | drink | drink | drink *\n");
			printf("* point | point | point | point | point *\n");
			break;
		default :
			break;
	}
	printf("* * * * * * * * * * * * * * * * * * * * * \n");
}
