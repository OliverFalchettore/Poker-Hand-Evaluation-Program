#include <iostream>
#include <string>
using namespace std;

#include "Card.h"

//♠♣♥♦

//prints out the enums of Card Values
string CardValueToString(Value cardValue) {
    switch (cardValue) {
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "8";
    case Ten: return "10";
    case Jack: return "J";
    case Queen: return "Q";
    case King: return "K";
    case Ace: return "A";
    default:    return "Invalid Value";
    }
}

//prints out the enums of Card Suits
string CardSuitToString(Suit cardSuit) {
    switch (cardSuit) {
    case Clubs: return "Club";
    case Diamonds: return "Diamond";
    case Hearts: return "Heart";
    case Spades: return "Spades";
    default:    return "Invalid Value";
    }
}

//converts int to corresponding Card Value
string HighCardtoCardVal(int x) {
    switch (x) {
    case 2: return "2";
    case 3: return "3";
    case 4: return "4";
    case 5: return "5";
    case 6: return "6";
    case 7: return "7";
    case 8: return "8";
    case 9: return "8";
    case 10: return "10";
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    case 14: return "A";
    default:    return "Invalid Value";
    }
}