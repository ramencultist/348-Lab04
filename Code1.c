#include <stdio.h>
// Kyle Fleming 93089
// Function to find and print all possible combinations of scoring plays
void findCombinations(int score) {
    int touchdown, touchdown_field, touchdown_safety, field, safety;

    // Nested loops to go through all possible combinations of scoring plays
    for (touchdown = 0; touchdown * 6 <= score; touchdown++) {// TDs (6 points)
        for (touchdown_field = 0; touchdown_field * 7 + touchdown * 6 <= score; touchdown_field++) {// TD + 1-point field goal (7 points)
            for (touchdown_safety = 0; touchdown_safety * 8 + touchdown_field * 7 + touchdown * 6 <= score; touchdown_safety++) {// TD + 2-point conversion (8 points)
                for (field = 0; field * 3 + touchdown_safety * 8 + touchdown_field * 7 + touchdown * 6 <= score; field++) {// Field goals (3 points)
                    for (safety = 0; safety * 2 + field * 3 + touchdown_safety * 8 + touchdown_field * 7 + touchdown * 6 <= score; safety++) {// Safeties (2 points)
                        
                        // Check if the current combination results in the exact score
                        if (touchdown * 6 + touchdown_field * 7 + touchdown_safety * 8 + field * 3 + safety * 2 == score) {
                            printf("%d Touchdown, %d Touchdown+Field, %d Touchdown+Safety, %d Field, %d Safety\n", touchdown, touchdown_field, touchdown_safety, field, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {// Promt until input <= 1
        printf("Enter an NFL score (<=1 to exit): ");
        scanf("%d", &score);

        if (score <= 1) {// Exit when <= 1
            printf("Exiting program.\n");
            break;
        }

        printf("Possible combinations for score %d:\n", score);// Print all possible combinations for the entered score
        findCombinations(score);
    }

    return 0;
}
