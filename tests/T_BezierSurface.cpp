﻿#include "gtest/gtest.h"
#include "BezierSurface.h"
#include "UV.h"
#include "XYZ.h"
#include "XYZW.h"
#include "MathUtils.h"

using namespace LNLib;

TEST(Test_BezierSurface, All)
{
	int degreeU = 2;
	int degreeV = 1;
	UV uv = UV(0.5, 0.5);

	std::vector<std::vector<XYZ>> controlPoints(degreeU + 1, std::vector<XYZ>(degreeV + 1));
	controlPoints[0][0] = XYZ(1, 1, 0);
	controlPoints[1][0] = XYZ(1, 1, 1);
	controlPoints[2][0] = XYZ(2, 0, 2);
	controlPoints[0][1] = XYZ(-1, 1, 0);
	controlPoints[1][1] = XYZ(-1, 1, 1);
	controlPoints[2][1] = XYZ(-2, 0, 2);
	XYZ result = BezierSurface::GetPointOnSurfaceByDeCasteljau(degreeU, degreeV, controlPoints, uv);
	EXPECT_TRUE(result.IsAlmostEqualTo(XYZ(0, 0.75, 1.0)));

	std::vector<std::vector<XYZW>> weightedControlPoints(degreeU + 1, std::vector<XYZW>(degreeV + 1));
	weightedControlPoints[0][0] = XYZW(1, 1, 0, 1);
	weightedControlPoints[1][0] = XYZW(1, 1, 1, 1);
	weightedControlPoints[2][0] = XYZW(2, 0, 2, 2);
	weightedControlPoints[0][1] = XYZW(-1, 1, 0, 1);
	weightedControlPoints[1][1] = XYZW(-1, 1, 1, 1);
	weightedControlPoints[2][1] = XYZW(-2, 0, 2, 2);	
	XYZW weightedResult = BezierSurface::GetPointOnRationalSurfaceByDeCasteljau(degreeU, degreeV, weightedControlPoints, uv);
	EXPECT_TRUE(weightedResult.ToXYZ(true).IsAlmostEqualTo(XYZ(0, 3.0 / 5, 4.0 / 5)));
}
