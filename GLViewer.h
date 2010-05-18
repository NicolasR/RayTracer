// *********************************************************
// OpenGL Viewer Class, based on LibQGLViewer, compatible
// with most hardware (OpenGL 1.2).
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#ifndef GLVIEWER_H
#define GLVIEWER_H

#include <QGLViewer/qglviewer.h>
#include <vector>
#include <string>

#include "Scene.h"

class GLViewer : public QGLViewer  {
    Q_OBJECT
public:
    
    typedef enum {Flat=0, Smooth=1} RenderingMode;
    typedef enum {Inter=0, Phong=1, Ombre1=2, Ombre2=3} Render;
    GLViewer ();
    virtual ~GLViewer ();
    
    inline bool isWireframe () const { return wireframe; }
    inline int getRenderingMode () const { return renderingMode; }
    
    class Exception  {
    public:
        Exception (const std::string & msg) : message ("[GLViewer]"+msg) {}
        virtual ~Exception () {}
        const std::string & getMessage () const { return message; }
    private:
        std::string message;
    }; 
     
public slots :
    void setWireframe (bool b);
    void setRenderingMode (int m);
    void setRender(int n);
    void setHD(bool c){ HD = c;}
    bool getHD(){ return HD;}
    void setUseBackground(bool c){ useBackground = c;}
    bool getUseBackground(){ return useBackground;}
    void setScene(int c){ scene = c;}
    bool getScene(){ return scene;}
    int getRender();
    
protected :
    void init();
    void draw ();
    QString helpString() const;

    virtual void keyPressEvent ( QKeyEvent * event );
    virtual void keyReleaseEvent ( QKeyEvent * event );

private:
    bool wireframe;
    RenderingMode renderingMode;
    Render render;
    bool HD;
    bool useBackground;
    int scene;
};

#endif // GLVIEWER_H

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End:
