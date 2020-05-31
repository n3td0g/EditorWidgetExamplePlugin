#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "EditorWidgetExampleSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class EDITORWIDGETEXAMPLE_API UEditorWidgetExampleSettings : public UDeveloperSettings
{
    GENERATED_BODY()
    
public:
    UEditorWidgetExampleSettings();
    
public:
    UPROPERTY(config, EditAnywhere)
    TSubclassOf<class UTestEditorWidget> TestEditorWidgetClass;

    UPROPERTY(config, EditAnywhere)
    TSubclassOf<class UEditorWidgetRow> EditorWidgetRowClass;
};