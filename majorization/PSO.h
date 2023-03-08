#pragma once
/************************************************************************/
/* Author:      weihan                     */
/* Email:       weihan@qq.com                                            */
/* FileName:    PSO.cpp                                                  */
/* LastChange:  2023-2-28                                                 */
/******************************************************************...******/

#ifndef _PSO_H
#define _PSO_H

//΢����
class PARTICLE
{
public:
	double* X;			//΢������������
	double* V;			//΢�����ٶ�����
	double* XBest;		//΢�������λ������
	int    Dim;			//΢����ά��
	double Fit;			//΢�����ʺ϶�
	double FitBest;		//΢�����λ�õ��ʺ϶�

	PARTICLE();		    //�չ��캯��
	PARTICLE(int n);    //ά��Ϊ�����Ĺ��캯��

	~PARTICLE();	    //��������

	void SetDim(int d); //����΢����ά��

};

//Ⱥ������
class PSO
{
protected:
	PARTICLE* Particle; //΢��Ⱥ����
	int    PNum;	    //΢������
	int    GBestIndex;	//���΢������
	double W_max;		//����Ȩ�ص����ֵ
	double W_min;		//����Ȩ�ص���Сֵ
	int    IteorMax;	//����������

	double C1;			//���ٶ�ϵ��1
	double C2;			//���ٶ�ϵ��2
	double* Xup;		//΢�������Ͻ�����
	double* Xdown;		//΢�������½�����
	double* Vmax;		//΢������ٶ�����

	void Initialize();			//��ʼ��Ⱥ��
	void CalFit();				//����ȫ���ʺ϶�
	virtual void ParticleFly();	//΢�����裬������һ��΢��


	//ͨѶ����������ֵΪfalseʱ��ϵͳֹͣ�Ż�

	bool (*Com)(double, /*����΢���ʺ϶�*/ double*, /*����΢����������*/
		double**, /*����΢������ָ������*/ int /*��ǰ����΢������*/);

public:
	PSO();						//�չ��캯��
	PSO(int dim, int n);			//dimΪ΢��ά����nΪ΢������

	~PSO();						//��������

	void SetXup(double*);		//����΢�������Ͻ�
	void SetXdown(double*);		//����΢�������½�
	void SetVmax(double*);		//����΢������ٶ�,������Ϊ����
	void SetVmax(double);		//����΢������ٶȣ�����������½�İٷֱ�Ϊ����
	void SetC1(double c) { C1 = c; }	//����C1
	void SetC2(double c) { C2 = c; }	//����C2
	void SetCom(void* p)		//����ͨѶ����
	{
		Com = (bool(*)(double, double*, double**, int))p;
	}

	void SetIteorMax(int iteor)
	{
		IteorMax = iteor;			//��������������
	}
	//�����ض�΢����������Ӧ���ʺ϶ȣ��������������ʵ��PSO�ඨ��,�Ա�����ʺ϶�
	virtual float GetFit(PARTICLE&) = 0;

	PARTICLE& Run(int max);		//����������������PSO
	PARTICLE& Run(double fit);	//������ʺ϶�Ŀ������PSO
	double GetBest(double*);	//������΢���ʺ϶Ⱥ�����

};

#endif
