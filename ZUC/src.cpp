#include <math.h>
#include <conio.h>
#include <stdio.h>			//用到了定时函数sleep()
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <graphics.h>              // 引用图形库头文件

#include "ZUC.h"
#include "compare.h"

int r[4][4] = { {130,130,230,170},{250,130,350,170},{130,190,230,230}, {250,190,350,230} };//三个按钮的二维数组
int rt[] = {100,60,380,110};

int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	if (x > r[3][0] && x<r[3][2] && y>r[3][1] && y < r[3][3])return 4;
	return 0;
}

int main()
{
	int i, event = 0;
	short win_width, win_height;//定义窗口的宽度和高度
	win_width = 480; win_height = 360;
	initgraph(win_width, win_height);//初始化窗口（黑屏）
	for (i = 0; i < 256; i += 5)
	{
		setbkcolor(RGB(i, i, i));//设置背景色，原来默认黑色
		cleardevice();//清屏（取决于背景色）
		Sleep(15);//延时15ms
	}
	RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
	RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
	RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };
	RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };
	RECT RT = { rt[0],rt[1],rt[2],rt[3] };

	LOGFONT f0;
	gettextstyle(&f0);					   // 获取字体样式
	_tcscpy_s(f0.lfFaceName, _T("楷体"));  // 设置字体为宋体
	f0.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f0.lfHeight = 26;                      // 字体高度(像素为单位)
	f0.lfWidth = 0;                        // 字体宽度
	settextstyle(&f0);                     // 设置字体样式
	settextcolor(BLACK);				   // BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext(_T("祖冲之算法文件加密系统"), &RT, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R3内输入文字，水平居中，垂直居中，单行显示

	LOGFONT f;
	gettextstyle(&f);					// 获取字体样式
	_tcscpy_s(f.lfFaceName, _T("楷体"));	// 设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;  // 设置输出效果为抗锯齿  
	settextstyle(&f);                   // 设置字体样式
	settextcolor(BLACK);				// BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext(_T("加密"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);// 在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("解密"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);// 在矩形区域R2内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("校验"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);// 在矩形区域R3内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("退出"), &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);// 在矩形区域R3内输入文字，水平居中，垂直居中，单行显示
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	MOUSEMSG m;//鼠标指针

	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//线条颜色为亮青色
			setlinestyle(PS_SOLID, 3);//设置画线样式为实现，10磅
			setfillcolor(WHITE);//填充颜色为白色
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//记录这一次触发的按钮
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//有框填充矩形（X1,Y1,X2,Y2）
				}
			}
			else
			{
				if (event != 0)//上次触发的按钮未被修正为原来的颜色
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//两次同或为原来颜色
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)
			for (i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//设置圆颜色
				circle(m.x, m.y, 2 * i);
				Sleep(30);//停顿30ms
				circle(m.x, m.y, 2 * i);//抹去刚刚画的圆
			}
			switch (button_judge(m.x, m.y))
			{
				//复原按钮原型
			case 1:
				do_zuc(0);
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 2:
				do_zuc(1);
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 3:
				//
				com_file();
				FlushMouseMsgBuffer();
				break;
			case 4:
				exit(0);//正常退出
			default:
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				//printf("\r\n(%d,%d)",m.x,m.y);//打印鼠标坐标，方便调试时确定区域
				break;
			}
			break;
		}
	}
	system("pause");//暂停，为了显示
	return 0;
}

