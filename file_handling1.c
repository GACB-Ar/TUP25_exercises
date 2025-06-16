#include <stdio.h>

void read_file(FILE *file_param);

int main()
{
    int user_number;
    FILE *archive;

    archive = fopen("number.txt", "w");

    if(archive == NULL){
        printf("Error: file doesn't exist or there was an error opening it\n");
        return 1;
    }

    printf("Type a number: ");
    scanf("%d", &user_number);

    fprintf(archive, "%d\n", user_number); // Write number to file
    fclose(archive); // Close after writing

    // Reopen for reading
    archive = fopen("number.txt", "r"); // Now open in read mode
    if (archive == NULL) {
        printf("Error: could not reopen file for reading\n");
        return 1;
    }

    read_file(archive); // Now read
    fclose(archive);
    return 0;
}

void read_file(FILE *file_param){
    char line[10];
    while (fgets(line, sizeof(line), file_param))
    {
        printf("%s", line);
    }
}
