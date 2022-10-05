#include "modern_robotics.h"
#include <iostream>

using namespace mr;
using namespace std;

int main()
{
	//�����˲���
	float L1 = 0.425;
	float L2 = 0.392;
	float W1 = 0.109;
	float W2 = 0.082;
	float H1 = 0.089;
	float H2 = 0.095;

	//��ʼֵ
	Eigen::MatrixXd M(4, 4);
	Eigen::Matrix3d M_R(rotx(-M_PI/2)*rotz(M_PI));
	Eigen::Vector3d M_p(L1+L2,W1+W2,H1-H2);
	M << M_R,     M_p,
		 0, 0, 0, 1;
	cout << "��ʼֵ:" << endl << "M = " << endl << M << endl;

	//�ռ�����ϵ�µĹؽ�����
	//���ٶȷ���
	Eigen::Vector3d w1(0, 0, 1),
					w2(0, 1, 0),
					w3(0, 1, 0),
					w4(0, 1, 0),
					w5(0, 0, -1),
					w6(0, 1, 0);
	//������λ��
	Eigen::Vector3d q1(0, 0, 0),
					q2(0, 0, H1),
					q3(L1, 0, H1),
					q4(L1+L2, 0, H1),
					q5(L1+L2, W1, 0),
					q6(L1+L2, 0, H1-H2);

	Eigen::Vector3d v1(-w1.cross(q1)),
					v2(-w2.cross(q2)),
					v3(-w3.cross(q3)),
					v4(-w4.cross(q4)),
					v5(-w5.cross(q5)),
					v6(-w6.cross(q6));
	Eigen::MatrixXd Slist(6, 6);
	Slist << w1, w2, w3, w4, w5, w6,
			 v1, v2, v3, v4, v5, v6;
	cout << "�ռ�����ϵ�µĹؽ�����:" << endl << "Slist = " << endl << Slist << endl;

	//�ؽڽǶ�ֵ
	Eigen::VectorXd thetalist(6, 1);
	thetalist << 0,
				-M_PI/4,
				M_PI/4,
				0,
				0,
				0;
	cout << "�ؽڽǶ�ֵ:" << endl << "thetalist = " << endl << thetalist << endl;

	//���˶�ѧ
	Eigen::MatrixXd T(4, 4); //Ŀ��λ�˾���
	T = FKinSpace(M, Slist, thetalist);
	cout << "���˶�ѧ-ĩ����α任����:" << endl << "T = " << endl << T << endl;

	//�ſɱ�
	Eigen::MatrixXd Js(6, 6);
	Js = JacobianSpace(Slist, thetalist);
	cout << "�ռ��ſɱȾ���:" << endl << "Js = " << endl << Js << endl;

	double eomg = 0.0;
	double ev = 0.0;
	Eigen::VectorXd thetalist0(6, 1);
	thetalist0 << 0,
			-M_PI/5,
			M_PI/5,
			0,
			0,
			0;
	IKinSpace(Slist, M, T, thetalist0, eomg, ev);
	cout << "���˶�ѧ-�ؽڽǶ�ֵ:" << endl << "thetalist = " << endl << thetalist0 << endl;

	return 0;
}