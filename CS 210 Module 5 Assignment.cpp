#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    string city;
    double temperature;

    // Read data from input file and write converted data to output file
    while (inputFile >> city >> temperature) {
        double celsius = fahrenheitToCelsius(temperature);
        outputFile << setw(10) << left << city << ": " << fixed << setprecision(2) << celsius << " Celsius" << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "Conversion complete. Output written to CelsiusTemperature.txt" << endl;

    return 0;
}