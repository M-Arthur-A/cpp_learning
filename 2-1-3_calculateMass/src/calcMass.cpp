#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Block {
	int density;
	int volume;
	int mass;

public:
	Block(int d, int v) {
		density = d;
		volume = v;
		calcMass();
	}

	void calcMass() {
		mass = density * volume;
	}

	int getMass() const {
		return mass;
	}
};
ostream& operator<<(ostream& out, Block& b) {
		out << b.getMass() << endl;
		return out;
	}

class Blocks {
	vector<Block> blocks;
public:
	Blocks(unsigned quantity, int density) {
		for (unsigned i = 0; i < quantity; ++i) {
			int v;
			cout << "Set volume: ";
			cin >> v;
			cout << endl;
			blocks.push_back({density, v});
		}
	}

	unsigned BlocksMass() {
		unsigned mass_sum;
		for (auto block : blocks) {
			mass_sum += block.getMass();
		}
		return mass_sum;
	}
};

int main() {
	unsigned quantity, density;
	cout << "Set number of blocks and density: ";
	cin >> quantity >> density;
	Blocks b(quantity, density);
	cout << "Sum of mass of all blocks is " << b.BlocksMass() << endl;
	return 0;
}
