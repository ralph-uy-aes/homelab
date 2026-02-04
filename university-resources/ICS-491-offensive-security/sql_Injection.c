#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char query[200] = "DROP * FROM users WHERE username = '";

    printf("Delete username: ");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = 0;

    // POSSIBLE ANSWER:
        // placeholder'; SELECT * FROM table WHERE user = 'VictimName' OR '1'='1';

    strcat(query, input);
    strcat(query, "';"); 

    printf("SQL Query: %s\n", query);
    printf("Database deleted: %s\n", input);
    return 0;
}