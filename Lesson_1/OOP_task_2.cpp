#include <iostream>
#include <cstdint>

using namespace std;

class RGBA {
public:
	RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255){

	}

	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {

	}

	void print() {
		cout << m_red << endl << m_green << endl << m_blue << endl << m_alpha << endl;
	}

private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
};

int main() {
	RGBA a;
	a.print();

	RGBA b(101, 102, 103, 104);
	b.print();
	
	return 0;
}