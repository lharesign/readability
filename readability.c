#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string input = get_string("Text: ");
    int input_length = strlen(input);
    float char_count = 0;
    float word_count = 0; 
    float sentence_count = 0;
    float cl_index;
    
    //Set word count to 1 as soon as a character there
    if (input[0] > 0) 
    {
        word_count = 1;
    }
    
    //Counting number of letters/spaces/. ? ! via ASCII codes
    for (int i = 0; i < input_length; i++)
    {
        if ((input[i] >= 65 && input [i] <= 90) || (input[i] >= 97 && input[i] <= 122))
        {
            char_count++;
        }
        
        else if (input[i] == 32)
        {
            word_count++;
        }
        
        else if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            sentence_count++;
        }
    }
    
    //Calculating averages for CL Index & CL Index
    float average_letters = (char_count / word_count) * 100;
    float average_words = (sentence_count / word_count) * 100;
    cl_index = round((0.0588 * average_letters) - (0.296 * average_words) - 15.8);
    
    //Printing out result according to CL Index
    if (cl_index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else if (cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else
    {
        printf("Grade %.0f\n", cl_index);
    }
}