//Fernando Israel Andrade
//Visual Studio 2019
//Advant of code Day 3
//https://adventofcode.com/2022/day/3

#include <iostream>
#include <fstream>
#include <string>
#include <malloc.h>
#define MAX_SIZE 16382
using namespace std;

int modifiedScore(string round[], int size) {
	//A and X are rock, B and Y are Paper, C and Z are Scissors
	string ax = "A X";
	string ay = "A Y";
	string az = "A Z";
	string bx = "B X";
	string by = "B Y";
	string bz = "B Z";
	string cx = "C X";
	string cy = "C Y";
	string cz = "C Z";
	int totalSum = 0;

	//Calculate scores based on user input.
	//If user chooses X we need a loss,
	//Y we need a draw,
	//Z we need a win
	//Points are calculated the same way as before
	for (int i = 0; i < size; i++)
	{
		//X = loss. AX becomes AZ
		if (round[i] == ax)
		{
			totalSum += 3;
		}
		//Y = Need a draw. AY becomes AX
		if (round[i] == ay)
		{
			totalSum += 4;
		}
		//Z = Win. AZ becomes AY
		if (round[i] == az)
		{
			totalSum += 8;
		}
		//X = loss. BX stays the same
		if (round[i] == bx)
		{
			totalSum += 1;
		}
		//Y = Need a draw. BY stays the same
		if (round[i] == by)
		{
			totalSum += 5;
		}
		//Z = Win. BZ stays the same
		if (round[i] == bz)
		{
			totalSum += 9;
		}
		//X = loss. CX becomes CY
		if (round[i] == cx)
		{
			totalSum += 2;
		}
		//Y = Need a draw. CY becomes CZ
		if (round[i] == cy)
		{
			totalSum += 6;
		}
		//Z = Win. CZ becomes CX
		if (round[i] == cz)
		{
			totalSum += 7;
		}
	}
	return totalSum;
}


int calculateScore(string round[], int size) {
	//A and X are rock, B and Y are Paper, C and Z are Scissors
	string ax = "A X";
	string ay = "A Y";
	string az = "A Z";
	string bx = "B X";
	string by = "B Y";
	string bz = "B Z";
	string cx = "C X";
	string cy = "C Y";
	string cz = "C Z";
	int totalSum = 0;

	//Calculate the points won each round based on outcome and what option was chosen.
	//Win = 6pts, Draw = 3pts, Loss = 0 pts
	//Rock = 1pt, Paper = 2pts, Scissor = 3pts
	for (int i = 0; i < size; i++)
	{
		//Rock vs Rock = draw. 3pts + 1 pt
		if (round[i] == ax)
		{
			totalSum += 4;
		}
		//Rock vs Paper = win. 6pts + 2pts
		if (round[i] == ay)
		{
			totalSum += 8;
		}
		//Rock vs Scissors = loss. 0pts + 3pts
		if (round[i] == az)
		{
			totalSum += 3;
		}
		//Paper vs Rock = loss. 0pts + 1pt
		if (round[i] == bx)
		{
			totalSum += 1;
		}
		//Paper vs Paper = draw. 3pts + 2pts
		if (round[i] == by)
		{
			totalSum += 5;
		}
		//Paper vs Scissors = win. 6pts + 3pts
		if (round[i] == bz)
		{
			totalSum += 9;
		}
		//Scissors vs Rock = win. 6pts + 1pt
		if (round[i] == cx)
		{
			totalSum += 7;
		}
		//Scissors vs Paper = loss. 0pts + 2pts
		if (round[i] == cy)
		{
			totalSum += 2;
		}
		//Scissors vs Scissors = draw. 3pts + 3pts
		if (round[i] == cz)
		{
			totalSum += 6;
		}
	}
	return totalSum;
}

int main() {
	fstream in;
	in.open("RockPaperScissors.txt");
	string* arr;
	arr = new string[MAX_SIZE];
	string round = {};
	string round2 = {};
	int total = 0;
	int k = 0;
	int modifiedTotal = 0;

	//Store each round in an array
	if (in.is_open())
	{
		while (getline(in, round))
		{
			arr[k] = round;
			k++;
		}
	}

	in.close();

	total = calculateScore(arr, k);
	modifiedTotal = modifiedScore(arr, k);

	cout << "Total score is: " << total << endl;
	cout << "Modified Total score is: " << modifiedTotal << endl;

	return 0;
}
