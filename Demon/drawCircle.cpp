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
	gluOrtho2D(-VIEW_WIDTH / 2, VIEW_WIDTH / 2, -VIEW_HEIGHT / 2, VIEW_HEIGHT / 2);//清除颜色  
	glBegin(GL_POLYGON);
	for (i = 0; i < N ; ++i){
		float x = 0.4*cos(2 * Pi / N*i);
		float y = 0.4*sin(2 * Pi / N*i);
		if (y <= 0){
			continue;
		}
		std::cout << x << "，"<<y << std::endl;
		
		glVertex2f(0.4*cos(2 * Pi / N*i), 0.4*sin(2 * Pi / N*i));
		
	}
	glEnd();
	
	
	glFlush();//保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）  

}



//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);//对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次  
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式  
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("第一个OpenGL程序"); //根据前面设置的信息创建窗口。参数将被作为窗口的标题。  
//	Util::getInfo();
//	char* file = Util::readConf(fileread);
//
//	printf("file content :%s \n", file);
//
//	glutDisplayFunc(myDisplaydrawCircle); //当需要画图时，请调用myDisplay函数  
//	glutMainLoop(); //进行一个消息循环  
//	return 0;
//}