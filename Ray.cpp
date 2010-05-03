// *********************************************************
// Ray Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#include "Ray.h"

using namespace std;

static const unsigned int NUMDIM = 3, RIGHT = 0, LEFT = 1, MIDDLE = 2;

bool Ray::intersect (const BoundingBox & bbox, Vec3Df & intersectionPoint) const {
    const Vec3Df & minBb = bbox.getMin ();
    const Vec3Df & maxBb = bbox.getMax ();
    bool inside = true;
    unsigned int  quadrant[NUMDIM];
    register unsigned int i;
    unsigned int whichPlane;
    Vec3Df maxT;
    Vec3Df candidatePlane;
    
    for (i=0; i<NUMDIM; i++)
        if (origin[i] < minBb[i]) {
            quadrant[i] = LEFT;
            candidatePlane[i] = minBb[i];
            inside = false;
        } else if (origin[i] > maxBb[i]) {
            quadrant[i] = RIGHT;
            candidatePlane[i] = maxBb[i];
            inside = false;
        } else	{
            quadrant[i] = MIDDLE;
        }

    if (inside)	{
        intersectionPoint = origin;
        return (true);
    }

    for (i = 0; i < NUMDIM; i++)
        if (quadrant[i] != MIDDLE && direction[i] !=0.)
            maxT[i] = (candidatePlane[i]-origin[i]) / direction[i];
        else
            maxT[i] = -1.;

    whichPlane = 0;
    for (i = 1; i < NUMDIM; i++)
        if (maxT[whichPlane] < maxT[i])
            whichPlane = i;

    if (maxT[whichPlane] < 0.) return (false);
    for (i = 0; i < NUMDIM; i++)
        if (whichPlane != i) {
            intersectionPoint[i] = origin[i] + maxT[whichPlane] *direction[i];
            if (intersectionPoint[i] < minBb[i] || intersectionPoint[i] > maxBb[i])
                return (false);
        } else {
            intersectionPoint[i] = candidatePlane[i];
        }
    return (true);			
}
bool Ray::intersect_real (Vec3Df A, Vec3Df B, Vec3Df C, Vec3Df & intersectionPoint, float & t) const {
	Vec3Df Ro = this->getOrigin();
	Vec3Df Rd = this->getDirection();

	float beta = 0.0;
	float gamma = 0.0;
	t = calcBar(A,B,C,beta,gamma);
	float alpha = 1 - beta - gamma;
	if (beta + gamma < 1 && beta > 0 && gamma > 0)
	{
	  float Px = Ro[0] + t * Rd[0];
	  float Py = Ro[1] + t * Rd[1];
	  float Pz = Ro[2] + t * Rd[2];
	  //std::cout<<"beta: "<<beta<<" gamma: "<<gamma<<"\n";
//	  std::cout<<"t: "<<t<<"\n";
//std::cout<<"Px: "<<Px<<" Py: "<<Py<<" Pz:"<<Pz<<"\n";
	  intersectionPoint = Vec3Df(Px, Py, Pz);
	  return true;
	}	
	else
	  return false;
}

float Ray::calcBar(Vec3Df A, Vec3Df B, Vec3Df C, float & beta, float & gamma) const{
	Vec3Df Ro = this->getOrigin();
	Vec3Df Rd = this->getDirection();
	Vec3Df AB = Vec3Df::segment(B,A);
	Vec3Df AC = Vec3Df::segment(C,A);
	Vec3Df ARo = Vec3Df::segment(Ro,A);

	float dA = (AB[0] * (AC[1] * Rd[2] - Rd[1] * AC[2]))
		 - (AB[1] * (AC[0] * Rd[2] - Rd[0] * AC[2]))
		 + (AB[2] * (AC[0] * Rd[1] - Rd[0] * AC[1]));

	beta = (
	          (ARo[0] * (AC[1] * Rd[2] - Rd[1] * AC[2]))
		- (ARo[1] * (AC[0] * Rd[2] - Rd[0] * AC[2]))
		+ (ARo[2] * (AC[0] * Rd[1] - Rd[0] * AC[1]))
	       )/dA;
	
	gamma = ( 
		  (AB[0] * (ARo[1] * Rd[2] - Rd[1] * ARo[2]))
		- (AB[1] * (ARo[0] * Rd[2] - Rd[0] * ARo[2]))
		+ (AB[2] * (ARo[0] * Rd[1] - Rd[0] * ARo[1]))
		)/dA;

	float t = (
		    (AB[0] * (AC[1] * ARo[2] - ARo[1] * AC[2]))
		  - (AB[1] * (AC[0] * ARo[2] - ARo[0] * AC[2]))
		  + (AB[2] * (AC[0] * ARo[1] - ARo[0] * AC[1]))
		  )/dA;

	return t;
}
