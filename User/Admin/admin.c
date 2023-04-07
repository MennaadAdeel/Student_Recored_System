#include <admin.h>
#include "system.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "student.h"

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: View_all_records			                                                               |
Parameters: it take one parameters (pointer to head of students linked list).                  |
Return: it returns no thing.                                                                   |
Usage: it is used to print the all information of the students that exists in the linked list. |
------------------------------------------------------------------------------------------------
*/
void View_all_records(s_student *head_student)
{
	/*
	counter variable is used to count number of the students
	total_grade is used to calculate the total grade of all students
	average_grade is used to calculate the average grade of all students
	*/
	int counter = 0, total_grade = 0, average_grade;
	
	if(head_student == NULL)
		printf("The list is empty.\n");
	else
	{
		while(head_student != NULL)
		{
			printf("\n");
			printf("-------------------------------------------------\n");
			printf("|Student Number | "); print_int(++counter);
			printf("-------------------------------------------------\n");
			printf("|ID             | "); print_int(head_student->m_id);
			printf("|Name           | "); print_string(head_student->m_name,strlen(head_student->m_name));
			printf("|Password       | "); print_string(head_student->m_password,strlen(head_student->m_password));
			printf("|Gender         | "); print_string(head_student->m_gender,strlen(head_student->m_gender));
			printf("|Age            | "); print_int(head_student->m_age);
			printf("|Total Grade    | "); print_int(head_student->m_grade);
			printf("-------------------------------------------------\n");
			
			total_grade += head_student->m_grade;
			
			head_student = head_student->link;
		}
		
		average_grade = total_grade / counter;
		
		printf("\n");
		printf("-------------------------------------------------\n");
		printf("|Total Grade    | "); print_int(total_grade);
		printf("|Average Gradde | "); print_int(average_grade);
		printf("-------------------------------------------------\n");
	}
}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Remove student record		                                                               |
Parameters: it take two parameters (pointer to pointer to head of students linked list, ID of student ).                  |
Return: it returns no thing.                                                                   |
Usage: it is used to Remove student record by entered the student ID . |
------------------------------------------------------------------------------------------------
*/
void Remove_student_record (s_student **head_student,long ID){
        int flag=0;    //use to check id is correct or not, flag =0 that means id is wrong,flag=1 id is correct
        s_student *current=*head_student;   //pointer point to head of students ,use it to free the memory
        s_student *previous= *head_student; //pointer point to head of students 

	if (*head_student==NULL){
		printf("list is empty \n");
	}
	else{
		
		/*if condition to  remove student record of head student (first)
		check if ID is id of the head student(first student) then remove  by
		 current points to head that want to remove ,then  head_student point to second
		 then free current 
		 else check the rest record
		*/
		 if((*head_student)->m_id==ID)
      {
          current = *head_student;  
          *head_student = current->link;
          free(current);    // free the memory
		  current=NULL;
          flag=1;
      }
	  else{

	      while(previous->link != NULL)
          {
            
              if(previous->link->m_id ==ID) //if  previous->link->m_id==ID ,we need to delete the previous->link
		        {
            current = previous->link;       //current point to the student record that has this id( this id of student want to remove) 
			previous->link = current->link; //previous now  doesn't point to this student record(this id of student want to remove) but point to after this ,
			                               // now node(student record of this id) will be disconnceted from the linked list
                 
				  free(current);           //free the memory
                  flag=1;
                  break;
              }
           //Otherwise, move the previous node and proceed
              else
                  previous = previous->link;

          }
      }

   if(flag==0){
    printf("wrong id!!!\n");
    }
 }
}