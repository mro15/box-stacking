#include <iostream>
#include <cstdlib>
#include <vector>

typedef struct box{
	int id;
	int height;
	int width;
	int depth;
}box;

int main(int argc, char *argv[]){
	if(argc!=1){
		std::cout << "Uso: ./caixas  < <arquivo de entrada>" << std::endl;
		return 0;
	}
	int id=1;
	std::vector<box> boxes;
	box dimensions;
	while(std::cin >> dimensions.height >> dimensions.width >> dimensions.depth){
		dimensions.id = id;
		boxes.push_back(dimensions);
		id++;
	}
	// Print vector [1...n]
	for(std::vector<box>::iterator it = boxes.begin(); it != boxes.end(); ++ it){
		std::cout << (*it).id << " " << (*it).height << " " << (*it).width << " " << (*it).depth <<  std::endl;
	}
	return 0;
}
