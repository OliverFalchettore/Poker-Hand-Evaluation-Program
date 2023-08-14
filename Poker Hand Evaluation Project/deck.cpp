#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "deck.h"
#include "Card.h"

#define DECK_SIZE 52
#define HAND_MAX 5




//creates the deck of cards and pushed into vector
void InitDeck(std::vector<Card>& Deck) {
    //iterate of enums of Suits
    for (int suit = Clubs; suit <= Spades; ++suit) {
        //iterate of enums of Values
        for (int value = Two; value <= Ace; ++value) {
            //creates card structure
            Card card;
            card.cardSuit = static_cast<Suit>(suit);
            card.cardValue = static_cast<Value>(value);
            Deck.push_back(card);
        }
    }
}

//shuffle the cards so that it can be dealt
void shufflecards(std::vector<Card>& Deck) {
    random_shuffle(Deck.begin(), Deck.end());
}

//deal cards to the users hand
void dealcards(std::vector<Card>& Deck, std::vector<Card>& Hand) {
    //counter for the while loop
    int hand_count = 0;
    int n;

    while (hand_count != HAND_MAX) {
        //gives random number
        n = rand() % Deck.size();
        //takes an element from the deck of *Card* and pushes back to Hand
        Hand.push_back(Deck[n]);
        //erases number from hand to prevent duplicates
        Deck.erase(Deck.begin() + n);
        hand_count++;
    }
}


