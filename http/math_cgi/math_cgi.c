#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

int main()
{
	char buff[MAX];
	if(getenv("METHOD") != NULL){
		if(strcmp(getenv("METHOD"), "GET") == 0){
			strcpy(buff, getenv("QUERY_STRING"));
		}else{
			int content_length = atoi(getenv("CONTENT_LENGTH"));
			int i = 0;
			char c;
			for(; i < content_length; i++){
				read(0, &c, 1);
				buff[i] = c;
			}
			buff[i] = 0;
		}
		int x = 0;
		int y = 0;
		sscanf(buff,"x=%d&y=%d", &x, &y);
		printf("<html>");
		printf("<body>");
		printf("<h2>%d + %d = %d</h2>", x, y, x + y);
		printf("<h2>%d - %d = %d</h2>", x, y, x - y);
		printf("<h2>%d * %d = %d</h2>", x, y, x * y);
		if( y == 0 ){
			printf("<h2>%d / %d = %d, div zero</h2>\n", x, y, -1);
			printf("<h2>%d % %d = %d, div zero</h2>\n", x, y, -1);
		}else{
			printf("<h2>%d / %d = %d</h2>\n", x, y, x/y);
			printf("<h2>%d % %d = %d</h2>\n", x, y, x%y);
		}
		printf("</body>");
		printf("</html>");
	}
	return 0;
}





















