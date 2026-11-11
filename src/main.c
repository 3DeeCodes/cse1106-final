
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <pigpio.h>
#include <string.h>
#define PIN 17
#define READING_COUNT 5
int Temp_Max = 76;
int Temp_Min = 68;

double calculateAverage(double readings[], int count) {
	double total = 0;
	for (int i = 0; i < count; i++) total += readings[i];
	return total / count;
}
void displayReadings(double readings[], int count) {
	printf("Temperature Readings:\n");
	for (int i = 0; i < count; i++) printf("%.1f F\n", readings[i]);
}
int isOutOfRange(double temperature) {
	if (temperature > Temp_Max || temperature < Temp_Min){
		gpioWrite(PIN,1); //LED ON
		return 1;
	}
	else 
{
	return 0;
}
}
void checkReadings(double readings[], int count) {
	printf("\nReadings requiring attention:\n");
	for (int i = 0; i < count; i++) {
		if (isOutOfRange(readings[i])) printf("%.1f F\n", readings[i]);
	}
}
int testsRun = 0;
int testsPassed = 0;
void recordTest(const char* testName, int passed)
{
	testsRun++;
	if (passed) {
		testsPassed++;
		printf("PASS: %s\n", testName);
	}
	else {
		printf("FAIL: %s\n", testName);
	}
}
/*
// Section 3 - Initial Test Suite 
// T1: 75 F is within the acceptable range. 
void test_T1_normalTemperature(void) {
	double temperature = 75.0;
	recordTest("T1 - 75 F is within the acceptable range",
		isOutOfRange(temperature) == 0);
}
// T2: 64 F is below the minimum and should require attention. 
void test_T2_belowMinimum(void) {
	double temperature = 64.0;
	recordTest("T2 - 64 F requires attention",
		isOutOfRange(temperature) == 1);
}
// T3: 78.5 F is above the maximum and should require attention. 
void test_T3_aboveMaximum(void) {
	double temperature = 76;
	recordTest("T3 - 76 F is within the acceptable range",
		isOutOfRange(temperature) == 0);
}
void runInitialTests(void) {
	printf("\n========================================\n");
	printf("CSE 1106 INITIAL TEST SUITE\n");
	printf("========================================\n\n");
	test_T1_normalTemperature();
	test_T2_belowMinimum();
	test_T3_aboveMaximum();
} */
/* Add your tests T4 - T8 here. */
/*Tests should follow the same flow and invoke the recordTest method*/
/* T4: One value below the minimum. */
void test_T4(void) {
}
/* T5: The minimum */
void test_T5(void) {
}
/* T6: One value inside the range. */
void test_T6(void) {
}
/* T7: The maximum. */
void test_T7(void) {
}
/* T8: One value above the maximum. */
void test_T8(void) {
}
/* Finish the method "runTestsNewRequirement" below that invokes the minimal number
of tests from T1-T8 needed to ensure (1) the new template change is correctly coded
and (2) nothing else has changed. */
void runTestsNewRequirement(void) {
	printf("\n========================================\n");
	printf("CSE 1106 NEW REQUIREMENT TEST SUITE\n");
	printf("========================================\n\n");
	//TODO invoke relevant tests
}
int main(void) {
 gpioInitialise();
 gpioSetMode(PIN, PI_OUTPUT);
 gpioWrite(PIN, 0); //LED OFF
	double readings[READING_COUNT] = { 68.0, 69.0, 70.0, 71.0, 100.0 };
	printf("========================================\n");
	printf("LEGACY CLASSROOM TEMPERATURE MONITOR\n");
	printf("========================================\n\n");
	/* First observe the existing program. */
	displayReadings(readings, READING_COUNT);
	printf("\nAverage temperature: %.1f F\n",
		calculateAverage(readings, READING_COUNT));
	checkReadings(readings, READING_COUNT);
	/* Then run the initial test suite. */
//	runInitialTests();
	printf("Temperature\t System Status \t Warning LED\n");
	for (int i = 0; i < READING_COUNT; i++){
		char str[10];
		char LED[10];
	if (isOutOfRange(readings[i]==1))	{
	 str[7] = "Warning";
	 LED [10] = "On";
	} else
	{
	 str[6] = "Normal";
	 LED [10] = "Off";
	}
		printf("%d %s %s\t",readings[READING_COUNT], str, LED);
// printf("fajkhfakjhfakjf %d", &tungtung);
	}
	
	
	
	return 0;
}

