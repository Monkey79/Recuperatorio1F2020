/*
 * LocationRepo.c
 *  Created on: 8 jun. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LocationRepo.h"

void locRep_initializeAllLocation(Location locations[], int locTOp){
	for(int i=0;i<locTOp;i++){
		locations[i].locId = 0;
		locations[i].empty = TRUE;
	}
}


