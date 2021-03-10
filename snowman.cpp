#include "snowman.hpp"
#include <iostream> 
#include <array>
#include <string>
#include <exception>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

namespace ariel

{
enum parts
{
    head = 0, leftArm, leftEye, nose, rightEye, rightArm, torso, base, PARTS_NUM 
};

    int charToDigit(char c)
    {
        return c - '0';
    }
// this class build the part of the snowman
class SnowPart
{
public:    

    void AddType(string type)
    {
        _types.push_back(type);
    }
    long GetTypesSize()
    {
        return _types.size();
    }
    // note: typeNum should start in 1 (not 0)
    string GetTypeInNum(int typeNum) noexcept(false) // means the func might throw
    {
        if(typeNum > _types.size())
        {
            throw range_error("part type num is not in range\n");
        }
        return _types[typeNum - 1];
    }

private:
    std::vector<string> _types; 
};
// class 
class SnowMan
{
public:
	SnowMan()
	{

//Hats        
		_parts["H"].AddType("\n      \n _===_\n");
		_parts["H"].AddType("\n  ___ \n .....\n");
		_parts["H"].AddType("\n   _  \n  /_\\ \n");
		_parts["H"].AddType("\n  ___ \n (_*_)\n");
//Noses
        _parts["N"].AddType(",");
		_parts["N"].AddType(".");
		_parts["N"].AddType("_");
		_parts["N"].AddType(" ");
//Left Eyes
        _parts["LE"].AddType(".");
		_parts["LE"].AddType("o");
		_parts["LE"].AddType("O");
		_parts["LE"].AddType("-");
//Right Eyes
        _parts["RE"].AddType(".");
		_parts["RE"].AddType("o");
		_parts["RE"].AddType("O");
		_parts["RE"].AddType("-");
//Left Arm 
        _parts["LA"].AddType("<");
		_parts["LA"].AddType(" ");
		_parts["LA"].AddType("/");
		_parts["LA"].AddType(" ");
//Left Arm Top
        _parts["LAT"].AddType(" ");
		_parts["LAT"].AddType("\\");
		_parts["LAT"].AddType(" ");
		_parts["LAT"].AddType(" ");
//Right Arm 
        _parts["RA"].AddType(">");
		_parts["RA"].AddType("/");
		_parts["RA"].AddType(" ");
		_parts["RA"].AddType(" ");
 //Right Arm  Top
        _parts["RAT"].AddType(" \n");
		_parts["RAT"].AddType(" \n");
		_parts["RAT"].AddType("\\\n");
		_parts["RAT"].AddType(" \n");
//Torsos
        _parts["T"].AddType("( : )");
		_parts["T"].AddType("(] [)");
		_parts["T"].AddType("(> <)");
		_parts["T"].AddType("(   )");
//Bases
        _parts["B"].AddType(" ( : )");
		_parts["B"].AddType(" (\" \")");
		_parts["B"].AddType(" (___) ");
		_parts["B"].AddType(" (   )");
		
	}

	string BuildSnowManByRecipe(string recipe) noexcept (false)
	{
		if(recipe.size() != PARTS_NUM)
        {
        			throw invalid_argument{"The input has the wrong number of digits!\n"};
		}


		string snowmanStr;
		snowmanStr += _parts["H"].GetTypeInNum(charToDigit(recipe[head]));
        snowmanStr += _parts["LAT"].GetTypeInNum(charToDigit(recipe[rightEye]));
        snowmanStr += " ("+ _parts["LE"].GetTypeInNum(charToDigit(recipe[leftEye]));
        snowmanStr += _parts["N"].GetTypeInNum(charToDigit(recipe[leftArm]));
        snowmanStr += _parts["RE"].GetTypeInNum(charToDigit(recipe[nose]))+")";
        snowmanStr += _parts["RAT"].GetTypeInNum(charToDigit(recipe[rightArm]))+"\n";
        snowmanStr += _parts["RA"].GetTypeInNum(charToDigit(recipe[rightEye]))+"\n";
       snowmanStr += _parts["T"].GetTypeInNum(charToDigit(recipe[torso]))+"\n";
        snowmanStr += _parts["LA"].GetTypeInNum(charToDigit(recipe[rightArm]));
        snowmanStr += _parts["B"].GetTypeInNum(charToDigit(recipe[base]));
		return snowmanStr;
	}

private:
	unordered_map<string, SnowPart> _parts{
        {"H",{}}, {"N",{}}, {"LE",{}}, {"RE",{}},{"LA",{}},{"LAT",{}},{"RA",{}},{"RAT",{}},{"T",{}},{"B",{}}
	};
};

	string snowman(int input){
		SnowMan snowMan;
		return snowMan.BuildSnowManByRecipe(to_string(input));
    }

}