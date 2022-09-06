// Trigonometry Library

// The MIT License (MIT)
// Copyright (c) 2022 Aditya Chaudhary
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// COORDINATE GEOMETRY (2D PLANE)

// Find which quadrant where point lies
// Implement Midpoint Theorem: Midpoint of a line connecting two points
// Angle Between Two Lines and also evaluate result that lines are parallel or perpendicular to each other
// Implement section formula
// Area of triangle in cartesian plane

// Header Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DEBUGMODE
#define PI 3.14159265

#ifdef DEBUGMODE
#define DEBUG_FLAG 1
#endif

// @desc: Function will give the quadrant location using points location
int findQuadrant(double x_coordinate, double y_coordinate)
{
    /*
     For First Quadrant : x_coordinate is positive and y_coordinate is positive.
     For Second Quadrant : x_coordinate is -ve and y_coordinate is positive.
     For Third Quadrant : x_coordinate is -ve and y_coordinate is -ve.
     For Fourth Quadrant : x_coordinate is positive and y_coordinate is -ve.

     Origin Condition : (0,0)
    */

    // Let's go with worst approach we can think of ! (If else)
    // Let's check zero condition

    //  If x is 0 -> On Y axis
    //  If y is 0 -> On X axis

    if ((x_coordinate > 0) && (y_coordinate > 0))
    {
        if (DEBUG_FLAG == 1)
            printf("First Quadrant\n");
        return 1;
    }
    else if ((x_coordinate < 0) && (y_coordinate > 0))
    {
        if (DEBUG_FLAG == 1)
            printf("Second Quadrant\n");
        return 2;
    }
    else if ((x_coordinate < 0) && (y_coordinate < 0))
    {
        if (DEBUG_FLAG == 1)
            printf("Third Quadrant\n");
        return 3;
    }
    else if ((x_coordinate > 0) && (y_coordinate < 0))
    {
        if (DEBUG_FLAG == 1)
            printf("Fourth Quadrant\n");
        return 4;
    }
    else
    {
        // We can target corner cases here !
        if ((x_coordinate == 0) && (y_coordinate == 0))
        {
            // On origin
            if (DEBUG_FLAG == 1)
                printf("Origin\n");
            return 0;
        }
        else if (x_coordinate == 0)
        {
            // On Y axis
            if (DEBUG_FLAG == 1)
                printf("On Y axis with x value = %lf\n", y_coordinate);
            return -1;
        }
        else if (y_coordinate == 0)
        {
            // On X axis
            if (DEBUG_FLAG == 1)
                printf("On X axis with y value = %lf\n", x_coordinate);
            return 10;
        }
    }
}

// @desc: Function will give distance between two points
double findDistance(int x1_coordinate, int y1_coordinate, int x2_coordinate, int y2_coordinate)
{
    double distance;

    // FORMULA:
    distance = sqrt(pow((x2_coordinate - x1_coordinate), 2) + pow((y2_coordinate - y1_coordinate), 2));

    if (DEBUG_FLAG == 1)
        printf("Distance between two points: %lf\n", distance);

    return distance;
}

// @desc: Function will give slope of a line, Provide values of A and B using conversion formula of general form to slope intercept form
// Formula to calculate slope of a line :
// General form of a line Ax + By + C = 0, we have to convert this general form to slope intercept form, y = mx + c
// Conversion:
// By = -Ax - C
// y = -(A/B)x - (C/B)
// Therefore value of m is -(A/B), which is slope.

double findSlope(double A, double B)
{
    //
    return -(A / B);
}

// Midpoint Theorem:
// Consider the same points A and B, which have coordinates (x1, y1) and (x2, y2), respectively.
// Let M(x,y) be the midpoint of lying on the line connecting these two points A and B.
// The coordinates of point M is given as -

void midpoint_of_line(double x1_coordinate, double y1_coordinate, double x2_coordinate, double y2_coordinate)
{
    // FORMULA
    // We want x and y coordinate of midpoint

    double x_coordinate, y_coordinate;

    x_coordinate = (x1_coordinate + x2_coordinate) / 2;
    y_coordinate = (y1_coordinate + y2_coordinate) / 2;

    if (DEBUG_FLAG == 1)
    {
        printf("X Coordinate: %lf\n", x_coordinate);
        printf("Y Coordinate: %lf\n", y_coordinate);
    }
}

// Angle Formula:
// Find Angle between two lines
// tan(theta) = (m1 - m2)/(1 + (m1.m2))
// @desc: Function will calculate angle between two lines, given both the slopes.

double find_angle(double slope_1, double slope_2)
{
    double calculated_value, theta, conversion_rate;
    int flag_exception = 0;

    if ((slope_1 * slope_2) == -1)
        flag_exception = 1; //Zer Denominator conditions


    if (flag_exception != 1)
    {
        calculated_value = ((slope_1 - slope_2) / (1 + (slope_1 * slope_2)));
        conversion_rate = 180.0 / PI;

        theta = atan(calculated_value) * conversion_rate;
    }
    else
    {
        if (DEBUG_FLAG == 1)
            printf("Error: Zero Denominator Exception\n");
    }

    if (DEBUG_FLAG == 1)
        printf("Angle between two lines : %lf\n", theta);


    printf("The arc tangent of %lf is %lf degrees\n", calculated_value, theta);

    return theta;
}

// Determine whether lines are parallel or perpendicular to each other
// Conditions :
// 1. If angle between two lines is 0 degrees
// 2. If angle between two lines is 90 degrees
// return: Parallel or Perpendicular

