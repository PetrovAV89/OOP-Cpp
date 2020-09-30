#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };

    Card() : suit(HEARTS), rank(ACE), IsFaceUp(false) {
    }

    Card(Suit s, Rank r, bool face) : suit(s), rank(r), IsFaceUp(face) {
    }

    void Flip() {
        IsFaceUp = !IsFaceUp;
    }

    int GetValue() {
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

class GenericPlayer : public Hand
{
public:
    GenericPlayer(string name) : Name(name) {
    }

    virtual bool IsHitting() const = 0 {        
    }

    bool IsBoosted() {
        return (GetTotal() > 21);
    }

    void Bust() const {
        cout << Name << " more than 21!" << endl;
    }

protected:
	string Name;
};


int main() {

    return 0;
}