#include "list.h"
#include <gtest.h>

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> L);
}

TEST(List, can_push_front)
{
	List<int> L;
	L.push_front(1);
	L.push_front(4);
	L.push_front(7);
	ASSERT_EQ(L[0], 7);
}

TEST(List, can_push_back)
{
	List<int> L;
	L.push_back(1);
	L.push_back(4);
	L.push_back(7);
	ASSERT_EQ(L[2], 7);
}

TEST(List, can_pop_back)
{
	List<int> L;
	L.push_back(1);
	L.push_back(4);
	L.push_back(7);
	L.pop_back();
	ASSERT_EQ(L[2], 0);
}

TEST(List, can_pop_front)
{
	List<int> L;
	L.push_back(1);
	L.push_back(4);
	L.push_back(7);
	L.pop_front();
	ASSERT_EQ(L[0], 4);
}

TEST(List, can_insert)
{
	List<int> L;
	L.push_back(1);
	L.push_back(4);
	L.push_back(7);
	L.insert(5, 1);
	ASSERT_EQ(L[1], 5);
}

TEST(List, can_insert_front)
{
	List<int> L;
	L.insert(5, 0);
	ASSERT_EQ(L[0], 5);
}

TEST(List, can_remove_front)
{
	List<int> L;
	L.push_front(1);
	L.erase(0);
	ASSERT_EQ(L[0], 0);
}

TEST(List, can_return_true_when_list_is_empty)
{
	List<int> L;
	EXPECT_TRUE(L.empty());
}
