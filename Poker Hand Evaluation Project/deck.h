//prototypes that controls the deck
#pragma once
#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "Card.h"

void InitDeck(std::vector<Card>& Deck);
void shufflecards(std::vector<Card>& Deck);
void dealcards(std::vector<Card>& Deck, std::vector<Card>& Hand);

#endif