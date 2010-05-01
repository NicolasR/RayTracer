#############################################################################
# Makefile for building: raymini
# Generated by qmake (2.01a) (Qt 4.4.3) on: ven. avr. 30 23:43:10 2010
# Project:  raymini.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile raymini.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -O3 -mfpmath=sse -msse2 -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -O3 -mfpmath=sse -msse2 -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I/usr/include -I/usr/X11R6/include -I.moc -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/X11R6/lib -L/usr/lib -L/usr/lib -lQGLViewer -lpthread -lGLU -lGL -lQtXml -lQtOpenGL -lQtGui -lQtCore
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = Window.cpp \
		GLViewer.cpp \
		QTUtils.cpp \
		Vertex.cpp \
		Triangle.cpp \
		Mesh.cpp \
		BoundingBox.cpp \
		Material.cpp \
		Object.cpp \
		Light.cpp \
		Scene.cpp \
		RayTracer.cpp \
		Ray.cpp \
		Main.cpp .moc/moc_Window.cpp \
		.moc/moc_GLViewer.cpp \
		.moc/moc_QTUtils.cpp
OBJECTS       = .obj/Window.o \
		.obj/GLViewer.o \
		.obj/QTUtils.o \
		.obj/Vertex.o \
		.obj/Triangle.o \
		.obj/Mesh.o \
		.obj/BoundingBox.o \
		.obj/Material.o \
		.obj/Object.o \
		.obj/Light.o \
		.obj/Scene.o \
		.obj/RayTracer.o \
		.obj/Ray.o \
		.obj/Main.o \
		.obj/moc_Window.o \
		.obj/moc_GLViewer.o \
		.obj/moc_QTUtils.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		raymini.pro
QMAKE_TARGET  = raymini
DESTDIR       = 
TARGET        = raymini

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: raymini.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQGLViewer.prl \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtOpenGL.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile raymini.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQGLViewer.prl:
/usr/lib/libQtXml.prl:
/usr/lib/libQtOpenGL.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile raymini.pro

dist: 
	@$(CHK_DIR_EXISTS) .obj/raymini1.0.0 || $(MKDIR) .obj/raymini1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .obj/raymini1.0.0/ && $(COPY_FILE) --parents Window.h GLViewer.h QTUtils.h Vertex.h Triangle.h Mesh.h BoundingBox.h Material.h Object.h Light.h Scene.h RayTracer.h Ray.h .obj/raymini1.0.0/ && $(COPY_FILE) --parents Window.cpp GLViewer.cpp QTUtils.cpp Vertex.cpp Triangle.cpp Mesh.cpp BoundingBox.cpp Material.cpp Object.cpp Light.cpp Scene.cpp RayTracer.cpp Ray.cpp Main.cpp .obj/raymini1.0.0/ && (cd `dirname .obj/raymini1.0.0` && $(TAR) raymini1.0.0.tar raymini1.0.0 && $(COMPRESS) raymini1.0.0.tar) && $(MOVE) `dirname .obj/raymini1.0.0`/raymini1.0.0.tar.gz . && $(DEL_FILE) -r .obj/raymini1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: .moc/moc_Window.cpp .moc/moc_GLViewer.cpp .moc/moc_QTUtils.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) .moc/moc_Window.cpp .moc/moc_GLViewer.cpp .moc/moc_QTUtils.cpp
.moc/moc_Window.cpp: QTUtils.h \
		GLViewer.h \
		/usr/include/QGLViewer/qglviewer.h \
		/usr/include/QGLViewer/camera.h \
		/usr/include/QGLViewer/manipulatedCameraFrame.h \
		/usr/include/QGLViewer/manipulatedFrame.h \
		/usr/include/QGLViewer/frame.h \
		/usr/include/QGLViewer/constraint.h \
		/usr/include/QGLViewer/vec.h \
		/usr/include/math.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/huge_val.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/bits/huge_valf.h \
		/usr/include/bits/huge_vall.h \
		/usr/include/bits/inf.h \
		/usr/include/bits/nan.h \
		/usr/include/bits/mathdef.h \
		/usr/include/bits/mathcalls.h \
		/usr/include/bits/mathinline.h \
		/usr/include/QGLViewer/config.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h \
		/usr/include/QGLViewer/quaternion.h \
		/usr/include/QGLViewer/mouseGrabber.h \
		/usr/include/QGLViewer/keyFrameInterpolator.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h \
		Window.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Window.h -o .moc/moc_Window.cpp

