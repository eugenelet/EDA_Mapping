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

using namespace std;

class basicCell;

class cell{
public:
	cell(){};
	void setCellName(char*);
	void setTotalInputNodes(int);
	void setDelay(int);
	void setTotalCells(int);

	char* getCellName();
	int getTotalInputNodes();
	int getDelay();
	int getTotalCells();	

	vector<basicCell> cells;
private:
	char* cellName;
	int totalInputNodes;
	int delay;
	int totalCells;

	vector<int> inputNodes;
	int outputNode;
};

class basicCell{
public:
	basicCell(){};
	void setCellName(char*);
	void setOutput(int);
	void setInput(int);

	char* getCellName();
	int getOutput();
	vector<int> getInput();//no friggin idea why it's not woring....
	
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
	vector<basicCell> cells;

private:
	vector<int> inputs;
	vector<int> outputs;

};
