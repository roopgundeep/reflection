#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)

//
double modelview[16];
double projection[16];
int viewport[4];
double mouse_x,mouse_y,mouse_z;
int mouse_motion=0;
void mouse_handle(int x,int y);


// Function Declarations
void drawScene();
void update(int value);
void drawBox(float window_width,float window_height);
void drawBall(float rad);
void drawTriangle();
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
// Global Variables
//float ball_x = 1.0f;
//float ball_y = 0.0f;
float ball_velx = 0.01f;
float ball_vely = 0.02f;
float ball_rad = 0.2f;
float world_height ;
float world_width ;
float resolution;
float array[1000][12];
int number;
float dist;
double a=0.4;
double ddd=0.4;
int random_v=0;
int countz=0;
int call=0;
int cal=0;
int speed=0;
int num_blocks;
float blocks[1000][12];
float mirrors[1000][12];
int num_mirrors;
float points;
float tri_x = 0.0f;
float tri_y = 0.0f;
float theta = 0.0f; 
int count=0;
int update_count=0;
int light=0;


void drawprojector(float x1,float y1,float x2,float y2,float cx,float cy,float cz);
void drawrays(float c1,float c2,float x1,float y1,float x2,float y2,float numb);
void drawblock(float x1,float y1,float x2,float y2,float cx,float cy,float cz);
void drawmirror(float x1,float y1,float x2,float y2,float cx,float cy,float cz);

void stop()
{
	int h;
	for(h=0;h<1000;h++)
	{
	//	int fgh=1;
	}
}

int main(int argc, char **argv) {


/*	ifstream ifile;
	ifile.open(argv[1], ios::in);
	string str;
	getline(ifile, str);
	stringstream ss;
	ss<<str;
//	if(ss =='#')
//	{
//		ss.str(""); ss.clear();
//		getline(ifile, str); ss << str;
//	}
	ss >> world_width; ss >> world_height;
	ss.str(""); ss.clear();

	getline(ifile, str); ss << str;
	ss >> number; ss.str(""); ss.clear();
	for(int i=0;i<number;i++)
	{
		getline(ifile, str); ss << str;
		array[i][8]=0;
		array[i][9]=1;
		array[i][10]=0;
		array[i][11]=0;

		ss>>array[i][0];
		ss>>array[i][1];
		ss>>array[i][2];
		ss>>array[i][3];
		ss.str(""); ss.clear();
		getline(ifile, str); ss << str;
		ss>>array[i][4];
		ss.str(""); ss.clear();
		getline(ifile, str); ss << str;
		ss>>array[i][5];
		ss.str(""); ss.clear();
	}

	getline(ifile, str); ss<<str;
	ss>>num_blocks; ss.str(""); ss.clear();

	for(int i=0;i<num_blocks;i++)
	{

		getline(ifile, str); ss << str;
		blocks[i][8]=1;
		blocks[i][9]=0;
		blocks[i][10]=0;
		blocks[i][11]=0;



		ss>>blocks[i][0];
		ss>>blocks[i][1];
		ss>>blocks[i][2];
		ss>>blocks[i][3];
		ss.str(""); ss.clear();
	}



	getline(ifile, str); ss<<str;
	ss>>num_mirrors; ss.str(""); ss.clear();
	for(int i=0;i<num_mirrors;i++)
	{

		getline(ifile, str); ss << str;

		mirrors[i][8]=1;
		mirrors[i][9]=0;
		mirrors[i][10]=1;
		mirrors[i][11]=0;
	

		ss>>mirrors[i][0];
		ss>>mirrors[i][1];
		ss>>mirrors[i][2];
		ss>>mirrors[i][3];
		ss.str(""); ss.clear();
	}

*/
/////////////////////////////////////////////////////////////////////////
		string s;
		freopen(argv[1],"r",stdin);
		getline(cin,s);
		scanf("%f",&world_width);
		scanf("%f",&world_height);
		getline(cin,s);
		scanf("%d",&number);
		getline(cin,s);
		int i;
		for(i=0;i<number;i++)
		{
			scanf("%f",&array[i][0]);
			scanf("%f",&array[i][1]);
			scanf("%f",&array[i][2]);
			scanf("%f",&array[i][3]);

			getline(cin,s);
			scanf("%f",&array[i][4]);

			getline(cin,s);
			scanf("%f",&array[i][5]);
			array[i][8]=0;
			array[i][9]=1;
			array[i][10]=0;
			array[i][11]=0;
			
		getline(cin,s);
		}
		scanf("%d",&num_blocks);

		getline(cin,s);
		for(i=0;i<num_blocks;i++)
		{
			scanf("%f",&blocks[i][0]);
			scanf("%f",&blocks[i][1]);
			scanf("%f",&blocks[i][2]);
			scanf("%f",&blocks[i][3]);
			blocks[i][8]=1;
			blocks[i][9]=0;
			blocks[i][10]=0;
			blocks[i][11]=0;

		getline(cin,s);
	}
	scanf("%d",&num_mirrors);
	getline(cin,s);
	for(i=0;i<num_mirrors;i++)
	{
		scanf("%f",&mirrors[i][0]);
		scanf("%f",&mirrors[i][1]);
		scanf("%f",&mirrors[i][2]);
		scanf("%f",&mirrors[i][3]);
		mirrors[i][8]=1;
		mirrors[i][9]=0;
		mirrors[i][10]=1;
		mirrors[i][11]=0;

		getline(cin,s);
	}
	
	if(world_width > world_height)
	{
		resolution=(( 1.5 * world_width)*(-1));
	}
	else
	{
		resolution=(( 1.5 * world_height)*(-1));
	}


	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w * 2 / 3;
	int windowHeight = h * 2 / 3;

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	glutCreateWindow("CSE251_sampleCode");  // Setup the window
	initRendering();

	// Register callbacks
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutPassiveMotionFunc(mouse_handle);
//	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(10, update, 0);
	glutMainLoop();
	return 0;
}

void mouse_handle(int win_x, int win_y)
{
	if(mouse_motion==0)
		return;
	glPopMatrix();
	glPushMatrix();

	// Draw Box
	if(world_width>=world_height)
		glTranslatef(0.0f, 0.0f, -1.5f * world_width);
	else
		glTranslatef(0.0f, 0.0f, -1.5f * world_height);
	glEnable(GL_DEPTH);
	glEnable(GL_DEPTH_COMPONENT);
	glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
	glGetDoublev(GL_PROJECTION_MATRIX,projection);
	glGetIntegerv(GL_VIEWPORT,viewport);
	float x,y,z;
	x = (float)win_x;
	y = (float)viewport[3] - (float)win_y;
	glReadPixels((int)x,(int)y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&z);
	gluUnProject(x,y,z,modelview,projection,viewport,&mouse_x,&mouse_y,&mouse_z);
//	printf("%lf %lf\n",mouse_x,mouse_y);
	for(int i=0;i<number;i++)
	{
		float kx1=array[i][0];
		float ky1=array[i][1];
		float kx2=array[i][2];
		float ky2=array[i][3];
		//float cx1=(array[i][0] + array[i][2])/2;
		//float cy1=(array[i][1]+array[i][3])/2;
		float sx1=array[i][6];
		float sy1=array[i][7];
		float dd=sqrt((kx2-kx1)*(kx2-kx1) + (ky1-ky2)*(ky1-ky2));
		double angk=atan2(mouse_y-sy1,mouse_x-sx1);
		float new_centerx=sx1 + array[i][4]*cos(angk);
		float new_centery=sy1 + array[i][4]*sin(angk);
		kx1= new_centerx - (dd/2)*sin(angk);
		ky1= new_centery + (dd/2)*cos(angk);
		kx2= new_centerx + (dd/2)*sin(angk);
		ky2= new_centery - (dd/2)*cos(angk);
		array[i][0]=kx1;
		array[i][1]=ky1;
		array[i][2]=kx2;
		array[i][3]=ky2;

	}
	glPopMatrix();
}