.moc/moc_GLViewer.cpp: /usr/include/QGLViewer/qglviewer.h \
		/usr/include/QGLViewer/camera.h \
		/usr/include/QGLViewer/manipulatedCameraFrame.h \
		/usr/include/QGLViewer/manipulatedFrame.h \
		/usr/include/QGLViewer/frame.h \
		/usr/include/QGLViewer/constraint.h \
		/usr/include/QGLViewer/vec.h \
		/usr/include/math.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/huge_val.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/bits/huge_valf.h \
		/usr/include/bits/huge_vall.h \
		/usr/include/bits/inf.h \
		/usr/include/bits/nan.h \
		/usr/include/bits/mathdef.h \
		/usr/include/bits/mathcalls.h \
		/usr/include/bits/mathinline.h \
		/usr/include/QGLViewer/config.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h \
		/usr/include/QGLViewer/quaternion.h \
		/usr/include/QGLViewer/mouseGrabber.h \
		/usr/include/QGLViewer/keyFrameInterpolator.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h \
		GLViewer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) GLViewer.h -o .moc/moc_GLViewer.cpp

.moc/moc_QTUtils.cpp: QTUtils.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) QTUtils.h -o .moc/moc_QTUtils.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

.obj/Window.o: Window.cpp Window.h \
		QTUtils.h \
		GLViewer.h \
		/usr/include/QGLViewer/qglviewer.h \
		/usr/include/QGLViewer/camera.h \
		/usr/include/QGLViewer/manipulatedCameraFrame.h \
		/usr/include/QGLViewer/manipulatedFrame.h \
		/usr/include/QGLViewer/frame.h \
		/usr/include/QGLViewer/constraint.h \
		/usr/include/QGLViewer/vec.h \
		/usr/include/math.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/huge_val.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/bits/huge_valf.h \
		/usr/include/bits/huge_vall.h \
		/usr/include/bits/inf.h \
		/usr/include/bits/nan.h \
		/usr/include/bits/mathdef.h \
		/usr/include/bits/mathcalls.h \
		/usr/include/bits/mathinline.h \
		/usr/include/QGLViewer/config.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h \
		/usr/include/QGLViewer/quaternion.h \
		/usr/include/QGLViewer/mouseGrabber.h \
		/usr/include/QGLViewer/keyFrameInterpolator.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h \
		RayTracer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Window.o Window.cpp

.obj/GLViewer.o: GLViewer.cpp GLViewer.h \
		/usr/include/QGLViewer/qglviewer.h \
		/usr/include/QGLViewer/camera.h \
		/usr/include/QGLViewer/manipulatedCameraFrame.h \
		/usr/include/QGLViewer/manipulatedFrame.h \
		/usr/include/QGLViewer/frame.h \
		/usr/include/QGLViewer/constraint.h \
		/usr/include/QGLViewer/vec.h \
		/usr/include/math.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/huge_val.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/bits/huge_valf.h \
		/usr/include/bits/huge_vall.h \
		/usr/include/bits/inf.h \
		/usr/include/bits/nan.h \
		/usr/include/bits/mathdef.h \
		/usr/include/bits/mathcalls.h \
		/usr/include/bits/mathinline.h \
		/usr/include/QGLViewer/config.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h \
		/usr/include/QGLViewer/quaternion.h \
		/usr/include/QGLViewer/mouseGrabber.h \
		/usr/include/QGLViewer/keyFrameInterpolator.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/GLViewer.o GLViewer.cpp

.obj/QTUtils.o: QTUtils.cpp QTUtils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/QTUtils.o QTUtils.cpp

.obj/Vertex.o: Vertex.cpp Vertex.h \
		Vec3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Vertex.o Vertex.cpp

.obj/Triangle.o: Triangle.cpp Triangle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Triangle.o Triangle.cpp

