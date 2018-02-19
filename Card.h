#pragma once
class Card
{

public:
	Card();
	void GenerateRandomNumberForGame();
	int cashUserDollar();
	int get_1_Suit_User();
	int get_2_Suit_User();
	int get_1_Suit_Dealer();
	int get_2_Suit_Dealer();
	int get_1_Rank_User();
	int get_2_Rank_User();
	int get_1_Rank_Dealer();
	int get_2_Rank_Dealer();
	int checkUserAmount();
	void userHitRule(int);
	~Card();
private:
	int set_1_Suit_User, set_2_Suit_User, set_1_Rank_User, set_2_Rank_User;
	int set_1_Suit_Dealer, set_2_Suit_Dealer, set_1_Rank_Dealer, set_2_Rank_Dealer;
	int cashUserMoney;
	const int suitSize = 4;
	const int rankSize = 13;
};

