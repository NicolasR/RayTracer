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
    const BoundingBox & bbox = scene->getBoundingBox ();
    const Vec3Df & minBb = bbox.getMin ();
    const Vec3Df & maxBb = bbox.getMax ();
    const Vec3Df rangeBb = maxBb-minBb;
    Vec3Df c (backgroundColor);

    for (unsigned int i = 0; i < screenWidth; i++)
    {

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
	          float Px, Py, Pz; Vec3Df test;
    	      float tmin=777, t, alpha=0., beta=0., gamma=0.;
    	      bool found = false;

	          for (std::vector<Object>::iterator k = objects.begin(); k!= objects.end();k++)
	          {
		            const Mesh & mesh = (*k).getMesh();
		            std::vector<Triangle> triangles = mesh.getTriangles();
		            std::vector<Vertex> vertices = mesh.getVertices();
		            for (std::vector<Triangle>::iterator l = triangles.begin(); l != triangles.end(); l++)
		            {

            	     //bool hasIntersection = ray.intersect (bbox, intersectionPoint);
		                const Vec3Df & A = mesh.getVertices().at((*l).getVertex(0)).getPos();
		                const Vec3Df & B = mesh.getVertices().at((*l).getVertex(1)).getPos();
		                const Vec3Df & C = mesh.getVertices().at((*l).getVertex(2)).getPos();
	    	            bool hasIntersection = ray.intersect_real (A,B,C,intersectionPoint,t,alpha,beta,gamma);
            	      if (hasIntersection && t <tmin)
		                {
			                  tmin = t;		
			                  test = intersectionPoint;
			                  found = true;	
		                }
            	     
		            }
            }
	          if (found)
	          {
	              Px = camPos[0] + tmin * dir[0];
	              Py = camPos[1] + tmin * dir[1];
	              Pz = camPos[2] + tmin * dir[2];

                c = 255.f * ((Vec3Df(Px, Py, Pz) - minBb) / rangeBb);
	              image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp (c[0], 0, 255),
                                                       	       clamp (c[1], 0, 255),
                                                       	       clamp (c[2], 0, 255)));
	              found = false;
	          }
        }
	  }
    return image;
}


QImage RayTracer::render2 (const Vec3Df & camPos,
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
    const BoundingBox & bbox = scene->getBoundingBox ();
    const Vec3Df & minBb = bbox.getMin ();
    const Vec3Df & maxBb = bbox.getMax ();
    const Vec3Df rangeBb = maxBb-minBb;
    Vec3Df c (backgroundColor);

    for (unsigned int i = 0; i < screenWidth; i++)
    {

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
	          Vec3Df intersectionPointMin;
    	      float tmin=777, t=778, alpha=0., beta=0., gamma=0.;
    	      Vec3Df Na;
            Vec3Df Nb;
            Vec3Df Nc;
    	      bool found = false;
            Object obj;
	          for (std::vector<Object>::iterator k = objects.begin(); k!= objects.end();k++)
	          {

		            const Mesh & mesh = (*k).getMesh();
		            std::vector<Triangle> triangles = mesh.getTriangles();
		            std::vector<Vertex> vertices = mesh.getVertices();
		            for (std::vector<Triangle>::iterator l = triangles.begin(); l != triangles.end(); l++)
		            {

		                const Vec3Df & A = mesh.getVertices().at((*l).getVertex(0)).getPos();
		                const Vec3Df & B = mesh.getVertices().at((*l).getVertex(1)).getPos();
		                const Vec3Df & C = mesh.getVertices().at((*l).getVertex(2)).getPos();
	    	            bool hasIntersection = ray.intersect_real (A,B,C,intersectionPoint,t,alpha,beta,gamma);
            	      if (hasIntersection && t <tmin)
		                {
			                  tmin = t;		
			                  intersectionPointMin = intersectionPoint;
			                  obj = (*k);
			                  Na = mesh.getVertices().at((*l).getVertex(0)).getNormal();
                        Nb = mesh.getVertices().at((*l).getVertex(1)).getNormal();
                        Nc = mesh.getVertices().at((*l).getVertex(2)).getNormal();
			                  found = true;	
		                }
            	     
		            }
            }
	          if (!found)
	              c = backgroundColor;
	          else
	          {
	              std::vector<Light> lights = scene->getLights();
                int nb = 0;
                float kd = obj.getMaterial().getDiffuse();
                float ks = obj.getMaterial().getSpecular();
                c = obj.getMaterial().getColor();
                Vec3Df normale = alpha * Na + beta * Nb + gamma * Nc;
                normale.normalize();
                for (std::vector<Light>::iterator m = lights.begin(); m != lights.end(); m++)
                {
                    Vec3Df posL, colorL, Li, R, S;
                    float I = 0;
                    float iL = 0;
                    float Id = 0, Is = 0;  
                    posL = (*m).getPos();
                    colorL = (*m).getColor();
                    iL = (*m).getIntensity();
                    Li = posL-intersectionPointMin;
                    Li.normalize();
                    Id = kd * Vec3Df::dotProduct(normale, Li) * iL;
                    R = Li - 2*(Vec3Df::dotProduct(Li,normale))*normale;
                    R.normalize();
                    S = camPos - intersectionPointMin;
                    S.normalize();
                    Is = ks * pow(Vec3Df::dotProduct(S, R), 20) * iL;
                  
                    if(Id>0){
                      I += Id + Is ;                                  
                      nb++;
                    }
                    c = c*colorL*I;
                }
                c = c/nb;
                
	              image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp(c[0]*255,0,255), clamp(c[1]*255,0,255), clamp(c[2]*255,0,255)));
	              found = false;
	          }
        }
	  }
    return image;
}
