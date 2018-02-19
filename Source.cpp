#include<iostream>
#include <string>
#include<fstream>
#include<vector>
#include"Card.h"
using namespace std;
// below array to store data of playing cards
string Suit[4] = { "Ace", "Jack", "Queen", "King" };
string Rank[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
// to display the result of game
void displayResult(vector<bool> &, vector<bool> &);

int main() {
	Card report;
	bool userWin = false, dealerWin = false;
	vector<bool> totalUserWin, totalDealerWin;
	int i = 0, j = 0;
	int repeat, betUserMoney = 0;
	double blackJackAmount;
	int user1CardRank, user2CardRank, user1CardSuit, user2CardSuit, total_user_rank = 0;
	int dealer1CardRank, dealer2CardRank, dealer1CardSuit, dealer2CardSuit, total_dealer_rank = 0;

	// repeat the game for 3 times
	while (j < 3) {
		cout << "Game #" << j + 1 << endl;
		i = 0;
	
		try
		{
			// ask user to enter the amount
			cout << "Enter the amount you want to bet = $";
			cin >> betUserMoney;
			if (betUserMoney <= 5 || betUserMoney >= 100) {
				betUserMoney = report.checkUserAmount(); // if the money is less than $5 and more than $100 reject it and ask them to enter again
			}
			if (betUserMoney >= 5 || betUserMoney <= 100) {
				do {
					// generate number to play
					userWin = false;
					dealerWin = false;
					report.GenerateRandomNumberForGame();
					user1CardRank = report.get_1_Rank_User(); user1CardSuit = report.get_1_Suit_User();
					user2CardRank = report.get_2_Rank_User(); user2CardSuit = report.get_2_Suit_User();
					dealer1CardRank = report.get_1_Rank_Dealer(); dealer1CardSuit = report.get_1_Suit_Dealer();
					dealer2CardRank = report.get_2_Rank_Dealer(); dealer2CardSuit = report.get_2_Suit_Dealer();
					// add the generated number to see if they win or not				
					total_user_rank = (user1CardRank + user2CardRank);
					total_dealer_rank = (dealer1CardRank + dealer2CardRank);

					// display their result of each draw
					cout << "#" << i + 1 << " Draw.\n";
					cout << "User(Suit, Rank) Card 1= " << Suit[user1CardSuit] << ", " << Rank[user1CardRank] << " ;";
					cout << "Card 2= " << Suit[user2CardSuit] << ", " << Rank[user2CardRank] << endl;
					cout << "Dealer(Suit, Rank) Card 1= " << Suit[dealer1CardSuit] << ", " << Rank[dealer1CardRank] << " ;";
					cout << "Card 2= " << Suit[dealer2CardSuit] << ", " << Rank[dealer2CardRank] << endl;
					cout << "User total Point = " << total_user_rank << " ;";
					cout << "Dealer total Point = " << total_dealer_rank << endl;

					//if the dealer point is 21 then the game is over and they win
					if (total_dealer_rank == 21) {
						cout << "Dealer total is 21, Black Jack! They win!\n";
						cout << "Black Jack winning Amount = $" << 2 * betUserMoney << endl;
						dealerWin = true;

						break;
					}
					//if the user point is 21 then the game is over and they win
					if (total_user_rank == 21) {
						cout << "User total is 21, Black Jack! They win!\n";
						blackJackAmount = 2 * (betUserMoney + (betUserMoney*0.5));
						cout << "Black Jack winning Amount = $" << blackJackAmount << endl;
						userWin = true;
						break;
					}
					// terminate  the game if it is more than 22
					if (total_user_rank >= 22) {
						cout << "User total point is more than 21, you loss. Please play again.!\n";
						break;
					}
					// to check the point or cash the money
					if (total_user_rank >= 17 && total_user_rank <= 21) {
						report.userHitRule(total_user_rank);
						if (report.cashUserDollar() == 1) {
							cout << "You win = $" << 2 * betUserMoney << endl;
							userWin = true;
							break;
						}
					}
					if (total_dealer_rank >= 22) {
						cout << "Dealer total point is more than 21, you loss. Please play again.!\n";
						break;
					}
					// terminate the game after 5 draw or if dealer win or user win
					if (i == 4 || total_dealer_rank == 21) {
						break;
					}
					// boolean data to check how many time user and dealer win
					
					cout << "Repeat Process = ";
					cin >> repeat;
					i++;
				} while (repeat == 1 && i != 5);
				cout << endl;
				totalDealerWin.push_back(dealerWin);
				totalUserWin.push_back(userWin);
			}
		}
		catch (string e)
		{
			cout << e << endl;
		}
		j++;
	}
	displayResult(totalDealerWin, totalUserWin);
	system("pause");
	return 0;
}
// display the result of the game
void displayResult(vector<bool> &dealerWin, vector<bool> &userWin) {
	int size = dealerWin.size();
	cout << endl << "Display the result of each game!" << endl;
	cout << "1 - Win / 0 - Loss\n";
	for (int i = 0; i < size; i++) {
		cout << "Game #" << i + 1 << "; User = " << userWin[i] << ", Dealer = " << dealerWin[i] << endl;
	}
}