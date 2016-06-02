// Fill out your copyright notice in the Description page of Project Settings.

#include "OrderVsChaos.h"
#include "OrderVsChaosLevel.h"

bool AOrderVsChaosLevel::CalculateOrderWin(TArray<AChip*> chips) {
	const int mapSize = 6;
	int countBlue = 0;
	int countRed = 0;
	int x = 0;
	int y = 0;
	//Vertical
	for (x = 1; x < mapSize; x++) {
		countBlue = 0;
		countRed = 0;
		for (y = 1; y < mapSize; y++) {
			AChip * chip = this->get2D<AChip*>(chips, mapSize, x, y);
			countRed += chip->IsRed();
			countBlue += chip->IsBlue();
		}
		if (countRed == 6 || countBlue == 6) return true;

	}
	//Horizontal
	for (y = 1; x < mapSize; y++) {
		countBlue = 0;
		countRed = 0;
		for (x = 1; y < mapSize; x++) {
			AChip * chip = this->get2D<AChip*>(chips, mapSize, x, y);
			countRed += chip->IsRed();
			countBlue += chip->IsBlue();
		}
		if (countRed == 6 || countBlue == 6) return true;

	}
	//Diagonal \

	countBlue = 0;
	countRed = 0;
	for (y = 1, x = 0; (x < mapSize) && (y < mapSize); y++, x++) {
		AChip * chip = this->get2D<AChip*>(chips, mapSize, x, y);
		countRed += chip->IsRed();
		countBlue += chip->IsBlue();
	}
	if (countRed == 6 || countBlue == 6) return true;
	//Diagonal /
	countBlue = 0;
	countRed = 0;
	for (y = mapSize, x = mapSize; (x > 1) && (y > 1); y--, x--) {
		AChip * chip = this->get2D<AChip*>(chips, mapSize, x, y);
		countRed += chip->IsRed();
		countBlue += chip->IsBlue();
	}
	if (countRed == 6 || countBlue == 6) return true;
	return false;
};
