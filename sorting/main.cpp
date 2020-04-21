#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL\glut.h>
#include<time.h>
#define SORT_NO 6	// Number of sorting algorithms
#define MAX 1000		// Number of values in the array
#define SPEED 1500	// Speed of sorting, must be greater than n always
int a[MAX];			// Array
int swapflag=0;		// Flag to check if swapping has occured
int i=0,j=0;		// To iterate through the array
int k=0;			// To Switch from Welcome screen to Main Screen
int sorting=0;		// 1 if Sorted
char *sort_string[]={"Bubble Sort","Selection Sort","Insertion Sort","Ripple Sort","Merge Sort","Quick Sort"};
int sort_count=0;
int r=1,g=0,b=0;    //RGB color
int n=50;           //current size

void merge(int Firstindex, int m, int Lastindex);//declaration

// Function to display text on screen char by char
void bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

// Function to integer to string
void int_str(int rad,char r[])
{
	itoa(rad,r,10);
}

// Return 1 if not sorted
int notsorted(){
	int q;
	for(q=0;q<n-1;q++)
	{
		if(a[q]>a[q+1])
			return 1;
	}
	return 0;
}
// Function to add delay using time.h
void delay()
{
    clock_t goal =clock();
    int d=SPEED/(n*2);
    if(k==0)
        d=50;
    if(!notsorted())
        d=MAX/(n*2);
    while (goal+(d) > clock())
        ;
}

