
#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace ariel;

#include <string>
#include <algorithm>

Notebook nb;

//write: (page, row, column, direction, input)
TEST_CASE("good writing") {
	nb.write(1,2,3,Direction::Horizontal,"dd");
	nb.write(1,1,1,Direction::Horizontal,"amit");
	nb.write(1,0,5,Direction::Vertical,"testcase");
	nb.write(1,2,2,Direction::Vertical,"ariel");
	nb.write(1,0,0,Direction::Horizontal,"unive");

}

TEST_CASE("Bad writing") {
    CHECK_THROWS(nb.write(1,0,0,Direction::Horizontal,"toy")); // one of the spots is already written
	CHECK_THROWS(nb.write(1,3,0,Direction::Horizontal,"disney")); // one of the spots is already written
	CHECK_THROWS(nb.write(1,3,96,Direction::Horizontal,"space")); // exeeding page boundries.
	CHECK_THROWS(nb.write(1,0,0,Direction::Horizontal,"spacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespacespace")); // exeeding page boundries.
	CHECK_THROWS(nb.write(1,-3,96,Direction::Horizontal,"space")); // negative row.
	CHECK_THROWS(nb.write(1,3,-1,Direction::Horizontal,"space")); // negative column.
	CHECK_THROWS(nb.write(-1,3,1,Direction::Horizontal,"space")); // negative page.
	CHECK_THROWS(nb.write(0,7,7,Direction::Horizontal,"la~")); // illegel character
}

//read: (page, row, column, direction, read x chars)
TEST_CASE("good reading") {
    CHECK(nb.read(1,0,3,Direction::Horizontal,4) == "vet_");
	CHECK(nb.read(1,1,2,Direction::Vertical,4) == "mari");
	CHECK(nb.read(1,4,0,Direction::Vertical,6) == "__i__c");
}

TEST_CASE("bad reading") {
    CHECK_THROWS(nb.read(1,0,91,Direction::Horizontal,10)); // read outside page boundries
	CHECK_THROWS(nb.read(1,0,0,Direction::Vertical,101)); // read outside page boundries
}


//read: (page, row, column, direction, erase x chars)
TEST_CASE("good erasing") {
	nb.erase(1,0,1,Direction::Horizontal,4);
	nb.erase(1,1,2,Direction::Vertical,3);
	nb.erase(1,0,4,Direction::Vertical,4);

}

TEST_CASE("bad erasing") {
	CHECK_THROWS(nb.erase(1,0,99,Direction::Horizontal,4)); // erasing outside page boundries
	CHECK_THROWS(nb.erase(1,1,2,Direction::Horizontal,104)); // erasing outside page boundries
}

TEST_CASE("write again good"){
	nb.write(1,1,0,Direction::Vertical,"dog");
	nb.write(1,7,0,Direction::Horizontal,"kitty");
}

TEST_CASE("write again bad"){
	CHECK_THROWS(nb.write(1,0,4,Direction::Horizontal,"tt")); // attempting to overwrite written text in one or more spots
	CHECK_THROWS(nb.write(1,3,4,Direction::Vertical,"lalala")); // attempting to overrwrite erased text in one or more spots
	CHECK_THROWS(nb.write(1,0,1,Direction::Vertical,"lalala")); // attempting to overrwrite erased text in one or more spots
	CHECK_THROWS(nb.write(1,4,0,Direction::Horizontal,"lalala")); // attempting to overrwrite erased text in one or more spots
}

TEST_CASE("reading again good") {
    CHECK(nb.read(1,0,0,Direction::Vertical,5) == "udog_");
	CHECK(nb.read(1,1,0,Direction::Horizontal,6) == "da~i~e");
	CHECK(nb.read(1,0,2,Direction::Vertical,6) == "~~~~iel");
	CHECK(nb.read(1,3,0,Direction::Horizontal,6) == "g_~_~t");
}

TEST_CASE("write extreme cases good"){
	//AS INSTRUCTED - YOU CAN WRITE '_', THEN OVERWRITE THE '_'
	nb.write(1,8,0,Direction::Horizontal,"hello_world");
}

TEST_CASE("reading extreme cases good") {
    CHECK(nb.read(1,8,4,Direction::Horizontal,3) == "o_w");
	CHECK(nb.read(1,6,5,Direction::Vertical,6) == "se____");
}

TEST_CASE("write extreme cases good continue"){
	nb.write(1,8,5,Direction::Vertical,"pizza");
}

TEST_CASE("reading extreme cases good continue") {
    CHECK(nb.read(1,8,4,Direction::Horizontal,3) == "opw");
	CHECK(nb.read(1,6,5,Direction::Vertical,6) == "sepizz");
}

TEST_CASE("good erasing 2") {
	nb.erase(1,7,5,Direction::Vertical,3);
}

TEST_CASE("reading erased"){
	CHECK(nb.read(1,9,4,Direction::Horizontal,3) == "_~_");
}

TEST_CASE("write again bad"){
	CHECK_THROWS(nb.write(1,9,4,Direction::Horizontal,"boy")); // attempting to overwrite written text in one or more spots
}




