#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define sMAX_LINE 3000


int main(int argc, char *argv[]) {

	FILE *fpin, *fpout;
	char line[sMAX_LINE];
	int c,bytecount = 0;
	int val;


    if ( argc != 3 ) /* argc should be 3 for correct execution */
    {
        printf( "Usage: %s <input hex file> <output bin file>", argv[0] );
		return 0;
    }


	fpin = fopen(argv[1],"r");
	if (!fpin) {
		printf( "Bad or invalid input file : ", argv[1] );
	}
	
	fpout = fopen(argv[2],"wb");

	memset(line,0,sMAX_LINE);
 	while(fgets(line, sMAX_LINE, fpin) != NULL)
   	{

	  
	// Find data of form XX, where XX is ASCII hex byte
	  while ( line[c+2] == ',')
      {
		  sscanf(line+c,"%x", &val);
		  c+=3;
	  	  fputc(val,fpout);
	  	  bytecount++;
	  }
	  c = 0;
		memset(line,0,sMAX_LINE);
   	}

	printf("Success! Output binary file to %s converted %ld bytes",argv[2],bytecount);

	fclose(fpin);
	fclose(fpout);





}

