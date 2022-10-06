#include "modern_robotics.h"
#include <iostream>
#include "MRTest.h"

using namespace mr;
using namespace std;

int main()
{
	/*--------------------��3�� �����˶� P69--------------------*/

	RotInvTest();
	VecToso3Test();
//	so3ToVecTest();//TODO
//	AxisAng3Test();//TODO
//	MatrixExp3Test();//TODO
//	MatrixLog3Test();//TODO
	DistanceToSO3Test();
	TestIfSO3Test();
//	ProjectToSO3Test();//TODO
//	RpToTransTest();//TODO
//	TransToRpTest();//TODO
	TransInvTest();
//	VecTose3Test();//TODO
//	se3ToVecTest();//TODO
	AdjointTest();
	ScrewToAxisTest();
	AxisAng6Test();
//	MatrixExp6Test();//TODO
	MatrixLog6Test();
	DistanceToSE3Test();
	TestIfSE3Test();
//	ProjectToSE3Test();//TODO

	/*--------------------��4�� �����˶�ѧ P99--------------------*/

	FKinBodyTest();
	FKinSpaceTest();

	/*--------------------��5�� һ���˶�ѧ�뾲��ѧ P125--------------------*/

	JacobianBodyTest();
	JacobianSpaceTest();

	/*--------------------��6�� ���˶�ѧ P144--------------------*/

	IKinBodyTest();
	IKinSpaceTest();

	/*--------------------��8�� ��������ѧ P197--------------------*/

	adTest();
	InverseDynamicsTest();
	MassMatrixTest();
	VelQuadraticForcesTest();
	GravityForcesTest();
	EndEffectorForcesTest();
	ForwardDynamicsTest();
	EulerStepTest();
	InverseDynamicsTrajectoryTest();
	ForwardDynamicsTrajectoryTest();

	/*--------------------��9�� �켣���� P216--------------------*/

	CubicTimeScalingTest();
	QuinticTimeScalingTest();
	JointTrajectoryTest();
	ScrewTrajectoryTest();
	CartesianTrajectoryTest();

	/*--------------------��11�� �����˿��� P287--------------------*/

	ComputedTorqueTest();
	SimulateControlTest();

	/*--------------------����--------------------*/
	UR5Test();

	return 0;
}