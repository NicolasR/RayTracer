// *********************************************************
// Scene Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#include "Scene.h"

using namespace std;

static Scene * instance = NULL;

Scene * Scene::getInstance (bool HD, bool useBackGround, int scene) {
    if (instance == NULL)
        instance = new Scene (HD, useBackGround, scene);
    return instance;
}

void Scene::destroyInstance () {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

Scene::Scene (bool HD, bool useBackGround, int scene) {
    buildDefaultScene (HD,useBackGround,scene);
    updateBoundingBox ();
}

Scene::~Scene () {
}

void Scene::updateBoundingBox () {
    if (objects.empty ())
        bbox = BoundingBox ();
    else {
        bbox = objects[0].getBoundingBox ();
        for (unsigned int i = 1; i < objects.size (); i++)
            bbox.extendTo (objects[i].getBoundingBox ());
    }
}

// Changer ce code pour créer des scènes originales
void Scene::buildDefaultScene (bool HD, bool useBackGround, int scene) {
    Mesh groundMesh;
    if (useBackGround)
    {
      if (HD)
        groundMesh.loadOFF ("models/ground_HD.off");
      else
        groundMesh.loadOFF ("models/ground.off");
    }
    Material groundMat;
    Object ground (groundMesh, groundMat);    
    objects.push_back (ground);
    Mesh ramMesh;
    
    switch(scene){
      case 1:
        if (HD)
          ramMesh.loadOFF ("models/ram_HD.off");
        else
          ramMesh.loadOFF ("models/ram.off");
        break;
      case 2:
        ramMesh.loadOFF ("models/sphere.off");
        break;
      default:
        ramMesh.loadOFF ("models/sphere.off");
    }
    Material ramMat (1.f, 1.f, Vec3Df (1.f, .6f, .2f));
    Object ram (ramMesh, ramMat);    
    objects.push_back (ram);
    Light l (Vec3Df (3.0f, 3.0f, 3.0f), Vec3Df (1.0f, 1.0f, 1.0f), 1.0f);
    lights.push_back (l);
}
