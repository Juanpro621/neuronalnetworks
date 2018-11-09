#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

void read_data(){
	int x=0;	
	while(x==0){
		std::string line;
	    std::getline(std::cin, line);
	    int d = std::stoi(line);
	    std::getline(std::cin, line);
	    int m = std::stoi(line);
	    std::getline(std::cin, line);
	    int n = std::stoi(line);
	    for(int i=0; i<m; i++){
	    	std::getline(std::cin, line);
		}
		for(int i=0; i<n; i++){
	    	std::getline(std::cin, line);
		}
	}
}

int main(){
	read_data();
}
