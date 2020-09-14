#include <iostream>
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

    void print() {                                                 //сделал для проверки методов класса
        cout << "The value of the card " << GetValue() << endl;;
    }

private:
    Suit suit;
    Rank rank;
    bool IsFaceUp;
};

int main() {

    Card card_1(Card::HEARTS,Card::QUEEN, true);
    card_1.print();
    card_1.Flip();
    card_1.print();
    cout << endl;

    Card card_2(Card::CLUBS, Card::SIX, false);
    card_2.print();
    card_2.Flip();
    card_2.print();

	return 0;
}
