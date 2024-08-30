#include <stdio.h>   // Include standard input/output library
#include <math.h>    // Include math library for sqrt() function

// Define constants for the dimensions and sphere size
#define WIDTH 80     // Width of the output (number of columns)
#define HEIGHT 24    // Height of the output (number of rows)
#define RADIUS 10    // Radius of the sphere

int main() {
    // Loop through each row
    for (int y = 0; y < HEIGHT; y++) {
        // Loop through each column in the current row
        for (int x = 0; x < WIDTH; x++) {
            // Calculate the distance from the current point to the center
            float dx = x - WIDTH / 2;   // x-distance from center
            float dy = y - HEIGHT / 2;  // y-distance from center
            float distance = sqrt(dx * dx + dy * dy);  // Pythagorean theorem
            
            // Check if the current point is within the sphere
            if (distance < RADIUS) {
                // Calculate the z-coordinate (depth) at this point
                float z = sqrt(RADIUS * RADIUS - distance * distance);
                
                // Calculate the intensity based on the z-coordinate
                float intensity = z / RADIUS;
                
                // Choose a character based on the intensity
                if (intensity > 0.9)
                    printf("@");        // Highest intensity
                else if (intensity > 0.7)
                    printf("O");        // High intensity
                else if (intensity > 0.5)
                    printf("o");        // Medium intensity
                else if (intensity > 0.3)
                    printf(".");        // Low intensity
                else
                    printf(" ");        // Lowest intensity
            } else {
                // If the point is outside the sphere, print a space
                printf(" ");
            }
        }
        // Move to the next line after completing a row
        printf("\n");
    }
    return 0;  // Indicate successful program completion
}