// Function to draw objects on the screen
void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, resolution);
	glColor3f(2.0f, 0.3f, 0.0f);
	drawBox(world_width,world_height);
	//Draw Blocks

	int i;
	for(i=0;i<num_blocks;i++)
	{
		drawblock(blocks[i][0],blocks[i][1],blocks[i][2],blocks[i][3],blocks[i][8],blocks[i][9],blocks[i][10]);
	}

	for(i=0;i<num_mirrors;i++)
	{
		drawmirror(mirrors[i][0],mirrors[i][1],mirrors[i][2],mirrors[i][3],mirrors[i][8],mirrors[i][9],mirrors[i][10]);
	}
	
	//Draw Projector Line
	//printf("x=%f,y=%f",((array[0][0]+array[0][2])*(0.5)),((array[0][1]+array[0][3])*(0.5)));
	for(i=0;i<number;i++)
	{
		float mid1=array[i][0]; float mid3=array[i][2]; float mid4=array[i][3];float rays=array[i][5];
		float mid2=array[i][1];
		float a=array[i][2]-mid1;
		float b=array[i][3]-mid2;
		float x1=array[i][0]-mid1;	float y1=array[i][1]-mid2;

		double theta = atan2(b,a)*180/PI;
		//	double fp=atan2(b,a);
		//	float x2=array[i][2]-mid1;	float y2=array[i][3]-mid2;
		//	float x2=a*cos(fp)-b*sin(fp);
		//	float y2=a*sin(fp)+b*cos(fp);
		float x2=sqrt((a*a) + (b*b));
		float y2=0;
		dist=array[i][4];
		points=array[i][5];
		glPushMatrix();
		glTranslatef(mid1,mid2,0.0);
		glRotatef(theta,0.0,0.0,1.0);
		glColor3f(0.0f, 1.0f, 0.0f);
		drawprojector(x1,y1,x2,y2,array[i][8],array[i][9],array[i][10]);	
		//find the coordinates of the dist point
		glPopMatrix();
		glPushMatrix();
		float cent1=(array[i][0]+array[i][2])*(0.5);
		float cent2=(array[i][1]+array[i][3])*(0.5);
		//	float m1=mid1-cent1;float n1=mid2-cent2;
		float m2=array[i][2]-cent1;float n2=array[i][3]-cent2;
		glTranslatef(cent1,cent2,0.0);
		double alpha = atan2(n2,m2);
		float c1=dist*sin(alpha)+cent1;float c2=(-1)*dist*cos(alpha)+cent2;
		glPopMatrix();
		glPushMatrix();
		array[i][6]=c1;array[i][7]=c2;
		drawrays(c1,c2,mid1,mid2,mid3,mid4,rays);


	}
	/*   
	// Draw Ball
	glPushMatrix();
	glTranslatef(ball_x, ball_y, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	drawBall(ball_rad);
	glPopMatrix();

	// Draw Triangle
	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawTriangle();*/
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {

	/*  // Handle ball collisions with box
	    if(ball_x + ball_rad > box_len/2 || ball_x - ball_rad < -box_len/2)
	    ball_velx *= -1;
	    if(ball_y + ball_rad > box_len/2 || ball_y - ball_rad < -box_len/2)
	    ball_vely *= -1;

	// Update position of ball
	ball_x += ball_velx;
	ball_y += ball_vely;
	 */
	update_count=update_count + 1;
	if( random_v == 1)
	{
		int j;
		int pp=rand()%4;
		if(pp==0)
		{
			for(j=0;j<num_blocks;j++)
			{	if(blocks[j][0]>=(world_width)/2 || blocks[j][2]>=(world_width)/2)
				{	blocks[j][0]=blocks[j][0]-(world_width)/2;	
					blocks[j][2]=blocks[j][2]-(world_width)/2;	}
				else{
					blocks[j][0] += 0.5;
					blocks[j][2] += 0.5;}
			}

			for(j=0;j<num_mirrors;j++)
			{
				if(mirrors[j][0]<=(-world_width)/2 || mirrors[j][2]<=(-world_width)/2)
				{	mirrors[j][0]=mirrors[j][0]+(world_width)/2;	
					mirrors[j][2]=mirrors[j][2]+(world_width)/2;	}
				else{

					mirrors[j][0] -= 0.5;
					mirrors[j][2] -= 0.5;}
			}

			for(j=0;j<number;j++)
			{
				if(array[j][0]<=(-world_width)/2 || array[j][2]<=(-world_width)/2 || array[j][6]<=(-world_width)/2)
				{	array[j][0]=array[j][0]+(world_width)/2;	
					array[j][2]=array[j][2]+(world_width)/2;	}
				else{


					array[j][0] += 0.5;
					array[j][2] += 0.5;}
			}


		}
		if(pp==1)
		{
			for(j=0;j<num_blocks;j++)
			{
				if(blocks[j][0]<=(-world_width)/2 || blocks[j][2]<=(-world_width)/2)
				{	blocks[j][0]=blocks[j][0]+(world_width)/2;	
					blocks[j][2]=blocks[j][2]+(world_width)/2;	}
				else{
					blocks[j][0] -= 0.5;
					blocks[j][2] -= 0.5;}
			}

			for(j=0;j<num_mirrors;j++)
			{
				if(mirrors[j][0]>=(world_width)/2 || mirrors[j][2]>=(world_width)/2)
				{	mirrors[j][0]=mirrors[j][0]-(world_width)/2;	
					mirrors[j][2]=mirrors[j][2]-(world_width)/2;	}
				else{
					mirrors[j][0] += 0.5;
					mirrors[j][2] += 0.5;}
			}

			for(j=0;j<number;j++)
			{
				if(array[j][0]>=(world_width)/2 || array[j][2]>=(world_width)/2 || array[j][6]>=(world_width)/2)
				{	array[j][0]=array[j][0]-(world_width)/2;	
					array[j][2]=array[j][2]-(world_width)/2;	}
				else{
					array[j][0] += 0.5;
					array[j][2] += 0.5;}
			}

		}
		if(pp==2)
		{
			for(j=0;j<num_blocks;j++)
			{
				if(blocks[j][1]>=(world_height)/2 || blocks[j][3]>=(world_height)/2)
				{	blocks[j][1]=blocks[j][1]-(world_height)/2;	
					blocks[j][3]=blocks[j][3]-(world_height)/2;	}
				{
					blocks[j][1] += 0.5;
					blocks[j][3] += 0.5;}
			}

			for(j=0;j<num_mirrors;j++)
			{
				if(mirrors[j][1]<=(-world_height)/2 || mirrors[j][3]<=(-world_height)/2)
				{	mirrors[j][1]=mirrors[j][1]+(world_height)/2;	
					mirrors[j][3]=mirrors[j][3]+(world_height)/2;	}
				else
				{
					mirrors[j][1] -= 0.5;
					mirrors[j][3] -= 0.5;}
			}

			for(j=0;j<number;j++)
			{
				if(array[j][1]<=(-world_height)/2 || array[j][3]<=(-world_height)/2 || array[j][7]<=(-world_height)/2)
				{	array[j][3]=array[j][3]+(world_height)/2;	
					array[j][1]=array[j][1]+(world_height)/2;	}
				else{

					array[j][1] -= 0.5;
					array[j][3] -= 0.5;}
			}

		}
		if(pp==3)
		{
			for(j=0;j<num_blocks;j++)
			{
				if(blocks[j][1]<=(-world_height)/2 || blocks[j][3]<=(-world_height)/2)
				{	blocks[j][1]=blocks[j][1]+(world_height)/2;	
					blocks[j][3]=blocks[j][3]+(world_height)/2;	}
				{
					blocks[j][1] -= 0.5;
					blocks[j][3] -= 0.5;}
			}

			for(j=0;j<num_mirrors;j++)
			{
				if(mirrors[j][1]>=(world_height)/2 || mirrors[j][3]>=(world_height)/2)
				{	mirrors[j][1]=mirrors[j][1]-(world_height)/2;	
					mirrors[j][3]=mirrors[j][3]-(world_height)/2;	}
				else
				{
					mirrors[j][1] += 0.5;
					mirrors[j][3] += 0.5;}
			}

			for(j=0;j<number;j++)
			{
				if(array[j][1]>=(world_height)/2 || array[j][3]>=(world_height)/2 || array[j][7]>=(world_height)/2)
				{	array[j][1]=array[j][1]-(world_height)/2;	
					array[j][3]=array[j][3]-(world_height)/2;	}
				else{

					array[j][1] += 0.5;
					array[j][3] += 0.5;}
			}

		}
	}
	glutTimerFunc(10, update, 0);
}

