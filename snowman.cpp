#include "snowman.hpp"
#include <iostream>
#include <array>
#include <string>
#include <exception>
#include <vector>
#include <unordered_map>

using namespace std;
namespace ariel{
constexpr int MIN_snowParts_NUM = 1;
const int NUMBER_TEMP = 10;

// build and define the snowman parts as class functions
class SnowMan
{
public:
	//For the build of the snowman 
	enum Parts
	{
		hat = 0, nose, lefteye, righteye, leftarm, rightarm, torso, base, NUM_OF_SNOWPARTS
	};

	//Build each part individually of the snowman 
	SnowMan()
	{
		_snowParts = {{"H",{}}, {"N",{}}, {"LE",{}}, {"RE",{}}, {"LAT",{}}, {"LA",{}},
		              {"RAT",{}}, {"RA",{}}, {"T",{}}, {"B",{}}
		};
//Hats        
		_snowParts["H"] += ("      \n _===_\n");
		_snowParts["H"] += ("  ___ \n .....\n");
		_snowParts["H"] += ("   _  \n  /_\\ \n");
		_snowParts["H"] += ("  ___ \n (_*_)\n");
//Noses
		_snowParts["N"] += (",");
		_snowParts["N"] += (".");
		_snowParts["N"] += ("_");
		_snowParts["N"] += (" ");
//Left Eyes
		_snowParts["LE"] += (".");
		_snowParts["LE"] += ("o");
		_snowParts["LE"] += ("O");
		_snowParts["LE"] += ("-");
//Right Eyes
		_snowParts["RE"] += (".");
		_snowParts["RE"] += ("o");
		_snowParts["RE"] += ("O");
		_snowParts["RE"] += ("-");
//Left Arm 
		_snowParts["LA"] += ("<");
		_snowParts["LA"] += (" ");
		_snowParts["LA"] += ("/");
		_snowParts["LA"] += (" ");
//Left Arm Top
		_snowParts["LAT"] += (" ");
		_snowParts["LAT"] += ("\\");
		_snowParts["LAT"] += (" ");
		_snowParts["LAT"] += (" ");
//Right Arm 
		_snowParts["RA"] += (">");
		_snowParts["RA"] += (" ");
		_snowParts["RA"] += ("\\");
		_snowParts["RA"] += (" ");
//Right Arm  Top

		_snowParts["RAT"] += (" ");
		_snowParts["RAT"] += ("/");
		_snowParts["RAT"] += (" ");
		_snowParts["RAT"] += (" ");
//Torsos
		_snowParts["T"] += (" : ");
		_snowParts["T"] += ("] [");
		_snowParts["T"] += ("> <");
		_snowParts["T"] += ("   ");
//Bases
		_snowParts["B"] += (" : ");
		_snowParts["B"] += ("\" \"");
		_snowParts["B"] += ( "___");
		_snowParts["B"] += ("   ");
	}

	string GetSnowMan(int input) noexcept(false)
	{
		CheckInput(input);
		return BuildSnowMan(to_string(input));
	}

private:

	class SnowPart
	{
	public:
		void operator+=(const string& typeToAdd)
		{
			_types.push_back(typeToAdd);
		}

		string GetType(int index)
		{
			if(index >= _types.size()){
				throw out_of_range("index not in range");
			}
			return _types[index];
		}

	private:
		std::vector<string> _types;
	};

	string BuildSnowMan(const string& input);
	static void CheckInput(int input) noexcept(false);
	static int ToDigit(char c) noexcept(false);

	unordered_map<string, SnowPart> _snowParts;
};

//checks if the  number(input) is valid
void SnowMan::CheckInput(int input){
	if(input <= 0){
		throw invalid_argument("the input must be a positive number");
	}
	int inputCopy = input;
	int numOfDigits = 0;
	for (;  inputCopy != 0; numOfDigits++)
	{
		inputCopy /= NUMBER_TEMP;
	}

	if(numOfDigits != Parts::NUM_OF_SNOWPARTS)
	{
		throw invalid_argument("the input size has wrong num of digits");
	}

	for (int i = 0 ; i <numOfDigits; i++) {
		if ((input % NUMBER_TEMP < 1) || (input % NUMBER_TEMP > 4)) {
			throw out_of_range("the number is not a valid");
		}
		input /= NUMBER_TEMP;
	}
}
//build the snow man (string)
string SnowMan::BuildSnowMan( const string& input)
{

	vector<int> digits;
	// reserve the size of the vector, in order to push members more efficiently (without need to resize on the fly)
	digits.reserve(input.length());
	for (int i = 0; i < input.length(); i++)
	{
		digits.push_back(ToDigit(input[i]) - 1); // -1 since nums are between 1...4 and indexs start in 0
	}

	return  _snowParts["H"].GetType(digits[hat]) +
			_snowParts["LAT"].GetType(digits[leftarm]) + "(" +
			_snowParts["LE"].GetType(digits[lefteye]) +
			_snowParts["N"].GetType(digits[nose])+
			_snowParts["RE"].GetType(digits[righteye]) + ")" +
			_snowParts["RAT"].GetType(digits[rightarm]) + "\n" +
			_snowParts["LA"].GetType(digits[leftarm]) + "(" +
			_snowParts["T"].GetType(digits[torso]) + ")" +
			_snowParts["RA"].GetType(digits[rightarm]) + "\n" + " (" +
			_snowParts["B"].GetType(digits[base]) + ") ";
}

//converting char to its integer representation
int SnowMan::ToDigit(char c)
{
	if(c < '0' || c > '9'){
		throw out_of_range("char is not a digit");
	}
	return c - '0';
}

string snowman(int input)
{
	SnowMan mySnowMan;
	return mySnowMan.GetSnowMan(input);
}

} // namespace ariel
