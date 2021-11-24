#include "../../TestBase.hpp"

static std::uint32_t GCounter { };
static HypervisorHost GHost { };

struct MySubsystem : ISubsystem
{
	MySubsystem() : ISubsystem { GHost, DEFAULT_HOOK_FLAGS, "Test" } { }

	auto OnConstruct(std::unique_ptr<SubsystemConfig>&& config, void* userData) & -> void override
	{
		ISubsystem::OnConstruct(std::move(config), userData);
		++GCounter;
	}

	auto OnDestruct() & noexcept -> void override
	{
		--GCounter;
		ISubsystem::OnDestruct();
	}
};

TEST(Subsystem, AllocateConstructHook)
{
	constexpr auto executor
	{
		[]
		{
			const SubsystemHandle handle { Factory::AllocateSubsystemInstance<MySubsystem>(std::make_unique<SubsystemConfig>(), &GHost) };
			ASSERT_EQ(handle->Name(), "Test");
			ASSERT_EQ(handle->UserData(), &GHost);
			ASSERT_EQ(GCounter, 1);
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	ASSERT_EQ(GCounter, 0);
}
