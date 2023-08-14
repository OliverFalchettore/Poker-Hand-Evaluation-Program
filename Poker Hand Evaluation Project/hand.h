#pragma once
#ifndef HAND_H_
#define HAND_H_
#include <vector>
#include <algorithm>

#include "Card.h"

int highcard(std::vector<Card>& Hand);
bool apair(std::vector<Card>& Hand);
bool two_pairs(std::vector<Card>& Hand);
bool three_of_kind(std::vector<Card>& Hand);
bool straight(std::vector<Card>& Hand);
bool flush(std::vector<Card>& Hand);
bool full_house(std::vector<Card>& Hand);
bool four_of_kind(std::vector<Card>& Hand);
bool straight_flush(std::vector<Card>& Hand);
bool royal_flush(std::vector<Card>& Hand);


#endif