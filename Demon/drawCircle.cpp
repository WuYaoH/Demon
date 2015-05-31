#include "Angel.h"
#include "Util.h"
const int N = 4;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
#define VIEW_WIDTH 1
#define VIEW_HEIGHT 1
long bufsize = 0;
char string[1024];

void myDisplaydrawCircle(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-VIEW_WIDTH / 2, VIEW_WIDTH / 2, -VIEW_HEIGHT / 2, VIEW_HEIGHT / 2);//�����ɫ  
	glBegin(GL_POLYGON);
	for (i = 0; i < N ; ++i){
		float x = 0.4*cos(2 * Pi / N*i);
		float y = 0.4*sin(2 * Pi / N*i);
		if (y <= 0){
			continue;
		}
		std::cout << x << "��"<<y << std::endl;
		
		glVertex2f(0.4*cos(2 * Pi / N*i), 0.4*sin(2 * Pi / N*i));
		
	}
	glEnd();
	
	
	glFlush();//��֤ǰ���OpenGL��������ִ�У��������������ڻ������еȴ���  

}



//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);//��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��  
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ  
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("��һ��OpenGL����"); //����ǰ�����õ���Ϣ�������ڡ�����������Ϊ���ڵı��⡣  
//	Util::getInfo();
//	char* file = Util::readConf(fileread);
//
//	printf("file content :%s \n", file);
//
//	glutDisplayFunc(myDisplaydrawCircle); //����Ҫ��ͼʱ�������myDisplay����  
//	glutMainLoop(); //����һ����Ϣѭ��  
//	return 0;
//}