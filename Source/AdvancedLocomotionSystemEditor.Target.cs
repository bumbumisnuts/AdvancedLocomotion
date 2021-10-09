

using UnrealBuildTool;
using System.Collections.Generic;

public class AdvancedLocomotionSystemEditorTarget : TargetRules
{
	public AdvancedLocomotionSystemEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "AdvancedLocomotionSystem" } );
	}
}