.obj/Mesh.o: Mesh.cpp Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Mesh.o Mesh.cpp

.obj/BoundingBox.o: BoundingBox.cpp BoundingBox.h \
		Vec3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/BoundingBox.o BoundingBox.cpp

.obj/Material.o: Material.cpp Material.h \
		Vec3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Material.o Material.cpp

.obj/Object.o: Object.cpp Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Object.o Object.cpp

.obj/Light.o: Light.cpp Light.h \
		Vec3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Light.o Light.cpp

.obj/Scene.o: Scene.cpp Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Scene.o Scene.cpp

.obj/RayTracer.o: RayTracer.cpp RayTracer.h \
		Vec3D.h \
		Ray.h \
		BoundingBox.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Triangle.h \
		Edge.h \
		Material.h \
		Light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/RayTracer.o RayTracer.cpp

.obj/Ray.o: Ray.cpp Ray.h \
		Vec3D.h \
		BoundingBox.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Ray.o Ray.cpp

.obj/Main.o: Main.cpp Window.h \
		QTUtils.h \
		GLViewer.h \
		/usr/include/QGLViewer/qglviewer.h \
		/usr/include/QGLViewer/camera.h \
		/usr/include/QGLViewer/manipulatedCameraFrame.h \
		/usr/include/QGLViewer/manipulatedFrame.h \
		/usr/include/QGLViewer/frame.h \
		/usr/include/QGLViewer/constraint.h \
		/usr/include/QGLViewer/vec.h \
		/usr/include/math.h \
		/usr/include/features.h \
		/usr/include/sys/cdefs.h \
		/usr/include/bits/wordsize.h \
		/usr/include/gnu/stubs.h \
		/usr/include/gnu/stubs-32.h \
		/usr/include/bits/huge_val.h \
		/usr/include/endian.h \
		/usr/include/bits/endian.h \
		/usr/include/bits/huge_valf.h \
		/usr/include/bits/huge_vall.h \
		/usr/include/bits/inf.h \
		/usr/include/bits/nan.h \
		/usr/include/bits/mathdef.h \
		/usr/include/bits/mathcalls.h \
		/usr/include/bits/mathinline.h \
		/usr/include/QGLViewer/config.h \
		/usr/include/GL/glut.h \
		/usr/include/GL/freeglut_std.h \
		/usr/include/GL/gl.h \
		/usr/include/GL/gl_mangle.h \
		/usr/include/stdlib.h \
		/usr/include/bits/waitflags.h \
		/usr/include/bits/waitstatus.h \
		/usr/include/xlocale.h \
		/usr/include/sys/types.h \
		/usr/include/bits/types.h \
		/usr/include/bits/typesizes.h \
		/usr/include/time.h \
		/usr/include/bits/time.h \
		/usr/include/sys/select.h \
		/usr/include/bits/select.h \
		/usr/include/bits/sigset.h \
		/usr/include/sys/sysmacros.h \
		/usr/include/bits/pthreadtypes.h \
		/usr/include/alloca.h \
		/usr/include/bits/stdlib.h \
		/usr/include/bits/stdlib-ldbl.h \
		/usr/include/GL/glext.h \
		/usr/include/inttypes.h \
		/usr/include/stdint.h \
		/usr/include/bits/wchar.h \
		/usr/include/GL/glu.h \
		/usr/include/GL/glu_mangle.h \
		/usr/include/QGLViewer/quaternion.h \
		/usr/include/QGLViewer/mouseGrabber.h \
		/usr/include/QGLViewer/keyFrameInterpolator.h \
		Scene.h \
		Object.h \
		Mesh.h \
		Vertex.h \
		Vec3D.h \
		Triangle.h \
		Edge.h \
		Material.h \
		BoundingBox.h \
		Light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Main.o Main.cpp

.obj/moc_Window.o: .moc/moc_Window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_Window.o .moc/moc_Window.cpp

.obj/moc_GLViewer.o: .moc/moc_GLViewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_GLViewer.o .moc/moc_GLViewer.cpp

.obj/moc_QTUtils.o: .moc/moc_QTUtils.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_QTUtils.o .moc/moc_QTUtils.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

