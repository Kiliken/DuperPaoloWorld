// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DuperPaoloWorld : ModuleRules
{
	public DuperPaoloWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DuperPaoloWorld",
			"DuperPaoloWorld/Variant_Platforming",
			"DuperPaoloWorld/Variant_Platforming/Animation",
			"DuperPaoloWorld/Variant_Combat",
			"DuperPaoloWorld/Variant_Combat/AI",
			"DuperPaoloWorld/Variant_Combat/Animation",
			"DuperPaoloWorld/Variant_Combat/Gameplay",
			"DuperPaoloWorld/Variant_Combat/Interfaces",
			"DuperPaoloWorld/Variant_Combat/UI",
			"DuperPaoloWorld/Variant_SideScrolling",
			"DuperPaoloWorld/Variant_SideScrolling/AI",
			"DuperPaoloWorld/Variant_SideScrolling/Gameplay",
			"DuperPaoloWorld/Variant_SideScrolling/Interfaces",
			"DuperPaoloWorld/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
