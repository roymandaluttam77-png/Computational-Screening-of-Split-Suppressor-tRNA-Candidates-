#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SIZE 10000000

/* Fisher-Yates shuffle */
void shuffle_sequence(char seq[], long length)
{
    long i, j;
    char temp;

    for (i = length - 1; i > 0; i--)
    {
        j = rand() % (i + 1);

        temp = seq[i];
        seq[i] = seq[j];
        seq[j] = temp;
    }
}

int main()
{
    FILE *random;
    FILE *output;

    char *original;
    char *random_seq;

    long length = 0;
    long i;
    int ch;
    int n;

    char filename[50];

    /* Allocate memory */
    original = (char *)malloc(MAX_SIZE * sizeof(char));
    random_seq = (char *)malloc(MAX_SIZE * sizeof(char));

    if (original == NULL || random_seq == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Open input file */
    random = fopen("random.txt", "r");

    if (random == NULL)
    {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    /*
       Read only A, T, G and C.
       New lines, spaces, FASTA headers, etc. are ignored.
    */
    while ((ch = fgetc(random)) != EOF)
    {
        ch = tolower(ch);

        if (ch == 'a' || ch == 't' ||
            ch == 'g' || ch == 'c')
        {
            original[length] = (char)ch;
            length++;

            if (length >= MAX_SIZE)
            {
                printf("Sequence is too large.\n");
                fclose(random);
                free(original);
                free(random_seq);
                return 1;
            }
        }
    }

    fclose(random);

    printf("Original sequence length = %ld nucleotides\n", length);

    /* Initialize random-number generator */
    srand((unsigned int)time(NULL));

    /*
       Generate 10 independently randomized sequences
    */
    for (n = 1; n <= 10; n++)
    {
        /* Start every shuffle from the ORIGINAL sequence */
        memcpy(random_seq, original, length);

        /* Randomize nucleotide positions */
        shuffle_sequence(random_seq, length);

        /* Create filenames:
           input1.txt
           input2.txt
           ...
           input10.txt
        */
        sprintf(filename, "input%d.txt", n);

        output = fopen(filename, "w");

        if (output == NULL)
        {
            printf("Cannot create %s\n", filename);
            continue;
        }

        /* Write 60 nucleotides per line */
        for (i = 0; i < length; i++)
        {
            fputc(random_seq[i], output);

            if ((i + 1) % 60 == 0)
                fputc('\n', output);
        }

        if (length % 60 != 0)
            fputc('\n', output);

        fclose(output);

        printf("%s created successfully.\n", filename);
    }

    free(original);
    free(random_seq);

    printf("\n10 randomized genome files created successfully.\n");

    return 0;
}