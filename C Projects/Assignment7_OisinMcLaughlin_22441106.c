/*
Name: Oisin Mc Laughlin
Student ID: 22441106
Date: 8/11/22
*/

#include <stdio.h>
#include <string.h>

#define pi 3.14159265359
int main() {
    char response[] = "";

    //triangle
    float trb = 0;
    float trh = 0;
    float triangle = 0;
    //rectangle
    float rw = 0;
    float rh = 0;
    float rectangle = 0;
    //circle
    float cr = 0;
    float circle = 0;
    //trapezium
    float ta = 0;
    float tb = 0;
    float th = 0;
    float trapezium = 0;

    //Start of loop and seeing what option of shape user wants.
    for (int i = 0; i < 10; i++) {
        printf("Area Calculator - The Shape Choices are:\n");
        printf("Triangle, Rectangle, Circle, Trapezium\n");
        puts("If finished, please type 'done' otherwise, Please chose an option: \n");
        gets(response);

        //Triangle statement, taking triangle inputs, calculating and giving response.
        if ((strcmp(response, "Triangle") == 0) || (strcmp(response, "triangle") == 0)) {
            printf("Triangle Selected\n");
            printf("Enter base: ");
            scanf("%f", &trb);
            printf("Enter height: ");
            scanf("%f", &trh);
            triangle = (0.5*trb*trh);
            printf("Area of triangle is %.2f\n", triangle);
            printf("-----------------------------------------------\n");
        }
        //Rectangle statement, taking rectangle inputs, calculating and giving response.
        else if ((strcmp(response, "Rectangle") == 0) || (strcmp(response, "rectangle") == 0)) {
            printf("Rectangle Selected\n");
            printf("Enter width: ");
            scanf("%f", &rw);
            printf("Enter height: ");
            scanf("%f", &rh);
            rectangle = (rw*rh);
            printf("Area of rectangle is %.2f\n", rectangle);
            printf("-----------------------------------------------\n");
        }
        //Circle statement, taking circle inputs, calculating and giving response.
        else if ((strcmp(response, "Circle") == 0) || (strcmp(response, "circle") == 0)) {
            printf("Circle Selected\n");
            printf("Enter radius: ");
            scanf("%f", &cr);
            circle = (pi*(cr*cr));
            printf("Area of circle is %.2f\n", circle);
            printf("-----------------------------------------------\n");
        }
        //Trapezium statement, taking trapezium inputs, calculating and giving response.
        else if ((strcmp(response, "Trapezium") == 0) || (strcmp(response, "trapezium") == 0)) {
            printf("Trapezium Selected\n");
            printf("Enter top length: ");
            scanf("%f", &ta);
            printf("Enter bottom length: ");
            scanf("%f", &tb);
            printf("Enter height: ");
            scanf("%f", &th);
            trapezium = ((0.5*(ta+tb))*th);
            printf("Area of trapezium is %.2f\n", trapezium);
            printf("-----------------------------------------------\n");
        }
        //If user says done, it ends the loop.
        else if ((strcmp(response, "Done") == 0) || (strcmp(response, "done") == 0)) {
            printf("Thank you, terminating program.\n");
            break;
        }
    }
}
//Thank you