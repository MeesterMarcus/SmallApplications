/*
Name: Marcus Lorenzana
Assignment: HW3

This program takes two lines from the user, using ordered pairs. It then
calculates whether or not the two lines interesect, are parallel, or if they are co-located.
*/

#include <stdio.h>
#include <math.h>

int main() {

	//Line 1 ordered pair
	double x1,x2,y1,y2;
	//Line 2 ordered pair
	double x3,y3,x4,y4;
	//Line 1 & 2 slopes
	double m1,m2;
	//Line 1 & 2 y-intercepts
	double b1,b2;
	
	//Get line 1
	printf("\nEnter line one ordered pairs:\n");
	printf("Enter (x1,y1):"); 
	scanf("%lf %lf",&x1,&y1); 
	printf("Enter (x2,y2):"); 
	scanf("%lf %lf",&x2,&y2); 
	printf("\n"); 
	
	//Checks if user entered (0,0)
	if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 ==0)) {
		printf("Can not be empty.\n");
		return 0; 
	}
	
	if (x1-x2 == 0) {
		printf("Cannot compute slope b/c cannot divide by zero.\n\n"); 
		return 0; 
	}
	
	//Prints out ordered pairs for Line 1
	printf("You entered: (%.1lf,%.1lf) and (%.1lf,%.1lf)\n",x1,y1,x2,y2); 
	
	//Get line 2
	printf("\n\nEnter line two ordered pairs:\n");
	printf("Enter (x3,y3):"); 
	scanf("%lf %lf",&x3,&y3); 
	printf("Enter (x4,y4):"); 
	scanf("%lf %lf",&x4,&y4); 
	printf("\n"); 
	
	//Checks if user entered (0,0)
	if((x3 == 0 && y3 == 0) || (x4 == 0 && y4 ==0)) {
		printf("Can not be empty.\n");
		return 0; 
	}
	
	if (x3-x4 == 0) {
		printf("Cannot compute slope b/c cannot divide by zero.\n\n"); 
		return 0; 
	}
	
	//Prints out ordered pairs for Line 2
	printf("You entered: (%.1lf,%.1lf) and (%.1lf,%.1lf)\n",x3,y3,x4,y4); 
	
	
	//Calculate slopes
	m1 = (y1-y2)/(x1-x2);
	m2 = (y3-y4)/(x3-x4); 
	
	//Calculate y intercepts
	b1 = y1 - (m1*x1); 
	b2 = y3 - (m2*x3); 
	
	printf("\nThe slope for Line 1 is: %.1lf \nThe slope for Line 2 is: %.1lf\n\n",m1,m2); 

	//Determine whether the two lines intersect, are parallel, or co-located
	if (m1 == m2) {
		printf("\nThe two lines are parallel.\n"); 
		if (b1 == b2) {
			printf("\nThey are also co-located.\n"); 
		}
		
	} else {
		printf("\nThe two lines intersect.\n"); 
	}
	
	return 0; 
}
