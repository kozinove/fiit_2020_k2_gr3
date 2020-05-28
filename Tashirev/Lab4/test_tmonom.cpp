#include"TMonom.h"
#include<gtest.h>

TEST(TMonom, can_create_monom_1)
{
	ASSERT_NO_THROW(TMonom M);
}

TEST(TMonom, can_create_monom_2)
{
	ASSERT_NO_THROW(TMonom M(112, 2));
}

TEST(TMonom, can_not_create_monom_2)
{
	ASSERT_ANY_THROW(TMonom M(1000, 2));
}

TEST(TMonom, can_add_monoms_with_the_same_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(100, 5);

	TMonom res(100, 15);

	EXPECT_EQ(m_one + m_two, res);
}

TEST(TMonom, can_not_add_monoms_with_the_different_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(101, 5);

	ASSERT_ANY_THROW(m_one + m_two);
}

TEST(TMonom, can_sub_monoms_with_the_same_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(100, 5);

	TMonom res(100, 5);

	EXPECT_EQ(m_one - m_two, res);
}

TEST(TMonom, can_not_sub_monoms_with_the_different_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(101, 5);

	ASSERT_ANY_THROW(m_one - m_two);
}

TEST(TMonom, can_mult_monoms_on_number)
{
	TMonom m_one(100, 10);
	double c = 10;
	TMonom res(100, 100);

	EXPECT_EQ(m_one*c, res);
}
TEST(TMonom, can_copy_monom)
{
	TMonom m_one(100, 10);
	TMonom res(m_one);

	EXPECT_EQ(m_one, res);
}
TEST(TMonom, can_mult_monoms)
{
	TMonom m(112, 2);
	TMonom m1(112, 4);
	TMonom res(224, 8);

	EXPECT_EQ(res, m*m1);
}
TEST(TMonom, can_not_mult_monoms)
{
	TMonom m(999, 2);
	TMonom m1(112, 4);

	ASSERT_ANY_THROW(m*m1);
}
