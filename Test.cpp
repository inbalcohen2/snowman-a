#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <exception>
#include <array>
using namespace std;

// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
//     CHECK(nospaces(snowman(11114411)) == nospaces("===\n(.,.)\n( : )\n( : )"));
// }

TEST_CASE("Good snowman code") {
    // Check all hat options
    CHECK(snowman(11441113) == string("\n      \n _===_\n (-,-) \n<( : )>\n (___) "));
    CHECK(snowman(21441113) == string("\n  ___ \n .....\n (-,-) \n<( : )>\n (___) "));
    CHECK(snowman(31441113) == string("\n   _  \n  /_\\\n (-,-)/ \n<( : )>\n (___) "));
    CHECK(snowman(41441113) == string("\n  ___ \n (_*_)\n (-,-)/ \n<( : )>\n (___) "));
   // check all eyes options
    CHECK(snowman(43123331) == string("\n  ___  \n (_*_)\n (._o) \n/(> <)\\\n ( : ) "));
    CHECK(snowman(43443331) == string("\n  ___  \n (_*_)\n (-_-) \n/(> <)\\\n ( : ) "));  
    CHECK(snowman(43233331) == string("\n  ___  \n (_*_)\n (o_O) \n/(> <)\\\n ( : ) "));
    CHECK(snowman(43313331) == string("\n  ___  \n (_*_)\n (O_.) \n/(> <)\\\n ( : ) "));
//    // check all nose options 
    CHECK(snowman(13222212) == string("\n       \n _===_\n\\(o_o)/\n ( : )\n (\" \") "));
    CHECK(snowman(12222212) == string("\n       \n _===_\n\\(o.o)/\n ( : )\n (\" \") "));   
    CHECK(snowman(14222212) == string("\n       \n _===_\n\\(o o)/\n ( : )\n (\" \") "));   
    CHECK(snowman(11222212) == string("\n       \n _===_\n\\(o,o)/\n ( : )\n (\" \") "));
//    // check all arms options 
    CHECK(snowman(33111142) == string("\n   _   \n  /_\\\n (._.) \n<(   )\n (\" \") "));
    CHECK(snowman(33112242) == string("\n   _   \n  /_\\\n\\(._.)/\n (   )\n (\" \") "));
    CHECK(snowman(33113342) == string("\n   _   \n  /_\\\n (._.) \n/(   )\\\n (\" \") "));
    CHECK(snowman(33114442) == string("\n   _   \n  /_\\\n (._.) \n (   ) \n (\" \") "));
//     // check all Torso option
    CHECK(snowman(21342314) == string("\n  ___  \n .....\n (O,-)/\n/( : )\n (   ) "));
    CHECK(snowman(21342324) == string("\n  ___  \n .....\n (O,-)/\n/(] [)\n (   ) "));
    CHECK(snowman(21342334) == string("\n  ___  \n .....\n (O,-)/\n/(> <)\n (   )"));
    CHECK(snowman(21342344) == string("\n  ___  \n .....\n (O,-)/\n/(   )\n (   ) "));
//     // check all Base option
    CHECK(snowman(11112311) == string("\n       \n _===_\n (.,.) \n<( : )\\\n ( : ) "));
    CHECK(snowman(11112312) == string("\n       \n _===_\n (.,.) \n<( : )\\\n (\" \") "));
    CHECK(snowman(11112313) == string("\n       \n _===_\n (.,.) \n<( : )\\\n (___) "));
    CHECK(snowman(11112314) == string("\n       \n _===_\n (.,.) \n<( : )\\\n (   )" ));
  
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