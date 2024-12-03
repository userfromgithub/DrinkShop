#include <stdio.h>

struct drinks {
	char name[30];
	int Mprice;
	int Lprice;
};

struct ingts {
	char name[30];
	char ing1[30];
	char ing2[30];
	char ing3[30];
	char ing4[30];
};

struct initingts {
	char ingname[30];
	int ingnum;
};

struct drinks Drink1 = {"", 0, 0};
struct drinks Drink2 = {"", 0, 0};
struct drinks milk_tea = {"", 0, 0};
struct drinks fruit_tea = {"", 0, 0};
struct drinks seasonal_tea = {"", 0, 0};
struct drinks tea_latte = {"", 0, 0};


struct ingts Ingt = {"", "", "", "", ""}; 
struct initingts Initingt = {"", 0}; 
