#include <iostream>

void fill_mat(char **mat, int h, int w, char car)
{
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
			mat[i][j] = car;
}

void print_mat(char **mat, int h, int w)
{
	for(int i=0; i<h; ++i)
	{
		for(int j=0; j<w; ++j)
			std::cout << mat[i][j] << " ";
		std::cout << std::endl;
	}
}

int main(void)
{
	int h=5, w=6;
	// char terrain_2[w*h];
	// terrain_2[i*w + j]
	char **terrain = new char*[h];
	for(int i = 0; i < h; ++i)
		terrain[i] = new char[w];
	fill_mat(terrain, h, w, 'X');
	print_mat(terrain, h, w);
	for(int i = 0; i < h; ++i)
		delete terrain[i];
	delete terrain;
	return 0;
}
