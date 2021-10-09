

using UnrealBuildTool;
using System.Collections.Generic;

public class AdvancedLocomotionSystemTarget : TargetRules
{
	public AdvancedLocomotionSystemTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "AdvancedLocomotionSystem" } );
	}
}
