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

// @desc: Function will give the quadrant location using points location
int findQuadrant(int x_coordinate, int y_coordinate)
{

}

// @desc: Function will give distance between two points
double findDistance(int x1_coordinate, int y1_coordinate, int x2_coordinate, int y2_coordinate)
{

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

void midpoint_of_line(int x1_coordinate, int y1_coordinate, int x2_coordinate, int y2_coordinate)
{
}

// Angle Formula:
// Find Angle between two lines
// tan(theta) = (m1 - m2)/(1 + (m1.m2))
// @desc: Function will calculate angle between two lines, given both the slopes.

int find_angle(double slope_1, double slope_2)
{
    int flag_exception = 0;
    double theta;

    if((slope_1 * slope_2) == -1)
        flag_exception = 1;
    
    if(flag_exception != 1)
        theta = atan(((slope_1 - slope_2)/(1 + (slope_1 * slope_2))));
    else
        printf("Error: Zero Denominator Exception");

    return theta;
}


// Determine whether lines are parallel or perpendicular to each other
// Conditions :
// 1. If angle between two lines is 0 degrees
// 2. If angle between two lines is 90 degrees
// return: Parallel or Perpendicular

int checkPerpendicular(double slope_1, double slope_2){
    // Let's go with angle 
    // Check for denominator exception
    double theta;
    int flag_exception = 0;

    if((slope_1 * slope_2) == -1)
        flag_exception = 1;

    if(flag_exception != 1){
        theta = atan(((slope_1 - slope_2)/(1 + (slope_1 * slope_2))));
        if(theta == 0)
            return 0; //lines are parallel.
        else 
            return 1;   //lines are perpendicular.
    }else{
        printf("Error: Zero Denominator Exception\n");

        return -1; //Error: zero denominator exception occured
    }

}

// Section Formula
// Find a point which divides a line into m:n ratio.
// Consider a line A and B having coordinates (x1, y1) and (x2, y2), respectively. 
// Let P be a point that which divides the line in the ratio m:n, 
// then the coordinates of the coordinates of the point P is given as-
// when the ratio m:n is internal:

void section_formula(double x1_coordinate, double y1_coordinate, double x2_coordinate, double y2_coordinate)
{
    //
}


// For successful build test.
int main(){
    printf("Just a test !\n");

    return 0;
}
