// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EditorWidgetExampleCommands.h"

#define LOCTEXT_NAMESPACE "FEditorWidgetExampleModule"

void FEditorWidgetExampleCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "EditorWidgetExample", "Execute EditorWidgetExample action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
