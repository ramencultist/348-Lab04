#include <stdio.h>
//Kyle Fleming 93089
// Function names
double toCelsius(double temp, char type);
double fromCelsius(double tempCelsius, char targetType);
void categorizeTemperature(double tempCelsius);

int main() {
    double temp, convertedTemp;
    char inputType, targetType;

    printf("Enter the temperature value: ");// Input temperature and type
    scanf("%lf", &temp);

    printf("Choose the input temperature type (F for Fahrenheit, C for Celsius, K for Kelvin): ");
    scanf(" %c", &inputType);

    printf("Choose the target temperature type (F for Fahrenheit, C for Celsius, K for Kelvin): ");
    scanf(" %c", &targetType);

    double tempCelsius = toCelsius(temp, inputType);// Convert the input temperature to Celsius

    convertedTemp = fromCelsius(tempCelsius, targetType);// Convert Celsiusto target type

    printf("Converted temperature: %.2lf %c\n", convertedTemp, targetType);// Output the converted temperature

    categorizeTemperature(tempCelsius);// Categorize advisory based on the temperature

    system("pause");// Prevents program from instantly closing so can actually see results
    return 0;
}

// Conversion to Celsius
double toCelsius(double temp, char type) {
    if (type == 'C' || type == 'c') {
        return temp;
    } else if (type == 'F' || type == 'f') {
        return (temp - 32) * 5.0 / 9.0;
    } else if (type == 'K' || type == 'k') {
        return temp - 273.15;
    } else {
        printf("Invalid input type!\n");
        return 0;
    }
}

// Celsius to Fahrenhiet/Kelvin
double fromCelsius(double tempCelsius, char targetType) {
    if (targetType == 'C' || targetType == 'c') {
        return tempCelsius;
    } else if (targetType == 'F' || targetType == 'f') {
        return (tempCelsius * 9.0 / 5.0) + 32;
    } else if (targetType == 'K' || targetType == 'k') {
        return tempCelsius + 273.15;
    } else {
        printf("Invalid target type!\n");
        return 0;
    }
}

// Categorize temperature and provide weather advisory
void categorizeTemperature(double tempCelsius) {
    if (tempCelsius < 0) {
        printf("Category: Freezing. Advisory: Wear a heavy jacket!\n");
    } else if (tempCelsius >= 0 && tempCelsius < 10) {
        printf("Category: Cold. Advisory: Wear a jacket!\n");
    } else if (tempCelsius >= 10 && tempCelsius < 25) {
        printf("Category: Comfortable. Advisory: Enjoy the day!\n");
    } else if (tempCelsius >= 25 && tempCelsius < 35) {
        printf("Category: Hot. Advisory: Stay hydrated!\n");
    } else if (tempCelsius >= 35) {
        printf("Category: Extreme Heat. Advisory: Stay indoors, it's very hot!\n");
    } else {
        printf("Category: Unknown. Advisory: Stay safe!\n");
    }
}
