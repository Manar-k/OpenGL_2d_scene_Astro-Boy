//  main.cpp
//  openglProject
//  Created by manar_k on 19/07/1441 AH.
//  Copyright © 1441 manar_k. All rights reserved.
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <glut.h>

using namespace std;

GLint win_width = 500,
win_hight = 500;
//HAPPY
float buble_eye_clr, buble_eye_clr2, buble_eye_clr12;
float hpy_muth_1, hpy_muth_2, hpy_muth_3;
//SAD
float sad_muth_tra, sad_muth_tras_2, sad_muth_tras_3, sad_scal_tong1, sad_scal_tong1y, sad_drops1, Eyelid
, EYEBROW1, EYEBROWtran, EYEBROW1_RIGHT;
//SUPRISED
float suprised_eyetran, suprised_eyetran2, suprised_eye1, suprised_eye2, suprised_mouth1, suprised_mouth2,
suprised_mouth3, suprised_mouth4;
//ROTATION
GLfloat angle = 45.0f;//rotate 45.0f
float xaxis, yaxis, zaxis, clockwise, face_clr1, face_clr2, face_clr3;

//EXTRA
bool leser = true;//Extra leaser gun
float flyud, flyrl, robotbody, robotface, shot, leaseron1, leaseron2, leaseron3;

class Eyes {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};
void draw_line()
{
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(0.5f);
    glBegin(GL_LINES);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.1f);

    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

void drawleaser(void)//extra
{
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(10.0f);

    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2i(0.0, 0.0);
    glColor3f(0, 0, 1);
    glVertex2f(0.0, 0.5);

    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glFlush();
}

void draw_mouth()
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.2f);
    glEnd();

    glFlush();
}

void draw_triangle()
{
    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.40f, 0.0f);
    glVertex2f(0.0f, 0.40f);
    glEnd();

    glFlush();
}

