#include "TestBase.hpp"

TEST(ScopeChecker, Construct)
{
	const ScopeChecker scope{};
	ASSERT_FALSE(scope.HasLeak());
	ASSERT_EQ(scope.GetOpenedScopeCount(), 0);
	ASSERT_EQ(scope.GetClosedScopeCount(), 0);
}

TEST(ScopeChecker, EnterScope)
{
	ScopeChecker scope{};
	scope.EnterScope();
	scope.LeaveScope();
	ASSERT_EQ(scope.GetOpenedScopeCount(), 1);
	ASSERT_EQ(scope.GetClosedScopeCount(), 1);
	ASSERT_FALSE(scope.HasLeak());
}

TEST(ScopeChecker, EnterScopeLeak)
{
	ScopeChecker scope{};
	scope.EnterScope();
	ASSERT_EQ(scope.GetOpenedScopeCount(), 1);
	ASSERT_EQ(scope.GetClosedScopeCount(), 0);
	ASSERT_TRUE(scope.HasLeak());
}

TEST(ScopeChecker, LeaveScopeLeak)
{
	ScopeChecker scope{};
	scope.LeaveScope();
	ASSERT_EQ(scope.GetOpenedScopeCount(), 0);
	ASSERT_EQ(scope.GetClosedScopeCount(), 1);
	ASSERT_TRUE(scope.HasLeak());
}

TEST(ScopeChecker, EnterScopeMismatchLeak)
{
	ScopeChecker scope{};
	scope.EnterScope();
	scope.EnterScope();
	scope.LeaveScope();
	ASSERT_EQ(scope.GetOpenedScopeCount(), 2);
	ASSERT_EQ(scope.GetClosedScopeCount(), 1);
	ASSERT_TRUE(scope.HasLeak());
}