void display_text()
{
	glColor3f(1,1,0);
	bitmap_output(200, 690, "SORTING ALGORITHM VISUALIZER",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(195, 685);
		glVertex2f(490, 685);
	glEnd();

	// other text small font
	glColor3f(1,1,1);
	bitmap_output(10, 660, "This program sorts a random set of numbers in ascending order displaying them graphically as ",GLUT_BITMAP_9_BY_15);
	bitmap_output(10, 640, "bars with varying height",GLUT_BITMAP_9_BY_15);

        glColor3f(0,0,1);
		bitmap_output(10, 610, "MENU",GLUT_BITMAP_9_BY_15);
		glBegin(GL_LINE_LOOP);
		glVertex2f(10, 605);
		glVertex2f(35, 605);
	glEnd();
	glColor3f(1,1,0);
		bitmap_output(10, 580, "Press s to SORT",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 560, "Select the sort algorithm using up or down arrow key",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 540, "Press r to RANDOMISE",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 520, "Press + or - to vary size",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 500, "Esc to QUIT",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 480, "Selected sort: ",GLUT_BITMAP_9_BY_15);
		bitmap_output(150, 480, *(sort_string+sort_count),GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 460, "Number of Elements: ",GLUT_BITMAP_9_BY_15);
		char text[10];
		int_str(n,text);
		bitmap_output(150, 460, text,GLUT_BITMAP_9_BY_15);

        glColor3f(0,0,1);
		bitmap_output(400, 610, "Various Sorting Algorithm:",GLUT_BITMAP_9_BY_15);
		glBegin(GL_LINES);
		glVertex2f(400, 605);
		glVertex2f(560, 605);
        glEnd();
        glColor3f(1,1,0);
		for(int i=0;i<SORT_NO;i++)
            bitmap_output(400, 580-(i*20), *(sort_string+i),GLUT_BITMAP_9_BY_15);
        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
		glVertex2f(390, 590-(sort_count*20));
		glVertex2f(390, 579-(sort_count*20));
		glVertex2f(395,585-(sort_count*20));
        glEnd();

}

void front()
{
	glColor3f(1,1,0);
	bitmap_output(300, 570, "WELCOME!",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(295, 560);
		glVertex2f(395, 560);
	glEnd();
	bitmap_output(330, 520, "TO",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(325, 510);
		glVertex2f(360, 510);
	glEnd();

	bitmap_output(200, 470, "SORTING ALGORITHM VISUALIZER",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(195, 460);
		glVertex2f(490, 460);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glVertex2f(510,120.0);glVertex2f(510,170);glVertex2f(680,170);glVertex2f(680,120.0);
	glEnd();
	glColor3f(0,0,0);
	bitmap_output(520, 140, "Press Enter to continue....",GLUT_BITMAP_HELVETICA_18);
	int arr[30];
	int arrlen=30;
	for(int i=0;i<arrlen;i++){
		arr[i]=rand()%200+1;
	}
	for(int ix=0;ix<arrlen;ix++)
		{
			glColor3f(r,g,b);
			glBegin(GL_POLYGON);
				glVertex2f(100+(300/(arrlen))*ix,120);
				glVertex2f(100+(300/(arrlen))*(ix+1),120);
				glVertex2f(100+(300/(arrlen))*(ix+1),120+arr[ix]);
				glVertex2f(100+(300/(arrlen))*ix,120+arr[ix]);
			glEnd();

			glColor3f(0,0,0);
			glBegin(GL_LINE_LOOP); // to change the type of bar graph
				glVertex2f(100+(300/(arrlen))*ix,120);
				glVertex2f(100+(300/(arrlen))*(ix+1),120);
				glVertex2f(100+(300/(arrlen))*(ix+1),120+arr[ix]);
				glVertex2f(100+(300/(arrlen))*ix,120+arr[ix]);
			glEnd();
		}
		delay();
		glFlush();
}

void Initialize() {
	int temp1;
    r=1,g=0,b=0;
	// Reset the array
	for(temp1=0;temp1<n;temp1++){
		a[temp1]=temp1+1;
	}
	for(int i=0;i<n;i++)
    {
        int r=rand()%n;
        int temp=a[i];
        a[i]=a[r];
        a[r]=temp;
    }

	// Reset all values
	i=j=0;

	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 720,0,799);
}



// Main function for display
void display()
{
	int ix,temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if(k==0)
		front();
	else{
		display_text();
		char text[10];
		for(ix=0;ix<n;ix++)
		{
			glColor3f(r,g,b);
			glBegin(GL_POLYGON);
				glVertex2f(10+(700.0/(n+1))*ix,50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50+float(a[ix])/n*100*4);
				glVertex2f(10+(700.0/(n+1))*ix,50+float(a[ix])/n*100*4);
			glEnd();

            if(n<=270)
            {
			glColor3f(0,0,0);
			glBegin(GL_LINE_LOOP); // to change the type of bar graph
				glVertex2f(10+(700.0/(n+1))*ix,50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50+float(a[ix])/n*100*4);
				glVertex2f(10+(700.0/(n+1))*ix,50+float(a[ix])/n*100*4);
			glEnd();
            }

			int_str(a[ix],text);
			glColor3f(1,1,1);
			if(n<=50)
			bitmap_output(5+(700.0/(n+1))*(2*ix+1)/2, 35, text,GLUT_BITMAP_8_BY_13);
		}

		if(swapflag || sorting==0)
		{
			glColor3f(0,0,1);
			glBegin(GL_POLYGON);
				glVertex2f(10+(700.0/(n+1))*j,50);
				glVertex2f(10+(700.0/(n+1))*(j+1),50);
				glVertex2f(10+(700.0/(n+1))*(j+1),50+float(a[j])/n*100*4);
				glVertex2f(10+(700.0/(n+1))*j,50+float(a[j])/n*100*4);
			glEnd();
			swapflag=0;
		}
	}
	glFlush();
}

void traverse()
{
    if(!notsorted())
        {
            sorting=0;
            for(int ix=0;ix<n;ix++)
		{
            r=0,g=1,b=0;
		    delay();
			glColor3f(0,1,0);
			glBegin(GL_POLYGON); // to change the type of bar graph
				glVertex2f(10+(700.0/(n+1))*ix,50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50+float(a[ix])/n*100*4);
				glVertex2f(10+(700.0/(n+1))*ix,50+float(a[ix])/n*100*4);
			glEnd();

            if(n<=270)
            {
			glColor3f(0,0,0);
			glBegin(GL_LINE_LOOP); // border for the bar graph
				glVertex2f(10+(700.0/(n+1))*ix,50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50);
				glVertex2f(10+(700.0/(n+1))*(ix+1),50+float(a[ix])/n*100*4);
				glVertex2f(10+(700.0/(n+1))*ix,50+float(a[ix])/n*100*4);
			glEnd();
            }
			glFlush();

        }
        }
}
void mergeSort(int Firstindex, int Lastindex)
{
    if (Firstindex < Lastindex)
    {

        int m = Firstindex + (Lastindex - Firstindex)/2;


        mergeSort(Firstindex, m);
        mergeSort(m+1, Lastindex);

        merge(Firstindex, m, Lastindex);
    }
}

void merge(int Firstindex, int m, int Lastindex)
{
    int x;
    int y;
    int z;
    int sub1 = m - Firstindex + 1;
    int sub2 =  Lastindex - m;


    int First[sub1];  //temp array

    int Second[sub2];


    for (x = 0; x < sub1; x++) // copying data to temp arrays
        First[x] = a[Firstindex + x];
    for (y = 0; y < sub2; y++)
        Second[y] = a[m + 1+ y];


    x = 0;
    y = 0;
    j = Firstindex;
    while (x < sub1 && y < sub2)
    {
        if (First[x] <= Second[y])
        {swapflag=1;
            a[j] = First[x];
            x++;

        }
        else
        {swapflag=1;
            a[j] = Second[y];
            y++;

        }
        j++;
        delay();
        display();
    }
    while (x < sub1)
    {   swapflag=1;
        a[j] = First[x];
        x++;
        j++;
        delay();
        display();

    }
    while (y < sub2)
    {   swapflag=1;
        a[j] = Second[y];
        y++;
        j++;
        delay();
        display();

    }
}

// Insertion Sort
void insertionsort()
{
    for (i = 1; i < n; i++)
  {
    int key = a[i];
     j = i - 1;
    while (key < a[j] && j >= 0)
    {   swapflag=1;
      a[j + 1] = a[j];
      --j;
      delay();
      display();
    }
    a[j + 1] = key;
  }
	i=j=0;
}

// Selection Sort
void selectionsort()
{
	int temp,min,pos;

	while(notsorted())
	{
	    for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    { swapflag=1;
      if (a[j] < a[min])
        min = j;
        delay();
        display();
    }
    temp=a[min];
    a[min]=a[i];
    a[i]=temp;
    delay();
    display();
  }

	}
	i=j=0;
}

//Bubble Sort
void bubblesort()
{
	int temp;
	while(notsorted())
	{
		 for (i = 0; i < n - 1; ++i)
    {
            for (j = 0; j < n - i - 1; ++j)
        {
			if(a[j]>a[j+1])
			{
				swapflag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

				delay();
                display();
			}
			}
		}
	}
}


void ripplesort()
{
	int temp;
		 for (i = 0; i < n && notsorted(); ++i)
    {

            for (j = 0; j <n-i-1; ++j)
            {
			if(a[j]>a[j+1])
			{
			    swapflag=2;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

				delay();
                display();
			}
			}
			for (j = n-i-1; j>i-1; --j)
            {
			if(a[j-1]>a[j])
			{
			    swapflag=2;
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;

				delay();
                display();
			}
			}
		}
}
//Quick sort
int partition(int low, int high)
{
  int pivot = a[high];
  i = (low - 1);
  int temp;
  for (j = low; j < high; j++)
  { swapflag=1;
    if (a[j] <= pivot)
    {
      i++;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      delay();
      display();
    }
  }
      temp=a[i+1];
      a[i+1]=a[high];
      a[high]=temp;
      delay();
      display();
  return (i + 1);
}
void quickSort(int low, int high)
{
  if (low < high)
  {
    int pi = partition(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}



// Timer Function, takes care of sort selection
void makedelay(int)
{
	if(sorting)
	{
		switch(sort_count)
		{
			case 0:	bubblesort();sorting=0;traverse();break;
			case 1:	selectionsort();sorting=0;traverse();break;
			case 2: insertionsort();sorting=0;traverse();break;
			case 3: ripplesort();sorting=0;traverse();break;
			case 4: mergeSort(0,n-1);sorting=0;traverse();break;
			case 5: quickSort(0,n-1); sorting=0;traverse();break;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(SPEED/n,makedelay,1);
}

// Keyboard Function
void keyboard (unsigned char key, int x, int y)
{
	if(key==13)
		k=1;
	if (k==1 && sorting!=1)
	{
		switch (key)
		{
			case 27	 :	exit (0); // 27 is the ascii code for the ESC key
			case 's' :	sorting = 1; break;
			case 'r' :	Initialize(); break;
			case '+' :  if(n+10<=MAX) n+=10;Initialize();break;
			case '-' :  if(n-10>=10) n-=10;Initialize();break;
		}
	}
	if(k==1 && sorting==1)
		if(key=='p')	sorting=0;
}
void Specialkey(int key, int x, int y)
    {
    switch(key)
    {
    case GLUT_KEY_UP  :  if(sort_count!=0)
                            sort_count=sort_count-1;
                         else
                            sort_count=SORT_NO-1;
                        break;
    case GLUT_KEY_DOWN   :  sort_count=(sort_count+1)%SORT_NO;	break;
    case GLUT_KEY_LEFT   :  n=50;Initialize();break;
    case GLUT_KEY_RIGHT  :  n=MAX;Initialize();break;
    }

    glutPostRedisplay();
    }
// Main Function
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sorting Algorithm Visualizer");
	Initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Specialkey);
	glutTimerFunc(1000,makedelay,1);
	glutMainLoop();
}