void drawBox(float window_width,float window_height) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex2f(-window_width / 2, -window_height / 2);
	glVertex2f(window_width / 2, -window_height / 2);
	glVertex2f(window_width / 2, window_height / 2);
	glVertex2f(-window_width / 2, window_height / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawprojector(float x1,float y1,float x2,float y2,float cx,float cy,float cz)
{
	glBegin(GL_LINES);
	//	printf("x1=%f, y1=%f,x2=%f,y2=%f",x1,y1,x2,y2);
	glColor3f(cx,cy,cz);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	/*	glBegin(GL_POINTS);		//draw point
		glColor3f(1.0f,0.0,0.0);
		glVertex2f((x1+x2)*(0.5),dist*(-1));
		glEnd();
	 */}
void drawrays(float c1,float c2,float x1,float y1,float x2,float y2,float numb)
{	

	glBegin(GL_POINTS);		//draw point
	glColor3f(1.0f,0.0,0.0);
	glVertex2f(c1,c2);
	glEnd();
	int i,cc=0;
	float kkk=update_count % 10;
	if(kkk==0 || kkk==2 || kkk==4 || kkk==1 || kkk==3)
	{
		cc=1;
	}
				
	for(i=0;i<numb;i++)
	{
		int m=i;
		int n=numb-i-1;
		float p1=(m*x1+n*x2)/(m+n);float p2=(m*y1+n*y2)/(m+n);
		//	glTranslatef(c1, c2, 0);
		p1=p1-c1;p2=p2-c2;
		double angle = atan2(p2,p1);
		//	glPopMatrix();
		//	glPushMatrix();
		float width=(world_width)*(0.5);
		float height=(world_height)*(0.5);
		float v1=c1,v2=c2;
		//float pointx=v1+ 1*cos(angle);
		//float pointy=v2 + 1*sin(angle);
		int b=0;int rr=0;
		float t1,t2;
		float m_x,m_y,m_z;
		if(i<numb/5)
		{
			m_x=1;m_y=0;m_z=0;
		}
		if(numb/5<=i && i<(numb/5)*2)
		{
			m_x=0.5;m_y=0.5;m_z=0;
		}

		if((numb/5)*2<=i && i<(numb/5)*3)
		{
			m_x=0;m_y=1;m_z=0;
		}

		if((numb/5)*3<=i && i<(numb/5)*4)
		{
			m_x=0;m_y=0.5;m_z=0.5;
		}

		if((numb/5)*4<=i)
		{
			m_x=0;m_y=0;m_z=1;
		}




		//		while(1)
		for(int itr=0;itr<1500;itr++)
		{
			float mirror_angle,xx,yy,h1,h2,h3,h4;
			t1=v1+ 0.5*cos(angle);
			t2=v2 + 0.5*sin(angle);
			b=0;
			rr=0;
			for(int itt=0;itt<num_blocks;itt++)
			{
				float x1=blocks[itt][0];float y1=blocks[itt][1];
				float x2=blocks[itt][2];float y2=blocks[itt][3];
				float x3=v1;float y3=v2;
				float x4=t1;float y4=t2;
				//point of intersection with block

				xx=(((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				yy=(((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				float d,d1,r,r1;
				d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*(0.5);
				d1=sqrt(((x1+x2)*(0.5)-xx)*((x1+x2)*0.5-xx)+((y1+y2)*0.5-yy)*((y1+y2)*0.5-yy));
				r=sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))*(0.5);
				r1=sqrt(((x4+x3)*(0.5)-xx)*((x4+x3)*0.5-xx)+((y4+y3)*0.5-yy)*((y4+y3)*0.5-yy));
				if(d>=d1 && r>=r1)
				{

					b=1;
					break;
				}

			}	
			if(b==1)
			{
				break;
			}
			cc=cc+1;
			for(int itt=0;itt<num_mirrors;itt++)
			{
				float x1=mirrors[itt][0];float y1=mirrors[itt][1];
				float x2=mirrors[itt][2];float y2=mirrors[itt][3];
				float x3=v1;float y3=v2;
				float x4=t1;float y4=t2;
				mirror_angle=atan2(y2-y1,x2-x1);
				//point of intersection with block

				xx=(((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				yy=(((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				float d,d1,r,r1;
				d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*(0.5);
				d1=sqrt(((x1+x2)*(0.5)-xx)*((x1+x2)*0.5-xx)+((y1+y2)*0.5-yy)*((y1+y2)*0.5-yy));
				r=sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))*(0.5);
				r1=sqrt(((x4+x3)*(0.5)-xx)*((x4+x3)*0.5-xx)+((y4+y3)*0.5-yy)*((y4+y3)*0.5-yy));
				h1=v1-x1;h2=v2-y1;h3=x2-x1; h4=y2-y1; 
				if(d>=d1 && r>=r1)
				{

					rr=1;
					break;
				}

			}
			if(rr==1)
			{
				angle= + (2*mirror_angle) - atan2(t2-v2,t1-v1);
				v1=xx+ 0.5*cos(angle);
				v2=yy + 0.5*sin(angle);
				if((h1*h4)-(h2*h3)<0)
				{
					break;	
				}
				

				continue;
			}
		
			if(t1<-width || t1>width || t2<-height || t2>height)
			{
				break;
			}
			if(light ==1)
			{
				if(cc%2==0)
				{
			
					glBegin(GL_LINES);
					glColor3f(m_x,m_y,m_z);
					glVertex2f(v1,v2);
					glVertex2f(t1,t2);
					glEnd();
					v1=t1;v2=t2;

				}
			}
			else{
			glBegin(GL_LINES);
			glColor3f(m_x,m_y,m_z);
			glVertex2f(v1,v2);
			glVertex2f(t1,t2);
			glEnd();
			v1=t1;v2=t2;}
			v1=t1;v2=t2;

		}

	}
}

/*
   float d,d1,d2,r,r1,r2;
   d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*(0.5);
   d1=sqrt(((x1+x2)*(0.5)-xx)*((x1+x2)*0.5-xx)+((y1+y2)*0.5-yy)*((y1+y2)*0.5-yy));
   r=sqrt(((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))*(0.5));
   r1=sqrt((((x4+x3)*(0.5)-xx)*((x4+x3)*0.5-xx)+((y4+y3)*0.5-yy)*((y4+y3)*0.5-yy)));
   if(d>=d1 && r>=r1)
   {

   b=1;
   break;
   }
	for(int jt=0;jt<num_mirrors;jt++)
			{
				float x1=mirrors[jt][0];float y1=mirrors[jt][1];
				float x2=mirrors[jt][2];float y2=mirrors[jt][3];
				float x3=v1;float y3=v2;
				float x4=t1;float y4=t2;
				//point of intersection with block
					mirror_angle=atan2(y2-y1,x2-x1);
	
				float xx=(((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				float yy=(((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)));
				float d,d1,d2,r,r1,r2;
				d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*(0.5);
				d1=sqrt(((x1+x2)*(0.5)-xx)*((x1+x2)*0.5-xx)+((y1+y2)*0.5-yy)*((y1+y2)*0.5-yy));
				r=sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))*(0.5);
				r1=sqrt(((x4+x3)*(0.5)-xx)*((x4+x3)*0.5-xx)+((y4+y3)*0.5-yy)*((y4+y3)*0.5-yy));
				if(d>=d1 && r>=r1)
				{
					rr=1;
		//			rays=atan2(y4-y3,x4-x3);
			//		angle= PI + (2*mirror_angle) -rays;

		//			t1=v1+ 0.5*cos(angle);
		//			t2=v2 + 0.5*sin(angle);
		//			v1=xx;v2=yy;
				 float h1=t1-x1;float h2=t2-y1;float h3=x2-x1;float h4=y2-y1; 
					if((h1*h4)-(h2*h3)>0)
					{
						angle=angle + PI;
						t1=v1+ 0.5*cos(angle);
						t2=v2 + 0.5*sin(angle);
					
					}
					else
					{
						rr=0;
						b=1;
					}*/
/*
					break;
				}

			}
			



   float a= y1 - y2;
   float b= x2 - x1;
   float c= (y2 - y1) * x1 - (x2 - x1) * y1;

   float dd= y3 - y4;
   float e= x4 - x3;
   float f= (y4 - y3) * x3 - (x4 - x3) * y3;

   if(-dd*b + a*e==0 || a==0)
   continue;
 */



/*

				float x=blocks[i][2]-blocks[i][0];
				float y=blocks[i][3]-blocks[i][1];
				float m1=blocks[i][0]-xx;
				float n1=blocks[i][1]-yy;
				float m2=blocks[i][2]-xx;
				float n2=blocks[i][3]-yy;
				float d,k1,k2,d1,d2;
				d=sqrt(x*x + y*y);k1=sqrt(m1*m1 + n1*n1);k2=sqrt(m2*m2 + n2*n2);
				if(d==k1+k2)
				{
					glBegin(GL_LINES);
					glColor3f(1.0f,1.0,0.0);
					glVertex2f(c1,c2);
					glVertex2f(xx,yy);
					glEnd();
					b=1;
					break;
			
				}*/
			



			/*	float d,d1,d2,r,r1,r2;
				d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*(0.5);
				d1=sqrt(((x1+x2)*(0.5)-xx)*((x1+x2)*0.5-xx)+((y1+y2)*0.5-yy)*((y1+y2)*0.5-yy));
				r=sqrt(((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3))*(0.5));
				r1=sqrt((((x4+x3)*(0.5)-xx)*((x4+x3)*0.5-xx)+((y4+y3)*0.5-yy)*((y4+y3)*0.5-yy)));
				if(d>=d1 && r>=r1)
				{
				
					b=1;
					break;
				}
				



				float a= y1 - y2;
				float b= x2 - x1;
				float c= (y2 - y1) * x1 - (x2 - x1) * y1;

				float dd= y3 - y4;
				float e= x4 - x3;
				float f= (y4 - y3) * x3 - (x4 - x3) * y3;

				if(-dd*b + a*e==0 || a==0)
					continue;a
*/
/*				float y = (c*d - f*a) / (-d*b + a*e);
				float x = (-b *y - c) / a;
		//		printf("x=%f,y=%f\n",x,y);

				if((x1<=x && x<=x2 && y1<=y && y<=y2) || (x1<=x && x<=x2 && y2<=y && y<=y1) ||(x2<=x && x<=x1 && y1<=y && y<=y2) ||(x2<=x && x<=x1 && y2<=y && y<=y1))
				{
					printf("x=%f,y=%f\n",x,y);
					b=1;
					break;
				}



				if(t1>=x && t2>=y)
				{
					b=1;
					printf("hel\n");
					break;
				}*/
			


			
//			printf("lo\n");
//				printf("b=%d\n",b);
//			printf("b=%d\n",b);
		/*
   void drawBall(float rad) {

   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++) {
   glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   }
   glEnd();
   }

   void drawTriangle() {

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 0.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, 0.0f);
   glEnd();
   }
 */
// Initializing some openGL 3D rendering options
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(15, 15, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, resolution*(-1), 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void drawblock(float x1,float y1,float x2,float y2,float cx,float cy,float cz)
{
	glBegin(GL_LINES);

	glColor3f(cx,cy,cz);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}
void drawmirror(float x1,float y1,float x2,float y2,float cx,float cy,float cz)
{
	glBegin(GL_LINES);
	glColor3f(cx,cy,cz);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}
void handleKeypress1(unsigned char key, int x, int y) {


	if(key == 27 || key == 'q')
	{


		freopen("output.txt","w",stdout);
		printf("# All numbers are in floating point except for number of items\n");
		printf("%f %f                                           # width (x) and height (y) of the world\n",world_width,world_height);
		printf("%d                                              # number of Projectors\n",number);
		int i;
		for(i=0;i<number;i++)
		{
			printf("%f ",array[i][0]);
			printf("%f ",array[i][1]);
			printf("%f ",array[i][2]);
			printf("%f                           		 # Project %d line: x1 y1 x2 y2\n",array[i][3],i+1);

			printf("%f                                       # Distance(d) to the point light source\n",array[i][4]);

			printf("%f                                       # Number of pixels in the Projector\n",array[i][5]);

		}
		printf("%d                                               # number of Blocks\n",num_blocks);
		for(i=0;i<num_blocks;i++)
		{
			printf("%f ",blocks[i][0]);
			printf("%f ",blocks[i][1]);
			printf("%f ",blocks[i][2]);
			printf("%f					 # Block %d: x1 y1 x2 y2\n",blocks[i][3],i+1);
		}
		printf("%d						 # number of Mirrors\n",num_mirrors);
		for(i=0;i<num_mirrors;i++)
		{
			printf("%f ",mirrors[i][0]);
			printf("%f ",mirrors[i][1]);
			printf("%f ",mirrors[i][2]);
			printf("%f					 # Mirror %d: x1 y1 x2 y2\n",mirrors[i][3],i+1);
		}



		exit(0);
	}

	if(key == 'g')
	{
		cal=cal+1;
		if(cal%2!=0)
		{
			mouse_motion=1;
		}
		else
		{
			mouse_motion=0;
		}

	}



	if(key == 't')
	{
		call=call+1;
		if(call%2!=0)
		{
			light=1;
		}
		else
		{
			light=0;
		}

	}


	if(key == 'z')
	{
		countz=countz+1;
		if(countz%2!=0)
		{
			random_v=1;
		}
		else
		{
			random_v=0;
		}

	}

	if (key == 'c') 
	{
		int i,j;
		int total=number+num_blocks+num_mirrors;
		for(i=0;i<total;i++)
		{
			for(j=0;j<number;j++)
		   {

			   array[j][8]=0;
			   array[j][9]=1;
			   array[j][10]=0;
			   array[j][11]=0;
		   }
		   for(j=0;j<num_blocks;j++)
		   {

			   blocks[j][8]=1;
			   blocks[j][9]=0;
			   blocks[j][10]=0;
			   blocks[j][11]=0;
		   }
		    for(j=0;j<num_mirrors;j++)
		   {

			   mirrors[j][8]=1;
			   mirrors[j][9]=0;
			   mirrors[j][10]=1;
			   mirrors[j][11]=0;
		   }
		  
		   int k=count%total;
		   if(k<number)
		   {
			   array[k][8]=1;
			   array[k][9]=1;
			   array[k][10]=1;
			   array[k][11]=1;
		   }
		   if(number<=k && k<number+num_blocks)
		   {
			   blocks[k-number][8]=1;
			   blocks[k-number][9]=1;
			   blocks[k-number][10]=1;
			   blocks[k-number][11]=1;
		   }
		   if(k>=number+num_blocks)
		   {
			   mirrors[k-(number+num_blocks)][8]=1;
			   mirrors[k-(number+num_blocks)][9]=1;
			   mirrors[k-(number+num_blocks)][10]=1;
			   mirrors[k-(number+num_blocks)][11]=1;
		   }

		}
		count=count+1;

	}
	if(key =='f')
	{
		a=a*2;
		ddd=ddd*2;
	}
	if(key =='s')
	{
		a=a/2;
		ddd=ddd/2;
	}
	if(key =='r')
	{
		int j;
		for(j=0;j<number;j++)
		{
			if(array[j][11]==1)
			{
				float kk1=array[j][2] -array[j][0];
				float kk2=array[j][3] -array[j][1];
				array[j][2]=(kk1*cos(a) - kk2*sin(a)) + array[j][0];
				array[j][3]=(kk1*sin(a) + kk2*cos(a)) + array[j][1];
				break;
			}
		}
		for(j=0;j<num_blocks;j++)
		{
			if(blocks[j][11]==1)
			{
				float kk1=blocks[j][2] -blocks[j][0];
				float kk2=blocks[j][3] -blocks[j][1];
				blocks[j][2]=kk1*cos(a) - kk2*sin(a) + blocks[j][0];
				blocks[j][3]=kk1*sin(a) + kk2*cos(a) + blocks[j][1];

				break;
			}
		}
		for(j=0;j<num_mirrors;j++)
		{
			if(mirrors[j][11]==1)
			{
				float kk1=mirrors[j][2] -mirrors[j][0];
				float kk2=mirrors[j][3] -mirrors[j][1];
				mirrors[j][2]=kk1*cos(a) - kk2*sin(a) + mirrors[j][0];
				mirrors[j][3]=kk1*sin(a) + kk2*cos(a) + mirrors[j][1];

				break;
			}
		}

	}
	if(key =='l')
	{
		int j;
		for(j=0;j<number;j++)
		{
			if(array[j][11]==1)
			{
			//	a=-a;
				float kk1=array[j][2] -array[j][0];
				float kk2=array[j][3] -array[j][1];
				array[j][2]=(kk1*cos(-a) - kk2*sin(-a)) + array[j][0];
				array[j][3]=(kk1*sin(-a) + kk2*cos(-a)) + array[j][1];
			//	a=-a;
				break;
			}
		}
		for(j=0;j<num_blocks;j++)
		{
			if(blocks[j][11]==1)
			{
				a=-a;
				float kk1=blocks[j][2] -blocks[j][0];
				float kk2=blocks[j][3] -blocks[j][1];
				blocks[j][2]=kk1*cos(a) - kk2*sin(a) + blocks[j][0];
				blocks[j][3]=kk1*sin(a) + kk2*cos(a) + blocks[j][1];
				a=-a;
				break;
			}
		}
		for(j=0;j<num_mirrors;j++)
		{
			if(mirrors[j][11]==1)
			{
				a=-a;
				float kk1=mirrors[j][2] -mirrors[j][0];
				float kk2=mirrors[j][3] -mirrors[j][1];
				mirrors[j][2]=kk1*cos(a) - kk2*sin(a) + mirrors[j][0];
				mirrors[j][3]=kk1*sin(a) + kk2*cos(a) + mirrors[j][1];
				a=-a;
				break;
			}
		}

	}


}  

void handleKeypress2(int key, int x, int y) 
{

	int j;
	for(j=0;j<number;j++)
	{
		if(array[j][11]==1)
		{

			if (key == GLUT_KEY_LEFT)
			{
				if(array[j][0]<=(-world_width)/2 || array[j][2]<=(-world_width)/2 || array[j][6]<=(-world_width)/2)
				{
					break;
				}
				else
				{	
				array[j][0] -= ddd;
				array[j][2] -= ddd;
				}
			}
			if (key == GLUT_KEY_RIGHT)
			{
				if(array[j][0]>=(world_width)/2 || array[j][2]>=(world_width)/2 || array[j][6]>=(world_width)/2)
				{break;}
				else{
				array[j][0] += ddd;
				array[j][2] += ddd;}
			}
			if (key == GLUT_KEY_UP)
			{
				if(array[j][1]>=(world_height)/2 || array[j][3]>=(world_height)/2 || array[j][7]>=(world_height)/2)
				{
					break;
				}else{
				array[j][1] += ddd;
				array[j][3] += ddd;}
			}
			if (key == GLUT_KEY_DOWN)
			{	
				if(array[j][1]<=(-world_height)/2 || array[j][3]<=(-world_height)/2 || array[j][7]<=(-world_height)/2)
				{break;}
				else{
				array[j][1] -= ddd;
				array[j][3] -= ddd;}
			}
		
			break;
		}
	}
	for(j=0;j<num_blocks;j++)
	{
		if(blocks[j][11]==1)
		{
			if (key == GLUT_KEY_LEFT)
			{
				if(blocks[j][0]<=(-world_width)/2 || blocks[j][2]<=(-world_width)/2)
				{
					break;
				}
				else{
				blocks[j][0] -= ddd;
				blocks[j][2] -= ddd;}
			}
			if (key == GLUT_KEY_RIGHT)
			{
				if(blocks[j][0]>=(world_width)/2 || blocks[j][2]>=(world_width)/2)
				{break;}
				else{
				blocks[j][0] += ddd;
				blocks[j][2] += ddd;}
			}
			if (key == GLUT_KEY_UP)
			{
				if(blocks[j][1]>=(world_height)/2 || blocks[j][3]>=(world_height)/2)
				{
					break;
				}else{
				
				blocks[j][1] += ddd;
				blocks[j][3] += ddd;}
			}
			if (key == GLUT_KEY_DOWN)
			{
				if(blocks[j][1]<=(-world_height)/2 || blocks[j][3]<=(-world_height)/2)
				{break;}
				else{
				blocks[j][1] -= ddd;
				blocks[j][3] -= ddd;}
			}
	
			break;
			break;
		}
	}
	for(j=0;j<num_mirrors;j++)
	{
		if(mirrors[j][11]==1)
		{
			if (key == GLUT_KEY_LEFT)
			{
				if(mirrors[j][0]<=(-world_width)/2 || mirrors[j][2]<=(-world_width)/2)
				{
					break;
				}
				else{
				mirrors[j][0] -= ddd;
				mirrors[j][2] -= ddd;}
			}
			if (key == GLUT_KEY_RIGHT)
			{
				if(mirrors[j][0]>=(world_width)/2 || mirrors[j][2]>=(world_width)/2)
				{break;}
				else{
				mirrors[j][0] += ddd;
				mirrors[j][2] += ddd;}
			}
			if (key == GLUT_KEY_UP)
			{
				if(mirrors[j][1]>=(world_height)/2 || mirrors[j][3]>=(world_height)/2)
				{
					break;
				}else{
			
				mirrors[j][1] += ddd;
				mirrors[j][3] += ddd;}
			}
			if (key == GLUT_KEY_DOWN)
			{	
				if(mirrors[j][1]<=(-world_height)/2 || mirrors[j][3]<=(-world_height)/2)
				{break;}
				else
				{
				mirrors[j][1] -= ddd;
				mirrors[j][3] -= ddd;}
			}
			break;
		}
	}

}
/*
   void handleMouseclick(int button, int state, int x, int y) {

   if (state == GLUT_DOWN)
   {
   if (button == GLUT_LEFT_BUTTON)
   theta += 15;
   else if (button == GLUT_RIGHT_BUTTON)
   theta -= 15;
   }
   }*/
