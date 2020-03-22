#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));

}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}
TEST_CASE("Test replacement of w and v") {
    string text = "I bought a new volkswagen";
    CHECK(find(text, "volksvagen") == string("volkswagen"));
    CHECK(find(text, "wolkswagen") == string("volkswagen"));
    CHECK(find(text, "wolksvagen") == string("volkswagen"));
    CHECK(find(text, "WolksVagen") == string("volkswagen"));
    CHECK(find(text, "volkswagen") == string("volkswagen"));
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "BuOght") == string("bought"));
    CHECK(find(text, "wulczvajen") == string("volkswagen"));
    CHECK(find(text, "VOLKSWagEN") == string("volkswagen"));
    CHECK(find(text, "NEW") == string("new"));
    CHECK(find(text, "BUOJHD") == string("bought"));

}

TEST_CASE("Test replacement of i and y") {
    string text = "I know how to spill superkalifragilistikexpialigetisch";
    CHECK(find(text, "superkalyfragilystikexpyaligetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "SuperkalYfragIlistIkexpYaligetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalIfragIlIstIkexpIalIgetIsch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalifragilistikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "zbill") == string("spill"));
    CHECK(find(text, "Huw") == string("how"));
    CHECK(find(text, "HOW") == string("how"));
    CHECK(find(text, "du") == string("to"));   
    CHECK(find(text, "zopirkalifragilistikexpialigetisch") == string("superkalifragilistikexpialigetisch"));     CHECK(find(text, "superkalifragilistikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "suFerCalifraJilYstikexpialigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "ZuperKaliFragYLiZtikexpYaLigetisch") == string("superkalifragilistikexpialigetisch"));
    CHECK(find(text, "superkalifRAGYlistikEXpialigetisch") == string("superkalifragilistikexpialigetisch"));
   
}
TEST_CASE("Test replacement of j and g") {
    string text = " Sir Roger George Moore was an English actor best known for playing British secret agent James Bond";
    CHECK(find(text, "Rojer") == string("Roger"));
    CHECK(find(text, "georje") == string("George"));
    CHECK(find(text, "ajent") == string("agent"));
    CHECK(find(text, "games") == string("James"));
    CHECK(find(text, "james") == string("James"));
    CHECK(find(text, "Zir") == string("Sir"));
    CHECK(find(text, "syr") == string("Sir"));
    CHECK(find(text, "rujer") == string("Roger"));
    CHECK(find(text, "muuRE") == string("Moore"));
    CHECK(find(text, "enjlyzh") == string("English"));

} 

TEST_CASE("Test replacement of more than two letters") {
    string text = "Roll the dice twice";
    CHECK(find(text, "tike") == string("dice"));
    CHECK(find(text, "rull") == string("Roll"));
    CHECK(find(text, "dhe") == string("the"));
    CHECK(find(text, "tvice") == string("twice"));
    CHECK(find(text, "DICe") == string("dice"));
    CHECK(find(text, "ROLL") == string("Roll"));
    CHECK(find(text, "DICE") == string("dice"));
    CHECK(find(text, "RolL") == string("Roll"));
    CHECK(find(text, "TVyce") == string("twice"));
    CHECK(find(text, "TvICE") == string("twice"));
    CHECK(find(text, "THE") == string("the"));

}