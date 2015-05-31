#include <fstream>
#include <iostream>
#include <vector>

struct Dot {
	int x;
	int z;
};

std::vector<Dot> dots;

int main()
{
	//write
	std::ofstream out("test.txt", std::ios_base::binary);
	dots.push_back({ 3, 2 });
	dots.push_back({ 3, 4 });
	int size = dots.size();
	out.write((char *)&size, sizeof(size));
	for (int i = 0; i < dots.size(); i++) {
		out.write((char *)&dots[i], sizeof(dots[i]));
	}

	//read
	std::ifstream in("test.txt", std::ios_base::binary);
	size=0;
	in.read((char *)&size, sizeof(size));
	for (int i = 0; i < size; i++) {
		Dot dot;
		in.read((char *)&dot, sizeof(dot));
		dots.push_back(dot);
	}
	for (int i = 0; i < dots.size(); i++) {
		std::cout << dots[i].x << " " << dots[i].z << std::endl;
	}
}