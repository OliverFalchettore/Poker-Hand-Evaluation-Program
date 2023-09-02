# Poker-Hand-Evaluation-Program

Poker Hand Evaluation Program

The Poker Hand Evaluation Program is a C++ application designed to determine and classify various hand ranks in a standard deck of playing cards. The program takes a user's hand of cards as input and analyzes it to identify the highest-ranking poker hand present in the given hand. The program uses a set of functions to check for different hand ranks, providing an assessment of the strength of the hand.

Key Features:

Hand Ranks Detection: The program is equipped with a range of functions to detect and evaluate different poker hand ranks, including:

One Pair (apair)
Two Pairs (two_pairs)
Three of a Kind (three_of_kind)
Straight (straight)
Flush (flush)
Full House (full_house)
Four of a Kind (four_of_kind)
Straight Flush (straight_flush)
Royal Flush (royal_flush)
User Interaction: The program interacts with the user by receiving input for a hand of cards. The user provides cards in the form of card values and suits, and the program processes this input to determine the highest-ranking hand.

Hand Classification: The program evaluates the given hand by checking it against each of the predefined functions. It then classifies the hand based on the highest-ranking hand found, providing textual feedback to the user.

High Card Determination: If no specific poker hand is detected, the program determines the high card value in the hand.

Usage:

Input: The user provides input for a hand of cards, where each card is represented by its value and suit.

Processing: The program processes the user's input and applies various functions to determine the hand's rank.

Output: The program outputs a message indicating the highest-ranking hand present in the input hand. If none of the specific hands are detected, the program displays the value of the highest card.

How to Run:

Compile: Compile the program using a C++ compiler.

Execute: Run the compiled executable.

Input: Follow the prompts to input the cards in your hand.

Output: The program will display the determined hand rank or high card value.

Example Output:

Enter the cards in your hand: Card 1 - Value: Ace, Suit: Hearts Card 2 - Value: King, Suit: Hearts Card 3 - Value: Queen, Suit: Hearts Card 4 - Value: Jack, Suit: Hearts Card 5 - Value: Ten, Suit: Hearts

Your Hand: Royal Flush!

Note: The Poker Hand Evaluation Program serves as a simple yet comprehensive tool to determine the strength of a given hand in a standard deck of playing cards, making it suitable for poker enthusiasts and game developers.
