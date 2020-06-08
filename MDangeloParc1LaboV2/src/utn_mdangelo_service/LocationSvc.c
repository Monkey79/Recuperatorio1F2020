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

void locSvc_getValidLocationId(Location locations[], int locationTop, int *pLocId){
	do{
		locSvc_showAllLocations(locations, locationTop);
		printf("--Ingrese id de localidad valido--[1-2-3]--\n");
		__fpurge(stdin);
		scanf("%d",pLocId);
	}while(*pLocId!=1 && *pLocId!=2 && *pLocId!=3);
}

void locSvc_showAllLocations(Location locations[], int locationTop){
	printf("Localidad_Id\t");
	printf("Estate (Provincia)\t");
	printf("Cod_Post\t");
	printf("Description\n");
	for(int i=0;i<locationTop;i++){
		printf("%10d %15s %18d %15s\n",locations[i].locId,locations[i].locEstate,locations[i].locPostCode,locations[i].locDescrp);
	}
}
