//////////////////第三章//////////////////
/*1*/
/*#include<iostream>

//1英尺 = 12 英寸
const double inch_per_feet = 12.0L;

int main()
{
	using namespace std;

	cout << "输入你的身高（单位：英寸）：";

	double high_inch;
	cin >> high_inch;

	double high_feet = high_inch / inch_per_feet;

	cout << "你的身高为" << high_feet << "英尺。\n";

	return 0;
}*/
/*2*/
/*#include<iostream>

const double inch_per_feet = 12.0;
const double meter_per_inch = 0.0254;
const double pound_per_kilogram = 2.2;


int main()
{
	using namespace std;

	cout << "输入你的身高（例：5英尺3英寸）:";
	double high_feet = 0, high_inch = 0;
	cin >> high_feet >> high_inch;

	//英寸为单位的身高转换为以米为单位
	double high_meter = (high_inch + high_feet * inch_per_feet) * meter_per_inch;

	cout << "输入你的体重（单位：磅）：";
	double weight_pound;
	cin >> weight_pound;

	//以磅为单位的体重转换为以千克为单位
	double weight_kilogram = weight_pound / pound_per_kilogram;

	//计算BMI
	double BMI = weight_kilogram / high_meter * high_meter;

	cout << "BMI:" << BMI << endl;

	return 0;
}*/
/*3*/
/*#include<iostream>

const int Seconds_per_Minuts = 60;
const int Minuts_per_Hours = 60;

int main()
{
	using namespace std;

	cout << "以度，分，秒为单位输入一个纬度。\n";
	cout << "首先，输入纬度的度：";
	double degrees;
	cin >> degrees;
	cout << "然后，输入纬度的分：";
	double minutes;
	cin >> minutes;
	cout << "最后，输入纬度的秒：";
	double seconds;
	cin >> seconds;

	double degrees_changed;
	degrees_changed = degrees + minutes / Minuts_per_Hours + seconds / Seconds_per_Minuts / Minuts_per_Hours;
	cout << degrees << "度" << minutes << "分" << seconds << "秒 = " << degrees_changed << "度。\n";

	return 0;
}*/
/*4*/
/*#include<iostream>

const int Seconds_per_Minuts = 60;
const int Minuts_per_Hours = 60;
const int Hours_per_Days = 24;

int main()
{
	using namespace std;

	cout << "输入一个秒数，将转换为天，小时，分钟，秒显示：";
	long total_seconds;
	cin >> total_seconds;

	//获取秒数
	int seconds = total_seconds % Seconds_per_Minuts;
	
	int total_minuts = total_seconds / Seconds_per_Minuts;

	//获取分钟数
	int minuts = total_minuts % Minuts_per_Hours;

	int total_hours = total_minuts / Minuts_per_Hours;

	//获取小时数
	int hours = total_hours % Hours_per_Days;

	//获取天数
	int days = total_hours / Hours_per_Days;

	//结果输出
	cout << total_seconds << "秒 = ";
	cout << days << "天，";
	cout << hours << "小时，";
	cout << minuts << "分钟，";
	cout << seconds << "秒。\n";

	return 0;
}*/
/*5*/
/*#include<iostream>
int main()
{
	using namespace std;

	cout << "输入全球人口数：";
	long long world_populations;
	cin >> world_populations;
	cout << "输入美国人口数：";
	long long us_populations;
	cin >> us_populations;

	double usPop_of_worldPop = double(us_populations) / double(world_populations);
	cout << "美国人口占世界人口数的" << usPop_of_worldPop << "%" << endl;

	return 0;
}*/
/*6*/
//pass