/*
 * LocationSvc.c
 *  Created on: 8 jun. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "../utn_mdangelo_repo/LocationRepo.h"
#include "LocationSvc.h"

void locSvc_initializeAllLocation(Location locations[], int locationTop){
	locRep_initializeAllLocation(locations, locationTop);
}

void locSvc_getLocationInfoById(Location locations[], int locationTop, int locationId, char locEsate[50], int *locCodPost){
	for(int i=0;i<locationTop;i++){
		if(!locations[i].empty && locations[i].locId==locationId){
			strcpy(locEsate,locations[i].locEstate);
			*locCodPost = locations[i].locPostCode;
		}
	}
}

void locSvc_getValidLocationId(Location locations[], int locationTop){

}
