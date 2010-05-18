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

// Trouve l'intersection la plus proche
QImage RayTracer::render (const Vec3Df & camPos,
                          const Vec3Df & direction,
                          const Vec3Df & upVector,
                          const Vec3Df & rightVector,
                          float fieldOfView,
                          float aspectRatio,
                          unsigned int screenWidth,
                          unsigned int screenHeight,
                          GLViewer& viewer) {
    QImage image (QSize (screenWidth, screenHeight), QImage::Format_RGB888);
    
    bool HD = viewer.getHD();
    bool useBackGround = viewer.getUseBackground();
    bool useScene = viewer.getScene();
    Scene * scene = Scene::getInstance (HD, useBackGround, useScene);
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

            	      //Vérification de l'intersection
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
	              //On a trouvé une intersection, on calcule les coordonnées du point
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

//BRDF de Phong
QImage RayTracer::render2 (const Vec3Df & camPos,
                          const Vec3Df & direction,
                          const Vec3Df & upVector,
                          const Vec3Df & rightVector,
                          float fieldOfView,
                          float aspectRatio,
                          unsigned int screenWidth,
                          unsigned int screenHeight,
                          GLViewer& viewer) {
    QImage image (QSize (screenWidth, screenHeight), QImage::Format_RGB888);
    
    bool HD = viewer.getHD();
    bool useBackGround = viewer.getUseBackground();
    bool useScene = viewer.getScene();
    Scene * scene = Scene::getInstance (HD, useBackGround, useScene);
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
            float alphaOK = 0.0, betaOK = 0.0, gammaOK = 0.0;
    	      bool found = false;
            Object obj;
	          for (std::vector<Object>::iterator k = objects.begin(); k!= objects.end();k++)
	          {

		            const Mesh & mesh = (*k).getMesh();
		            std::vector<Triangle> triangles = mesh.getTriangles();
		            std::vector<Vertex> vertices = mesh.getVertices();
		            for (std::vector<Triangle>::iterator l = triangles.begin(); l != triangles.end(); l++)
		            {
                    //On cherche également l'intersection mais on stocke aussi les normales des sommets et les coordonnées barycentriques
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
			                  
			                  alphaOK = alpha;
			                  betaOK = beta;
			                  gammaOK = gamma;
			                  found = true;
		                }
            	     
		            }
            }
	          if (found)
	          {
	              //On a trouvé une intersection, on calcule donc la couleur de l'objet en fonction de la lumière (BRDF)
	              std::vector<Light> lights = scene->getLights();
                int nb = 0;
                float kd = obj.getMaterial().getDiffuse();
                float ks = obj.getMaterial().getSpecular();
                c = Vec3Df(0,0,0);
                Vec3Df normale = alphaOK * Na + betaOK * Nb + gammaOK * Nc;
                normale.normalize();
                for (std::vector<Light>::iterator m = lights.begin(); m != lights.end(); m++)
                {
                    Vec3Df posL, colorL, Li, R, S;
                    float I = 0.0;
                    float iL = 0.0;
                    float Is = 0.0;
                    float Id = 0.0;  
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
                    c += obj.getMaterial().getColor()*colorL*I;   
                }
                c = c/nb;
                
	              image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp(c[0]*255,0,255), clamp(c[1]*255,0,255), clamp(c[2]*255,0,255)));
	              found = false;
	          }
	          else
	            c = backgroundColor;
        }
	  }
    return image;
}

bool egale3DFloat(Vec3Df a, Vec3Df b){
    return (a[0]-b[0])*(a[0]-b[0])<= 0.01
           || (a[1]-b[1])*(a[1]-b[1])<= 0.01
           || (a[2]-b[2])*(a[2]-b[2])<= 0.01 ;
}

//Ombres Dures (question 2.a)
QImage RayTracer::render3 (const Vec3Df & camPos,
                          const Vec3Df & direction,
                          const Vec3Df & upVector,
                          const Vec3Df & rightVector,
                          float fieldOfView,
                          float aspectRatio,
                          unsigned int screenWidth,
                          unsigned int screenHeight,
                          GLViewer& viewer) {
    QImage image (QSize (screenWidth, screenHeight), QImage::Format_RGB888);
    
    bool HD = viewer.getHD();
    bool useBackGround = viewer.getUseBackground();
    bool useScene = viewer.getScene();
    Scene * scene = Scene::getInstance (HD, useBackGround, useScene);
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
            float alphaOK = 0.0, betaOK = 0.0, gammaOK = 0.0;
            Vec3Df AOK, BOK, COK;
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
			                  
			                  alphaOK = alpha;
			                  betaOK = beta;
			                  gammaOK = gamma;
			                  AOK = A;
			                  BOK = B;
			                  COK = C;
			                  found = true;
		                }
            	     
		            }
            }
	          if (found)
	          {
	             
	              std::vector<Light> lights = scene->getLights();
                int nb = 0;
                float kd = obj.getMaterial().getDiffuse();
                float ks = obj.getMaterial().getSpecular();
                c = Vec3Df(0,0,0);
                Vec3Df normale = alphaOK * Na + betaOK * Nb + gammaOK * Nc;
                normale.normalize();
                for (std::vector<Light>::iterator m = lights.begin(); m != lights.end(); m++)
                {
                    Vec3Df posL, colorL, Li, R, S;
                    float I = 0.0;
                    float iL = 0.0;
                    float Is = 0.0;
                    float Id = 0.0;  
                    posL = (*m).getPos();
                    colorL = (*m).getColor();
                    iL = (*m).getIntensity();
                    Li = posL-intersectionPointMin;
                    Li.normalize();
                                        
                    bool ombre = false;
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
		                        
                            Ray ray2 (posL, Li);
                            Vec3Df IpMinL = intersectionPointMin - posL; //Distance entre l'intersection et la lumière
                            ray2.intersect_real (A,B,C,intersectionPoint,t,alpha,beta,gamma);
                            Vec3Df IpL = IpMinL - (intersectionPoint-posL);
            	              if (!egale3DFloat(intersectionPoint, intersectionPointMin) && (IpL[0] < 0.0 && IpL[1] < 0.0 && IpL[2] < 0.0))
		                          ombre = true;
                         }
                     }
                     if (ombre)
		                 {
		                            
		                     c += Vec3Df(0,0,0);
		                     nb++;
		                     ombre = false; 
		                 }
		                 else
		                 {
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
                         c += obj.getMaterial().getColor()*colorL*I; 
                     }
                }
                c = c/nb;
                
	              image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp(c[0]*255,0,255), clamp(c[1]*255,0,255), clamp(c[2]*255,0,255)));
	              found = false;
	          }
	          else
	            c = backgroundColor;
        }
	  }
    return image;
}

