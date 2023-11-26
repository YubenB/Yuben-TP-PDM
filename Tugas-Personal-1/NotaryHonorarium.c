#include <stdio.h>
#include <stdint.h>

// Function to calculate the price of the house object
unsigned long calculate_house_object_price()
{
    return 1500000000; // House object price
}

// Function to calculate sociological value
double calculate_sociological_value()
{
    return 5000000.0; // Sociological value
}

// Function to process honorarium cost
double calculate_honorarium_cost(unsigned long houseObjectPrice, double sociologicalValue, float *honorPercentage)
{
    if (houseObjectPrice <= 100000000)
    {
        *honorPercentage = 0.025f;
    }
    else if (houseObjectPrice <= 1000000000)
    {
        *honorPercentage = 0.015f;
    }
    else
    {
        *honorPercentage = 0.010f;
    }

    // Calculating total honor after converting the percentage to nominal value
    return houseObjectPrice * (*honorPercentage) + sociologicalValue;
}

// Function to display the output
void display_output(unsigned long houseObjectPrice, double sociologicalValue, float honorPercentage, double totalHonor)
{
    printf("\n=======================================\n");
    printf("NOTARY HONORARIUM CALCULATION PROGRAM\n");
    printf("=======================================\n\n");
    printf("\033[1;34mHouse Object Price:\033[0m \033[1;32mRp.%lu\033[0m\n", houseObjectPrice);
    printf("\033[1;34mSociological Value:\033[0m \033[1;32mRp.%.lf\033[0m\n", sociologicalValue);
    printf("--------------------------------------\n");
    printf("         HONORARIUM DETAIL\n");
    printf("--------------------------------------\n");
    printf("\033[1;34mHonor Percentage:\033[0m \033[1;32m%.2f%%\033[0m\n", honorPercentage * 100);
    printf("\033[1;34mTotal Honor:\033[0m \033[1;32mRp.%.lf\033[0m\n", totalHonor);
}

int main()
{
    // Calling the function to calculate the price of the house object
    unsigned long houseObjectPrice = calculate_house_object_price();

    // Calling the function to calculate sociological value
    double sociologicalValue = calculate_sociological_value();

    // Calling the function to process honorarium cost
    float honorPercentage;
    double totalHonor = calculate_honorarium_cost(houseObjectPrice, sociologicalValue, &honorPercentage);

    // Calling the function to display the output
    display_output(houseObjectPrice, sociologicalValue, honorPercentage, totalHonor);

    return 0;
}
