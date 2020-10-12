#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card { 
public:
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };

    Card() : suit(HEARTS), rank (ACE), IsFaceUp(false) {
    }

    Card (Suit s, Rank r, bool face) : suit(s), rank(r), IsFaceUp(face) {
    }

    void Flip() {
        IsFaceUp = !IsFaceUp;
    }

    int GetValue () {
        int val = 0;
        if (IsFaceUp) {
            val = rank;
        }
        return val;
    }

private:
    Suit suit;
    Rank rank;
    bool IsFaceUp;
};

class Hand
{
public:
    Hand() {
        Cards.reserve(10);
    }

    void Add(Card* pCard) {
       Cards.push_back(pCard);
    }

    void Clear() {
        vector<Card*>::iterator it = Cards.begin();
        for (it = Cards.begin(); it != Cards.end(); ++it) {
            *it = 0;
        }
        Cards.clear();
    }

    int GetTotal() const {
        if (Cards.empty()) {
            return 0;
        }

        if (Cards[0]->GetValue() == 0) {
            return 0;
        }

        int total = 0;
        vector<Card*>::const_iterator it;
        for (it = Cards.begin(); it != Cards.end(); ++it) {
            total += (*it)->GetValue();
        }

        bool containsAce = false;
        for (it = Cards.begin(); it != Cards.end(); ++it) {
            if ((*it)->GetValue() == Card::ACE) {
                containsAce = true;
            }
        }

        if (containsAce && total <= 11) {
            total += 10;
        }

        return total;
    }

protected:
    vector<Card*> Cards;
};

int main()
{
    Card card_1(Card::HEARTS,Card::QUEEN, true);
    Card card_2(Card::HEARTS, Card::SIX, true);

    Hand hand;
    hand.Add(&card_1);
    hand.Add(&card_2);
    cout << hand.GetTotal() << endl;

    hand.Clear();
    cout << hand.GetTotal() << endl;

    Card card_3(Card::HEARTS, Card::SEVEN, true);  
    Card card_4(Card::HEARTS, Card::ACE, true);
    Card card_5(Card::HEARTS, Card::ACE, true);
    hand.Add(&card_3);
    hand.Add(&card_4);
    hand.Add(&card_5);
    cout << hand.GetTotal() << endl;


    return 0;
}

