#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY "/usr/share/dict/words"
#define LONGEST_WORD 100

void trim_line(char line[])
{
    int i = 0;

    //  LOOP UNTIL WE REACH THE END OF line
    while (line[i] != '\0')
    {

        //  CHECK FOR CARRIAGE-RETURN OR NEWLINE
        if (line[i] == '\r' || line[i] == '\n')
        {
            line[i] = '\0'; // overwrite with nul-byte
            break;          // leave the loop early
        }
        i = i + 1; // iterate through character array
    }
}

//  ENSURE THAT A WORD CONTAINS ONLY LOWERCASE CHARACTERS
bool valid_word(char word[])
{
    int i = 0;

    //  IF NOT A LOWERCASE CHARACTER, THE FUNCTION RETURNS false
    while (word[i] != '\0')
    {
        if (!islower(word[i]))
        {
            return false;
        }
        i = i + 1;
    }
    //  WE'VE REACHED THE END OF THE WORD - IT'S ALL LOWERCASE
    return true;
}

//  CALCULATE THE SCRABBLE VALUE OF ANY WORD
int calc_value(char word[])
{
    //  AN ARRAY TO PROVIDE THE VALUE OF EACH LETTER, FROM 'a' TO 'z'
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1,
                    1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int total = 0;
    int i = 0;

    //  TRAVERSE THE WORD DETERMINING THE VALUE OF EACH LETTER
    while (word[i] != '\0')
    {
        total = total + values[word[i] - 'a'];
        i = i + 1;
    }
    return total;
}

//  FIND THE WORD WITH THE BEST VALUE
void findbest(char filename[])
{
    FILE *fp = fopen(filename, "r");

    //  ENSURE THAT WE CAN OPEN (WITH READ-ACCESS) THE FILE
    if (fp != NULL)
    {
        char bestword[LONGEST_WORD];
        int bestvalue = 0;
        char thisword[LONGEST_WORD];
        int thisvalue = 0;

        //  READ EACH LINE OF THE FILE
        while (fgets(thisword, sizeof thisword, fp))
        {
            //  REPLACE THE NEWLINE CHARACTER WITH A NUL-BYTE
            trim_line(thisword);

            //  ENSURE THAT THIS WORD IS VALID (previously defined)
            if (valid_word(thisword))
            {
                thisvalue = calc_value(thisword);

                //  IS THIS WORD BETTER THAN THE PREVIOUSLY BEST?
                if (bestvalue < thisvalue)
                {
                    bestvalue = thisvalue; // save current details
                    strcpy(bestword, thisword);
                }
            }
        }
        fclose(fp);
        printf("best word is %s = %d\n", bestword, bestvalue);
    }
}

int main(int argc, char *argv[])
{
    findbest(DICTIONARY);
    return 0;
}