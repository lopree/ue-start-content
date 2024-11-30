// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ReProject : ModuleRules
{
	public ReProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","Paper2D","UMG" });
	}
}
