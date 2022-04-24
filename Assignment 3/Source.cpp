#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>
using namespace std;
const int SIZE = 10;
void loadArrays(ifstream&, string[], double[][4], int&);
void computeSum(const double[][4], double[], int);
void printReport(ofstream&, const string[], const double[][4], const double[], int, int);
void findWine(const double[][4], int&, int&, int);
void mostWineSold(const double[], int&,int);\

//Author: Jacob Vowles
//Purpose: Wine Store monthly sales record(Assignment #3)
int main()
{
	double salesAmt[SIZE][4];  //no need to change your variable names to match mine!
	string wine[SIZE];
	double yearlySales[SIZE] = { 0.00 };
	int noWines;
	int highestRow, highestCol, mostSold;
	cout << fixed << setprecision(2);
	ifstream fin("wines.dat");
	if (!fin.is_open()) 
	{
		cout << "error opening wines.dat file - contact systems";
		system("pause");
		exit(-1);
	}
	ofstream fout("winesales.rpt");
	if (!fout.is_open())
	{
		cout << "error opening winesales.rpt file - contact systems";
		system("pause");
		exit(-2);
	}
	fout << fixed << setprecision(2);

	cout << "\n\nLoad arrays\n\n";
	loadArrays(fin, wine, salesAmt, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nCompute yearly Sale\n\n";
	computeSum(salesAmt, yearlySales, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind best selling wine and highest sales amount:\n\n";
	findWine(salesAmt, highestRow, highestCol, noWines);
	cout << "\n\n" << wine[highestRow] << " had the highest sales amount = $"
		<< salesAmt[highestRow][highestCol] << endl;
	cout << "\n\n=======================================================\n\n";

	cout << "\n\nFind the most sold wine:\n\n";
	mostWineSold(yearlySales, mostSold, noWines);
	cout << "\n\n Most sold wine is " << wine[mostSold] << endl;

	cout << "\n\n=======================================================\n\n";
	printReport(fout, wine, salesAmt, yearlySales, mostSold, noWines);
	cout << "\n\n=======================================================\n\n";

	cout << "program ended successfully" << endl;
	cout << "\n\n Printing wines.dat file\n\n";
	system("type wines.dat");
	cout << "\n\n Printing winesales.rpt file\n\n";
	system("type winesales.rpt");
	system("pause");
}
void loadArrays(ifstream& fin, string nameOfWines[], double salesAmount[][4],int& row)
{
	row = 0;

	for (; row < SIZE; row++)
	{
		getline(fin, nameOfWines[row]);
		if (fin.eof())
			break;
		for (int column = 0; column < 4; column++)
		{
			fin >> salesAmount[row][column];
		}
		fin.ignore(80, '\n');
	}
}
void computeSum(const double salesAmount[][4],double yearlySales[],int noWines)
{
	int row = 0;
	int sum;
	for (; row < noWines; row++) 
	{
		sum = 0;
		for (int column = 0; column < 4; column++) 
		{
			sum += salesAmount[row][column];
		}
		yearlySales[row] = sum;
	}

}
void printReport(ofstream& fout,const string nameOfWines[], const double salesAmount[][4],const double yearlySales[],int mostSold,int noWines)
{
	double total = 0;
	fout << left << "Wine" << right << setw(55) << "Quarterly Sales" << endl;
	fout << setw(25) << "1st" << setw(18) << "2nd" << setw(18) << "3rd" << setw(18) << "4th" << setw(18) << "Yearly" << endl << endl;
	for (int row = 0; row < noWines; row++) 
	{
		fout << left << setw(10) << nameOfWines[row];
		for (int column = 0; column < 4; column++) 
		{
			fout << right << setw(18) << salesAmount[row][column];
		}
		fout << setw(18) << yearlySales[row];
		if (yearlySales[row] == yearlySales[mostSold]) 
		{
			fout << "***most sold***";
		}
		fout << endl;
		for (int index = 0; index < noWines; index++) 
		{
			total += yearlySales[index];
		}
		
	}
	fout << endl << "Total Sales Amount $" << total << endl;
}
void findWine(const double salesAmount[][4], int& highestRow, int& highestCol, int noWines)
{
	highestCol = 0, highestRow = 0;
	for (int row = 0; row < noWines; row++) 
	{
		
		for (int column = 0; column < 4; column++) 
		{
			if (salesAmount[row][column] > salesAmount[highestRow][highestCol]) 
			{
				highestCol = column;
				highestRow = row;
			}
		}
		
	}
}
void mostWineSold(const double yearlySales[], int& mostSold, int noWines)
{
	mostSold = 0;
	int index = 0;
	for (; index < noWines; index++) 
	{
		if (yearlySales[index] > yearlySales[mostSold])
			mostSold = index;
	}
}



































