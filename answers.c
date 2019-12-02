#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Made by Samuel Bergeron
//Student ID: 260925810

//Method To print the empty HTML page with the link to other dungeons
void printToBrowser(char *data, int gold, char *direction){
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<a href=\"https://www.cs.mcgill.ca/~%s/cgi-bin/addgold.cgi?gold=%d\"> Press HERE to go %s </a>", data, gold, direction);
	printf("</html>"); 	
}

//Method to rpint the HTML page with the right ammount of gold coins
void printGold(int gold) {
	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("You have %d gold coins", gold);
	printf("<a href=\"https://www.cs.mcgill.ca/~sberge62/cgi-bin/addgold.cgi?gold=%d\"> Press HERE to go BACK </a>", gold);
	printf("</html>"); 
}

//Method to print the HTML page that says if the user is right or wrong 
void printAnswer(int right, int gold) {
	if(right == 1) {
		gold += 10;
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("This is the right answer!");
		printf("<a href=\"https://www.cs.mcgill.ca/~sberge62/cgi-bin/addgold.cgi?gold=%d\"> Press HERE to go Back</a>", gold);
		printf("</html>"); 
	} else {
		gold -= 5;
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("This is the wrong answer :( ");
		printf("<a href=\"https://www.cs.mcgill.ca/~sberge62/cgi-bin/addgold.cgi?gold=%d\"> Press HERE to go Back </a>", gold);
		printf("</html>"); 
	}
}

//Method to print the HTML page that says if the user won or lost
void printWinLose(int win) {
	if(win == 1) {
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("YOU WIN!");
		printf("</html>"); 
	} else {
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("YOU LOSE :'(");
		printf("</html>"); 
	}
}

//Main method
int main(void) {
	//Getting the Query String
	char *data = getenv("QUERY_STRING");

	//Assume 10 gold for any new user
	int gold = 10;

	//Boolean to check whether or not the query is contains the gold argument
	int goldCheck = 0; 
	
	char command[50];

	//Loopeint trhought the query to see if the user already has gold
	for(int i = 0; i < strlen(data); i++) {
		if(data[i] == '&') {
			goldCheck = 1;
		}
	}

	
	//Scanning the Query String appropriately get the right command as well as the ammount of gold
	if(goldCheck == 0) {
		sscanf(data, "command=%s", command);
	} else {
		sscanf(data, "%*[^=]%*c%[^&]%*[^=]%*c%d", command , &gold);
	}

	//Win/Lose condition as well as printing the right page
	if(gold >= 100) {
		printWinLose(1);
		return 0;	
	}

	if(gold <= 0) {
		printWinLose(0);
		return 0;
	}

	//Looking at the users command and doing the apropriatte thing
	if(strcmp("NORTH", command) == 0) {

		//Sending the user Noth
		printToBrowser("wmadih", gold, "North");

	}else if(strcmp("WEST", command) == 0) {
		
		//Sending the user West
		printToBrowser("hhuang80", gold, "West");

	}else if(strcmp("EAST", command) == 0) {
		
		//Sending the user east
		printToBrowser("rsowa", gold, "East");		

	}else if(strcmp("SOUTH", command) == 0) {
		
		//Sending the user South
		printToBrowser("hperez6", gold, "South");

	}else if(strcmp("GOLD", command) == 0) {
		
		//Sending the user to see his or her gold
		printGold(gold);

	}else if(strcmp("Ganondorf", command) == 0) {
		
		//Right Answer
		printAnswer(1, gold);

	}else {
		//Wrong Answer
		printAnswer(0, gold);

	}	

	return 0;
}

