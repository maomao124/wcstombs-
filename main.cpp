#include"head and macro.h"
#include"Class.h"
#include"function declaration.h"
#include"struct.h"

int main()
{
	/*   *************************************                                             //全屏图形窗口模板
	int rw, rh;
	rw = GetSystemMetrics(SM_CXSCREEN);                                          // 屏幕宽度 像素
	rh = GetSystemMetrics(SM_CYSCREEN);                                          // 屏幕高度 像素
	HWND hwnd = initgraph(rw, rh);                                                    // 初始化绘图窗口并获取窗口句柄
	setbkcolor(GREEN);
	cleardevice();
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);               // 获取窗口信息
																										 // 设置窗口信息 最大化 取消标题栏及边框
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);           // 修改窗口样式
	SetWindowPos(hwnd, HWND_TOP, 0, 0, rw, rh, 0);
	*/   //***********************************
	/*      ***********************************
	initgraph(1600, 900);
	setbkcolor(WHITE);
	cleardevice();
	*/  //***********************************
	/*    ***********************************                                             //后台方式运行，Unicode字符集改成多字节字符集
	HWND hwnd; if (hwnd = ::FindWindow("ConsoleWindowClass", NULL)) //找到控制台句柄
	{
		::ShowWindow(hwnd, SW_HIDE); //隐藏控制台窗口
	}
                                                                                                    //unicode字符集下：
	const char* sss = "ConsoleWindowClass";
	WCHAR wszName[200];
	memset(wszName, 0, sizeof(wszName));
	MultiByteToWideChar(CP_ACP, 0, sss, strlen(sss) + 1, wszName,
		sizeof(wszName) / sizeof(wszName[0]));
	HWND hwnd; if (hwnd = ::FindWindow(wszName, NULL)) //找到控制台句柄
	{
		::ShowWindow(hwnd, SW_HIDE); //隐藏控制台窗口
	}
	*/  //**********************************

	 //全局变量声明：
     //开始

	extern MyStruct s;

    //结束
	//****************从这里开始写主函数代码**********************
	//*************************************************************************



	//*************************************************************************
	runstart();
	//*************************计时开始***************************************
	
	//C 库函数 size_t wcstombs(char *str, const wchar_t *pwcs, size_t n) 把宽字符字符串 pwcs 转换为一个 str 开始的多字节字符串。最多会有 n 个字节被写入 str 中
	//str -- 指向一个 char 元素的数组，至少有 n 字节长。
	//pwcs -- 要被转换的宽字符字符串。
    //n -- 要被写入到 str 中的最大字节数。
	size_t ret;
	char* MB = (char*)malloc(50);
	const wchar_t* WC = L"12389756";

	/* 转换宽字符字符串 */
	ret = wcstombs(MB, WC, 50);

	printf("要转换的字符数 = %u\n", ret);
	printf("多字节字符 = %s\n\n", MB);

	//*************************计时结束***************************************
	runend();



	//***************************结束********************************
	/*   *************************************
	constexpr int MIN = 1;                            //随机数
	constexpr int MAX = 100;
	constexpr int numm = 10;
	 random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(MIN, MAX);

	for (int n = 0; n < numm; ++n)
	{
		cout << distr(eng) << ",";
	}
	*/   //***********************************
	/*  //************************************
	SYSTEMTIME sys;                                    //获取系统时间
	GetLocalTime(&sys);
	cout << sys.wYear << "/" << sys.wMonth << "/" << sys.wDay << "      ";
	cout<< setfill('0') << setw(2) << sys.wHour << ":" << setfill('0') << setw(2) << sys.wMinute << ":" << setfill('0') << setw(2) << sys.wSecond << endl;
	*/   //***********************************
	/*   ************************************                            //微软TTS语音模板
	ISpVoice* pVoice = NULL;                                            //创建一个ISpVoice的空指针
	if (FAILED(::CoInitialize(NULL)))                                     //初始化COM编程环境
	{
		cout << "初始化COM环境失败！" << endl;
		return 0;
	}
	                                                                                   //获取ISpVoice接口对象：
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
	if (SUCCEEDED(hr))                                                      //如果获取接口对象成功
	{
		char* szStr = (char*)malloc(200);
		sprintf(szStr, "你好，世界。");
		WCHAR wszClassName[200];
		memset(wszClassName, 0, sizeof(wszClassName));
		MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName,
			sizeof(wszClassName) / sizeof(wszClassName[0]));
		hr = pVoice->Speak(wszClassName, 0, NULL);         //朗读
		
		pVoice->Release();                                                 //释放分配资源
		pVoice = NULL;                                                     //防止野指针
	}
	::CoUninitialize();                                                       //退出COM编程环境
	*/  //*********************************
	/*   **********************************                          //多线程模板
	void task()
    {
	//多线程代码
    }
	thread t(task);
	t.detach();
	*/   //*******************************
	rundisplay();                                                                   //计时结果显示
	_getch();
	//closegraph();
	// system("pause");
	//Sleep(10000);
	return 0;
}
