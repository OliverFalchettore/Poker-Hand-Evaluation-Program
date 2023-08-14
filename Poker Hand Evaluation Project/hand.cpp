#include <vector>
#include <algorithm>

#include "Card.h"
#include "hand.h"


int highcard(std::vector<Card>& Hand) {
	// Initialize a variable to store the highest card value
	int high_card = Hand[0].cardValue;

	// Loop through each card in the hand
	for (int i = 0; i < Hand.size(); i++) {
		// Check if the current card's value is higher than the current highest card value
		if (high_card < Hand[i].cardValue) {
			// If so, update the highest card value to the current card's value
			high_card = Hand[i].cardValue;
		}
	}

	// Return the highest card value in the hand
	return high_card;
}


// This function checks whether there is a pair of cards with the same value in a given hand.
bool apair(std::vector<Card>& Hand) {
	// Iterate through each card in the hand.
	for (int i = 0; i < Hand.size(); i++) {
		// Iterate through the remaining cards to compare them with the current card.
		for (int j = i + 1; j < Hand.size(); j++) {
			// Compare the values of the current card and the card being compared.
			if (Hand[i].cardValue == Hand[j].cardValue) {
				// If the values are the same, a pair has been found, so return true.
				return true;
			}
		}
	}
	// If no pairs were found after checking all combinations, return false.
	return false;
}

bool two_pairs(std::vector<Card>& Hand) {
	int match = 0;

	for (int i = 0; i < Hand.size(); i++) {
		for (int j = i + 1; j < Hand.size(); j++) {
			if (Hand[i].cardValue == Hand[j].cardValue) {
				match++;
			}
		}
	}

	if (match == 2) {
		return true;
	}

	return false;
}


// This function checks whether there is a three-of-a-kind combination of cards with the same value in a given hand.
bool three_of_kind(std::vector<Card>& Hand) {
	// Iterate through each card in the hand.
	for (int i = 0; i < Hand.size(); i++) {
		// Initialize a counter to keep track of how many cards match the value of the current card.
		int match = 0;

		// Iterate through the remaining cards to compare them with the current card.
		for (int j = i + 1; j < Hand.size(); j++) {
			// Compare the values of the current card and the card being compared.
			if (Hand[i].cardValue == Hand[j].cardValue) {
				// Increment the match counter if the values match.
				match++;
			}

			// Check if a three-of-a-kind has been found.
			if (match == 3) {
				// If three matching cards have been found, return true.
				return true;
			}
		}
	}

	// If no three-of-a-kind combinations were found after checking all combinations, return false.
	return false;
}



// This function checks whether a straight combination of cards exists in a given hand.
bool straight(std::vector<Card>& Hand) {
	// Determine the lowest card value in the hand.
	int k = Hand[0].cardValue;
	for (int i = 0; i < Hand.size(); i++) {
		// Update the lowest card value if a smaller value is encountered.
		if (k > Hand[i].cardValue) {
			k = Hand[i].cardValue;
		}
	}

	// Check for a sequence of consecutive cards starting from the lowest card value.
	for (int i = 1; i < 4; i++) {
		// Flag to track whether a card with the required value exists.
		bool hasStraight = false;

		// Iterate through the hand to find a card with the expected value.
		for (int j = 0; j < Hand.size(); j++) {
			if (Hand[j].cardValue == (k + i)) {
				// Set the flag to true if a matching card is found.
				hasStraight = true;
			}
		}

		// If no matching card was found for this part of the sequence, return false.
		if (hasStraight == false) {
			return false;
		}
	}

	// If a sequence of consecutive cards was found, return true.
	return true;
}


// This function checks whether all cards in a given hand belong to the same suit, indicating a flush.
bool flush(std::vector<Card>& Hand) {
	// Get the suit of the first card in the hand.
	Suit firstsuit = Hand[0].cardSuit;

	// Iterate through the remaining cards in the hand.
	for (int i = 0; i < Hand.size() - 1; i++) {
		// Compare the suit of each card with the suit of the first card.
		if (firstsuit != Hand[i].cardSuit) {
			// If any card has a different suit, return false (not a flush).
			return false;
		}
	}

	// If all cards have the same suit, return true (flush).
	return true;
}


