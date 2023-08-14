//first initialize the enumeration card values
//make a card object containing Suit and Values
#pragma once
#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Suit { Clubs, Diamonds, Hearts, Spades };
enum Value { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

struct Card {
    Suit cardSuit;
    Value cardValue;
};

string CardValueToString(Value cardValue);
string CardSuitToString(Suit cardSuit);
string HighCardtoCardVal(int x);

#endif
