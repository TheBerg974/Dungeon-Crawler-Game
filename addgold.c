#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

//Made by: Samuel Bergeron 
//Student ID: 260925810

int main(void) {

	//Opening the HTML file
	FILE *f = fopen("../index.html", "r");
	char line[100];
	
	//CGI output tage
	printf("Content-Type:text/html\n\n");

	//Checking if the file exists
	if(f == NULL) {
		printf("<html>");
		printf("<head><title>ERROR</title></head>");
		printf("<body><p>Unable to open file!</p></body>");
		printf("</html>");
	} else {
		int gold;
		
		//getting the Query String
		char *data = getenv("QUERY_STRING");

		//Scanning the Query String
		sscanf(data, "gold=%d", &gold);

		int count = 0;
		
		//Looping through thw HTML file
		while(fgets(line, sizeof(line), f)) {
			printf("%s", line);
			//At the forty first line print the hidden field
			if(count == 41) {
				printf("<input type=\"hidden\" name=\"gold\"value=\"%d\">", gold);
			}
			count++;
		}
	}

	return 0;
}
