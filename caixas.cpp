#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

//Boxes
typedef struct box{
	int id;
	int height;
	int width;
	int depth;
	int lex_sort;
}box;

/* 	The only important value for PD is the height,
	but we keep the ids to be to show in the result */
typedef struct pd_vector{
	std::vector<int> ids;
	int height;
}pd_vector;

/* Compare function to sort in descending order*/
bool compare(box a, box b){
    return  a.lex_sort > b.lex_sort; //compares the lex_sort
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
		/* Concat width + depth and save in lex_sort,
			lex_sort will be the value used for sorting */
		std::ostringstream aux;
		aux << dimensions.width << dimensions.depth;
		std::istringstream aux1(aux.str());
		aux1 >> dimensions.lex_sort;
		boxes.push_back(dimensions);
		id++;
	}
	// Print vector [1...n]
	/*for(std::vector<box>::iterator it = boxes.begin(); it != boxes.end(); ++ it){
		std::cout << (*it).id << " " << (*it).height << " " << (*it).width << " " 
		<< (*it).depth << " " << (*it).lex_sort <<  std::endl;
	}*/
	// Sort decreasing by lex_sort
	std::sort(boxes.begin(), boxes.end(), compare);	
	int n = id-1;
	pd_vector pd[n];
	/* Starts the position of the vector with their respective heights*/
	for (int i = 0; i < n; i++ ){
     	pd[i].height = boxes.at(i).height;
		pd[i].ids.push_back(boxes.at(i).id);
	}
	/* PD: calculates from the bottom up */
	for(int i=1; i<n; ++i){
		for(int j = 0; j< i; ++j){
			/* condition to add an element value in pd vector */
			if(boxes.at(i).width < boxes.at(j).width && boxes.at(i).depth < boxes.at(j).depth 
				&& pd[i].height < pd[j].height + boxes.at(i).height){
				pd[i].height = pd[j].height + boxes.at(i).height;
				pd[i].ids.clear(); //this is necessary to print response
				pd[i].ids.push_back(boxes.at(i).id); // add the box id of de current position
				// add all ids of the boxes in  pd[j]
				for(std::vector<int>::iterator it = pd[j].ids.begin(); it != pd[j].ids.end(); ++it)
					pd[i].ids.push_back(*it);
			}
		}
	}
	int max = -1, position = -1;
	/* Find max value */
	for(int i=0; i<n; ++i){
		if(max<pd[i].height){
			max = pd[i].height;
			position = i;
		}
	}
	//std::cout << max << std::endl;
	/* Print the boxes id's*/
	for(std::vector<int>::iterator it = pd[position].ids.begin(); it != pd[position].ids.end(); ++it)
		std::cout << *it << std::endl; 
	return 0;
}
