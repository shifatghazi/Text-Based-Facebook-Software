/********* definitions.c ********
	
	Student Name 	= Shifat Ghazi
	Student Number	= 101265285
*/

#include "a1_functions.h"

// Your solution goes here

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


/*
Total number of employees get calculated from cost and time
Calculate number of employees needed for the project based on cost and time
*/
void number_of_employees(milestone_t *project_details) 
{
	//Initalize variables
	float time, cost, employeeCount;
	int totalNum;
	cost = project_details -> cost;
	time = project_details -> time;
	employeeCount = round( (cost) / (time * 40 * 25) );
	project_details -> num_employees = employeeCount;

	project_details->num_employees = round(project_details->cost / (project_details->time * 40 * 25));
}


/* 
   Initialize milestones with names and planned budget
*/
milestone_t init_milestone(char stage_name[], float assigned_budget)
{
	milestone_t milestone;
	strcpy(milestone.name, stage_name);
	milestone.cost = assigned_budget;
	milestone.num_employees = 0;
	milestone.time = 0;
	milestone.completed = 0;
	return milestone;
}



/* 
   Get unsigned short integer user input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
unsigned short int get_input_usi(void)
{
	short int userInput;
	while (1)
	{
		scanf("%hi", &userInput);
		if (userInput < 0) 
		{
			printf("The value you entered is wrong\n");
			printf("Enter a positve value: ");
		}else
		{
			// return userInput;
			break;
		}
	}
	return userInput;
}



/*
   Get user float input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
float get_input_f(void)
{
	float userInput;
	while(1)
	{
		scanf("%f", &userInput);
		{
			if (userInput < 0) 
			{
				printf("The value you entered is wrong\n");
				printf("Enter a positve value: ");
			}else{
				return userInput;
				break;
			}
		}
	}
}






/* 
   Print menu with a list of milestones/options for the user to choose from
*/
void print_menu(void)
{
	printf("Which milestone you want to update? (0 to exit): \n");
	printf("1. Technical requirements\n");
	printf("2. System Design\n");
	printf("3. Software Develpment\n");
	printf("4. Testing\n");
	printf("5. Product release\n");
}


/*
   Print out current stats of each milestone/project
   (i.e, print all members of the milestone_t struct)
*/
void print_stats(milestone_t details)
{
	printf("\nActual Time: %.2f\n", details.time);
	printf("Actual number of employees: %hu\n", details.num_employees);
	printf("Actual cost: %.2f\n", details.cost);
	printf("Completed: %s\n", details.completed? "Yes" : "No");
}


/*
   Update the stats of the milestones (not the project).
   (i.e., Asks the user to update time, number of employees and completed.
    Cost is calculated based on the input data)
*/
void update_stats(milestone_t milestone_array[], int milestone_num)
{
	//Explicitly updating time with new value
	printf("Enter the milestone's actual time: ");
	milestone_array[milestone_num].time = get_input_f();

	//Explicitly updating number of employees with new value
	printf("Enter the milestone's actual number of employees: ");
	milestone_array[milestone_num].num_employees = get_input_usi();


	//Explicitly updating user complete value
	printf("Is this milestone complete?: (1 for Y/ 0 for N) ");
	short int askCompleteChar = get_input_usi();

	//Error proofing
	while (1)
	{
		if (askCompleteChar != 1 && askCompleteChar != 0)
		{	
			printf("\nThe value you entered is not an option");
			printf("\nIs this milestone complete?: (1 for Y/ 0 for N) ");
			askCompleteChar = get_input_usi();
		}else
		{
			break;//Exit loop
		}
	}

	//Perform code based on user's input
	if (askCompleteChar == 1)
	{
	short int askComplete = 1;
	milestone_array[milestone_num].completed = askComplete;
	}else
	{
		short int askComplete = 0;
		milestone_array[milestone_num].completed = askComplete;
	}
	//Explicitly updating cost with new value
	milestone_array[milestone_num].cost = milestone_array[milestone_num].num_employees * milestone_array[milestone_num].time * 40 * 25;
}




/*
   Check if all milestones are completed or not. If completed, updated the project's details to completed.
*/
void check_project_completion(milestone_t milestone_array[], int num_milestones)
{
	//Declare and intilize varaible
	short int askComplete = 1;

	//Perform loop to check each milestone
	for (int x = 1;x < num_milestones; x++)
	{
		if(milestone_array[x].completed == 0)
		{
			askComplete = 0;//Milstone not completed
		}
	}

	if (askComplete == 1)
	{
		milestone_array[0].completed = 1;//Milestone completed (1 = True)
	}
}