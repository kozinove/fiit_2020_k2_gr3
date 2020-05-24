#include"TPolynom.h"
#include<gtest.h>

TEST(TPolynom, can_create_polynom)
{
	string s = "-xyz-2y4z2+z5";

	ASSERT_NO_THROW(TPolynom p(s));
}
TEST(TPolynom, can_create_polynom_2)
{
	char s[8] = "xyz+x2y";

	ASSERT_NO_THROW(TPolynom p(s));
}

TEST(TPolynom, can_mult_on_number_one)
{
	string s = "x2y2z2";
	string s_one = "2x2y2z2";
	TPolynom res(s_one);
	TPolynom tmp(s);

	EXPECT_EQ(tmp * 2, res);
}
TEST(TPolynom, can_mult_on_number_two)
{
	string s = "4x2y4z1-12x2y2z2";
	string s_one = "12x2y4z1-36x2y2z2";
	TPolynom res(s_one);
	TPolynom tmp(s);
	EXPECT_EQ(tmp * 3, res);
}
TEST(TPolynom, can_mult_on_number_three)
{
	string s = "2x2+2y2+3z";
	string s_one = "4x2+4y2+6z";
	TPolynom res(s_one);
	TPolynom tmp(s);
	EXPECT_EQ(tmp * 2, res);
}
TEST(TPolynom, can_mult_on_number_four)
{
	string s = "2x2+2y2+3z";
	string s_one = "-4x2-4y2-6z";
	TPolynom res(s_one);
	TPolynom tmp(s);
	EXPECT_EQ(tmp * (-2), res);
}
TEST(TPolynom, can_again)
{
	string s = "xyz+x2y2z2";
	TPolynom res(s);
	TPolynom tmp;
	tmp = res;
	EXPECT_EQ(tmp, res);
}
TEST(TPolynom, can_add_polynoms)
{
	string s_two = "xyz+2x2y2z2";
	string s_one = "xyz+2x2y2z2";
	string res = "4x2y2z2+2xyz";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a + b, c);
}
TEST(TPolynom, can_add_polynoms_one)
{
	string s_two = "x2+y4+12z2";
	string s_one = "x2+y+z2";
	string res = "2x2+y4+y+2z2";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a + b, c);
}
TEST(TPolynom, can_add_polynoms_two)
{
	string s_two = "x2+z2";
	string s_one = "x2-z2";
	string res = "2x2";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a + b, c);
}
TEST(TPolynom, can_sub_polynoms_one)
{
	string s_two = "x2+z2";
	string s_one = "x2-z2";
	string res = "2z2";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a - b, c);
}
TEST(TPolynom, can_sub_polynoms_two)
{
	string s_two = "2x2yz4+4xyz";
	string s_one = "-3x2yz4-3xyz";
	string res = "5x2yz4+xyz";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a - b, c);
}
TEST(TPolynom, can_calculate_on_point)
{
	string s_two = "xyz+5x2y2z2";

	TPolynom a(s_two);

	EXPECT_EQ(a.ComputationAtPoint(1, 1, 1), 6);
}
TEST(TPolynom, can_calculate_on_point_one)
{
	string s_two = "x5+y4+z3";

	TPolynom a(s_two);

	EXPECT_EQ(a.ComputationAtPoint(1, 2, 3), 44);
}
TEST(TPolynom, can_add_polynoms_and_update_one)
{
	string s_two = "xyz+xyz";
	string s_one = "2xyz";
	string res = "3xyz";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a + b, c);
}
TEST(TPolynom, can_add_polynoms_and_update_two)
{
	string s_two = "xyz+xyz";
	string s_one = "2xyz";
	string res = "3xyz";
	TPolynom a(s_two), b(s_one), c(res);

	EXPECT_EQ(a + b, c);
}
TEST(TPolynom, can_sort_polynom)
{
	string r = "2x3y3z+x2yz+x";
	string s = "x+x2yz+2x3yz";
	TPolynom p(s);
	TPolynom res(r);
	p.Sort();
	EXPECT_EQ(p, res);
}
TEST(TPolynom, can_mult_polynoms)
{
	string s = "xyz";
	string s1 = "xyz+2x2y2z3";
	string r = "2x3y3z4+x2y2z2";
	TPolynom a(s), b(s1), res(r);

	EXPECT_EQ(a*b, res);
}
TEST(TPolynom, can_mult_polynoms_one)
{
	string s = "x2+y";
	string s1 = "xyz+y+z2";
	string r = "x3yz+x2y+x2z2+xy2z+y2+yz2";
	TPolynom a(s), b(s1), res(r);

	EXPECT_EQ(a*b, res);
}
TEST(TPolynom, very_hard_test_from_Kolyan)
{
	TPolynom a("-y3+x2z1-37");
	TPolynom b("-1x0y3z0+1x2y0z1-37x0y0z0");

	EXPECT_EQ(a, b);
}
TEST(TPolynom, very_hard_test_from_Kolyan_two)
{
	TPolynom a("xyz-xyz");

	EXPECT_EQ("0", a.ToString());
}
TEST(TPolynom, test_for_debug)
{
	string s = "xyz+xyz+xyz";
	TPolynom a(s);
	TPolynom b("3xyz");

	EXPECT_EQ(a, b);
}
