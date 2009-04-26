#ifndef XRAYGLWIDGET_H
#define XRAYGLWIDGET_H

#include <QGLWidget>

enum SimulationMode
{
    SIM_MODE_TEXTURE_BLEND,
    SIM_MODE_PIXEL_CUBES
};

enum TransformationMode
{
    MODE_TRANSLATE,
    MODE_ROTATE
};

class XRayGLWidget : public QGLWidget
{
    Q_OBJECT

 public:
     XRayGLWidget(QWidget *parent = 0);
     ~XRayGLWidget();

     QSize minimumSizeHint() const;
     QSize sizeHint() const;

     /**
      * Resets the modelview matrix and the transformation variables and updates the view
      */
     void resetView();

     void setTransformationMode(TransformationMode mode);
     void setSimulationMode(SimulationMode mode);

     void setScale(int scalePercent);

 public slots:
     void setXRotation(int angle);
     void setYRotation(int angle);
     void setZRotation(int angle);



 signals:
     void xRotationChanged(int angle);
     void yRotationChanged(int angle);
     void zRotationChanged(int angle);

protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int width, int height);

     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);

private:
    //Transformation variables
    TransformationMode transformationMode;
    SimulationMode simulationMode;
    float xRot, yRot, zRot;
    float xMov, yMov, zMov;
    float scale; //Changed by the slider
    double baseScale; //Changed by a spin box, multiplied with scale
    QPoint lastPos;

    //Private functions
    void renderTextureBlending();

    /**
     * OpenGL variables
     */
    //Display list IDs
    GLuint drawCubeListID;
};

#endif // XRAYGLWIDGET_H
