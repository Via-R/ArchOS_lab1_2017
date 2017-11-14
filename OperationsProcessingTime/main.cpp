#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template <typename T>
int getTime(T a, T b, clock_t c, string type, char op) {
	clock_t sum = 0, start, end;
	const unsigned int iterations = 100;
	cout << "Progress (out of " << iterations << "): 0";
	for (int k = 0; k < iterations; k++) {
		do {
			start = clock();
			for (int i = 0; i < 1000; i++)
				for (int j = 0; j < 1000; j++) {
					if (op == '+')
						a + b;
					if (op == '-')
						a - b;
					if (op == '*')
						a * b;
					if (op == '/')
						a / b;
						
				}
			end = clock();
			
		} while (end - start - c < 0);
		sum += end - start - c;
		
		string shift = k < 10 ? "\b" : "\b\b";
		cout << shift << (k+1);
	}
	cout << endl;
	cout << "Average time of " << op << " (" << type << "): " << sum/100. << endl << endl;
	return sum / 10;
}

template <typename T>
int getTimeMod(T a, T b, clock_t c, string type, char op) {
	clock_t sum = 0, start, end;
	const unsigned int iterations = 100;
	cout << "Progress (out of " << iterations << "): 0";
	for (int k = 0; k < iterations; k++) {
		do {
			start = clock();
			for (int i = 0; i < 1000; i++)
				for (int j = 0; j < 1000; j++) {
					a % b;
				}
			end = clock();

		} while (end - start - c < 0);
		sum += end - start - c;

		string shift = k < 10 ? "\b" : "\b\b";
		cout << shift << (k + 1);
	}
	cout << endl;
	cout << "Average time of " << op << " (" << type << "): " << sum/100. << endl << endl;
	return sum / 10;
}
int main() {
	clock_t time_a = clock();

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++) {
			if ('0' == 48) {}
			if ('1' == 49) {}
			if ('2' == 50) {}
			if ('3' == 51) {}
			if ('4' == 52 && '5' == 53 && '6' == 54) {}
		}

	clock_t time_b = clock();

	if (time_a == ((clock_t)-1) || time_b == ((clock_t)-1))
		cout << "Unable to calculate elapsed time";
	else{
		clock_t cycleTime = time_b - time_a;
		double result = 0;
		cout << "Cycle time: " << cycleTime << endl;
		unsigned int counter[5][5];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				counter[i][j] = 0;
		{
			unsigned int a = 42, b = 21;
			counter[0][0] += getTime(a, b, cycleTime, "int", '+');
			counter[0][1] += getTime(a, b, cycleTime, "int", '-');
			counter[0][2] += getTime(a, b, cycleTime, "int", '*');
			counter[0][3] += getTime(a, b, cycleTime, "int", '/');
			counter[0][4] += getTimeMod(a, b, cycleTime, "int", '%');
			
		}
		{
			long a = 42, b = 21;
			counter[1][0] += getTime(a, b, cycleTime, "long", '+');
			counter[1][1] += getTime(a, b, cycleTime, "long", '-');
			counter[1][2] += getTime(a, b, cycleTime, "long", '*');
			counter[1][3] += getTime(a, b, cycleTime, "long", '/');
			counter[1][4] += getTimeMod(a, b, cycleTime, "long", '%');
		}
		{
			double a = 42, b = 21;
			counter[2][0] += getTime(a, b, cycleTime, "double", '+');
			counter[2][1] += getTime(a, b, cycleTime, "double", '-');
			counter[2][2] += getTime(a, b, cycleTime, "double", '*');
			counter[2][3] += getTime(a, b, cycleTime, "double", '/');
		}
		{
			float a = 42, b = 21;
			counter[3][0] += getTime(a, b, cycleTime, "float", '+');
			counter[3][1] += getTime(a, b, cycleTime, "float", '-');
			counter[3][2] += getTime(a, b, cycleTime, "float", '*');
			counter[3][3] += getTime(a, b, cycleTime, "float", '/');
		}
		{
			char a = 42, b = 21;
			counter[4][0] += getTime(a, b, cycleTime, "char", '+');
			counter[4][1] += getTime(a, b, cycleTime, "char", '-');
			counter[4][2] += getTime(a, b, cycleTime, "char", '*');
			counter[4][3] += getTime(a, b, cycleTime, "char", '/');
			counter[4][4] += getTimeMod(a, b, cycleTime, "char", '%');
		}
		char operations[5] = { '+', '-', '*', '/', '%' };
		cout << "Int: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << operations[i] << ": ";
			for (int j = 0; j < counter[0][i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << "\nLong: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << operations[i] << ": ";
			for (int j = 0; j < counter[1][i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << "\nDouble: " << endl;
		for (int i = 0; i < 4; i++) {
			cout << operations[i] << ": ";
			for (int j = 0; j < counter[2][i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << "\nFloat: " << endl;
		for (int i = 0; i < 4; i++) {
			cout << operations[i] << ": ";
			for (int j = 0; j < counter[3][i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << "\nChar: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << operations[i] << ": ";
			for (int j = 0; j < counter[4][i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
		cout << endl << "This histogram is based on time (ms) of 1*10^6 operations, multiplied by ten to make histogram larger" << endl;
	}
	system("pause");
	return 0;
}