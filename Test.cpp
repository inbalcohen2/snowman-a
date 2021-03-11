#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <exception>
#include <array>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    // Check all hat options
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11441113)) == nospaces("_===_\n(-,-)\n<( : )>\n(___)"));
    CHECK(nospaces(snowman(21441113)) == nospaces("___\n.....\n(-,-)\n<( : )>\n(___)"));
    CHECK(nospaces(snowman(31441113)) == nospaces("_\n/_\\\n(-,-)\n<( : )>\n(___)"));
    CHECK(nospaces(snowman(41441113)) == nospaces("___\n(_*_)\n(-,-)\n<( : )>\n(___)"));
   // check all eyes options
     CHECK(nospaces(snowman(43123331)) == nospaces("___\n(_*_)\n(._o)\n/(> <)\\\n( : )"));
     CHECK(nospaces(snowman(43443331)) == nospaces("___\n(_*_)\n(-_-)\n/(> <)\\\n( : )"));  
     CHECK(nospaces(snowman(43233331)) == nospaces("___\n(_*_)\n(o_O)\n/(> <)\\\n( : )"));
     CHECK(nospaces(snowman(43313331)) == nospaces("___\n(_*_)\n(O_.)\n/(> <)\\\n( : )"));
//    // check all nose options 
    CHECK(nospaces(snowman(13222212)) == nospaces("_===_\n\\(o_o)/\n( : )\n(\" \")"));
    CHECK(nospaces(snowman(12222212)) == nospaces("_===_\n\\(o.o)/\n( : )\n(\" \")"));   
    CHECK(nospaces(snowman(14222212)) == nospaces("_===_\n\\(o o)/\n( : )\n(\" \")"));   
    CHECK(nospaces(snowman(11222212)) == nospaces("_===_\n\\(o,o)/\n( : )\n(\" \")"));
//    // check all arms options 
    CHECK(nospaces(snowman(33111142)) == nospaces("_\n/_\\\n(._.)\n<(   )>\n(\" \")"));
    CHECK(nospaces(snowman(33112242)) == nospaces("_\n/_\\\n\\(._.)/\n(   )\n(\" \")"));
    CHECK(nospaces(snowman(33113342)) == nospaces("_\n/_\\\n(._.)\n/(   )\\\n(\" \")"));
    CHECK(nospaces(snowman(33114442)) == nospaces("_\n/_\\\n(._.)\n(   )\n(\" \")"));
//     // check all Torso option
    CHECK(nospaces(snowman(21342314)) == nospaces("___\n.....\n\\(O,-)\n( : )\\\n(   )"));
    CHECK(nospaces(snowman(21342324)) == nospaces("___\n.....\n\\(O,-)\n(] [)\\\n(   )"));
    CHECK(nospaces(snowman(21342334)) == nospaces("___\n.....\n\\(O,-)\n(> <)\\\n(   )"));
    CHECK(nospaces(snowman(21342344)) == nospaces("___\n.....\n\\(O,-)\n(   )\\\n(   )"));
//     // check all Base option
    CHECK(nospaces(snowman(11112311)) == nospaces("_===_\n\\(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11112312)) == nospaces("_===_\n\\(.,.)\n( : )\\\n(\" \")"));
    CHECK(nospaces(snowman(11112313)) == nospaces("_===_\n\\(.,.)\n( : )\\\n(___)"));
    CHECK(nospaces(snowman(11112314)) == nospaces("_===_\n\\(.,.)\n( : )\\\n(   )"));
  
}
TEST_CASE("Snowman input invalid numbers"){
    CHECK_THROWS(snowman(91111111));
    CHECK_THROWS(snowman(18111111));
    CHECK_THROWS(snowman(31711141));
    CHECK_THROWS(snowman(11161112));
    CHECK_THROWS(snowman(11215111));
    CHECK_THROWS(snowman(11511014));
    CHECK_THROWS(snowman(221111-11));
    CHECK_THROWS(snowman(1111231-2));
}

TEST_CASE("Input invalid input too long"){
    CHECK_THROWS(snowman(123234344));
    CHECK_THROWS(snowman(222222224));
}

TEST_CASE("Invalid input - numbers not between 1-4"){
    CHECK_THROWS(snowman(34211199)); // the number in the end
    CHECK_THROWS(snowman(-23441123)); // the number in the begin
    CHECK_THROWS(snowman(00000000)); //all the numbers
}

TEST_CASE("Input invalid input too short"){
     CHECK_THROWS(snowman(3));
    CHECK_THROWS(snowman(341));
    CHECK_THROWS(snowman(123432));
}