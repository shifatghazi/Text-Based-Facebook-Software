/********* main.c ********
	
	Student Name 	= Shifat Ghazi
*/

// Includes go here
#include "a1_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	//Miles array declared of size 6
	milestone_t milestonesArr[6];

	//Milestone struct is initialized fro name, cost, employee num, completed boolean
	milestone_t projectElements = {"Elements of Project", 0, 0, 0, 0};
	
	//Intro ouputted
	printf("Welcome to ABC Project Tracker");

	//Budget saved to milestone
	printf("\nEnter total project's budget: ");
	projectElements.cost = get_input_f();

	//Budget saved to milestone
	printf("Enter total project's duration in weeks: ");
	projectElements.time = get_input_f();

	//Determine total employees
	number_of_employees(&projectElements);
	printf("The planned number of employees neededd is %hu: ", projectElements.num_employees);

	printf("\n\n--------------------------------------------\n\n");

	milestonesArr[0] = (milestone_t) {"Planned Details", projectElements.cost, projectElements.time, projectElements.num_employees, 0};

	//Initialize each milestone with their specified costs
	for (int x = 1; x < 6; x++)
	{
		if (x == 1)
		{
			milestonesArr[x] = init_milestone("Technical Requirements" , projectElements.cost / 5);
		}
		if (x == 2)
		{
			milestonesArr[x] = init_milestone("System Design" , projectElements.cost / 5);
		}
		if (x == 3)
		{
			milestonesArr[x] = init_milestone("Software Development" , projectElements.cost / 5);
		}
		if (x == 4)
		{
			milestonesArr[x] = init_milestone("Testing" , projectElements.cost / 5);
		}
		if (x == 5)
		{
			milestonesArr[x] = init_milestone("Product" , projectElements.cost / 5);
		}
	}

	//Values will be updated until user no longer wants to
	while (1)
	{
		//Output menu to the user
		print_menu();

		//Variable initialized
		//User enters milestone number wanted to be updated
		int userMilNumber = -1;
		while (1)
		{
			//Error proofing
			if (userMilNumber < 0 || userMilNumber > 5)
			{
				printf("\nYour choice is: ");
				userMilNumber = get_input_usi();


				if (userMilNumber < 0 || userMilNumber > 5)
				{
					printf("\n--------------------------------------------\n");
					printf("The value you entered is wrong");
					printf("\nEnter a value between 0 and 5: ");
				}else//Loop is exited
				{
					break;
				}
			}
		}

		//Determine which route the user wants 
		if (userMilNumber != 0)
		{
			printf("\n---------------Milestone Stats--------------\n");
			printf("Below is \"%s\" current stats:\n", milestonesArr[userMilNumber].name);
			printf("--------------------------------------------\n");

			//Stats for chosen milestone is printed
			print_stats(milestonesArr[userMilNumber]);	

			//Determine if user milstone is completed or not
			//Boolean value of 1 will output as true
			if (milestonesArr[userMilNumber].completed)    
			{
				printf("\n--------------------------------------------\n");
				printf("%s milestone is completed cannot be updated", milestonesArr[userMilNumber].name);
				printf("\n--------------------------------------------\n\n");
			}
			else // Boolean value of 0 is present (0 means False)
			{
				printf("\n-------------Update Stats-----------------\n\n");
				//Stats will be outputted
				update_stats(milestonesArr, userMilNumber);
				printf("Status updated!\n");
				printf("\n---------------Milestone Stats--------------\n");
				printf("Below is \"%s\" current stats:", milestonesArr[userMilNumber].name);
				printf("\n---------------------------------------------\n");
				print_stats(milestonesArr[userMilNumber]);
				printf("\n");

			}
		
		}else//User selected choice 0
		{
			//Initialize total cost associated 
			float totalCost = 0;
			//Add up the total cost
			for (int y = 0; y < 6; y++)
			{
				totalCost += milestonesArr[1].cost;
			}
			//Determine project completion
			check_project_completion(milestonesArr, 6);
			if (milestonesArr[0].completed == 0)
			{
				printf("\n--------------------------------------------\n");
				printf("---------------Project's Performance--------\n");
				printf("--------------------------------------------\n\n");
				
				printf("---------------Milestone Stats--------------\n");
				printf("Below is \"%s\" current status:", milestonesArr[0].name);
				printf("\n--------------------------------------------\n");

				//Stats get outputted
				print_stats(milestonesArr[0]);

				//Ask user if they want to complete anymore milestones before finishing
				printf("Do you want to finish the remamining milestones? (1 for Y/ 0 for N) ");
				
				//Get user choice
				short int endChoice = get_input_usi();
				printf("\n\n");
				//Error proof
				while (endChoice != 1 && endChoice != 0)
				{
					printf("\nThe value you entered is wrong");
					printf("\nDo you want to finish the remamining milestones? (1 for Y/0 for N) ");
					endChoice = get_input_usi();
					printf("\n");
				}

				if (endChoice == 0) //User no longer wants to update milestones, loop is exited
				{
					break;
				}//If user wants to continue, beginning of loop is started
			}
			else
			{
				//Check to see if all muilestones are completed
				if (milestonesArr[0].completed == 1)
				{
					break;//Loop is automatically exited if all milestones are completed
				}
			}
		}
	}
	//User is no longer able to edit milestones and performance is outputted
	printf("\n--------------------------------------------");
	printf("\n-----------Final Project's Performance------");
	printf("\n--------------------------------------------\n\n");

	//Final cost is totalled
	float finalCost = 0;
	for (int z = 1; z < 6; z++)
	{
		finalCost += milestonesArr[z].cost;
	}

	if (finalCost <  milestonesArr[0].cost)
	{
		printf("\nThe project's cost is below budget!");
	}
	else if (finalCost > milestonesArr[0].cost)
	{
		printf("\nThe project's cost is above budget!");
	}
	else
	{
		printf("\nThe project's cost is equal to the budget!");
	}
	//Output final data
	printf("\nPlanned budget: %.2f", milestonesArr[0].cost);
	printf("\nActual cost: %.2f", finalCost);
	printf("$");
	printf("\n\n--------------------------------------------");
	printf("\n---The program will quit now! Goodbye! -----");
	printf("\n--------------------------------------------");   
}
