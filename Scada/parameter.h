
#ifndef INIT_H_
#define INIT_H_
/*
	编译MonitorSystem工程，需要将 RUNNING 设置为 1， 使状态监测界面中的指示灯默认为隐藏状态
	编译 Scada 工程， 需要将 RUNNING 设置为 0，在状态监测配置界面中需要使指示灯显示
*/
static const int  RUNNING = 1;  


#endif //INIT_H_