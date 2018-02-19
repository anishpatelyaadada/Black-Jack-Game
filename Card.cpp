#include "Card.h"
#include <stdlib.h>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

Card::Card()
{
	
}
void Card::userHitRule(int totalPoint) {
	
		cout << "Do you like to cash money (enter 1 - YES / 2 - NO) = ";
		cin >> cashUserMoney;
}
int Card::cashUserDollar() {
	return cashUserMoney;
}
// below function generat the random number for the game
void Card::GenerateRandomNumberForGame() {
	srand((unsigned)time(NULL));
	set_1_Rank_Dealer = rand() % (rankSize - 1);
	set_2_Rank_Dealer = rand() % (rankSize - 1);
	set_1_Suit_Dealer = rand() % (suitSize - 1);
    set_2_Suit_Dealer = rand() % (suitSize - 1);
	set_1_Rank_User = rand() % (rankSize - 1);
	set_2_Rank_User = rand() % (rankSize - 1);
	set_1_Suit_User = rand() % (suitSize - 1);
	set_2_Suit_User = rand() % (suitSize - 1);
}
// check the enter user amount is correct or not
int Card::checkUserAmount() {
	int money;
	do {
		cout << "Incorrect amount!\n";
		cout << "Please enter the amount from $5.00 to $100.00 range = $";
		cin >> money;
	} while ((money) <= 17 || (money) >= 100);
	return money;
}

/*1 rank and suit for user*/
int Card::get_1_Rank_User() {
	return set_1_Rank_User;
}
int Card::get_1_Suit_User() {
	return set_1_Suit_User;
}
/*2 rank and suit for user*/
int Card::get_2_Rank_User() {
	return set_2_Rank_User;
}
int Card::get_2_Suit_User() {
	return set_2_Suit_User;
}
/*1 rank and suit for dealer*/
int Card::get_1_Rank_Dealer() {
	return set_1_Rank_Dealer;
}
int Card::get_1_Suit_Dealer() {
	return set_1_Suit_Dealer;
}
/*2 rank and suit for user*/
int Card::get_2_Rank_Dealer() {
	return set_2_Rank_Dealer;
}
int Card::get_2_Suit_Dealer() {
	return set_2_Suit_Dealer;
}
Card::~Card()
{
}
