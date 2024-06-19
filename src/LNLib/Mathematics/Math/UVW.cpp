#include "MathUtils.h"
#include "UVW.h"
#include <cmath>

using namespace LNLib;

LNLib::UVW::UVW()
{
	m_uvw[0] = 0;
	m_uvw[1] = 0;
	m_uvw[2] = 0;
}

UVW::UVW(double u, double v, double w)
{
	m_uvw[0] = u;
	m_uvw[1] = v;
	m_uvw[2] = w;
}

void UVW::SetU(const double x)
{
	m_uvw[0] = x;
}

double UVW::GetU() const
{
	return m_uvw[0];
}

void UVW::SetV(const double y)
{
	m_uvw[1] = y;
}

double UVW::GetV() const
{
	return m_uvw[1];
}

void UVW::SetW(const double z)
{
	m_uvw[2] = z;
}

double UVW::GetW() const
{
	return m_uvw[2];
}

double UVW::U() const
{
	return m_uvw[0];
}

double& UVW::U()
{
	return m_uvw[0];
}

double UVW::V() const
{
	return m_uvw[1];
}

double& UVW::V()
{
	return m_uvw[1];
}

double UVW::W() const
{
	return m_uvw[2];
}

double& UVW::W()
{
	return m_uvw[2];
}

bool LNLib::UVW::IsZero(const double epsilon) const
{
	return SqrLength() <= epsilon * epsilon;
}

bool LNLib::UVW::IsUnit(const double epsilon) const
{
	return std::fabs(SqrLength() - 1) < epsilon * epsilon;
}

bool UVW::IsAlmostEqualTo(const UVW& another) const
{
	return MathUtils::IsAlmostEqualTo(m_uvw[0], another.m_uvw[0]) &&
		MathUtils::IsAlmostEqualTo(m_uvw[1], another.m_uvw[1]) &&
		MathUtils::IsAlmostEqualTo(m_uvw[2], another.m_uvw[2]);
}

double UVW::Length() const
{
	return std::sqrt(m_uvw[0] * m_uvw[0] + m_uvw[1] * m_uvw[1] + m_uvw[2] * m_uvw[2]);
}

double UVW::SqrLength() const
{
	return m_uvw[0] * m_uvw[0] + m_uvw[1] * m_uvw[1] + m_uvw[2] * m_uvw[2];
}

double UVW::DotProduct(const UVW& another) const
{
	return m_uvw[0] * another.m_uvw[0] + m_uvw[1] * another.m_uvw[1] + m_uvw[2] * another.m_uvw[2];
}

// Cross product of two vectors in 3D
UVW UVW::CrossProduct(const UVW& another) const
{
	return UVW(
		m_uvw[1] * another.m_uvw[2] - m_uvw[2] * another.m_uvw[1],
		m_uvw[2] * another.m_uvw[0] - m_uvw[0] * another.m_uvw[2],
		m_uvw[0] * another.m_uvw[1] - m_uvw[1] * another.m_uvw[0]
	);
}

double UVW::Distance(const UVW& another) const
{
	double squareValue =
		std::pow(another.GetU() - m_uvw[0], 2) +
		std::pow(another.GetV() - m_uvw[1], 2) +
		std::pow(another.GetW() - m_uvw[2], 2);
	return std::sqrt(squareValue);
}

UVW& UVW::operator=(const UVW& uvw)
{
	m_uvw[0] = uvw.m_uvw[0];
	m_uvw[1] = uvw.m_uvw[1];
	m_uvw[2] = uvw.m_uvw[2];
	return *this;
}

double& UVW::operator[](int index)
{
	return m_uvw[index];
}

const double& UVW::operator[](int index) const
{
	return m_uvw[index];
}

UVW UVW::operator+(const UVW& uvw) const
{
	return LNLib::UVW(m_uvw[0] + uvw.m_uvw[0], m_uvw[1] + uvw.m_uvw[1], m_uvw[2] + uvw.m_uvw[2]);
}

UVW UVW::operator-(const UVW& uvw) const
{
	return LNLib::UVW(m_uvw[0] - uvw.m_uvw[0], m_uvw[1] - uvw.m_uvw[1], m_uvw[2] - uvw.m_uvw[2]);
}

double UVW::operator*(const UVW& uvw) const
{
	return DotProduct(uvw);
}

UVW& UVW::operator*=(const double& d)
{
	m_uvw[0] *= d;
	m_uvw[1] *= d;
	m_uvw[2] *= d;
	return *this;
}

UVW& UVW::operator/=(const double& d)
{
	m_uvw[0] /= d;
	m_uvw[1] /= d;
	m_uvw[2] /= d;
	return *this;
}

UVW& UVW::operator+=(const UVW& uvw)
{
	m_uvw[0] += uvw.m_uvw[0];
	m_uvw[1] += uvw.m_uvw[1];
	m_uvw[2] += uvw.m_uvw[2];
	return *this;
}

UVW& UVW::operator-=(const UVW& uvw)
{
	m_uvw[0] -= uvw.m_uvw[0];
	m_uvw[1] -= uvw.m_uvw[1];
	m_uvw[2] -= uvw.m_uvw[2];
	return *this;
}

UVW UVW::operator-() const
{
	return UVW(-m_uvw[0], -m_uvw[1], -m_uvw[2]);
}

// Global operators
LNLib::UVW LNLib::operator*(const UVW& source, const double d)
{
	return UVW(source.GetU() * d, source.GetV() * d, source.GetW() * d);
}

LNLib::UVW LNLib::operator*(const double& d, const UVW& source)
{
	return UVW(source.GetU() * d, source.GetV() * d, source.GetW() * d);
}

// Cross product operator
LNLib::UVW LNLib::operator^(const UVW& uvw1, const UVW& uvw2)
{
	return uvw1.CrossProduct(uvw2);
}

LNLib::UVW LNLib::operator/(const UVW& source, double d)
{
	return UVW(source.GetU() / d, source.GetV() / d, source.GetW() / d);
}