void draw_EYEBROW()
{
    float x1 = 0.0f, y1 = 0.0f, radius = 0.2f;

    int steps = 1000;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 1.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_POINTS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_bow()
{
    float x1 = 0.0f, y1 = 0.0f, radius = 0.04f;

    int steps = 1000;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 3.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_POINTS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_circle()
{

    float x1 = 0.0f, y1 = 0.0f, radius = 0.5f;
    int steps = 100;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 3.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_tonge()
{

    float x1 = 0.0f, y1 = 0.0f, radius = 0.3f;
    int steps = 100;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 1.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_eye()
{

    float x1 = 0.0f, y1 = 0.0f, radius = 0.3f;
    int steps = 100;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 3.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_ear()
{
    float x1 = 0.0f, y1 = 0.0f, radius = 0.1f;
    int steps = 100;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 3.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}

void draw_hair()
{

    float x1 = 0.0f, y1 = 0.0f, radius = 0.6f;

    glColor3f(0.0f, 0.0f, 0.0f);
    int steps = 100;
    float x2 = x1;
    float y2 = y1 - radius;
    float angle = 3.1415926f * 3.0f / steps;
    for (int i = 0; i < steps; i++)
    {
        float xnew = radius * sin(angle * i);
        float ynew = -radius * cos(angle * i);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(xnew, ynew, 0.0);
        glEnd();

        x2 = xnew;
        y2 = ynew;
    }
    glFlush();
}


static //to start moving astro boy by showing body
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            robotbody = 0.5f;
            robotface = 0.5f;
            shot = 0.0;
            leaseron1 = 0.412f;
            leaseron2 = 0.412f;
            leaseron3 = 0.412f;

        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {
            robotbody = 0.5f;
            robotface = 0.5f;
            shot = 0.5;
            leaseron1 = 1.0f;
            leaseron2 = 0.0f;
            leaseron3 = 0.0f;

        }
    }
}

static
void keyfly(int key, int x, int y)//make astro boy flying
{
    //handle special keys
    switch (key) {

        // Exercise 1
    case GLUT_KEY_LEFT:
        flyrl = flyrl - 0.1;
        printf("%f", flyrl);
        break;
    case GLUT_KEY_RIGHT:
        flyrl = flyrl + 0.1;
        printf("%f", flyrl);
        break;
    case GLUT_KEY_UP:
        flyud = flyud + 0.1;
        printf("%f", flyud);
        break;
    case GLUT_KEY_DOWN:
        flyud = flyud - 0.1;
        printf("%f", flyud);
        break;
    default:
        break;
        //----------------------
    }
}


static void play(void)
{
    glutPostRedisplay();
}

static
void key(unsigned char keyPressed, int x, int y) //faces
{
    switch (keyPressed) {

    case 'H':  //to rotate the simile face counterclockwise relative to y-axis
        //happy mouth & eye
        buble_eye_clr = 1.0;
        buble_eye_clr12 = 1.0f;
        buble_eye_clr2 = 1.6f;

        hpy_muth_1 = 0.65;
        hpy_muth_2 = 0.5;
        hpy_muth_3 = 0.28;

        suprised_mouth1 = 0.0;//helper to o back
        suprised_mouth2 = 0.0;
        suprised_mouth3 = 0.0;
        suprised_mouth4 = 0.0;

        suprised_eye1 = 0.3;//helper to o back
        suprised_eye2 = 0.55;
        suprised_eyetran = 0.28;
        suprised_eyetran2 = -0.28;

        sad_muth_tra = 270.0;//helper to o back
        sad_muth_tras_2 = -0.28;
        sad_muth_tras_3 = -0.39;
        sad_scal_tong1 = 0.65;
        sad_scal_tong1y = 0.0;
        sad_drops1 = 0.0;
        Eyelid = 0.0;
        EYEBROW1 = 90.0;
        EYEBROW1_RIGHT = 90.0;
        EYEBROWtran = 0.2;
        //face color
        face_clr1 = 1.0f;
        face_clr2 = 0.894f;
        face_clr3 = 0.769f;

        //y-axies
        xaxis = 0.0f;
        yaxis = 1.0;
        zaxis = 0.0f;
        clockwise = 1.0;
        break;

    case 'h':// to rotate the simile face clockwise relative to y - axis
        buble_eye_clr = 1.0f;
        buble_eye_clr12 = 1.0f;
        buble_eye_clr2 = 1.6f;

        hpy_muth_1 = 0.65;
        hpy_muth_2 = 0.5;
        hpy_muth_3 = 0.28;

        suprised_mouth1 = 0.0;//helper to o back
        suprised_mouth2 = 0.0;
        suprised_mouth3 = 0.0;
        suprised_mouth4 = 0.0;

        suprised_eye1 = 0.3;//helper to o back
        suprised_eye2 = 0.55;
        suprised_eyetran = 0.28;
        suprised_eyetran2 = -0.28;

        sad_muth_tra = 270.0;//helper to o back
        sad_muth_tras_2 = -0.28;
        sad_muth_tras_3 = -0.39;
        sad_scal_tong1 = 0.65;
        sad_scal_tong1y = 0.0;
        sad_drops1 = 0.0;
        Eyelid = 0.0;
        EYEBROW1 = 90.0;
        EYEBROW1_RIGHT = 90.0;
        EYEBROWtran = 0.2;

        //face color
        face_clr1 = 1.0f;
        face_clr2 = 0.894f;
        face_clr3 = 0.769f;

        //y-axies
        xaxis = 0.0f;
        yaxis = 1.0f;
        zaxis = 0.0f;
        clockwise = -1.0;
        //printf("The new translate value is :%f", transValue);
        break;

    case 'S'://to rotate the sad face counterclockwise relative to x-axi
        buble_eye_clr = 0.529;
        buble_eye_clr2 = 0.980;
        buble_eye_clr12 = 0.808;

        sad_muth_tra = 90.0;
        sad_muth_tras_2 = -0.46;
        sad_muth_tras_3 = -0.46;
        sad_scal_tong1 = -0.55;
        sad_scal_tong1y = 0.5;

        Eyelid = 0.6;
        sad_drops1 = 0.1;
        EYEBROWtran = 0.35;
        EYEBROW1 = -110.0;
        EYEBROW1_RIGHT = -70.0;

        suprised_mouth1 = 0.0;//helper to o back
        suprised_mouth2 = 0.0;
        suprised_mouth3 = 0.0;
        suprised_mouth4 = 0.0;

        suprised_eye1 = 0.3;//helper to o back
        suprised_eye2 = 0.55;
        suprised_eyetran = 0.28;
        suprised_eyetran2 = -0.28;

        //face color
        face_clr1 = 0.933f;
        face_clr2 = 0.910f;
        face_clr3 = 0.667f;

        //x-axies
        xaxis = 1.0f;
        yaxis = 0.0f;
        zaxis = 0.0f;
        clockwise = 1.0;

        break;

    case 's'://to rotate the sad face clockwise relative to x-axis
        buble_eye_clr = 0.529;
        buble_eye_clr2 = 0.980;
        buble_eye_clr12 = 0.808;

        sad_muth_tra = 90.0;
        sad_muth_tras_2 = -0.46;
        sad_muth_tras_3 = -0.46;
        sad_scal_tong1 = -0.55;
        sad_scal_tong1y = 0.5;

        Eyelid = 0.6;
        sad_drops1 = 0.1;
        EYEBROWtran = 0.35;
        EYEBROW1 = -110.0;
        EYEBROW1_RIGHT = -70.0;

        suprised_mouth1 = 0.0;//helper to o back
        suprised_mouth2 = 0.0;
        suprised_mouth3 = 0.0;
        suprised_mouth4 = 0.0;

        suprised_eye1 = 0.3;//helper to o back
        suprised_eye2 = 0.55;
        suprised_eyetran = 0.28;
        suprised_eyetran2 = -0.28;

        //face color
        face_clr1 = 0.933f;
        face_clr2 = 0.910f;
        face_clr3 = 0.667f;

        //x-axies
        xaxis = 1.0f;
        yaxis = 0.0f;
        zaxis = 0.0f;
        clockwise = -1.0;

        break;

    case 'R'://to rotate the surprise face counterclockwise relative to z-axis

        hpy_muth_1 = 0.0;
        hpy_muth_2 = 0.0;
        hpy_muth_3 = 0.0;
        sad_scal_tong1 = 0.0;
        sad_scal_tong1y = 0.0;

        EYEBROW1 = 90.0;
        EYEBROW1_RIGHT = 90.0;
        EYEBROWtran = 0.2;

        Eyelid = 0.0;
        sad_drops1 = 0.0;

        buble_eye_clr = 1.000;
        buble_eye_clr2 = 1.000;
        buble_eye_clr12 = 1.000;

        suprised_eye1 = 0.17;
        suprised_eye2 = 0.43;
        suprised_eyetran = 0.3;
        suprised_eyetran2 = -0.3;

        suprised_mouth1 = 0.33;
        suprised_mouth2 = 0.38;
        suprised_mouth3 = 0.31;
        suprised_mouth4 = 0.40;

        //face color
        face_clr1 = 0.902f;
        face_clr2 = 0.902f;
        face_clr3 = 0.980f;

        //z-axies
        xaxis = 0.0f;
        yaxis = 0.0f;
        zaxis = 1.0f;
        clockwise = 1.0;

        break;

    case 'r'://to rotate the surprise face clockwise relative to z - axi
        hpy_muth_1 = 0.0;
        hpy_muth_2 = 0.0;
        hpy_muth_3 = 0.0;
        sad_scal_tong1 = 0.0;
        sad_scal_tong1y = 0.0;

        EYEBROW1 = 90.0;
        EYEBROW1_RIGHT = 90.0;
        EYEBROWtran = 0.2;

        Eyelid = 0.0;
        sad_drops1 = 0.0;

        buble_eye_clr = 1.000;
        buble_eye_clr2 = 1.000;
        buble_eye_clr12 = 1.000;

        suprised_eye1 = 0.17;
        suprised_eye2 = 0.43;
        suprised_eyetran = 0.3;
        suprised_eyetran2 = -0.3;

        suprised_mouth1 = 0.33;
        suprised_mouth2 = 0.38;
        suprised_mouth3 = 0.31;
        suprised_mouth4 = 0.40;

        //face color
        face_clr1 = 0.902f;
        face_clr2 = 0.902f;
        face_clr3 = 0.980f;


        //z-axies
        xaxis = 0.0f;
        yaxis = 0.0f;
        zaxis = 1.0f;
        clockwise = -1.0;

        break;

    case 'q':
    case 27:
        exit(0);
        break;

    default:
        fprintf(stderr, "\nKeyboard commands:\n\n"
            "q, <esc> - Quit\n");
        break;
    }
}

void init() {
    glClearColor(0.282f, 0.239f, 0.545f, 1.0f); // Set background color to black and opaque
    glMatrixMode(GL_PROJECTION);

}

void reshapeFunc(GLint new_width, GLint new_hight)
{
    glViewport(0, 0, new_width, new_hight);
    win_width = new_width;
    win_hight = new_hight;

}

void FACE()
{

    //HAIR AROUND
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    draw_hair();
    glPopMatrix();

    // HAIR RIGHT SIDE
    glPushMatrix();
    glTranslatef(0.4, 0.4, 0.0);
    glScalef(1.5, 1.5, 1.0);
    glRotatef(270.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_triangle();
    glPopMatrix();

    //FACE
    glPushMatrix();
    glScalef(1.02, 1.02, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    glColor3f(face_clr1, face_clr2, face_clr3);
    draw_circle();

    //INFRONT HAIR
    glPushMatrix();
    glTranslatef(0.0, 0.3, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_triangle();
    glPopMatrix();

    //R EAR
    glPushMatrix();//face_clr1
    glTranslatef(0.5, -0.2, 0.0);
    glColor3f(face_clr1, face_clr2, face_clr3);
    draw_ear();
    glPopMatrix();

    //L EAR
    glPushMatrix();
    glTranslatef(-0.5, -0.2, 0.0);
    glColor3f(face_clr1, face_clr2, face_clr3);
    draw_ear();
    glPopMatrix();

    //HAIR UP SIDE
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0.0);
    glScalef(1.5, 1.5, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_triangle();
    glPopMatrix();

    //NOSE
    glPushMatrix();
    glTranslatef(0.0, -0.22, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_bow();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.18, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_line();
    glPopMatrix();


}

void EYES()
{

    //MARK R RYR
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.42, 0.77, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_eye();
    glPopMatrix();

    //MARK L RYR
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glScalef(0.42, 0.77, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_eye();
    glPopMatrix();

    //R EYE
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.4, 0.75, 0.0);
    glColor3f(1.0f, 1.0f, 1.6f);
    draw_eye();
    glPopMatrix();

    //L EYE
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glScalef(0.4, 0.75, 0.0);
    glColor3f(1.0f, 1.0f, 1.6f);
    draw_eye();
    glPopMatrix();

    //R EYE b
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(suprised_eye1, suprised_eye2, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_eye();
    glPopMatrix();

    //L EYE b
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.0);
    glScalef(suprised_eye1, suprised_eye2, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_eye();
    glPopMatrix();

    //buble EYE r
    glPushMatrix();
    glTranslatef(suprised_eyetran, 0.0, 0.0);
    glScalef(0.1, 0.26, 0.0);
    glColor3f(1.0f, 1.0f, 1.6f);
    draw_eye();
    glPopMatrix();

    //buble EYE l
    glPushMatrix();
    glTranslatef(suprised_eyetran2, 0.0, 0.0);
    glScalef(0.1, 0.26, 0.0);
    glColor3f(1.0f, 1.0f, 1.6f);
    draw_eye();
    glPopMatrix();

    //EYEBROW LEFT
    glPushMatrix();
    glTranslatef(-0.3, EYEBROWtran, 0.0);
    glScalef(0.65, 0.65, 0.0);
    glRotatef(EYEBROW1, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_EYEBROW();
    glPopMatrix();

    //EYEBROW RIGHT
    glPushMatrix();
    glTranslatef(0.3, EYEBROWtran, 0.0);
    glScalef(0.65, 0.65, 0.0);
    glRotatef(EYEBROW1_RIGHT, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_EYEBROW();
    glPopMatrix();

    //tye buble eye for happy buble_eye_clr
    //buble EYE R HAPPY & sad
    glPushMatrix();
    glTranslatef(0.36, -0.1, 0.0);//-0.1 y sad_drops
    glScalef(0.1, 0.1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();

    //buble EYE l HAPPY
    glPushMatrix();
    glTranslatef(-0.36, -0.1, 0.0);
    glScalef(0.1, 0.1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();

    //R Eyelid sad
    glPushMatrix();
    glTranslatef(0.3, -0.28, 0.0);//3
    glScalef(Eyelid, Eyelid, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(face_clr1, face_clr2, face_clr3);
    draw_triangle();
    glPopMatrix();

    //L Eyelid sad
    glPushMatrix();
    glTranslatef(-0.3, -0.28, 0.0);
    glScalef(Eyelid, Eyelid, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glColor3f(face_clr1, face_clr2, face_clr3);
    draw_triangle();
    glPopMatrix();

    //sad 3 drops
    glPushMatrix();
    glTranslatef(0.36, -0.2, 0.0);//second drop
    glScalef(sad_drops1, sad_drops1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();

    //buble EYE l HAPPY
    glPushMatrix();
    glTranslatef(-0.36, -0.2, 0.0);
    glScalef(sad_drops1, sad_drops1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();
    //-----
    glPushMatrix();
    glTranslatef(0.36, -0.3, 0.0);//thired drop
    glScalef(sad_drops1, sad_drops1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();

    //buble EYE l HAPPY
    glPushMatrix();
    glTranslatef(-0.36, -0.3, 0.0);
    glScalef(sad_drops1, sad_drops1, 0.0);
    glColor3f(buble_eye_clr, buble_eye_clr12, buble_eye_clr2);
    draw_eye();
    glPopMatrix();

    //ear detail LEFT
    glPushMatrix();
    glTranslatef(-0.5, -0.2, 0.0);
    glScalef(0.3, 0.3, 0.0);
    glRotatef(-190.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_EYEBROW();
    glPopMatrix();

    //ear detail RIGHT
    glPushMatrix();
    glTranslatef(0.5, -0.2, 0.0);
    glScalef(0.3, 0.3, 0.0);
    glRotatef(27.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_EYEBROW();
    glPopMatrix();

    //hair highliter
    glPushMatrix();
    glTranslatef(0.45, 0.45, 0.0);
    glScalef(0.1, 0.1, 0.0);
    glRotatef(170.0, 1.0, 1.0, 1.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    draw_circle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35, 0.55, 0.0);
    glScalef(0.3, 0.3, 0.0);
    glRotatef(170.0, 1.0, 1.0, 1.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    draw_circle();
    glPopMatrix();

}

void MOUTH()
{
    //mouth
    glPushMatrix();
    glTranslatef(0.1, -0.38, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    draw_mouth();
    glPopMatrix();

    //happy mouth
    glPushMatrix();
    glTranslatef(0.0, sad_muth_tras_2, 0.0);
    glScalef(hpy_muth_1, hpy_muth_1, 0.0);
    glRotatef(sad_muth_tra, 0.0, 0.0, 1.0);
    glColor3f(0.863f, 0.078f, 0.235f);
    draw_tonge();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.4, 0.0);
    glScalef(hpy_muth_2, hpy_muth_3, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glColor3f(0.859f, 0.439f, 0.576f);
    draw_tonge();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, sad_muth_tras_3, 0.0);
    glScalef(hpy_muth_2, hpy_muth_3, 0.0);
    glRotatef(sad_muth_tra, 0.0, 0.0, 1.0);
    glColor3f(0.859f, 0.439f, 0.576f);
    draw_tonge();
    glPopMatrix();

    //sad helper tong
    glPushMatrix();
    glTranslatef(0.0, sad_muth_tras_2, 0.0);//sad_muth_tras_2 -0.28
    glScalef(sad_scal_tong1, sad_scal_tong1y, 0.0);//
    glRotatef(sad_muth_tra, 0.0, 0.0, 1.0);//270
    glColor3f(0.859f, 0.439f, 0.576f);
    draw_tonge();
    glPopMatrix();


    glPushMatrix();//suprised_mouth1
    glTranslatef(0.0, -0.38, 0.0);
    glScalef(suprised_mouth1, suprised_mouth2, 0.0);
    //glRotatef(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.859f, 0.439f, 0.576f);
    draw_eye();
    glPopMatrix();

    glPushMatrix();//suprised mouth
    glTranslatef(0.0, -0.38, 0.0);
    glScalef(suprised_mouth3, suprised_mouth4, 0.0);//24y,2x
    glRotatef(271.0, 0.0, 0.0, 1.0);
    glColor3f(1.000f, 0.714f, 0.757f);//0.859f,0.439f,0.576f
    draw_tonge();
    glPopMatrix();

}
void leaser_shot()//EXTRA
{
    glPushMatrix();//leaser shot
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(0.7, 0.7, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    drawleaser();
    glPopMatrix();

    glPushMatrix();//leaser shot
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(1.0, 1.0, 0.0);
    glRotatef(angle, 1.0, 1.0, 0.0);
    drawleaser();
    glPopMatrix();

    glPushMatrix();//leaser shot
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(1.0, 1.0, 0.0);
    glRotatef(angle, 1.0, 0.0, 0.0);
    drawleaser();
    glPopMatrix();
}

void body()
{
    if (leser) {
        //left fire
        glPushMatrix();
        glTranslatef(-0.2, -0.9, 0.0);
        glScalef(0.6, 0.6, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 0.0f, 0.0f);//red
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.2, -0.9, 0.0);
        glScalef(0.55, 0.55, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 0.549f, 0.0f);//orange
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.2, -0.9, 0.0);
        glScalef(0.45, 0.45, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 1.0f, 0.0f);//yellow
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.2, -0.9, 0.0);
        glScalef(0.3, 0.3, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle();
        glPopMatrix();

        //right fire
        glPushMatrix();
        glTranslatef(0.1, -0.85, 0.0);
        glScalef(0.5, 0.5, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 0.0f, 0.0f);//red
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.1, -0.85, 0.0);
        glScalef(0.45, 0.45, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 0.549f, 0.0f);//orange
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.1, -0.85, 0.0);
        glScalef(0.35, 0.35, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 1.0f, 0.0f);//yellow
        draw_circle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.1, -0.85, 0.0);
        glScalef(0.2, 0.2, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle();
        glPopMatrix();
    }

    //mark down robo sho
    //glColor3f(1.0f,0.894f,0.769f); skin
    glPushMatrix();
    glTranslatef(0.1, -0.76, 0.0);
    glScalef(0.48, -0.28, 0.0);
    glRotatef(85.0, 0.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //down shoes
    glPushMatrix();
    glTranslatef(0.1, -0.76, 0.0);
    glScalef(0.45, -0.25, 0.0);
    glRotatef(85.0, 0.0, 1.0, 1.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //mark left down robot shoes
    glPushMatrix();
    glTranslatef(-0.15, -0.81, 0.0);
    glScalef(0.38, 0.38, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    // left down robot shoes
    glPushMatrix();
    glTranslatef(-0.15, -0.81, 0.0);
    glScalef(0.35, 0.35, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();


    //mark robot shoe
    glPushMatrix();
    glTranslatef(-0.15, -0.7, 0.0);
    glScalef(0.46, 0.46, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    // L left robot shoe
    glPushMatrix();
    glTranslatef(-0.15, -0.7, 0.0);
    glScalef(0.42, 0.42, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    // R mark r robot shoes
    glPushMatrix();
    glTranslatef(0.19, -0.63, 0.0);
    glScalef(0.34, 0.34, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //right robot shoes
    glPushMatrix();
    glTranslatef(0.19, -0.63, 0.0);
    glScalef(0.3, 0.3, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();


    //mark* left leg
    glPushMatrix();
    glTranslatef(-0.15, -0.63, 0.0);
    glScalef(0.34, 0.34, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //mark right leg*
    glPushMatrix();
    glTranslatef(0.15, -0.54, 0.0);
    glScalef(0.34, 0.34, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //left leg
    glPushMatrix();
    glTranslatef(-0.15, -0.63, 0.0);
    glScalef(0.3, 0.3, 0.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //right leg
    glPushMatrix();
    glTranslatef(0.15, -0.54, 0.0);
    glScalef(0.3, 0.3, 0.0);
    //glRotatef(85.0, 0.0,0.0,1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //mark*body 2 part left arm
    glPushMatrix();
    glTranslatef(-0.75, -0.4, 0.0);
    glScalef(0.84, -0.48, 0.0);
    glRotatef(85.0, 0.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //mark* body 1 part left arm
    glPushMatrix();
    glTranslatef(-0.5, -0.4, 0.0);
    glScalef(0.74, -0.44, 0.0);
    glRotatef(15.0, 0.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //mark* body part front up
    glPushMatrix();
    glTranslatef(-0.1, -0.35, 0.0);
    glScalef(1.1, 0.72, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //body part front up
    glPushMatrix();
    glTranslatef(-0.1, -0.35, 0.0);
    glScalef(1.0, 0.7, 0.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();


    //body 1 part left arm
    glPushMatrix();
    glTranslatef(-0.5, -0.4, 0.0);
    glScalef(0.7, -0.4, 0.0);
    glRotatef(15.0, 0.0, 1.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();


    //body 2 part left arm
    glPushMatrix();
    glTranslatef(-0.75, -0.4, 0.0);
    glScalef(0.8, -0.44, 0.0);
    glRotatef(85.0, 0.0, 1.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //body 3 part left arm
    glPushMatrix();
    glTranslatef(-0.9, -0.5, 0.0);
    glScalef(0.35, 0.35, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //mark hand
    glPushMatrix();
    glTranslatef(-1.1, -0.55, 0.0);
    glScalef(0.47, 0.47, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslatef(-1.1, -0.55, 0.0);
    glScalef(0.45, 0.45, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //robot hand
    glPushMatrix();
    glTranslatef(-1.1, -0.55, 0.0);
    glScalef(0.35, 0.35, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.663f, 0.663f, 0.663f);
    draw_circle();
    glPopMatrix();

    //healper robot hand
    glPushMatrix();
    glTranslatef(-1.1, -0.55, 0.0);
    glScalef(0.25, 0.25, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.412f, 0.412f, 0.412f);
    draw_circle();
    glPopMatrix();

    if (leser) {
        glPushMatrix();//l turn on leaser gun
        glTranslatef(-1.1, -0.55, 0.0);
        glScalef(0.25, 0.25, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(leaseron1, leaseron2, leaseron3);
        draw_circle();
        glPopMatrix();
    }

    //pull
    glPushMatrix();
    glTranslatef(-1.1, -0.55, 0.0);
    glScalef(1.0, 1.0, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_bow();
    glPopMatrix();

    //right arm robot
    glPushMatrix();
    glTranslatef(0.5, -0.35, 0.0);
    glScalef(1.0, 0.7, 0.0);
    glRotatef(95.0, 0.0, 1.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //R mark hand
    glPushMatrix();
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(0.67, 0.67, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle();
    glPopMatrix();

    //R hand
    glPushMatrix();
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(0.65, 0.65, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.894f, 0.769f);
    draw_circle();
    glPopMatrix();

    //R robot hand
    glPushMatrix();
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(0.55, 0.55, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.663f, 0.663f, 0.663f);
    draw_circle();
    glPopMatrix();

    //R healper robot hand
    glPushMatrix();
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(0.412f, 0.412f, 0.412f);
    draw_circle();
    glPopMatrix();

    if (leser) {
        //R turn on leaser gun
        glPushMatrix();
        glTranslatef(0.8, -0.53, 0.0);
        glScalef(0.4, 0.4, 0.0);
        glRotatef(85.0, 0.0, 0.0, 1.0);
        glColor3f(leaseron1, leaseron2, leaseron3);
        draw_circle();
        glPopMatrix();
    }

    //pull
    glPushMatrix();
    glTranslatef(0.8, -0.53, 0.0);
    glScalef(2.0, 2.0, 0.0);
    glRotatef(85.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_bow();
    glPopMatrix();


}

void update(int value) {
    glutTimerFunc(50, update, 0);
    leser = !leser;
}


//rotate
int refreshmill = 1;
void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshmill, timer, 0);
}


void ASTROBOY()//ASTRO BOY FACE
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();//Extra body fling astroboy
    glTranslatef(flyrl, flyud, 0.0f);//for game make it move(fly) using robot sheos
    glRotatef(angle, xaxis, yaxis, zaxis);
    glScalef(robotbody, robotbody, 0.0f);//to show robot body
    body();//EXTRA
    glPopMatrix();

    glPushMatrix();//EXTRA fighting astroboy shot leser gun
    glTranslatef(flyrl, flyud, 0.0f);
    glRotatef(angle, xaxis, yaxis, zaxis);
    glScalef(shot, shot, 0.0f);
    leaser_shot();//EXTRA leaser shot
    glPopMatrix();

    glPushMatrix();
    glTranslatef(flyrl, flyud, 0.0f);
    glRotatef(angle, xaxis, yaxis, zaxis);
    glTranslatef(-0.95, 0.0f, 0.0f);
    glScalef(shot, shot, 0.0f);
    leaser_shot();//EXTRA leaser shot
    glPopMatrix();

    glPushMatrix();//HAPPY,SAD,SUPRISED,ROTATION FACES
    glTranslatef(flyrl, flyud, 0.0f);
    glRotatef(angle, xaxis, yaxis, zaxis);
    glScalef(robotface, robotface, 0.0f);//to show robot body
    FACE();
    EYES();
    MOUTH();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();

    angle = angle + clockwise;

}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(700, 700);// Set the window's initial width & height
    glutInitWindowPosition(300, 300);
    glutCreateWindow("**ASTRO BOY**");
    init();


    //happy
    buble_eye_clr = 0.0f;
    buble_eye_clr12 = 0.0f;
    buble_eye_clr2 = 0.0f;
    hpy_muth_1 = 0.0;
    hpy_muth_2 = 0.0;
    hpy_muth_3 = 0.0;

    //sad
    sad_muth_tra = 270.0;
    sad_muth_tras_2 = -0.28;
    sad_muth_tras_3 = -0.39;
    sad_scal_tong1 = 0.65;
    sad_scal_tong1y = 0.0;
    sad_drops1 = 0.0;
    Eyelid = 0.0;
    EYEBROW1 = 90.0;
    EYEBROW1_RIGHT = 90.0;
    EYEBROWtran = 0.2;

    //suprised
    suprised_eye1 = 0.3;
    suprised_eye2 = 0.55;
    suprised_eyetran = 0.28;
    suprised_eyetran2 = -0.28;
    suprised_mouth1 = 0.0;
    suprised_mouth2 = 0.0;
    suprised_mouth3 = 0.0;
    suprised_mouth4 = 0.0;

    //rotate
    xaxis = 0.0f;
    yaxis = 0.0f;
    zaxis = 0.0f;
    clockwise = 1;

    //sad-suprised clc face
    face_clr1 = 1.0f;
    face_clr2 = 0.894f;
    face_clr3 = 0.769f;

    //extra
    flyud = 0.0f;
    flyrl = 0.0f;
    robotbody = 0.0f;
    robotface = 1.0f;
    shot = 0.0f;
    leaseron1 = 0.412f;
    leaseron2 = 0.412f;
    leaseron3 = 0.412f;

    glutIdleFunc(play);
    glutDisplayFunc(ASTROBOY);
    glutReshapeFunc(reshapeFunc);

    glutTimerFunc(0, timer, 0);//for rotate
    glutTimerFunc(0, update, 0);//5 leser

    glutMouseFunc(mouse);//make astro boy sho leaser gun
    glutSpecialFunc(keyfly);//EXTRA MAKE ASTRO BOY FLY (move)
    glutKeyboardFunc(key);//faces with rotation

    glutMainLoop();// Enter the infinitely event-processing loop
    return 0;
}

