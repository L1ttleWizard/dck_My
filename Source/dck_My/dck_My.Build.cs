using UnrealBuildTool;

public class dck_My : ModuleRules
{
	public dck_My(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "LevelSequence", "MovieScene" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}