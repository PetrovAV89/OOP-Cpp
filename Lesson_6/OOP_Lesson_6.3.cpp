#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
    friend ostream& operator<<(ostream& os, const Card& aCard);

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

class Hand {
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

class GenericPlayer : public Hand {
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

class Player : public GenericPlayer {
public:

    virtual bool IsHitting() const {
        cout << Name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void Win() const {
        cout << Name << " wins!" << endl;
    }

    void Lose() const {
        cout << Name << " loses!" << endl;
    }

    void Push() const {
        cout << Name << " pushes!" << endl;
    }
};

class House : public GenericPlayer {
public:
    virtual bool IsHitting() const {
        return (GetTotal() <= 16);
    }

    void FlipFirstCard() {
        if (!(Cards.empty())) {
            Cards[0]->Flip();
        }
        else {
            cout << "No card to flip!" << endl;
        }
    }
};

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.IsFaceUp) {
        os << RANKS[aCard.rank] << SUITS[aCard.suit];
    }
    else {
        os << "XX";
    }
    return os;
}


int main() {

    return 0;
}