#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_CITIES 6

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int calculateDistance(int *route, int distances[NUM_CITIES][NUM_CITIES]) {
    int totalDistance = 0;
    for (int i = 0; i < NUM_CITIES; i++) {
        totalDistance += distances[route[i]][route[(i + 1) % NUM_CITIES]];
    }
    return totalDistance;
}

void copyArray(int *source, int *destination, int length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
}

void permute(int *array, int start, int end, int distances[NUM_CITIES][NUM_CITIES], int *shortestRoute, int *minDistance) {
    if (start == end) {
        int currentDistance = calculateDistance(array, distances);
        if (currentDistance < *minDistance) {
            *minDistance = currentDistance;
            copyArray(array, shortestRoute, NUM_CITIES);
        }
    } else {
        for (int i = start; i < end; i++) {
            swap((array + start), (array + i));
            permute(array, start + 1, end, distances, shortestRoute, minDistance);
            swap((array + start), (array + i)); // backtrack
        }
    }
}

int main() {
    int distances[NUM_CITIES][NUM_CITIES] = {
        {0, 2, 2, 5, 9, 3},
        {2, 0, 4, 6, 7, 8},
        {2, 4, 0, 8, 6, 3},
        {5, 6, 8, 0, 4, 9},
        {9, 7, 6, 4, 0, 10},
        {3, 8, 3, 9, 10, 0}
    };

    int route[NUM_CITIES], shortestRoute[NUM_CITIES];
    for (int i = 0; i < NUM_CITIES; i++) {
        route[i] = i;
    }

    int minDistance = INT_MAX;
    permute(route, 0, NUM_CITIES, distances, shortestRoute, &minDistance);

    printf("Shortest Route: ");
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("%d ", shortestRoute[i]);
    }
    // Ensure to print the return to the starting city for completeness
    printf("%d", shortestRoute[0]);
    printf("\nTotal Distance: %d\n", minDistance);

    return 0;
}

