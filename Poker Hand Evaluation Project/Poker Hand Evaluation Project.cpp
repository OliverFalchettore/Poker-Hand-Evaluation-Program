//started 8/7/2023 
//Completed on 8/10/2023 11:22 PM
/*
This program will give the user 5 random cards and will
determine whether the hand is either highcard, a pair, two pairs,
three of a kind, stright, fullhouse...(Yeah you get the point)
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "Card.h"
#include "deck.h"
#include "hand.h"

void showranks() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Poker Hands Ranked Highest to Lowest:" << std::endl;
    std::cout << "Royal Flush" << std::endl;
    std::cout << "Stright Flush" << std::endl;
    std::cout << "Four of a Kind" << std::endl;
    std::cout << "Full House" << std::endl;
    std::cout << "Flush" << std::endl;
    std::cout << "Stright" << std::endl;
    std::cout << "Three of a Kind" << std::endl;
    std::cout << "Two Pair" << std::endl;
    std::cout << "One pair" << std::endl;
    std::cout << "High Card" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

int main() {

    srand(time(0));

    //two vectors that contains the cards
    std::vector<Card> Deck;
    std::vector<Card> Hand;

    //prints out the UI
    showranks();
    //Makes the deck of 52 cards
    InitDeck(Deck);
    //This shuffles the deck
    shufflecards(Deck);
    //Deals the cards from Deck to Hand, Only 5 cards
    dealcards(Deck, Hand);

    //This will print out the players Hand
    std::cout << "Current Hand:" << std::endl;
    for (const Card& card : Hand) {
        std::cout << CardValueToString(card.cardValue) << " of " << CardSuitToString(card.cardSuit) << std::endl;
    }

    std::cout << endl;

    //Checks which hand the player has
    std::cout << "----------------------------------------------------" << std::endl;
    if (royal_flush(Hand)) {
        std::cout << "ROYAL FLUSH!!!" << std::endl;
    }
    else if (straight_flush(Hand)) {
        std::cout << "Straight Flush" << std::endl;
    }
    else if (four_of_kind(Hand)) {
        std::cout << "Four of a kind" << std::endl;
    }
    else if (full_house(Hand)) {
        std::cout << "Full House" << std::endl;
    }
    else if (flush(Hand)) {
        std::cout << "Flush" << std::endl;
    }
    else if (straight(Hand)) {
        std::cout << "Straight" << std::endl;
    }
    else if (three_of_kind(Hand)) {
        std::cout << "Three of a kind" << std::endl;
    }
    else if (two_pairs(Hand)) {
        std::cout << "Two Pairs of Cards" << std::endl;
    }
    else if (apair(Hand)) {
        std::cout << "Pair of Cards" << std::endl;
    }
    else {
        std::cout << "Your High Card is " << HighCardtoCardVal(highcard(Hand)) << std::endl;;
    }

    std::cout << "----------------------------------------------------" << std::endl;


    return 0;
}