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
bool Ray::intersect_real (Mesh mesh, Triangle triangle, Vec3Df & intersectionPoint) const {
	Vec3Df RayOrigin = this->getOrigin();
	Vec3Df RayDirection = this->getDirection();
	Vec3Df A = mesh.getVertices().at(triangle.getVertex(0)).getPos();
	Vec3Df B = mesh.getVertices().at(triangle.getVertex(1)).getPos();
	Vec3Df C = mesh.getVertices().at(triangle.getVertex(2)).getPos();
	Vec3Df AB = Vec3Df::segment(A,B);
	Vec3Df AC = Vec3Df::segment(A,C);

	//Calcul du produit vectoriel AB,AC pour obtenir la normale du plan
	Vec3Df normale = Vec3Df::crossProduct(AB,AC);

	//On résout un système à une équation pour trouver le point d'intersection entre le rayon et le plan que l'on appelera M
	int d = -(normale[0]*A[0] + normale[1]*A[1]+normale[2]*A[2]);
	int k = (-normale[0] * RayOrigin[0] - normale[1] * RayOrigin[1] - normale[2] * RayOrigin[2] - d)/
		(normale[0] * RayDirection[0] + normale[1] * RayDirection[1] + normale[2] * RayDirection[2]);

	int Mx = k * RayDirection[0] + RayOrigin[0];
	int My = k * RayDirection[1] + RayOrigin[1];
	int Mz = k * RayDirection[2] + RayDirection[2];
	//std::cout<<"Mx: "<<Mx<<" My: "<<My<<" Mz:"<<Mz<<"\n";
	Vec3Df M = Vec3Df(Mx, My, Mz);

	//On cherche si M appartient au Triangle, on résout le système
	int l = AC[2] * (AC[1] - M[1]) / ( AC[2] * AB[1] + AC[1] * (-AB[2] + M[2] - A[2]));
	int q = - (l * AB[2] + A[2] - M[2])/AC[2];
	if (l>0 && q>0)
	{
	  intersectionPoint = M;
	  return true;
	}
	else
	{
	  return false;
	}
}

