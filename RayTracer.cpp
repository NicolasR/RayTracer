// *********************************************************
// Ray Tracer Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#include "RayTracer.h"
#include "Ray.h"
#include "Scene.h"

static RayTracer * instance = NULL;

RayTracer * RayTracer::getInstance () {
    if (instance == NULL)
        instance = new RayTracer ();
    return instance;
}

void RayTracer::destroyInstance () {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

inline int clamp (float f, int inf, int sup) {
    int v = static_cast<int> (f);
    return (v < inf ? inf : (v > sup ? sup : v));
}

// POINT D'ENTREE DU PROJET.
// Le code suivant ray trace uniquement la boite englobante de la scene.
// Il faut remplacer ce code par une veritable raytracer
QImage RayTracer::render (const Vec3Df & camPos,
                          const Vec3Df & direction,
                          const Vec3Df & upVector,
                          const Vec3Df & rightVector,
                          float fieldOfView,
                          float aspectRatio,
                          unsigned int screenWidth,
                          unsigned int screenHeight) {
    QImage image (QSize (screenWidth, screenHeight), QImage::Format_RGB888);
    
    Scene * scene = Scene::getInstance ();
    std::vector<Object> objects = scene->getObjects();
    //const BoundingBox & bbox = scene->getBoundingBox ();

    
    for (unsigned int i = 0; i < screenWidth; i++)
        for (unsigned int j = 0; j < screenHeight; j++) {
	    float tanX = tan (fieldOfView);
            float tanY = tanX/aspectRatio;
            Vec3Df stepX = (float (i) - screenWidth/2.f)/screenWidth * tanX * rightVector;
            Vec3Df stepY = (float (j) - screenHeight/2.f)/screenHeight * tanY * upVector;
            Vec3Df step = stepX + stepY;
            Vec3Df dir = direction + step;
            dir.normalize ();
            Ray ray (camPos, dir);
            Vec3Df intersectionPoint;
	    
	    for (std::vector<Object>::iterator k = objects.begin(); k!= objects.end();k++)
	    {
		Mesh mesh = (*k).getMesh();
		std::vector<Triangle> triangles = mesh.getTriangles();
		std::vector<Vertex> vertices = mesh.getVertices();
		const BoundingBox & bbox = (*k).getBoundingBox ();
    		const Vec3Df & minBb = bbox.getMin ();
    		const Vec3Df & maxBb = bbox.getMax ();
    		const Vec3Df rangeBb = maxBb-minBb;
		for (std::vector<Triangle>::iterator l = triangles.begin(); l != triangles.end(); l++)
		{
		     
            	     //bool hasIntersection = ray.intersect (bbox, intersectionPoint);
	    	     bool hasIntersection = ray.intersect_real (mesh, *l,intersectionPoint);
            	     Vec3Df c (backgroundColor);
            	     if (hasIntersection)
                	     c = 255.f * ((intersectionPoint - minBb) / rangeBb);
            	     image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp (c[0], 0, 255),
                                                       		    clamp (c[1], 0, 255),
                                                       		    clamp (c[2], 0, 255)));
		}
		std::cout<<"Fin iteration Triangles\n";
            }
	}
    return image;
}
