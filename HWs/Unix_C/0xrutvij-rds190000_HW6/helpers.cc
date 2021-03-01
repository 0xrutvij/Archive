/* Filename:  helpers.cc
 * Date:      04/28/2020
 * Author:    Rutvij Shah
 * Email:     rutvij.shah@utdallas.edu
 * Course:    CS3377.502 Spring 2020
 * Version:   1.0
 * Copyright: 2020, All Rights Reserved
 *
 * Description:
 *     Helper function definitions for Binary File I/O adapted to classes 
 *		defined in the header.		
 */
 
#include "header.h"

BinaryFileHeader* readHeader(ifstream& binFile){

	BinaryFileHeader *myHeader = new BinaryFileHeader();

	if(binFile.is_open()){
		binFile.read((char*) myHeader, sizeof(BinaryFileHeader));
	}

	return myHeader;
}

BinaryFileRecord* readRecord(ifstream& binFile){

	BinaryFileRecord *myRecord = new BinaryFileRecord();

	if(binFile.is_open()){
		binFile.read((char*) myRecord, sizeof(BinaryFileRecord));
	}

	return myRecord;
}