#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

typedef struct box{
	int id;
	int height;
	int width;
	int depth;
	int area;
	int lex_sort;
}box;

bool compare(box a, box b){
    return  a.lex_sort > b.lex_sort;
}

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
		dimensions.area = dimensions.height * dimensions.width;
		std::ostringstream aux;
		aux << dimensions.width << dimensions.depth;
		std::istringstream aux1(aux.str());
		aux1 >> dimensions.lex_sort;
		boxes.push_back(dimensions);
		id++;
	}
	// Print vector [1...n]
	/*for(std::vector<box>::iterator it = boxes.begin(); it != boxes.end(); ++ it){
		std::cout << (*it).id << " " << (*it).height << " " << (*it).width << " " << (*it).depth << " " << (*it).area << " " << (*it).lex_sort <<  std::endl;
	}*/
	// Sort decreasing by lex_sort
	std::sort(boxes.begin(), boxes.end(), compare);	
	/*for(std::vector<box>::iterator it = boxes.begin(); it != boxes.end(); ++ it){
		std::cout << (*it).id << " " << (*it).height << " " << (*it).width << " " << (*it).depth << " " << (*it).area << " " << (*it).lex_sort <<  std::endl;
	}*/
	int n = id-1;
	int pd_vector[n];
	for (int i = 0; i < n; i++ ){
     	pd_vector[i] = boxes.at(i).height;
		std::cout << pd_vector[i] << std::endl;
	}
	for(int i=1; i<n; ++i){
		for(int j = 0; j< i; ++j){
			if(boxes.at(i).width < boxes.at(j).width && boxes.at(i).depth < boxes.at(j).depth && pd_vector[i] < pd_vector[j] + boxes.at(i).height){
				pd_vector[i] = pd_vector[j] + boxes.at(i).height;
			}
		}
	}
	int max = -1;
	for(int i=0; i<n; ++i){
		if(max<pd_vector[i]){
			max = pd_vector[i];
		}
	}
	std::cout << max << std::endl; 
	
	return 0;
}
