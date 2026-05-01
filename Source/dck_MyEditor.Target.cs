using UnrealBuildTool;
using System.Collections.Generic;

public class dck_MyEditorTarget : TargetRules
{
    public dck_MyEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("dck_My");

        bUseAdaptiveUnityBuild = false; // Отключаем проверку Git
    }
}