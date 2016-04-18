#include "cell.h"

using namespace std;
/*
*
*	Cell Setter
*
*/
void cell::setCellName(char* input){
	cellName = input;
}


void cell::setTotalInputNodes(int input){
	totalInputNodes = input;
}


void cell::setDelay(int input){
	delay = input;
}
	


void cell::setTotalCells(int input){
	totalCells = input;	
}

/*
*
*	Cell Getter
*
*/

char* cell::getCellName(){
	return cellName;
}


int cell::getTotalInputNodes(){
	return totalInputNodes;
}


int cell::getDelay(){
	return delay;
}
	


int cell::getTotalCells(){
	return totalCells;	
}


/*
*
*	Basic Cell Setter
*
*/


void basicCell::setCellName(char* input){
	cellName = input;
}



void basicCell::setOutput(int input){
	outputNode = input;	
}



void basicCell::setInput(int input){
	inputNode.push_back(input);
}

/*
*
*	Basic Cell Getter
*
*/

char* basicCell::getCellName(){
	return cellName;
}



int basicCell::getOutput(){
	return outputNode;	
}



vector<int> basicCell::getInput(){
	return this->inputNode;	
}



/*
*
*	Bench Cell Setter
*
*/


void benchCell::setInputs(int input){
	inputs.push_back(input);
}


void benchCell::setOutputs(int input){
	outputs.push_back(input);
}


/*
*
*	Bench Cell Getter
*
*/


vector<int> benchCell::getInputs(){
	return inputs;
}


vector<int> benchCell::getOutputs(){
	return outputs;
}