//Ombres Douces (question 2.b)
QImage RayTracer::render4 (const Vec3Df & camPos,
                          const Vec3Df & direction,
                          const Vec3Df & upVector,
                          const Vec3Df & rightVector,
                          float fieldOfView,
                          float aspectRatio,
                          unsigned int screenWidth,
                          unsigned int screenHeight,
                          GLViewer& viewer) {
    QImage image (QSize (screenWidth, screenHeight), QImage::Format_RGB888);
    
    bool HD = viewer.getHD();
    bool useBackGround = viewer.getUseBackground();
    bool useScene = viewer.getScene();
    Scene * scene = Scene::getInstance (HD, useBackGround, useScene);
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
            float alphaOK = 0.0, betaOK = 0.0, gammaOK = 0.0;
            Vec3Df AOK, BOK, COK;
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
			                  
			                  alphaOK = alpha;
			                  betaOK = beta;
			                  gammaOK = gamma;
			                  AOK = A;
			                  BOK = B;
			                  COK = C;
			                  found = true;
		                }
            	     
		            }
            }
	          if (found)
	          {
	             
	              std::vector<Light> lights = scene->getLights();
                int nb = 0;
                float kd = obj.getMaterial().getDiffuse();
                float ks = obj.getMaterial().getSpecular();
                c = Vec3Df(0,0,0);
                Vec3Df normale = alphaOK * Na + betaOK * Nb + gammaOK * Nc;
                normale.normalize();
                for (std::vector<Light>::iterator m = lights.begin(); m != lights.end(); m++)
                {
                    Vec3Df posL, colorL, Li, R, S;
                    float I = 0.0;
                    float iL = 0.0;
                    float Is = 0.0;
                    float Id = 0.0;  
                    posL = (*m).getPos();
                    colorL = (*m).getColor();
                    iL = (*m).getIntensity();
                    Li = posL-intersectionPointMin;
                    
                    bool ombre = false;
                    
                    //Remplissage du tableau de rayons
                    Ray raytab[13];
                    Vec3Df lighttab[13];
                    for(float i=posL[0]-1.5;i<4.5;i+=0.5){
                        int j=0;
                        Vec3Df posLtemp = Vec3Df(i,posL[1],posL[2]);
                        Ray raytemp(posLtemp, Li);
                        raytab[j] = raytemp;
                        lighttab[j] = posLtemp;
                        j++;
                    }
                    for(float i=posL[1]-1.5;i!=3 && i<4.5;i+=0.5){
                        int j=7;
                        Vec3Df posLtemp = Vec3Df(posL[0],i,posL[2]);
                        Ray raytemp(posLtemp, Li);
                        raytab[j] = raytemp;
                        lighttab[j] = posLtemp;
                        j++;
                    }
                    
                    float fact = 0.0;
                    float nbfact = 0.0;
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
		                        
                            for(int i=0;i<13;i++){
                                Vec3Df IpMinL = intersectionPointMin - lighttab[i]; //Distance entre l'intersection et la lumière
                                raytab[i].intersect_real (A,B,C,intersectionPoint,t,alpha,beta,gamma);
                                Vec3Df IpL = IpMinL - (intersectionPoint-lighttab[i]);
            	                  if (!egale3DFloat(intersectionPoint, intersectionPointMin) && (IpL[0] < 0.0 && IpL[1] < 0.0 && IpL[2] < 0.0))
		                                fact += 1.0/13.0;
                            }
                            nbfact++;
                            
                         }
                     }
                     if (fact > 0.0)
		                 {   float temp = fact/nbfact;
		                     c += Vec3Df(temp,temp,temp)+Vec3Df(0,0,0);
		                     nb++;
		                     ombre = false; 
		                 }
		                 else
		                 {
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
                         c += obj.getMaterial().getColor()*colorL*I/**(fact/nbfact)*/; 
                     }
                }
                c = c/nb;
                
	              image.setPixel (i, ((screenHeight-1)-j), qRgb (clamp(c[0]*255,0,255), clamp(c[1]*255,0,255), clamp(c[2]*255,0,255)));
	              found = false;
	          }
	          else
	            c = backgroundColor;
        }
	  }
    return image;
}
