#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

class muestra{
	public:
		std::vector<float> inputs;
		int value;
};

std::vector<muestra> training_set;
std::vector<std::string> buffer;
std::vector<std::string> buffer2;
std::vector<muestra> test_set;
std::vector<float> weights;
int m, n, d, pred, bias;
float learnf, w_bias, threshold, error, res;


std::vector<std::string> splitStrings(std::string str, char dl) 
{ 
    std::string word = ""; 
    int num = 0; 
    str = str + dl; 
    int l = str.size(); 
  
    std::vector<std::string> substr_list; 
    for (int i = 0; i < l; i++) { 
        if (str[i] != dl) 
            word = word + str[i]; 
        else {
            if ((int)word.size() != 0) 
                substr_list.push_back(word); 
            word = ""; 
        } 
    } 
    return substr_list; 
}

void read_data(){
	std::string line;
    std::getline(std::cin, line);
	d = std::stoi(line);
    std::getline(std::cin, line);
    m = std::stoi(line);
	std::getline(std::cin, line);
    n = std::stoi(line);
	for(int i=0; i<m; i++){
    	muestra muestra1;
		std::getline(std::cin, line);
		buffer = splitStrings(line,',');
		for (int j=0; j <= d; j++){
			muestra1.inputs.push_back(std::stof(buffer[j]));
		}
		muestra1.value = std::stoi(buffer.back());
		training_set.push_back(muestra1);
	}
	for(int i=0; i<n; i++){
    	muestra muestra1;
		std::getline(std::cin, line);
		buffer2 = splitStrings(line,',');
		for (int j=0; j <= d; j++){
			muestra1.inputs.push_back(std::stof(buffer[j]));
		}
		test_set.push_back(muestra1);
	}
	for(int i = 0; i <= d; i++){
		float random = (rand() % 100) / 100;
		weights.push_back(random);
	}
}

void learn(){	
	bias = 1; 
	learnf = 0.05;
	w_bias = (rand() % 100) / 100;
	threshold = bias * w_bias;
	error;
	res = 0;
	for(int i = 0; i < 50; i++){
		for(int j = 0; j<training_set.size(); j++){
			for (int k = 0; k < d; k++)
				res = res + training_set[j].inputs[k]*weights[k];
			if(res >= threshold)
				pred = 1;
			else
				pred = 0;
			error = training_set[j].value - pred;
			for (int k = 0; k < d; k++)
				weights[k] = ((int)((weights[k] + learnf * error * training_set[j].inputs[k]) * 100) % 100) / 100;
			w_bias = ((int)((w_bias + learnf*error)*100)%100)/100;
		}
	}
}
void go(){
	res = 0;
	for(int i = 0; i < test_set.size(); i++){
		for(int j = 0; j < d; j++)
			res = res + test_set[i].inputs[j]*weights[j];
		if(res >= threshold)
			std::cout << "1" << "\n";
		else
			std::cout << "0" << "\n";
	}
	return;
}
int main(){
	srand(time(NULL));
	read_data();
	learn();
	go();
	return 0;
}
