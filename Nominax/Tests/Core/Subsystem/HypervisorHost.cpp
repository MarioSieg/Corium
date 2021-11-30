#include "SubsystemMockWithAllEvents.hpp"

TEST(HypervisorHost, Install)
{
    MockSubsystemWithAllEvents::MockCounter = 0;
    HypervisorHost host { };
    const auto key { host.Install<MockSubsystemWithAllEvents>() };
    ASSERT_TRUE(host.IsInstalled(key));
    ASSERT_EQ(key, 1);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);
    ASSERT_EQ(host.InstalledSystemCount(), 1);
    ASSERT_EQ(host.Lookup(key).Name(), "Noel");
    ASSERT_EQ(host.Lookup(key).SubscribedHooks(), HookFlags::All);
    MockSubsystemWithAllEvents::MockCounter = 0;
}

TEST(HypervisorHost, Uninstall)
{
    MockSubsystemWithAllEvents::MockCounter = 0;
    HypervisorHost host { };
    const auto key { host.Install<MockSubsystemWithAllEvents>() };
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);
    MockSubsystemWithAllEvents::MockCounter = 0;
    host.Uninstall(key);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);
    ASSERT_FALSE(host.IsInstalled(key));
    ASSERT_EQ(std::size(host.FullSystemMap()), 0);
    MockSubsystemWithAllEvents::MockCounter = 0;
}

TEST(HypervisorHost, PauseResume)
{
    MockSubsystemWithAllEvents::MockCounter = 0;
    HypervisorHost host { };
    const auto key { host.Install<MockSubsystemWithAllEvents>() };
    MockSubsystemWithAllEvents::MockCounter = 0;

    ASSERT_FALSE(host.Lookup(key).IsPaused());
    host.Pause(key);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 1);
    ASSERT_TRUE(host.Lookup(key).IsPaused());
    host.Resume(key);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);
    ASSERT_FALSE(host.Lookup(key).IsPaused());

    MockSubsystemWithAllEvents::MockCounter = 0;
}

TEST(HypervisorHost, UninstallAll)
{
    MockSubsystemWithAllEvents::MockCounter = 0;

    HypervisorHost host { };
    const auto key { host.Install<MockSubsystemWithAllEvents>() };
    ASSERT_TRUE(host.IsInstalled(key));
    host.UninstallAll();
    ASSERT_FALSE(host.IsInstalled(key));
    ASSERT_EQ(host.InstalledSystemCount(), 0);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 4);

    MockSubsystemWithAllEvents::MockCounter = 0;
}

TEST(HypervisorHost, BootAll)
{
    MockSubsystemWithAllEvents::MockCounter = 0;
    MockSubsystemWithAllEvents::MockMessage = "";
    MockSubsystemWithAllEvents::Messages.clear();

    HypervisorHost host { };
    host.Install<MockSubsystemWithAllEvents>();
    host.Install<MockSubsystemWithAllEvents>();
    MockSubsystemWithAllEvents::MockCounter = 0;
    host.BootAll();
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 4);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockMessage, "Post");
    ASSERT_EQ(MockSubsystemWithAllEvents::Messages.size(), 4);
    ASSERT_EQ(MockSubsystemWithAllEvents::Messages[0], "Pre");
    ASSERT_EQ(MockSubsystemWithAllEvents::Messages[1], "Pre");
    ASSERT_EQ(MockSubsystemWithAllEvents::Messages[2], "Post");
    ASSERT_EQ(MockSubsystemWithAllEvents::Messages[3], "Post");

    MockSubsystemWithAllEvents::MockCounter = 0;
    MockSubsystemWithAllEvents::MockMessage = "";
    MockSubsystemWithAllEvents::Messages.clear();
}

TEST(HypervisorHost, ShutdownAll)
{
    MockSubsystemWithAllEvents::MockCounter = 0;

    HypervisorHost host { };
    host.Install<MockSubsystemWithAllEvents>();
    MockSubsystemWithAllEvents::MockCounter = 0;

    host.ShutdownAll();
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);

    MockSubsystemWithAllEvents::MockCounter = 0;
}

TEST(HypervisorHost, InvokeGroup)
{
    MockSubsystemWithAllEvents::MockCounter = 0;
    MockSubsystemWithAllEvents::MockMessage = "";
    MockSubsystemWithAllEvents::Messages.clear();

    HypervisorHost host { };
    host.Install<MockSubsystemWithAllEvents>();
    host.Install<MockSubsystemWithAllEvents>();
    MockSubsystemWithAllEvents::MockCounter = 0;

    host.InvokeGroup<HookFlags::OnPreBoot, false>();
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 2);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockMessage, "Pre");

    host.InvokeGroup<HookFlags::OnPostBoot, true>();
    ASSERT_EQ(MockSubsystemWithAllEvents::MockCounter, 4);
    ASSERT_EQ(MockSubsystemWithAllEvents::MockMessage, "Post");

    MockSubsystemWithAllEvents::MockMessage = "";
    MockSubsystemWithAllEvents::MockCounter = 0;
    MockSubsystemWithAllEvents::Messages.clear();
}
