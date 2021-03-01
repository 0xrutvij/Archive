/* Filename:  header.h
 * Date:      04/28/2020
 * Author:    Rutvij Shah
 * Email:     rutvij.shah@utdallas.edu
 * Course:    CS3377.502 Spring 2020
 * Version:   1.0
 * Copyright: 2020, All Rights Reserved
 *
 * Description:
 *     Class definitions and Macros for Assignment 6
 */
 
#ifndef HEADER_H
#define HEADER_H


#define MAX_RECORD_STR_LENGTH 25

#include <iostream>
#include <iomanip>
#include <fstream>
#include "cdk.h"
#include <stdint.h>
using namespace std;

class BinaryFileHeader
{
	public:
		uint32_t magicNumber;
		uint32_t versionNumber;
		uint64_t numRecords;
};


class BinaryFileRecord
{
	public:
		uint8_t strLength;
		char stringBuffer[MAX_RECORD_STR_LENGTH];
};

BinaryFileHeader* readHeader(ifstream&);

BinaryFileRecord* readRecord(ifstream&);



#endif