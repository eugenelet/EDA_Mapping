#include "cell.h"
using namespace std;

vector<cell> libParser(char* fileName){
	vector<cell> totalCells;
	// create a file-reading object
	ifstream fin;
	fin.open(fileName); // open a file
	if (!fin.good()){
		cerr << "usage: ./output [cell library] [input set] " << endl;
    	exit(1);
    }
	
	// read each line of the file
	while (!fin.eof())
	{
		cell dummyCell;
		totalCells.push_back(dummyCell);

		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);
		
		
		// array to store memory addresses of the tokens in buf
		char* token; // initialize to 0
		char* newString;
		
		// parse the line
		token = strtok(buf, " ");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		totalCells.back().setCellName((char*)newString); // set Cell's Name


		token = strtok(0, " ");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		totalCells.back().setTotalInputNodes(atoi(newString)); // set Cell's Total input Nodes

		fin.getline(buf, MAX_CHARS_PER_LINE);

		token = strtok(buf, " ");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		totalCells.back().setDelay(atoi(newString)); // set Cell's Delay

		fin.getline(buf, MAX_CHARS_PER_LINE);
		while( (buf[0] != '\r') && (!fin.eof()) ){

			basicCell dummyBasicCell;

			token = strtok(buf, " ");
			newString = (char*)malloc(strlen(token) + 1);
			strncpy(newString, token, sizeof(token));
			dummyBasicCell.setOutput(atoi(newString));

			strtok(0, " ");

			token = strtok(0, "(");
			newString = (char*)malloc(strlen(token) + 1);
			strncpy(newString, token, sizeof(token));
			dummyBasicCell.setCellName((char*)newString);


			token = strtok(0, ")");
			newString = (char*)malloc(strlen(token) + 1);
			strncpy(newString, token, sizeof(token));

			token = strtok(newString, ",");

			while(token != NULL){
				dummyBasicCell.setInput(atoi(token));
				token = strtok(0, ",");
			}

			totalCells.back().cells.push_back(dummyBasicCell);
			fin.getline(buf, MAX_CHARS_PER_LINE);
		}
	}

	return totalCells;

}


benchCell benchParser(char* fileName){
	benchCell bench;
	// create a file-reading object
	ifstream fin;
	fin.open(fileName); // open a file
	if (!fin.good()){
		cerr << "usage: ./output [cell library] [input set] " << endl;
    	exit(1);
    }

	char buf[MAX_CHARS_PER_LINE];
	
	
	// array to store memory addresses of the tokens in buf
	char* token; // initialize to 0
	char* newString;
/*
*
*	Set inputs
*
*/
	fin.getline(buf, MAX_CHARS_PER_LINE);
	while( (buf[0] != '\r') && (!fin.eof()) && (buf[0] != 0)){
		strtok(buf, "(");
		token = strtok(0, " )");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		bench.setInputs(atoi(newString));
		fin.getline(buf, MAX_CHARS_PER_LINE);
	}	



/*
*
*	Set outputs
*
*/
	fin.getline(buf, MAX_CHARS_PER_LINE);
	while( (buf[0] != '\r') && (!fin.eof())  && (buf[0] != 0)){
		strtok(buf, "(");
		token = strtok(0, " )");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		bench.setOutputs(atoi(newString));
		fin.getline(buf, MAX_CHARS_PER_LINE);
	}		

/*
*
*	Set Cells
*
*/
	
	fin.getline(buf, MAX_CHARS_PER_LINE);
	while( (buf[0] != '\r') && (!fin.eof())  && (buf[0] != 0)){
		basicCell dummyBasicCell;
		token = strtok(buf, " ");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		dummyBasicCell.setOutput(atoi(newString));
		strtok(0, " ");
		token = strtok(0, "(");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));
		dummyBasicCell.setCellName((char*)newString);
		token = strtok(0, ")");
		newString = (char*)malloc(strlen(token) + 1);
		strncpy(newString, token, sizeof(token));


		token = strtok(newString, ",");
		//newString = (char*)malloc(strlen(token) + 1);
		//strncpy(newString, token, sizeof(token));

		while(token != NULL){
			dummyBasicCell.setInput(atoi(token));
			token = strtok(0, ",");
		}
		/*
		if(strlen(token) == 4){
			dummyBasicCell.setInput((newString[0]) - '0');
		dummyBasicCell.setInput(newString[3] - '0');
		}
		else{
			dummyBasicCell.setInput(atoi(newString));
		}*/
		bench.cells.push_back(dummyBasicCell);
		fin.getline(buf, MAX_CHARS_PER_LINE);
	}

	return bench;

}



void libPrinter(vector<cell> inputLib){
	std::vector<cell>::iterator cellIterator;
	for(cellIterator = inputLib.begin(); cellIterator != inputLib.end(); cellIterator++){
		cout << "Top Cell Name: " << cellIterator->getCellName() << endl;
		cout << "Total Input Nodes: " << cellIterator->getTotalInputNodes() << endl;
		cout << "Cell Delay: " << cellIterator->getDelay() << endl;
		std::vector<basicCell>::iterator basicCellIterator;
		for(basicCellIterator = cellIterator->cells.begin(); basicCellIterator != cellIterator->cells.end(); basicCellIterator++){
			cout << "\t Cell Name: " << basicCellIterator->getCellName() << endl;
			cout << "\t Output: " << basicCellIterator->getOutput() << endl;
			std::vector<int>::iterator inputIt;
			
			vector<int> inputs = basicCellIterator->getInput();//something's wrong with iterator
			for(int i = 0; i< inputs.size(); i++){
				cout << "\t Input: " << inputs[i] << endl;
			}
		}
		cout << endl << endl;
	}

}



void benchPrinter(benchCell inputBench){
	vector<int> inputs = inputBench.getInputs();
	vector<int> outputs = inputBench.getOutputs();

	for(int i = 0; i < inputs.size(); i++){
		cout << "Input: " << inputs[i] << endl;
	}

	cout << endl ;


	for(int i = 0; i < outputs.size(); i++){
		cout << "Output: " << outputs[i] << endl;
	}

	cout << endl;


	std::vector<basicCell>::iterator basicCellIterator;
	for(basicCellIterator = inputBench.cells.begin(); basicCellIterator != inputBench.cells.end(); basicCellIterator++){
		cout << "\t Cell Name: " << basicCellIterator->getCellName() << endl;
		cout << "\t Output: " << basicCellIterator->getOutput() << endl;
		std::vector<int>::iterator inputIt;
		
		vector<int> inputs = basicCellIterator->getInput();//something's wrong with iterator
		for(int i = 0; i< inputs.size(); i++){
			cout << "\t Input: " << inputs[i] << endl;
		}
	}
	cout << endl << endl;
	

}

int main(int argc, char** argv){
	char* library;
	char* inputBench;

	vector<cell> cellLibrary;
	benchCell bench;


    if ( (argc < 2) || (strcmp(argv[1],"-h") == 0) ) { 
          cerr << "usage: ./output [cell library] [input set] " << endl;
          exit(1);
    } 

    library = argv[1];
    inputBench = argv[2];


	cellLibrary = libParser(library);
	bench = benchParser(inputBench);

	libPrinter(cellLibrary);
	benchPrinter(bench);

}
