/*
 * LocationSvc.h
 *  Created on: 8 jun. 2020
 *  Author: mdangelo
 */


#ifndef UTN_MDANGELO_SERVICE_LOCATIONSVC_H_
#define UTN_MDANGELO_SERVICE_LOCATIONSVC_H_

#include "../utn_mdangelo_entities/MainEntities.h"

void locSvc_initializeAllLocation(Location locations[], int locationTop);
void locSvc_getLocationInfoById(Location locations[], int locationTop, int locationId, char locEsate[50], int *locCodPost);
void locSvc_getValidLocationId(Location locations[], int locationTop, int *pLocId);
void locSvc_showAllLocations(Location locations[], int locationTop);

#endif /* UTN_MDANGELO_SERVICE_LOCATIONSVC_H_ */
