// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EditorWidgetExampleStyle.h"

class FEditorWidgetExampleCommands : public TCommands<FEditorWidgetExampleCommands>
{
public:

	FEditorWidgetExampleCommands()
		: TCommands<FEditorWidgetExampleCommands>(TEXT("EditorWidgetExample"), NSLOCTEXT("Contexts", "EditorWidgetExample", "EditorWidgetExample Plugin"), NAME_None, FEditorWidgetExampleStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