int checkPerpendicular(double slope_1, double slope_2)
{
    /*
     * Angle Measurement
     * Check for denominator exception
    */
    
    double theta,calculated_value,conversion_rate;
    int flag_exception = 0;

    if ((slope_1 * slope_2) == -1)
        flag_exception = 1;

    if (flag_exception != 1)
    {
        calculated_value = ((slope_1 - slope_2) / (1 + (slope_1 * slope_2)));
        conversion_rate = 180.0 / PI;
        theta = atan(calculated_value) * conversion_rate;

        if(DEBUG_FLAG == 1)
          printf("Theta : %lf\n",theta);

        if (theta == 0)
        {
            if (DEBUG_FLAG == 1)
                printf("Lines are parallel\n");
            return 0; // lines are parallel.
        }
    }
    else
    {
        if (DEBUG_FLAG == 1)
            printf("Lines are perpendicular\n");

        return 1; // Error: zero denominator exception occured, tan90 is undefined
    }
}

/*
 * Section Formula
 * Find a point which divides a line into m:n ratio.
 * Consider a line A and B having coordinates (x1, y1) and (x2, y2), respectively.
 * Let P be a point that which divides the line in the ratio m:n,
 * then the coordinates of the coordinates of the point P is given as
 * when the ratio m:n is internal:
*/

void section_formula(double x1_coordinate, double y1_coordinate, double x2_coordinate, double y2_coordinate, int m, int n, int mode)
{
    /*
     * Find a point which divides a line into m : n ratio
     * Put Modes :
     * Mode 0 : Internal
     * Section formula, when m:n is internal,
     * double x_coordinate = ((m*x2_coordinate + n*x1_coordinate)/(m + n))
     * double y_coordinate = ((m*y2_coordinate + n*y1_coordinate)/(m + n))
     * Return: [x_coordinate,y_coordinate]
     * Mode 1 : External
     * Section formula, when m:n is external,
     * double x_coordinate = ((m*x2_coordinate - n*x1_coordinate)/(m - n))
     * double y_coordinate = ((m*y2_coordinate - n*y1_coordinate)/(m - n))
     * Return: [x_coordinate,y_coordinate]
    */

    double x_coordinate, y_coordinate;

    if (mode == 0)
    {
        x_coordinate = (((m * x2_coordinate) + (n * x1_coordinate)) / (m + n));
        y_coordinate = (((m * y2_coordinate) + (n * y1_coordinate)) / (m + n));
    }
    else if (mode == 1)
    {
        x_coordinate = (((m * x2_coordinate) - (n * x1_coordinate)) / (m - n));
        y_coordinate = (((m * y2_coordinate) - (n * y1_coordinate)) / (m - n));
    }

    // @TODO : RETURN coordinates as an array as x and y coordinate.

    // For Debugging
    if (DEBUG_FLAG == 1)
    {
        printf("X Coordinate: %lf\n", x_coordinate);
        printf("Y Coordinate: %lf\n", y_coordinate);
    }
}

// Area of a Triangle in Cartesian Plane
// The area of a triangle In coordinate geometry whose vertices are (x1, y1), (x2, y2) and (x3, y3) :
// area_of_triangle is given by 1/2|(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))|

double area_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{

    double calculate_operand = (x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2));

    if(DEBUG_FLAG == 1)
	    printf("Operand Value : %lf\n",calculate_operand);

    double area = ((1 / 2) * calculate_operand);

    if (DEBUG_FLAG == 1)
        printf("AREA OF TRIANGLE: %lf\n", area);

    return area;
}

// For successful build test.
int main()
{

    // Lets test some functions,

    /*
        Test 1: Quadrant Test
        Test Case :

        Input : x = 0, y = 0
        Output : Debug Result : Origin, return 0;
    */

    // printf("Result : %d\n", findQuadrant(0, 0));

    /*
        Test 2: Distance Between Points Test
        Test Case :

        Input : x1 = 10, y1 = 2, x2 = -1, y2 = 4
        Output : Debug Result : 11.308, return 11.308;
    */

    // printf("Result : %lf\n", findDistance(10, 2, -1, 4));

    /*
        Test 3: Find Slope Test
        Test Case :

        Input : A = 10, B = -3
        Output : Debug Result : -3.33, return -3.33;
    */

    // printf("Result : %lf\n", findSlope(10,3));

    /*
        Test 4: Find Angle Test
        Test Case :

        Input : slope_1 = 3, slope_2 = 2
        Output : Debug Result : 8.130102 degrees , return 8.130102 degree;
    */
    // printf("Result : %lf\n", find_angle(3,2));

    /*
        Test 5: Midpoint Test
        Test Case :

        Input : x1_coordinate = 1, y1_coordinate = 2, x2_coordinate = 1, y2_coordinate = 2
        Output : Debug Result : x = 1.5, y = 1.5
    */
    //    midpoint_of_line(1,1,2,2);


     /*
        Test 6: Check Perpendicular Test
        Test Case :

        Input : x1_coordinate = 1, y1_coordinate = 2, x2_coordinate = 1, y2_coordinate = 2
        Output : Debug Result : x = 1.5, y = 1.5
    */

       // printf("Result : %d\n", checkPerpendicular(1,-1));

       /*
	* Test 7:
	* Section Formula Test
	*
	* Test Case:
	*Input : Test Failed
	*
	* */


       //section_formula(2,1,3,4,2,3,0);
       
       /*
	* Test 8: Area of a triangle
	* 
	*
	*/

	printf("Result: %lf\n",area_of_triangle(3,4,5,6,7,8));

    return 0;
}
