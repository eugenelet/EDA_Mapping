#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;

#define NAND_2	7	//111
#define NAND_L	6	//110
#define NAND_R	5	//101
#define NAND_0	4	//100
#define INV_1 	1	//001
#define INV_0 	0	//000

using namespace std;

class basicCell;
class gate;
class cell;
class benchCell;
class twigCell;

class twigCell{
public:
	char* cellName;
	vector<int> codedCells;
	int cellNumber;
	int delay;
};

class gate{
public:
	gate();
	gate* left;
	gate* right;
	bool leftCut;
	bool rightCut;
	vector<gate*> parent;
	basicCell* cell;
	bool operator==(char*);
private:

};


class cell{
public:
	cell(){};
	bool operator==(char*);
	void setCellName(char*);
	void setTotalInputNodes(int);
	void setDelay(int);
	void setTotalCells(int);

	char* getCellName();
	int getTotalInputNodes();
	int getDelay();
	int getTotalCells();	

	vector<basicCell*> cells;
private:
	char* cellName;
	int totalInputNodes;
	int delay;
	int totalCells;

	//vector<int> inputNodes;
	int outputNode;
};

class basicCell{
public:
	basicCell(){};
	bool operator==(char*);
	void setCellName(char*);
	void setOutput(int);
	void setInput(int);
	void setInputs(vector<int>);
	char* getCellName();
	int getOutput();
	vector<int> getInput();//no friggin idea why it's not working....
	
private:
	char* cellName;
	int outputNode;
	vector<int> inputNode;
	//vector<int> inputNode;
};

class benchCell{
public:
	benchCell(){};
	void setInputs(int);
	void setOutputs(int);

	vector<int> getInputs();
	vector<int> getOutputs();
	vector<basicCell*> cells;


private:
	vector<int> inputs;
	vector<int> outputs;

};

#endif