#include "cell.h"

using namespace std;


/*=================================================================

			GATE

=================================================================*/

gate::gate(){
	left = NULL;
	right = NULL;
	cell = NULL;
	leftCut = false;
	rightCut = false;
}

bool gate::operator== (char* input){
	if(strcmp(this->cell->getCellName(), input) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*=================================================================

			CELL

=================================================================*/

/*
*
*	Cell Setter
*
*/
void cell::setCellName(char* input){
	char* newString = new char[strlen(input) + 1];
	strncpy(newString, input, strlen(input));
	newString[strlen(input)] = '\0';
	cellName = newString;
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

bool cell::operator==(char* input){
	if(strcmp(this->cellName, input) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*=================================================================

			BASIC CELL

=================================================================*/

/*
*
*	Basic Cell Setter
*
*/


void basicCell::setCellName(char* input){
	char* newString = new char[strlen(input) + 1];
	strncpy(newString, input, strlen(input));
	newString[strlen(input)] = '\0';
	cellName = newString;
}



void basicCell::setOutput(int input){
	outputNode = input;	
}



void basicCell::setInput(int input){
	inputNode.push_back(input);
}

void basicCell::setInputs(vector<int> input){
	inputNode = input;
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

bool basicCell::operator==(char* input){
	if(strcmp(this->cellName, input) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*=================================================================

			BENCH CELL

=================================================================*/

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
