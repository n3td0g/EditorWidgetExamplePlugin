// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EditorWidgetExample.h"
#include "EditorWidgetExampleStyle.h"
#include "EditorWidgetExampleCommands.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "Widgets/Docking/SDockTab.h"
#include "EditorWorldExtension.h"

#include "LevelEditor.h"
#include "TestEditorWidget.h"
#include "EditorWidgetExampleSettings.h"
#include "Blueprint/UserWidget.h"

static const FName EditorWidgetExampleTabName("EditorWidgetExample");

#define LOCTEXT_NAMESPACE "FEditorWidgetExampleModule"

void FEditorWidgetExampleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEditorWidgetExampleStyle::Initialize();
	FEditorWidgetExampleStyle::ReloadTextures();

	FEditorWidgetExampleCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEditorWidgetExampleCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FEditorWidgetExampleModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FEditorWidgetExampleModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FEditorWidgetExampleModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FEditorWidgetExampleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorWidgetExampleStyle::Shutdown();

	FEditorWidgetExampleCommands::Unregister();
}

void FEditorWidgetExampleModule::PluginButtonClicked()
{
	TSubclassOf<UTestEditorWidget> TestEditorWidgetClass = GetDefault<UEditorWidgetExampleSettings>()->TestEditorWidgetClass;

	if (TestEditorWidgetClass)
	{
        FText DisplayName = FText::FromString(TestEditorWidgetClass->GetName());

        const FName EditorWidgetRegistrationName = FName(TEXT("TestEditorWidget"));

        TSharedPtr<FTabManager> TabManager = FGlobalTabmanager::Get();
        TSharedPtr<SDockTab> NewDockTab = TabManager->FindExistingLiveTab(EditorWidgetRegistrationName);

        if (!NewDockTab.IsValid())
        {
            NewDockTab = TabManager->InvokeTab(EditorWidgetRegistrationName);
        }
		else
		{
			return;
		}

        UWorld* World = GEditor->GetEditorWorldContext().World();
        check(World);
        UTestEditorWidget* CreatedEditorWidget = CreateWidget<UTestEditorWidget>(World, TestEditorWidgetClass);
        if (IsValid(CreatedEditorWidget))
        {
            TSharedRef<SWidget> CreatedSlateWidget = CreatedEditorWidget->TakeWidget();
            NewDockTab->SetContent(CreatedSlateWidget);
            NewDockTab->SetLabel(DisplayName);
        }
	}
}

void FEditorWidgetExampleModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FEditorWidgetExampleCommands::Get().PluginAction);
}

void FEditorWidgetExampleModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FEditorWidgetExampleCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorWidgetExampleModule, EditorWidgetExample)