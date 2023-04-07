#include "system.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*
----------------------------------------------------------------------------------------------
									Function Definition		                	    		 |
----------------------------------------------------------------------------------------------
Name: View_student_record			                                                         |
Parameters: it take two parameters (pointer to head of students linked list, ID of student). |
Return: it returns no thing.                                                                 |
Usage: it is used to print the information of the student that we receive its ID.            |
----------------------------------------------------------------------------------------------
*/
void View_student_record(s_student *head_student,long ID)
{
	/* 
	flag variable is used to check ID
	if flag == 0 at end of function --> this means that id is not exist
	else if flag == 1 at end of function --> this means that id is exists and we print information of the student
	*/
	int flag = 0;
	
	if(head_student == NULL)
		printf("The list is empty.\n");
	else
	{
		
		while(head_student != NULL)
		{
			if(head_student->m_id == ID)
			{
				printf("\n");
				printf("------------------------------------------------------\n");
				printf("|Student Information |                               |\n");
				printf("------------------------------------------------------\n");
				printf("|ID                  | "); print_int(head_student->m_id);
				printf("|Name                | "); print_string(head_student->m_name,strlen(head_student->m_name));
				printf("|Password            | "); print_string(head_student->m_password,strlen(head_student->m_password));
				printf("|Gender              | "); print_string(head_student->m_gender,strlen(head_student->m_gender));
				printf("|Age                 | "); print_int(head_student->m_age);
				printf("|Grade               | "); print_int(head_student->m_grade);
				printf("------------------------------------------------------\n");
				
				flag = 1;
				break;
			}
			head_student = head_student->link;
		}
	}
	
	if(flag == 0)
		printf("Wrong ID !!!\n");
}


/*
------------------------------------------------------------
				Function Definition						   |
------------------------------------------------------------
Name: print_int						                       |
Parameters: it take one parameter (intger value).          |
Return: it returns no thing.                               |
Usage: it is used to print an integer value with number    |
	   of white spaces to improve the shape of the output. |
------------------------------------------------------------
*/
void print_int(int num)
{
    int num_spaces = Total_Length - (int)(log10(num)+1);
    int counter;
	
	printf("%d", num);
	if(num_spaces > 0)
	{
        for(counter = 0; counter < num_spaces; counter++)
		{
            printf(" ");
        }
		printf("|\n");
    }
}

/*
--------------------------------------------------------------
				Function Definition						     |
--------------------------------------------------------------
Name: print_string						                     |
Parameters: it take two parameters (string,length of string).|
Return: it returns no thing.                                 |
Usage: it is used to print the string with number of white   |
	   spaces to improve the shape of the output.            |
--------------------------------------------------------------
*/
void print_string(char *string, int len)
{
    int num_spaces = Total_Length - len;
    int counter;
	
	printf("%s", string);
	if(num_spaces > 0)
	{
        for(counter = 0; counter < num_spaces; counter++)
		{
            printf(" ");
        }
		printf("|\n");
    }
}