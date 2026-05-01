using UnrealBuildTool;
using System.Collections.Generic;

public class dck_MyTarget : TargetRules
{
    public dck_MyTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("dck_My");

        bUseAdaptiveUnityBuild = false; // Отключаем проверку Git
    }
}