// This function checks whether a full house combination exists in a given hand.
bool full_house(std::vector<Card>& Hand) {
	int threeofkind = 0;  // To store the value of the three-of-a-kind part of the full house.

	// Iterate through each card in the hand to find a three-of-a-kind.
	for (int i = 0; i < Hand.size(); i++) {
		int match = 0;  // Count the number of matching cards.

		// Iterate through the remaining cards to compare them with the current card.
		for (int j = i + 1; j < Hand.size(); j++) {
			// Compare the values of the current card and the card being compared.
			if (Hand[i].cardValue == Hand[j].cardValue) {
				match++;
			}

			// If three matching cards are found, store the value and exit the loop.
			if (match == 2) {
				threeofkind = Hand[i].cardValue;
				break;
			}
		}
	}

	// If no three-of-a-kind was found, return false.
	if (threeofkind == 0) {
		return false;
	}

	// Iterate through the hand to check for a pair with a different value.
	for (int i = 0; i < Hand.size(); i++) {
		for (int j = i + 1; j < Hand.size(); j++) {
			// Check if a pair with a different value exists.
			if (Hand[i].cardValue == Hand[j].cardValue && Hand[i].cardValue != threeofkind) {
				// If found, a full house is present, so return true.
				return true;
			}
		}
	}

	// If no pair with a different value was found, return false.
	return false;
}



// This function checks whether a four-of-a-kind combination exists in a given hand.
bool four_of_kind(std::vector<Card>& Hand) {
	// Iterate through each card in the hand.
	for (int i = 0; i < Hand.size(); i++) {
		int match = 0;  // Count the number of matching cards.

		// Iterate through the remaining cards to compare them with the current card.
		for (int j = i + 1; j < Hand.size(); j++) {
			// Compare the values of the current card and the card being compared.
			if (Hand[i].cardValue == Hand[j].cardValue) {
				match++;
			}

			// If four matching cards are found, return true.
			if (match == 4) {
				return true;
			}
		}
	}

	// If no four-of-a-kind was found, return false.
	return false;
}



// This function checks whether a straight flush combination exists in a given hand.
bool straight_flush(std::vector<Card>& Hand) {
	Suit firstsuit = Hand[0].cardSuit;  // Get the suit of the first card in the hand.
	int k = Hand[0].cardValue;  // Get the value of the first card in the hand.

	// Find the lowest card value in the hand.
	for (int i = 0; i < Hand.size(); i++) {
		if (k > Hand[i].cardValue) {
			k = Hand[i].cardValue;
		}
	}

	// Check for a sequence of consecutive cards with the same suit.
	for (int i = 1; i < 4; i++) {
		bool hasStraightandflush = false;  // Flag to track if a straight flush is found.

		// Iterate through the hand to find a card with the expected value and suit.
		for (int j = 0; j < Hand.size(); j++) {
			if ((Hand[j].cardValue == (k + i)) && (firstsuit == Hand[j].cardSuit)) {
				hasStraightandflush = true;
			}
		}

		// If no card with the expected value and suit was found, return false.
		if (hasStraightandflush == false) {
			return false;
		}
	}

	// If a sequence of consecutive cards with the same suit was found, return true.
	return true;
}



// This function checks whether a royal flush combination exists in a given hand.
bool royal_flush(std::vector<Card>& Hand) {
	Suit firstsuit = Hand[0].cardSuit;  // Get the suit of the first card in the hand.
	int k = Hand[0].cardValue;  // Get the value of the first card in the hand.

	// Find the lowest card value in the hand.
	for (int i = 0; i < Hand.size(); i++) {
		if (k > Hand[i].cardValue) {
			k = Hand[i].cardValue;
		}
	}

	// Check if the lowest card value is Ten.
	if (k != Ten) {
		return false;
	}

	// Check for a sequence of consecutive cards with the same suit starting from Ten.
	for (int i = 1; i < 4; i++) {
		bool hasStraightandflush = false;  // Flag to track if a royal flush is found.

		// Iterate through the hand to find a card with the expected value and suit.
		for (int j = 0; j < Hand.size(); j++) {
			if ((Hand[j].cardValue == (k + i)) && (firstsuit == Hand[j].cardSuit)) {
				hasStraightandflush = true;
			}
		}

		// If no card with the expected value and suit was found, return false.
		if (hasStraightandflush == false) {
			return false;
		}
	}

	// If a sequence of consecutive cards with the same suit starting from Ten was found, return true.
	return true;
}