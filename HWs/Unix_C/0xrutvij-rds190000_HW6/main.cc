/* Filename:  main.cc
 * Date:      04/28/2020
 * Author:    Rutvij Shah
 * Email:     rutvij.shah@utdallas.edu
 * Course:    CS3377.502 Spring 2020
 * Version:   1.0
 * Copyright: 2020, All Rights Reserved
 *
 * Description:
 *     Driver code and matrix display code for Assignment 6
 */


#include "header.h"
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  ifstream binFile("/scratch/perkins/cs3377.bin", ios::in|ios::binary);

  BinaryFileHeader* header = readHeader(binFile);

  BinaryFileRecord* record = NULL;

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH,  MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', COL, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  char hexBuff[MAX_RECORD_STR_LENGTH+1];
  sprintf(hexBuff, "Magic: 0x%X", (int)header->magicNumber);

  setCDKMatrixCell(myMatrix, 1, 1, (const char*) hexBuff);

  sprintf(hexBuff, "Version: %u", header->versionNumber);

  setCDKMatrixCell(myMatrix, 1, 2, (const char*) hexBuff);  

  sprintf(hexBuff, "NumRecords: %lu", header->numRecords);
  
  setCDKMatrixCell(myMatrix, 1, 3, (const char*) hexBuff);  

  long numRec = header->numRecords;

  int i = 0;

  while(numRec > i && i < MATRIX_HEIGHT){
    record = readRecord(binFile);
    sprintf(hexBuff, "strlen: %hu", record->strLength);
  	setCDKMatrixCell (myMatrix, i+2, 1, (const char*) hexBuff);
  	sprintf(hexBuff, "%s", (record->stringBuffer));
  	setCDKMatrixCell (myMatrix, i+2, 2, (const char*) hexBuff);
  	i++;
  }
  
  //setCDKMatrixCell(myMatrix, 2, 2, "Test Message");

  drawCDKMatrix(myMatrix, true);    /* required  */


  /* so we can see results */
  //cin.ignore();
  cin.get();
  //int activateCDKMatrix (myMatrix, "\n");


  // Cleanup screen
  endCDK();

  binFile.close();
}
