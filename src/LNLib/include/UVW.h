#pragma once

#include "Constants.h"
#include "LNLibDefinitions.h"

namespace LNLib
{
/// <summary>
/// Represents three-dimension location/vector/offset
/// </summary>
class LNLIB_EXPORT UVW
{
public:

	UVW();
	UVW(double u, double v, double w);

public:

	void SetU(const double x);
	double GetU() const;
	void SetV(const double y);
	double GetV() const;
	void SetW(const double z);
	double GetW() const;

	double U() const;
	double& U();
	double V() const;
	double& V();
	double W() const;
	double& W();

public:

	bool IsZero(const double epsilon = Constants::DoubleEpsilon) const;
	bool IsUnit(const double epsilon = Constants::DoubleEpsilon) const;
	bool IsAlmostEqualTo(const UVW& another) const;
	double Length() const;
	double SqrLength() const;
	double AngleTo(const UVW& another) const;
	UVW Normalize();
	UVW Add(const UVW& another) const;
	UVW Subtract(const UVW& another) const;
	UVW Negative() const;
	double DotProduct(const UVW& another) const;
	UVW CrossProduct(const UVW& another) const;
	double Distance(const UVW& another) const;

public:

	UVW& operator =(const UVW& uvw);
	double& operator[](int index);
	const double& operator[](int index) const;
	UVW operator +(const UVW& uvw) const;
	UVW operator -(const UVW& uvw) const;
	double operator *(const UVW& uvw) const; // Scalar product
	UVW& operator *=(const double& d);
	UVW& operator /=(const double& d);
	UVW& operator +=(const UVW& uvw);
	UVW& operator -=(const UVW& uvw);
	UVW operator-() const;

private:

	double m_uvw[3];
};

LNLIB_EXPORT UVW operator *(const UVW& source, const double d);
LNLIB_EXPORT UVW operator *(const double& d, const UVW& source);
LNLIB_EXPORT UVW operator ^(const UVW& uvw1, const UVW& uvw2);
LNLIB_EXPORT UVW operator /(const UVW& source, double d);
}
